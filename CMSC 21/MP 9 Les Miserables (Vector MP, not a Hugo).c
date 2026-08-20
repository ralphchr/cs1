/*Implement the vector using the dynamic array implementation. The vector class is a container holding items similar to a C-style array, A[n], but allocated dynamically. In other words, it is a dynamic array that can expand and shrink its capacity.

Set the initial capacity of the vector to 5. Every time the vector gets full, increase its capacity by 5.

It should have an init function that initializes the vector.

Finally, it should implement the following operations:

int at(vector *v, int p) - returns the item at the given position p
int set(vector *v, int x, int p) - sets the item at position p to x. Return the item that was replaced.
int insert(vector *v,int x, int p) - inserts the item x at position p. Assume that first position is at position 0. Return the appropriate boolean value.
void push_back(vector *v, int x) - appends the item x at the end of the array.
void push_front(vector *v, int x) - inserts the item x in the front of the array.
void display(vector) - displays all the elements of the array on one line (separated by a space)
int remove(vector *v,int p) - removes the item found at position p. Returns the item that was removed.
In addition, create 2 functions that accept a vector as argument: (1) Call the first one isSorted. isSorted checks whether the vector is sorted in increasing order or not. (2) Call the second function deleteDuplicates. It is supposed to remove the duplicate items.

INPUT
The first line of the input is a number t that represents the number of test cases, followed by the t test cases.

Each test case consists of 2 sets: The first set has a number n, followed by n integers. These integers should be inserted into the array in the order that they are read. The second set is a number c, which is an operation to be done on the array.

c can be either 1, 2, 3, 4, 5, 6, 7, or 8.

If c is:

another number will follow. This number is to be appended to the array.
the number that will follow is to be inserted into the front of the array.
2 numbers will follow. The first number is the item to be inserted and the second number is the position as to where the number is to be inserted into the array
only one number will follow and this is the position where the item to be removed is found. Print the item that was removed.
one number will follow. This represents the position and you are to print the item found in that position.
2 numbers will follow, an item x and position p. You are to replace the item found in position p by x. Then print the item that was replaced or overwritten.
determine whether the array is sorted or not by printing "SORTED" or "NOT SORTED."
remove all duplicate elements in the array and then display it.
For all cases where the operation fails, instead of displaying the contents of the array, print "OPERATION FAILED."
*/

#include <stdio.h>
#include <stdlib.h>
int checker = 0;

typedef struct{
    int max;
	int *items;
	int size;
} vector;

void init(vector *v);
int at(vector *v, int p);
int set(vector *v, int x, int p);
int insert(vector *v, int x, int p);
void push_back(vector *v, int x);
void push_front(vector *v, int x);
void display(vector v);
int removes(vector *v,int p);
int isSorted(vector *v);
void deleteDuplicates(vector *v);
void resize(vector *v);

int main(){
    int tests, test, operation, num, nums, myItem, opara, x, p, tempf;
    vector v;


    scanf("%d", &tests);

    for (test = 1; test <= tests; test++){
        init(&v);
        operation = 0;
        scanf("%d", &nums);
        for (num = 0; num < nums; num++){
            scanf("%d", &myItem);
            push_back(&v, myItem);
        }
        scanf("%d", &operation);

        switch (operation){
            case 1:
                scanf("%d", &opara);
                push_back(&v, opara);
                if (checker == 1)
                    display(v);
                else
                    printf("OPERATION FAILED\n");
                break;

            case 2:
                scanf("%d", &opara);
                push_front(&v, opara);
                if (checker == 1)
                    display(v);
                else
                    printf("OPERATION FAILED\n");
                break;

            case 3:
                scanf("%d %d", &x, &p);
                if (insert(&v, x, p))
                    display(v);
                else
                    printf("OPERATION FAILED\n");
                break;

            case 4:
                scanf("%d", &opara);
                tempf = removes(&v, opara);
                if (tempf){
                    printf("%d\n", tempf);
                    display(v);
                } else
                    printf("OPERATION FAILED\n");
                break;

            case 5:
                scanf("%d", &opara);
                tempf = at(&v, opara);
                if (tempf){
                    printf("%d\n", tempf);
                    display(v);
                } else
                    printf("OPERATION FAILED\n");
                break;

            case 6:
                scanf("%d %d", &x, &p);
                tempf = set(&v, x, p);
                if (tempf){
                    printf("%d\n", tempf);
                    display(v);
                } else
                    printf("OPERATION FAILED\n");
                break;

            case 7:
                if (isSorted(&v))
                    printf("SORTED\n");
                else
                    printf("NOT SORTED\n");
                break;

            case 8:
                deleteDuplicates(&v);
        }
    }

    return 0;
}

void init(vector *v){
    v->max = 5;
	v->size = 0;
	v->items = malloc(sizeof(int)*v->max);
}
int at(vector *v, int p){
    if (p < v->size)
        return v->items[p];
    else
        return 0;
}
int set(vector *v, int x, int p){
    int temp;
    if(p >= 0 && p < v->size){
		temp = v->items[p];
		v->items[p] = x;
		return temp;
	}
	else
		return 0;
}
int insert(vector *v, int x, int p){
    int i;
    if (v->size == v->max)
        resize(v);
    if(p < 0 || p > v->size || v->size == v->max)
		return 0;
	else {
		if(p == v->size){
			push_back(v,x);
			return x;
		} else {
			for(i = v->size; i > p; i--){
				v->items[i] = v->items[i-1];
			}
			v->items[i] = x;
			v->size++;
			return x;
		}
	}
}
void push_back(vector *v, int x){
    if (v->size == v->max)
        resize(v);
	v->items[v->size++] = x;
	checker = 1;

}
void push_front(vector *v, int x){
    int i;
    if (v->size == v->max)
        resize(v);
	for(i = v->size; i > 0; i--)
		v->items[i] = v->items[i-1];
	v->items[i] = x;
	v->size++;
		checker = 1;

}
void display(vector v){
    int i;
    for (i = 0; i < v.size; i++)
        printf("%d ", v.items[i]);
    printf("\n");
}
int removes(vector *v,int p){
    int i, temp = v->items[p];
    if(p < 0 || p >= v->size)
		return 0;
	else {
		for(i = p; i < v->size - 1; i++)
			v->items[i] = v->items[i+1];
		v->size--;
		return temp;
	}
}
int isSorted(vector *v){
    int i;
    for (i = 0; i < v->size - 1; i++){
        if (v->items[i] > v->items[i+1])
            return 0;
    }
    return 1;
}
void deleteDuplicates(vector *v){
    int i, j, k;
    for (i = 0; i < v->size; i++){
        for(j = i+1; j < v->size; j++){
            if (v->items[i] == v->items[j]){
                for (k = j; k < v->size; k++)
                    v->items[k] = v->items[k+1];
                j--;
                v->size--;
            }
        }
    }
    display(*v);
}

/*void deleteDuplicates(vector v){
    int i, j, k;
    for (i = 0; i < v.size; i++){
        for(j = i+1; j < v.size; j++){
            if (v.items[i] == v.items[j]){
                for (k = j; k < v.size; k++)
                    v.items[k] = v.items[k+1];
                j--;
                v->size--;
            }
        }
    }
}*/

void resize(vector *v){
    v->max += 5;
    v->items = realloc(v->items, sizeof(int)*(v->max));
}
