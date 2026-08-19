//Ask the user to enter 3 numbers, a, b, c. Print them in descending order.

#include <stdio.h>

int main(){
    int n1,n2,n3;

    scanf("%d %d %d", &n1, &n2, &n3);

    int high, mid, low;

    if (n1>n2 && n2>n3){
        high = n1;
        mid = n2;
        low = n3;
    } else if (n1>n3 && n3>n2){
        high = n1;
        mid = n3;
        low = n2;
    } else if (n2>n1 && n1>n3){
        high = n2;
        mid = n1;
        low = n3;
    } else if (n2>n3 && n3>n1){
        high = n2;
        mid = n3;
        low = n1;
    } else if (n3>n1 && n1>n2){
        high = n3;
        mid = n1;
        low = n2;
    }else if (n3>n2 && n2>n1){
        high = n3;
        mid = n2;
        low = n1;
    }

    printf("%d %d %d", high, mid, low);
}