/*Ask the user to enter a positive number and determine if it is a perfect number or not. Recall that a number is perfect if the sum of all its factors except itself is itself. 6 is perfect because the sum of its factors 1, 2, 3, excluding 6, is 6.
For the output, print YES if the input is a perfect number. Print NO when it is not. And print INVALID INPUT if it is invalid. For invalid input here, do not ask the user to re-enter the input. Simply print the appropriate message.

NOTE: Please follow the output message correctly, including case.
*/

#include <stdio.h>
int main(){
    int num,sum = 0;

    printf("Enter a positive number: ");
    scanf("%d", &num);

    if (num <= 0){
        printf("INVALID INPUT");
    } else {
        for (int i = 1; i <= num/2; i++ ){
            if (num % i == 0){
                sum += i;
            } else {
                continue;
            }
        }


        if (sum == num){
            printf("YES");
        } else {
            printf("NO");
        }
    }
}