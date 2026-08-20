/*The first line of input is the number of test cases, say t. t test cases will follow. Each test case is composed of 2 sets of input. The first input is a positive integer that identifies the operation to be performed. The operations are described below:

Simplify the lone polynomial
Add the given 2 polynomials
Subtract the second polynomial from the first
Multiply the given 2 polynomials
The second set of input depends on the operation to be performed. Only the simplify operation has 1 polynomial as input. The rest of the operations have two polynomials. Each polynomial is a set of coefficient and exponent pair.

Output
This the resulting polynomial displayed as a string of the form c1x^e1 OP c2x^e2 OP c3x^e3 OP ... OP cnx^en where ci
 is the coefficient, ei
 the exponent, and OP is an operator that is either + or -. If there are t test cases, there should be t lines of output as well. The resulting polynomial should be displayed in a sorted decreasing manner based on the exponent of the terms. If the coefficient is 1 (i.e. 1x^3), do not display the coefficient (x^3). If the exponent is 1 (i.e. 5x^1), do not display exponent (5x). If the exponent is 0 (i.e. 7x^0), then the independent variable is not displayed (7). If the coefficient is 0 (i.e. 0x^4), then the term is not displayed or may be removed from the array of terms entirely.
 */

 #include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct{
    int coef;
    int expo;
}term;

typedef struct mynode{
	term data;
	struct mynode *next;
}node;

typedef struct{
	int size;
	node *head;
	node *tail;
}list;

void init(list *poly){
    poly->head = NULL;
    poly->tail = NULL;
    poly->size = 0;
}

void push_back(list* poly, int coef, int expo){
    node *new = (node*) malloc(sizeof(node));

    new->data.coef = coef;
    new->data.expo = expo;
    new->next = NULL;

    if (poly->head == NULL){
        poly->head = new;
        poly->tail = new;
    } else {
        poly->tail->next = new;
        poly->tail = new;
    }
    poly->size++;
}

void strToInt(char* polyn, list* poly){
    int coef, expo, sign, i=0;

    while (polyn[i] != '\0'){
        coef = 0, expo = 0, sign = 1;

        if (polyn[i] == '+'){
            sign = 1;
            i++;
        } else if (polyn[i] == '-'){
            sign = -1;
            i++;
        }

        while (isdigit(polyn[i])){
            coef = coef * 10 + (polyn[i] - '0');
            i++;
        }

        if (polyn[i] == 'x'){
            i++;

            if (coef == 0)
                coef = 1;

            if (polyn[i] == '^'){
                i++;
                while (isdigit(polyn[i])){
                    expo = expo * 10 + (polyn[i] - '0');
                    i++;
                }
            } else {
                expo = 1;
            }
        } else
            expo = 0;

        coef *= sign;

        push_back(poly, coef, expo);
    }
}

void negstrToInt(char* polyn, list* poly){
    int coef, expo, sign, i=0;

    while (polyn[i] != '\0'){
        coef = 0, expo = 0, sign = -1;

        if (polyn[i] == '+'){
            sign = -1;
            i++;
        } else if (polyn[i] == '-'){
            sign = 1;
            i++;
        }

        while (isdigit(polyn[i])){
            coef = coef * 10 + (polyn[i] - '0');
            i++;
        }

        if (polyn[i] == 'x'){
            i++;

            if (coef == 0)
                coef = 1;

            if (polyn[i] == '^'){
                i++;
                while (isdigit(polyn[i])){
                    expo = expo * 10 + (polyn[i] - '0');
                    i++;
                }
            } else {
                expo = 1;
            }
        } else
            expo = 0;

        coef *= sign;

        push_back(poly, coef, expo);
    }
}

void multi(list* multix, list* multiy, list* prodxy){
    node* xptr1 = multix->head;
    node* xptr2;
    int prodCoef, prodExpo;

    while (xptr1 != NULL){
        xptr2 = multiy->head;
        while (xptr2 != NULL){
            prodCoef = xptr1->data.coef * xptr2->data.coef;
            prodExpo = xptr1->data.expo + xptr2->data.expo;

            push_back(prodxy, prodCoef, prodExpo);
            xptr2 = xptr2->next;
        }
        xptr1 = xptr1->next;
    }
}

void display(list poly){
    node* temp;
    int absCoef;
    temp = poly.head;
    while (temp != NULL){
        if (temp->data.coef != 0){
            if (temp->data.coef > 0 && temp != poly.head){
                printf("+");
            } else if (temp->data.coef < 0){
                printf("-");
            }
            absCoef = (temp->data.coef < 0) ? -temp->data.coef : temp->data.coef;
            if (absCoef != 1 || temp->data.expo == 0){
                printf("%d", absCoef);
            }
            if (temp->data.expo > 0){
                printf("x");
                if (temp->data.expo > 1){
                    printf("^%d", temp->data.expo);
                }
            }
        }

        temp = temp->next;
    }
    printf("\n");
}

void sort(list* poly){
    term tempvalue;
    int flag;
    node* temp;
    flag = 1;
    while (flag == 1){
        flag = 0;
        temp = poly->head;
        while (temp->next != NULL){
            if (temp->data.expo < temp->next->data.expo){
                tempvalue = temp->data;
                temp->data = temp->next->data;
                temp->next->data = tempvalue;
                flag = 1;
            }
            temp = temp->next;
        }
    }
}

void simplify(list* poly){
    node* temp;
    node* forDel;
    temp = poly->head;
    sort(poly);
    while (temp->next != NULL){
        if (temp->data.expo == temp->next->data.expo){
            temp->data.coef = temp->data.coef + temp->next->data.coef;
            forDel = temp->next;
            temp->next = temp->next->next;
            free(forDel);
        } else{
            temp = temp->next;
        }

    }

    display(*poly);
}

int main(){
    list multix, multiy, prodxy;
    list poly, polyx1;
    int tcase, tcases, op;
    char poly1[100], poly2[100], poly11[100];

    scanf("%d", &tcases);

    for (tcase = 1; tcase <= tcases; tcase++){
        init(&poly);
        init(&multix);
        init(&multiy);
        init(&prodxy);
        scanf("%d", &op);

        switch (op){
            case 1:
                scanf("%s", poly1);
                strToInt(poly1, &poly);
                simplify(&poly);
                break;
            case 2:
                scanf("%s", poly1);
                scanf("%s", poly2);
                strToInt(poly1, &poly);
                strToInt(poly2, &poly);
                simplify(&poly);
                break;
            case 3:
                scanf("%s", poly1);
                scanf("%s", poly2);
                strToInt(poly1, &poly);
                negstrToInt(poly2, &poly);
                simplify(&poly);
                break;
            case 4:
                scanf("%s", poly1);
                scanf("%s", poly2);
                strToInt(poly1, &multix);
                strToInt(poly2, &multiy);
                multi(&multix, &multiy, &prodxy);
                simplify(&prodxy);
                break;
        }
    }
}

