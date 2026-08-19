/*Ask the user to enter a non-negative number, say n.  Compute and display for the factorial of n. Sample: The factorial of 5 (written as 5!) is 5*4*3*2*1 which is 120.

If and when the input is invalid, print "INVALID INPUT". Input values going beyond 12 should be flagged as invalid as well. 13! is over 6 billion already.

NOTE: Please follow the output message correctly, including case.
*/

#include <stdio.h>
int main(){
    int n, result = 1;

    printf("Enter a positive number: ");
    scanf("%d", &n);

    if (n>12 || n<0){
        printf("INVALID INPUT");
    } else if (n == 0){
        printf("1");
    } else {
        for (int i = 1; i <= n; i++){
            result *= i;
        }

        printf("%d", result);
    }

}