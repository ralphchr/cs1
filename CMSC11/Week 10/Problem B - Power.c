/*Ask the user to enter two integers, x and y.  Compute and display for the power when x is raised to y.  Note that for this problem, x and y are integers. This means that they may be negative, 0, or positive.

For the output, print the actual result. When the exponent is less than 0, i.e. negative, print the result as a fraction. For instance, if x is 2 and y is -3, print 1/8 as the result. Do not print it with floating points. Also, when both x and y are 0, print "INDETERMINATE".

NOTE: Please follow the output message correctly, including case.
*/

#include <stdio.h>
int main(){
    int x, y, result = 1;

    printf("Enter two integers: ");
    scanf("%d %d", &x, &y);

    if (x == 0 && y == 0){
        printf("INDETERMINATE");
    } else if (x == 0 && y > 0){
        printf("0");
    } else if (x == 0 && y < 0){
        printf("UNDEFINED");
    } else if (y == 0){
        printf("1");
    } else if (x == 1){
        printf("1");
    } else if (x == -1){
        if (y % 2 == 0)
            printf("1");
        else
            printf("-1");
    } else if (y < 0){
        for (int i = 0; i < -y; i++){
            result *= x;
        }
        if (result < 0)
            printf("-1/%d", -result);
        else
            printf("1/%d", result);
    } else {
        for (int i = 0; i < y; i++){
            result *= x;
        }
        printf("%d", result);
    }
}