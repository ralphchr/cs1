import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import solve_ivp

#Object properties
radius = 0.0366
mass = 0.145
drag_coeff = 0.47
air_density = 1.225
gravity = 9.81

cross_section = np.pi * radius**2
drag_constant = 0.5 * drag_coeff * air_density * cross_section

#Time
time_span = (0, 100)
time_points = np.linspace(time_span[0], time_span[1], 2000)

#motion: dv/dt = g - (k/m)v
def motion(t, v):
    return gravity - (drag_constant / mass) * v

#Solve velocity using a different solver
solution = solve_ivp(motion, time_span, [0], t_eval=time_points)
velocity_drag = solution.y[0]

#Numerical integration for position
dt = time_points[1] - time_points[0]
position_drag = np.zeros_like(velocity_drag)
for i in range(1, len(time_points)):
    position_drag[i] = position_drag[i-1] + velocity_drag[i] * dt

#Acceleration from numerical gradient
acceleration_drag = np.gradient(velocity_drag, time_points)

#No air resistance case
velocity_free = gravity * time_points
position_free = 0.5 * gravity * time_points**2
acceleration_free = np.full_like(time_points, gravity)

#Plot layout
fig, axes = plt.subplots(1, 3, figsize=(18, 5))

#Acceleration
axes[0].plot(time_points, acceleration_free, label="Vacuum case")
axes[0].plot(time_points, acceleration_drag, label="With drag")
axes[0].set_title("Acceleration vs Time")
axes[0].set_xlabel("Time (s)")
axes[0].set_ylabel("Acceleration (m/s²)")
axes[0].legend()
axes[0].grid()

#Velocity
axes[1].plot(time_points, velocity_free, label="Vacuum case")
axes[1].plot(time_points, velocity_drag, label="With drag")
axes[1].set_title("Velocity vs Time")
axes[1].set_xlabel("Time (s)")
axes[1].set_ylabel("Velocity (m/s)")
axes[1].legend()
axes[1].grid()

#Position
axes[2].plot(time_points, position_free, label="Vacuum case")
axes[2].plot(time_points, position_drag, label="With drag")
axes[2].set_title("Position vs Time")
axes[2].set_xlabel("Time (s)")
axes[2].set_ylabel("Displacement (m)")
axes[2].legend()
axes[2].grid()

plt.tight_layout()
plt.show()
