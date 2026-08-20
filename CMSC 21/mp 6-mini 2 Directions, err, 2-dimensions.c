//The instructions is too long i dont wanna put it here

#include <stdio.h>

int main(){
    int n;

    scanf("%d", &n);

    int arr[1][1]; //replace the 1's with n, just a compiler error AGAIN

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    //last column
    for (int i = 0; i < n; i++){
        printf("%d", arr[i][n-1]);
        printf("\n");
    }

    //last row
    for (int j = 0; j < n; j++){
        printf("%d ", arr[n-1][j]);
    }

    printf("\n");

    //left to right diagonal
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i][i]);
    }

    printf("\n");
    //right to left diagonal

    for (int i = 0; i < n; i++){
        printf("%d ", arr[i][n-i-1]);
    }
}


