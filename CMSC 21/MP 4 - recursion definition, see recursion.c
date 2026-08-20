/*You are to compute for the product when 1 number is multiplied with another. Implement this using recursion and without using the multiplication operator. There should be only 2 arguments in the recursive function.

Given n integers (single digit positive integers) stored in an array, determine if the array elements form a palindrome or not. Again, implement this recursively. Since you will need to keep track the indices in the array from both ends, the recursive function can be implemented with 3 arguments, i.e. the array, some lower bound and some upper bound.

For input, you will read 2 integers (assume they are all positive). These are the numbers to be multiplied. The next input is a positive integer, say n. It signifies how many elements the array is going to contain. n single digit positive integers will follow.

For each recursive call that is made, print "Recursive Case!" Once the recursion reaches the base case, print "Base Case!" Print the product of the multiplication in one line. Print "The array is palindromic!" or "The array is not palindromic!" depending on the case for the second recursive function.
*/

#include <stdio.h>


int prod(int, int);
void pal(int[], int, int);

int main(){
    int num1, num2;
    scanf("%d %d", &num1, &num2);

    printf("%d", prod(num1,num2));
    printf("\n");
    int size;
    scanf("%d", &size);
    int nums[1]; //replace 1 with size, just a compiler error again
    for (int i = 0; i < size; i++)
        scanf("%d", &nums[i]);

    int start = 0, end = size -1;
    pal(nums,start,end);

}


int prod(int num1, int num2){
    // int temp;
    // if (num1 < num2){
    //      temp = num1;
    //      num1 = num2;
    //      num2 = temp;
    // }
    if (num2 == 1){
        printf("Base case!\n");
        return num1;
    } else if (num1 == 1){
         printf("Base case!\n");
         return num2;
    }
    else{
        if (num2 % 2 == 0){
            printf("Recursive case!\n");
            return prod(num1 + num1, num2/2);

        } else if (num2 % 2 == 1){
            printf("Recursive case!\n");
            return num1 + prod(num1 + num1, num2/2);
        }
    }

}

void pal(int nums[], int start, int end){

    if (start>=end){
        printf("Base case!\n");
        printf("The array is palindromic!");
    } else if (nums[start] == nums[end]){
        printf("Recursive Case!\n");
        pal(nums,start+1,end-1);
    } else if (nums[start] != nums[end]){
        printf("The array is not palindromic!");
    }

}