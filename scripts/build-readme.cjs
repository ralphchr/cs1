// node scripts/build-readme.cjs
// Uses the same outlined Inter Black and JetBrains Mono as the ralphchr profile.
// All output is self-contained SVG: no font downloads, scripts, or dependencies.
const fs = require('node:fs');
const path = require('node:path');
const fonts = require('./readme-fonts.json');
const output = path.join(__dirname, '../assets/readme');
const C = { ivory: '#F0E9DD', silver: '#C5C6D0', blue: '#8EBBEE', purple: '#8B5CF6', red: '#EF7583' };
const esc = value => value.replaceAll('&', '&amp;').replaceAll('<', '&lt;').replaceAll('"', '&quot;');
const n = value => +value.toFixed(3);

class Artwork {
  constructor(width, height, title, description) {
    Object.assign(this, { width, height, title, description, parts: [], glyphs: new Map() });
  }
  measure(text, size, font = 'display', spacing = 0) {
    return [...text].reduce((width, c) => width + fonts[font].glyphs[c].advance * size / 1000 + spacing, 0) - spacing;
  }
  text(text, x, y, size, font = 'display', color = C.ivory, { outline = false, spacing = 0, end = false } = {}) {
    if (end) x -= this.measure(text, size, font, spacing);
    let at = 0;
    const letters = [...text].map(c => {
      const glyph = fonts[font].glyphs[c];
      if (!glyph) throw new Error(`Missing ${font} glyph: ${c}`);
      const id = font[0] + c.codePointAt(0);
      this.glyphs.set(id, glyph.d);
      const letter = glyph.d ? `<use href="#${id}" x="${n(at)}"/>` : '';
      at += glyph.advance + spacing * 1000 / size;
      return letter;
    }).join('');
    const paint = outline ? `fill="none" stroke="${color}" stroke-width="${n(1400 / size)}" stroke-linejoin="round"` : `fill="${color}"`;
    return `<g transform="translate(${n(x)} ${n(y)}) scale(${n(size / 1000)})" ${paint}>${letters}</g>`;
  }
  add(part) { this.parts.push(part); }
  finish() {
    return `<svg xmlns="http://www.w3.org/2000/svg" width="${this.width}" height="${this.height}" viewBox="0 0 ${this.width} ${this.height}" role="img" aria-labelledby="title desc"><title id="title">${esc(this.title)}</title><desc id="desc">${esc(this.description)}</desc><!-- Outlined Inter Black and JetBrains Mono; transparent canvas. --><defs>${[...this.glyphs].map(([id, d]) => `<path id="${id}" d="${d}"/>`).join('')}</defs>${this.parts.join('')}</svg>\n`;
  }
}

function grid(s) {
  s.add(`<defs><pattern id="grid" width="48" height="48" patternUnits="userSpaceOnUse"><path d="M48 0H0V48" fill="none" stroke="${C.blue}" stroke-opacity=".045"/><circle cx="1" cy="1" r="1" fill="${C.purple}" fill-opacity=".2"/></pattern></defs><rect width="${s.width}" height="${s.height}" fill="url(#grid)"/>`);
}

// Keep the words readable between short, displaced chromatic slices.
function headline(s, text, x, baseline, size, animated, id, outline = false) {
  const width = s.measure(text, size, 'display', -1);
  const art = color => s.text(text, x, baseline, size, 'display', color, { outline, spacing: -1 });
  let result = art(outline ? C.silver : C.ivory);
  if (!animated) return result;
  const keys = '0;.86;.89;.915;.94;.96;1';
  const pulse = `<animate attributeName="opacity" values="0;0;.9;0;.65;0;0" keyTimes="${keys}" calcMode="discrete" dur="6s" repeatCount="indefinite"/>`;
  result = `<g>${result}<animateTransform attributeName="transform" type="translate" values="0 0;0 0;2 0;-2 0;0 0;0 0" keyTimes="0;.86;.89;.915;.94;1" calcMode="discrete" dur="6s" repeatCount="indefinite"/></g>`;
  for (const [slice, fraction, shift, color] of [['blue', .52, 7, C.blue], ['red', .2, -6, C.red]]) {
    const clip = `${id}-${slice}`;
    result += `<defs><clipPath id="${clip}"><rect x="${x - 10}" y="${baseline - size * fraction}" width="${width + 24}" height="${slice === 'blue' ? 4 : 3}"/></clipPath></defs><g clip-path="url(#${clip})" aria-hidden="true"><g opacity="0" transform="translate(${shift} 0)">${art(color)}${pulse}</g></g>`;
  }
  return result;
}

function underline(x, y, width, animated) {
  return `<path d="M${x} ${y}h${width}" stroke="${C.purple}" stroke-width="1.5"/>` + (animated ? `<path d="M${x} ${y}h${width}" pathLength="100" stroke="${C.blue}" stroke-dasharray="18 82"><animate attributeName="stroke-dashoffset" from="100" to="-100" dur="9s" repeatCount="indefinite"/></path>` : '');
}

function hero(mobile, animated) {
  const w = mobile ? 600 : 1200, h = mobile ? 460 : 430, p = mobile ? 32 : 48;
  const s = new Artwork(w, h, 'COMPUTER SCIENCE. YEAR ONE.', 'First-year Computer Science coursework at UP Cebu. Machine problems, homework, and projects.');
  grid(s);
  s.add(s.text('CS1', p, 60, 38));
  s.add(s.text('_', p + s.measure('CS1', 38), 60, 38, 'display', C.blue));
  if (!mobile) s.add(s.text('UP CEBU / COMPUTER SCIENCE I', 178, 54, 16, 'mono', C.silver, { spacing: .5 }));
  s.add(s.text('@RALPHCHR', w - p, 54, 16, 'mono', C.blue, { spacing: .5, end: true }));
  s.add(`<path d="M${p} 85H${w - p}M${p} ${h - 43}H${w - p}" stroke="${C.silver}" stroke-opacity=".22"/>`);
  if (mobile) {
    s.add(headline(s, 'COMPUTER', p, 163, 64, animated, 'computer', true));
    s.add(headline(s, 'SCIENCE.', p, 235, 64, animated, 'science', true));
    s.add(headline(s, 'YEAR ONE.', p, 325, 78, animated, 'year'));
    s.add(s.text('Machine problems,', p, 365, 22, 'mono', C.blue));
    s.add(s.text('homework, and projects.', p, 395, 22, 'mono', C.blue));
  } else {
    s.add(headline(s, 'COMPUTER SCIENCE.', p, 187, 78, animated, 'computer', true));
    s.add(headline(s, 'YEAR ONE.', p, 293, 108, animated, 'year'));
    s.add(s.text('Machine problems, homework, and projects.', p + 2, 345, 23, 'mono', C.blue));
    s.add(`<path d="M1116 119h36v36M48 318v-14h14" fill="none" stroke="${C.purple}" stroke-opacity=".65"/>`);
  }
  s.add(s.text('C / C++ / PYTHON', p, h - 17, mobile ? 16 : 15, 'mono', C.silver, { spacing: .4 }));
  s.add(s.text('01', w - p, h - 17, 16, 'mono', C.blue, { end: true }));
  s.add(underline(p, 85, mobile ? 88 : 140, animated));
  return s.finish();
}

function toolkit(mobile) {
  const w = mobile ? 600 : 1200, h = mobile ? 350 : 185, p = mobile ? 32 : 48;
  const s = new Artwork(w, h, 'Toolkit', 'C for fundamentals. C++ for classes and data structures. Python with NumPy, SciPy, and Matplotlib.');
  s.add(`<path d="M${p} 1H${w - p}" stroke="${C.silver}" stroke-opacity=".22"/>`);
  const entries = [['C', 'FUNDAMENTALS', 'Loops / strings / functions'], ['C++', 'DATA STRUCTURES', 'Pointers / lists / classes'], ['Python', 'SCIENTIFIC COMPUTING', 'NumPy / SciPy / Matplotlib']];
  entries.forEach(([name, label, detail], i) => {
    const x = mobile ? p : p + i * 380, y = mobile ? 29 + i * 110 : 29;
    s.add(s.text(label, x, y, mobile ? 16 : 14, 'mono', C.blue, { spacing: .4 }));
    s.add(s.text(name, x - 1, y + 49, mobile ? 38 : 42));
    s.add(s.text(detail, x, y + 79, mobile ? 17 : 16, 'mono', C.silver));
    if (!mobile && i) s.add(`<path d="M${x - 28} 25v101" stroke="${C.silver}" stroke-opacity=".16"/>`);
  });
  return s.finish();
}

function light(svg) {
  const palette = { '#F0E9DD': '#222432', '#C5C6D0': '#4B5064', '#8EBBEE': '#376A9F', '#8B5CF6': '#6D42BE', '#EF7583': '#BA4356' };
  return svg.replace(/#(?:F0E9DD|C5C6D0|8EBBEE|8B5CF6|EF7583)/gi, color => palette[color.toUpperCase()]);
}

fs.mkdirSync(output, { recursive: true });
for (const [stem, build] of [['hero', hero], ['toolkit', toolkit]]) {
  for (const mobile of [false, true]) {
    for (const animated of stem === 'toolkit' ? [false] : [false, true]) {
      const filename = stem + (mobile ? '-mobile' : '') + (animated ? '-animated' : '');
      const svg = build(mobile, animated);
      fs.writeFileSync(path.join(output, filename + '.svg'), svg);
      fs.writeFileSync(path.join(output, filename + '-light.svg'), light(svg));
    }
  }
}
console.log('Built README banners: mobile, light, animated, and reduced-motion versions.');
