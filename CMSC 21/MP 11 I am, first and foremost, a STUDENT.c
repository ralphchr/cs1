#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char studnum[100];
    char fname[100];
    char mname[100];
    char lname[100];
    char prog[100];
    int year;
}student;

typedef struct mynode{
    student studentInfo;
    struct mynode *next;
}node;

typedef struct{
    node *head;
    node *tail;
    int size;
}list;

void push_back(list *l, char sn[100], char f[100], char m[100], char surn[100], char p[100], int yr){
    node *new = malloc(sizeof(node));
    node *temp;

    strcpy(new->studentInfo.studnum, sn);
    strcpy(new->studentInfo.fname, f);
    strcpy(new->studentInfo.mname, m);
    strcpy(new->studentInfo.lname, surn);
    strcpy(new->studentInfo.prog, p);
    new->studentInfo.year = yr;
    new->next = NULL;

    if (l->head == NULL){
        l->head = new;
        l->tail = new;
    } else {
        l->tail->next = new;
        l->tail = new;
    }
    l->size++;
}

void insert(list *l, char sn[100], char f[100], char m[100], char surn[100], char p[100], int yr, int pos){
	node *new = malloc(sizeof(node));
	node *temp;
	int i;

	strcpy(new->studentInfo.studnum, sn);
    strcpy(new->studentInfo.fname, f);
    strcpy(new->studentInfo.mname, m);
    strcpy(new->studentInfo.lname, surn);
    strcpy(new->studentInfo.prog, p);
    new->studentInfo.year = yr;
    new->next = NULL;

	if (pos == 0){
	    new->next = l->head;
	    l->head = new;

	    if (l->tail == NULL)
	        l->tail = new;
	} else {
	    temp = l->head;

	   for (i = 0; i < pos - 1; i++)
	        temp = temp->next;

	   new->next = temp->next;
	   temp->next = new;

	   if (new->next == NULL)
	       l->tail = new;
	}

	l->size++;
}

int delete(list *l, char sn[100]){
	node *temp, *prev;
	temp = l->head;
	prev = NULL;

	while (temp != NULL && (strcmp(temp->studentInfo.studnum, sn) != 0)){
	    prev = temp;
	    temp = temp->next;
	}

	if (temp == NULL)
	    return 0;
	if (prev == NULL)
	    l->head = temp->next;
	else
	    prev->next = temp->next;

	if (temp == l->tail)
	    l->tail = prev;
	free(temp);
	l->size--;

	return 1;
}

int access(list *l, char sn[100]){
    node *temp;

    temp = l->head;
	while (temp != NULL){
        if (strcmp(temp->studentInfo.studnum, sn) == 0){
            printf("Student Number: %s\n", temp->studentInfo.studnum);
            printf("Name: %s %s %s\n", temp->studentInfo.fname, temp->studentInfo.mname, temp->studentInfo.lname);
            printf("Program: %s\n", temp->studentInfo.prog);
            printf("Year Level: %d\n", temp->studentInfo.year);
            return 1;
	    }
	    temp = temp->next;
	}
	return 0;
}

int editprog(list *l, char sn[100], char newprogram[]){
    node *temp;
    temp = l->head;
	while (temp != NULL){
        if (strcmp(temp->studentInfo.studnum, sn) == 0){
            strcpy(temp->studentInfo.prog, newprogram);
            return 1;
	    }
	    temp = temp->next;
	}
	return 0;
}

int edityear(list *l, char sn[100], int newyear){
    node *temp;
    temp = l->head;
	while (temp != NULL){
        if (strcmp(temp->studentInfo.studnum, sn) == 0){
            temp->studentInfo.year = newyear;
            return 1;
	    }
	    temp = temp->next;
	}
	return 0;
}

int displayprog(list *l, char program[100]){
    int checker;
    node *temp;
    checker = 0;
    temp = l->head;
    while (temp != NULL){
        if (strcmp(temp->studentInfo.prog, program) == 0){
            checker = 1;
            printf("Student Number: %s\n", temp->studentInfo.studnum);
            printf("Name: %s %s %s\n", temp->studentInfo.fname, temp->studentInfo.mname, temp->studentInfo.lname);
            printf("Program: %s\n", temp->studentInfo.prog);
            printf("Year Level: %d\n", temp->studentInfo.year);
            printf("------------------------------------");
        }
        temp = temp->next;
    }

    if (!checker)
        return 0;
    return 1;
}

int displayyear(list *l, int yr){
    int checker;
    node *temp;
    checker = 0;
    temp = l->head;
    while (temp != NULL){
        if (temp->studentInfo.year == yr){
            checker = 1;
            printf("Student Number: %s\n", temp->studentInfo.studnum);
            printf("Name: %s %s %s\n", temp->studentInfo.fname, temp->studentInfo.mname, temp->studentInfo.lname);
            printf("Program: %s\n", temp->studentInfo.prog);
            printf("Year Level: %d\n", temp->studentInfo.year);
            printf("------------------------------------");
        }
        temp = temp->next;
    }

    if (!checker)
        return 0;
    return 1;
}

void init(list *l){
    l->head = NULL;
    l->tail = NULL;
    l->size = 0;
}

void display(list l){
    node *temp = l.head;

    while (temp != NULL){
        printf("Student Number: %s\n", temp->studentInfo.studnum);
        printf("Name: %s %s %s\n", temp->studentInfo.fname, temp->studentInfo.mname, temp->studentInfo.lname);
        printf("Program: %s\n", temp->studentInfo.prog);
        printf("Year Level: %d\n", temp->studentInfo.year);
        temp = temp->next;
    }

    printf("------------------------------------");
}

int main(){
    list students;
    int num, nums, op, ops, optype, pos, edittype, yearLevel, newyr, checker;
    char studentNumber[100], firstName[100], midName[100], lastName[100], program[100], newprog[100];
    init(&students);
    scanf("%d", &nums);

    for (num = 0; num < nums; num++){
        scanf("%s", studentNumber);
        scanf("%s %s %s", firstName, midName, lastName);
        getchar();
        scanf(" %[^\n]", program);
        scanf("%d", &yearLevel);
        getchar();

        push_back(&students, studentNumber, firstName, midName, lastName, program, yearLevel);
    }

    scanf("%d", &ops);
    for (op = 0; op < ops; op++){
        scanf("%d", &optype);

        switch (optype){
            case 1:
                scanf("%s", studentNumber);
                scanf("%s %s %s", firstName, midName, lastName);
                getchar();
                scanf(" %[^\n]", program);
                scanf("%d", &yearLevel);
                getchar();
                scanf("%d", &pos);

                insert(&students, studentNumber, firstName, midName, lastName, program, yearLevel, pos);
                display(students);
                break;

            case 2:
                scanf("%s", studentNumber);

                checker = delete(&students, studentNumber);
                if (!checker)
                    printf("Student not enrolled.");
                display(students);
                break;

            case 3:
                scanf("%s", studentNumber);

                checker = access(&students, studentNumber);
                if (!checker)
                    printf("Student not enrolled.");
                display(students);
                break;

            case 4:
                scanf("%s", studentNumber);
                scanf("%d", &edittype);
                if (edittype == 1){
                    scanf(" %[^\n]", newprog);
                    editprog(&students, studentNumber, newprog);
                } else if (edittype == 2){
                    scanf("%d", &newyr);
                    edityear(&students, studentNumber, newyr);
                }
                display(students);
                break;

            case 5:
                scanf(" %[^\n]", program);
                checker = displayprog(&students, program);
                if (!checker)
                    printf("No students enrolled in %s.", program);
                break;

            case 6:
                scanf("%d", &yearLevel);
                checker = displayyear(&students, yearLevel);
                if (!checker)
                    printf("No students with year level %d.", yearLevel);
                break;
        }
        printf("\n");
    }

    return 0;
}