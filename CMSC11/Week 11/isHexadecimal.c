/*Ask the user to enter a string. Make sure the string can store a maximum of 100 actual characters. Print the length of the string if it is a strictly hexadecimal string. Otherwise, it returns the position where an invalid hexadecimal digit is found (this the first occurrence of a non-hexadecimal digit). Assume uppercase letters are used for A-F.

Sample: 234ABF0, program prints 7.

Sample: FFB$23, function returns 3.

Sample: ACZFFR01, function returns 2.
*/

#include <stdio.h>

int main(){
    char hexa[100];
    int ctr = 0;

    printf("Enter a string: ");
    scanf("%s", hexa);

    for (int i = 0; ((hexa[i] >= 'A' && hexa[i] <= 'F') || (hexa[i] >= '0' && hexa[i] <= '9')) && hexa[i] != '\0'; i++){
        ctr+=1;
    }

    printf("%d", ctr);
}