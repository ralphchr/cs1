/*In general, a Sophie Germain Prime is defined as a prime “p” such that (2 * p) + 1 is also a prime. Here are some of them: 2,3,5,11,23,29,41
.

Input: A positive integer x. 2≤x≤2147483647
.

Output: Determine if x is a Sophie (print Sophie) or not (print Nophie).

Print the count of iterations incurred in determining whether the input is Sophie or Nophie (the count for determining if x is prime plus the count in determining if 2*x + 1 is prime as well). There should be 3 counts, each representing the count for the 3 versions of primality check we did.

Recall the 3 versions of primality check. They are shown below.

The check that goes all the way to n−1
.

for(int cf = 2; cf < n; cf++){
    if(n%cf == 0){
        prime = 0;
        break;
    }
}
The check that goes all the way to just n/2
.

for(int cf = 2; cf <= n/2; cf++){
    if(n%cf == 0){
        prime = 0;
        break;
    }
}
And finally, the check that goes all the way to just the n−−√
.

for(int cf = 2; cf*cf <= n; cf++){
    if(n%cf == 0){
        prime = 0;
        break;
    }
}
The versions above do not initially eliminate the numbers and even factors. Redo the solutions above that eliminates the checks on the even numbers and the even candidate factors as well.

This will ensure that in check whether, say 49
, is prime or not, we no longer check if it is divisible by 2,4,6,8,10,
 etc. We instead check if it is divisible by 3,5,7,9,11,
 etc. This should reduce the primality check by approximately half the time.

Let's consider 11
. For the naive version of primality check, the count of the iterations is 4
, since the loop will iterate for checking if it is divisible by 3,5,7,and 9
. We then check if 2∗11+1=23
 is prime as well. This will result in the loop iterating for candidate factors 3,5,7,9,11,13,15,17,19,and 21
. That's 10
 iterations. So in total, the count of iterations for checking if 11
 is a Sophie Germain Prime or not is 14
.

SAMPLE INPUTS AND OUTPUTS:

input = 11
output = Sophie 14 5 2
input = 13
output = Nophie 6 3 2
input = 2147483646
output = Nophie 0 0 0
RESTRICTIONS:

NO USE OF sqrt function
NO USE OF SIEVE OF ERATOSTHENES
NO USE OF STRUCTURES
NO USE OF GLOBAL VARIABLES
NO USE OF POINTERS
IMPLEMENT THE PRIMALITY CHECK FUNCTIONS ONLY, since you will need to call them twice (once to check if the number is prime, and then if 2*n + 1 is prime as well). This means though that the primality checks will simply not return true or false, but information of the count as well. That means we should be able to determine whether the numbers are prime or not based solely on the count that is returned.
*/

#include <stdio.h>

int isPrimeN(int);
int isPrimehN(int);
int isPrimeSqrtN(int);

int main(){
    int n, total = 0;

    scanf("%d", &n);

    if (isPrimeN(n) >= 0 && isPrimehN(n) >= 0 && isPrimeSqrtN(n) >= 0){
        long long int germain = (2*n) + 1;
        if (isPrimeN(germain) >= 0 && isPrimehN(germain) >= 0 && isPrimeSqrtN(germain) >= 0)
            printf("Sophie %d %d %d", isPrimeN(n)+isPrimeN(germain),isPrimehN(n)+isPrimehN(germain),isPrimeSqrtN(n)+isPrimeSqrtN(germain));
        else
            printf("Nophie %d %d %d", isPrimeN(n)+(-isPrimeN(germain)),isPrimehN(n)+(-isPrimehN(germain)),isPrimeSqrtN(n)+(-isPrimeSqrtN(germain)));
    } else{
        printf("Nophie 0 0 0");
    }


}

int isPrimeN(int n){
    int prime = 1, ctr = 0;
    if (n <= 1 || n % 2 == 0 && n != 2)
        return -1;
    if (n == 2)
        return 0;
    for(int cf = 3; cf < n; cf+=2){
        ctr++;
        if(n % cf == 0){
            prime = -1;
            break;
        }
    }

    return ctr*prime;

}
int isPrimehN(int n){
    int prime = 1, ctr = 0;

    if (n <= 1)
        return -1;
    if (n == 2 || n % 2 == 0)
        return 0;
    for(int cf = 3; cf < n/2; cf+=2){
        ctr++;
        if(n % cf == 0){
            prime = -1;
            break;
        }

    }

    return ctr*prime;
}
int isPrimeSqrtN(int n){
    int prime = 1, ctr = 0;
    if (n <= 1 || n % 2 == 0 && n != 2)
        return -1;
    if (n == 2)
        return 0;
    for(int cf = 3; cf*cf <= n; cf+=2){
        ctr++;
        if(n % cf == 0){
            prime = -1;
            break;
        }
    }

    return ctr*prime;
} //this solution wasnt able to get the perfect score :(