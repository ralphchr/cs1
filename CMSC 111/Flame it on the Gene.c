/*INPUT:
The first line contains the number of test cases, say n. Then n test cases will follow. Each test is composed of three (3) lines. The first line will contain a number that tells us whether to do the FLAMES game or find "gene sequences", i.e. 1 for FLAMES and 2 for "gene sequences." For option 1, the next two lines contain the names of the persons to do the FLAMES game on. For option 2, the first line should be a longer string and the second line should a shorter string.

OUTPUT:
For option 1, simulate the game FLAMES (FRIENDS, LOVERS, ACCEPTANCE, MARRIAGE, ENGAGEMENT and SWEETHEARTS). Display the result for the first person, then the result of the second person, and finally, the overall result. The resulting count is based on the number of similar letters (letters cancelled out). For purposes of counting similar letters, the uppercase letter 'A' is the same as the lowercase 'a'. The spaces are not included in the counts. For instance, if the first name is Sam Milby and the second name is Piolo Pascual, 4 letters will be cancelled out from Sam Milby (s, a, i, l), and 6 letters from Piolo Pascual (i, 2 l's , 2 a's, s). The total score is 10. This should be interpreted as "Sam Milby wants to be MARRIED to Piolo Pascual. Piolo Pascual wants to be SWEETHEARTS with Sam Milby. They will end up as a MARRIED couple). To be consistent with the output:

... wants to be FRIENDS with ...
... wants to be LOVERS with ...
... wants to ACCEPT their fate with ...
... wants to be ENGAGED to ...
... wants to be MARRIED to ...
... wants to be SWEETHEARTS with ...
For the total:

They will end up as FRIENDS.
They will end up as LOVERS.
They will ACCEPT their fate, whatever it is.
They will end up as a MARRIED couple.
They will be ENGAGED.
They will end up as SWEETHEARTS.
For option 2, recall that the human genome (approximately 3 billion DNA base pairs) has 4 types of nitrogen-containing bases, namely Adenine, Guanine, Cytosine and Thymine. It usually looks like "AGCTCTAGAGCTCTCTAGAGAGCT" but longer of course. For this task, the goal is to check whether the shorter second string is found in the first longer string and if it is, how many times does it occur and at which indices they occur. Let's take "AGCTCTAGAGCTCTCTAGAGAGCT" for instance. And let's have "CT" as the second shorter string. The outputs based on these inputs are that yes, the shorter string exists in the longer string 6 times. And they occur in indices 2, 4, 10, 12, 14, and 22. If the shorter string does not occur in the longer string, then simply output NO.
*/

//Sources:
//https://youtu.be/0UJX96_ZpVE?si=OLeVkkYv-BB_7OF7
//https://www.w3schools.com/c/ref_stdio_getchar.php
//https://www.w3schools.com/c/ref_string_strcspn.php
//https://www.w3schools.com/c/ref_ctype_tolower.php

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
    int n, game;

    scanf("%d", &n);
    getchar();

    for (int i = 1; i <= n; i++){
        game = 0;
        scanf("%d", &game);
        getchar();

        if (game == 1){
            char name1[500], name2[500], lname1[500], lname2[500];
            int total, point1, point2;
            point1 = 0;
            point2 = 0;
            total = 0;

            fgets(name1, sizeof(name1), stdin);
            name1[strcspn(name1, "\n")] = '\0';
            fgets(name2, sizeof(name2), stdin);
            name2[strcspn(name2, "\n")] = '\0';


            for (int i = 0; name1[i] != '\0'; i++)
                lname1[i] = tolower(name1[i]);

            for (int i = 0; name2[i] != '\0'; i++)
                lname2[i] = tolower(name2[i]);

            for (int i = 0; lname1[i] != '\0'; i++){
                int check = 0;

                if (lname1[i] == ' ')
                    continue;

                for (int j = 0; lname2[j] != '\0'; j++){
                    if (lname1[i] == lname2[j]){
                        check+=1;
                        break;
                    }
                }

                if (check == 1)
                    point1+=1;
            }


            for (int i = 0; lname2[i] != '\0'; i++){
                int check = 0;

                if (lname2[i] == ' ')
                    continue;

                for (int j = 0; lname1[j] != '\0'; j++){
                    if (lname2[i] == lname1[j]){
                        check+=1;
                        break;
                    }
                }

                if (check == 1)
                    point2+=1;
            }

            total = point1 + point2;

            while (point1 > 6)
                point1-=6;

            while (point2 > 6)
                point2-=6;

            while (total > 6)
                total-=6;

            if (point1 == 1){
                printf("%s wants to be FRIENDS with %s.", name1, name2);
            } else if (point1 == 2){
                printf("%s wants to be LOVERS with %s.", name1, name2);
            } else if (point1 == 3){
                printf("%s wants ACCEPT their fate with %s.", name1, name2);
            } else if (point1 == 4){
                printf("%s wants to be MARRIED with %s.                               ", name1, name2);
            } else if (point1 == 5){
                printf("%s wants to be ENGAGED to %s.", name1, name2);
            } else if (point1 == 6){
                printf("%s wants to be SWEETHEARTS with %s.", name1, name2);
            }

            printf("\n");

            if (point2 == 1){
                printf("%s wants to be FRIENDS with %s. ", name2, name1);
            } else if (point2 == 2){
                printf("%s wants to be LOVERS with %s. ", name2, name1);
            } else if (point2 == 3){
                printf("%s wants ACCEPT their fate with %s. ", name2, name1);
            } else if (point2 == 4){
                printf("%s wants to be MARRIED to %s. ", name2, name1);
            } else if (point2 == 5){
                printf("%s wants to be ENGAGED to %s. ", name2, name1);
            } else if (point2 == 6){
                printf("%s wants to be SWEETHEARTS with %s.                           ", name2, name1);
            }

            printf("\n");

            if (total == 1){
                printf("They will end up as FRIENDS.");
            } else if (total == 2){
                printf("They will end up as LOVERS.");
            } else if (total == 3){
                printf("They will ACCEPT their fate, whatever it is.");
            } else if (total == 4){
                printf("They will end up as a MARRIED couple.");
            } else if (total == 5){
                printf("They will be ENGAGED.");
            } else if (total == 6){
                printf("They will end up as SWEETHEARTS.");
            }

            if (point1 == 0 && point2 == 0 && total == 0){
                printf("%s does not want to have anything to do with %s.", name1, name2);
                printf("%s does not want to have anything to do with %s.", name2, name1);
                printf("They are not a thing. They will never be.");
            }

            } else if (game == 2){
                char dna[500], subdna[255];
                int ctr = 0;
                fgets(dna, sizeof(dna), stdin);
                dna[strcspn(dna, "\n")] = '\0';
                fgets(subdna, sizeof(subdna), stdin);
                subdna[strcspn(subdna, "\n")] = '\0';

                int lendna = strlen(dna);
                int lensub = strlen(subdna);

                int found = 0;

                for (int i = 0; i <= lendna; i++){
                    int checker = 1;

                    for (int j = 0; j < lensub; j++){
                        if (dna[i + j] != subdna[j]){
                            checker = 0;
                            break;
                        }
                    }

                    if (checker == 1){
                        if (found == 0){
                            found = 1;
                            printf("YES\n");
                        }

                        ctr+=1;
                    }
                }

                if (found == 1)
                    printf("%d\n", ctr);

                for (int i = 0; i <= lendna; i++){
                    int checker = 1;

                    for (int j = 0; j < lensub; j++){
                        if (dna[i + j] != subdna[j]){
                            checker = 0;
                            break;
                        }
                    }

                    if (checker == 1)
                        printf("%d ", i);
                }

                if (found == 0)
                    printf("NO");

            }
        }
    }