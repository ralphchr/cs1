/*Make a program that asks for 2 input strings. The strings should have a maximum of 500 characters. You are to check whether the second string is a prefix of the first string or not. If the second string is indeed a prefix of the first string, say it so. If it is not, print the index in the second string that made it not a prefix (i.e. the index where the mismatch is found). Check some samples below.

Samples:

string 1: mastery string 2: master
master is a prefix of mastery.

string 1: mastery string 2: mastery
mastery is a prefix of mastery.

string 1: master string 2: mastery
mastery is not a prefix of master because of index 6.

string 1: excellence string 2: exert
exert is not a prefix of excellence because of index 2.
*/

#include <stdio.h>

int main(){
    char st1[500];
    char st2[500];

    scanf("%s", st1);

    scanf("%s", st2);

    int ctr = 0, check = 1;
    for (int i = 0; st2[i] != '\0';i++){
        ctr+=1;
        if (st2[i] != st1[i]){
            ctr = i;
            check = 0;
            printf("%s is not a prefix of %s because of index %d.", st2, st1, ctr);
            break;
        }
    }

    if (check == 1)
        printf("%s is a prefix of %s.", st2, st1);


}