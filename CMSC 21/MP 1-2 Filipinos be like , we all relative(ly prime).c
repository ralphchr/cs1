/*This MP still has to do with running time, similar to the Sophie's world MP.

The inputs to this MP are two positive integers. All we need to do is to determine if the integers are relatively prime. Two integers are relatively prime if their greatest common factor is 1. 11 and 23 are relatively prime. 37 and 43 are relatively prime. The numbers themselves do not have to be prime to be relatively prime. Take 49 and 25, neither are prime but they are relatively prime since their greatest common factor is 1.

We are going to provide 2 solutions to this problem. One that runs in linear time and another that takes sub-linear time (meaning faster than the linear time solution). This means that apart from the main, make two other functions.

As with Sophie's World, we are going to display the number of iterations it took for the solutions to finally say if the numbers are relatively prime or not. No printing in the functions as well. Getting inputs and displaying outputs should be done in the main function.

For the sub-linear solution, we are going to use the Euclidean Algorithm. It computes for the greatest common factor between numbers. Take 49 and 25. Instead of looking for the a common factor between them beginning at some candidate factor, it continuously takes the remainder when one is divided by the other. Below is a simulation.

49 % 25 = 24
25 % 24 = 1
24 % 1 = 0
Another sample (55 and 121):

55 % 121 = 55
121 % 55 = 11
55 % 11 = 0
Another sample (13 18):

13 % 21 = 13
21 % 13 = 8
13 % 8 = 5
8 % 5 = 3
5 % 3 = 2
2 % 1 = 0

The algorithm ends when the remainder is 0. The GCF should be evident in the simulation.
*/

#include <stdio.h>

int naive(int, int);
int euclid(int, int);

int main(){
    int num1, num2, ans1, ans2;
    scanf("%d %d", &num1, &num2);

    ans1 = naive(num1, num2);
    ans2 = euclid(num1, num2);

    if (ans1 > 0)
        printf("Yes %d", ans1);
    else{
        ans1 = -ans1;
        printf("No %d", ans1);
    }

    printf("\n");

    if (ans2 >= 0)
        printf("Yes %d", ans2);
    else{
        ans2 = -ans2;
        printf("No %d", ans2);
    }

}

int naive(int n1, int n2){
    int min = 0, max = 0, sign = 1, ctr = 0;
    if (n1 > n2){
        max = n1;
        min = n2;
    }
    if (n1 < n2){
        max = n2;
        min = n1;
    }

    for (int i = 2; i <= min; i++){
        ctr++;
        if (max % i == 0 && min % i == 0){
            sign = -1;
            break;
        }

    }

    return ctr*sign;
}

int euclid(int n1, int n2){
    int temp = n1;

    if (n2 > n1){
        n1 = n2;
        n2 = temp;
    }

    int remainder = n1 % n2, ctr = 1, sign = 1;

    if (remainder == 0)
        return -1;
    else{
        while (remainder > 0){
            n1 = n2;
            n2 = remainder;
            remainder = n1 % n2;
            ctr++;
        }

        if (remainder == 0 && n2 == 1)
            return ctr*sign;
        else{
            sign = -1;
            return ctr*sign;
        }
    }
}