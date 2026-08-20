/*Given an array A with size n, determine whether there is an element in A[i] equal to the index i. In this problem, it is assumed that the elements of A are sorted in increasing order.

Produce two solutions, the first one linear and the other sub-linear. This means two solutions that is one after another in the same main function. You are not allowed to use global variables. You are to print the number of comparisons made (how many times A[i]==i was executed) and whether it's a yes or no, i.e. whether there is an A[i] equal to i.

The first input is a number t. This number is the number of test cases to be solved. t test cases will follow.

For each test case, a number n should be read. This represents the size of A. This is the range of n: 5<=n<=20 (declare an array with capacity size 20). Then n integers will follow.

Output:

For each test case, there should be 2 lines of output. The first line is for the linear solution and the second is for the sub-linear solution. For each line, print YES, if there is an A[i] equal to i, followed by the number of comparisons made. If there is no such A[i] equal to i, print NO, followed by the number of comparisons made. There should be 2t lines of output for the t test cases.
*/

#include <stdio.h>

int main(){
    int tests;

    scanf("%d", &tests);

    for (int test = 1; test <= tests; test++){

        int size;

        scanf("%d", &size);

        int nums[1]; //change 1 to size, just an error in my vsc for some reason
        int linctr = 0, binctr = 0;

        for (int i = 0; i < size; i++){
            scanf("%d", &nums[i]);
        }

        int linvalid = 0;
        for (int i = 0; i < size; i++){
            linctr += 1;

            if (nums[i] > i){
                break;
            }

            if (nums[i] == i){
                linvalid = 1;
                printf("YES %d\n", linctr);
                break;
            }
        }

        if (linvalid == 0){
            printf("NO %d\n", linctr);
        }

        int l = 0, r = size - 1, median = size / 2;

        while (l <= r){
            int binvalid = 0;
            median = (l + r) / 2;
            binctr += 1;

            if (nums[median] == median){
                binvalid = 1;
                printf("YES %d\n", binctr);
                break;
            } else if (nums[median] > median){
                r = median - 1;
            } else {
                l = median + 1;
            }
        }

        if (l > r){
            printf("NO %d\n", binctr);
        }
    }
}