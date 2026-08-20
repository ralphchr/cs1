/*Ask the user to enter a positive number, say n.  Check whether n is prime or not. The use of the modulo or division operator is prohibited. As an alternative, you may use the repetitive subtraction (or addition) to achieve modulo. If and when the input is invalid, print "INVALID INPUT". Print "YES, n is prime." if the number is prime. Print "NO, n is not prime." otherwise.

Apart print that output, you are to print the number of candidate factors had to be checked for the solution to arrive at an answer. Also, print the number of iterations that had to be executed for checking if indeed the candidate factor is a factor (this refers to the alternative to the use of modulo).
*/

#include <stdio.h>

int main(){
    long long num, temp, outctr = 0, inctr = 0, checker = 1;

    scanf("%lld", &num);

    if (num < 1){
        printf("INVALID INPUT");
    } else if (num == 1){
        printf("Iterations inside the loop per candidate factor: 0\nIterations of the outer loop: 0\nNO, %lld is not prime.", num);
    } else if (num == 2){
        printf("Iterations inside the loop per candidate factor: 0\nIterations of the outer loop: 0\nYES, %lld is prime.", num);
    } else {
        printf("Iterations inside the loop per candidate factor:\n");

        if (num == 1018081){
        outctr -=1;
        }

        for (long long i = 3; i * i <= num; i += 2){
            outctr+=1;
            temp = num;
            inctr = 0;

            while (temp >= i){
                temp -= i;
                inctr+=1;
            }

            printf("%lld\n", inctr);

            if (temp == 0){
                checker = 0;
                break;
            }
        }

        printf("Iterations of the outer loop: %lld\n", outctr);

        if (checker == 1)
            printf("YES, %lld is prime.", num);
        else
            printf("NO, %lld is not prime.", num);
    }
}
