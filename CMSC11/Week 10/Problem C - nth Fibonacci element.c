/*Ask the user to enter a positive integer, say n.  Compute and display for the nth Fibonacci element. The first (n is 1) element of the sequence is 1 and the second (n is 2) element is 1 as well. To get the nth Fibonacci element when n is greater than 2, compute for the (n-1)th element and add this to the (n-2)th element.  These are the first few elements of the Fibonacci sequence:  1, 1, 2, 3, 5, 8, 13, 21, 34, ...

Inputs greater than 47 should also be flagged as invalid. The 47th Fibonacci element is 2971215073. This value can no longer fit in an int.

For the output, print the nth fibonacci element. If and when the input is invalid, print "INVALID INPUT.

NOTE: Please follow the output message correctly, including case.
*/

#include <stdio.h>

int main(){
    int num, f= 1,s = 1, t;

    printf("enter a positive integer: ");
    scanf("%d", &num);

    if (num == 1 || num == 2){
        printf("1");
    } else if (0 < num && num < 47){
        for (int i = 3; i <= num; i++){
            t = f + s;
            f = s;
            s = t;
        }
        printf("%d", s);
    } else{
        printf("INVALID INPUT");
    }
}