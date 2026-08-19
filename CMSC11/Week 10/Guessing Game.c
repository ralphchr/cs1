/*
Generate a random number from 1-100. Ask the user to guess this number. Give him/her 5 tries. If in the 5th try he/she isn't able to guess the number, reveal the magic number. If he/she is able to guess the number within the allotted tries, congratulate the user. Use the "HIGHER/LOWER" scheme to give clues to the user.

Below is a video primer for Guessing Game.

Here.

Implement the game as it should be. But for your submission (and for purposes of auto-checking), do not generate the magic number, read it as input.

OUTPUT:

Print HIGHER when the guess is smaller than the magic/hidden number. Print LOWER when the guess bigger than the magic/hidden number. But if the user still fails to guess the number correctly on the 5th try, reveal the magic/hidden number by saying "SORRY. THE MAGIC NUMBER IS <magic number>." Then the game ends. If the user is able to guess the number correctly within the allotted tries, congratulate the user by saying "CONGRATULATIONS! YOU GUESSED IT!" and the game ends. The use of break will be helpful.
*/

#include <stdio.h>

int main(){

    int rnum, guess = 0, check = 1;


    scanf("%d", &rnum);

    for (int i = 1; i<=5; i++){
        scanf("%d", &guess);

        if (i != 5){
            if (rnum == guess){
                printf("CONGRATULATIONS! YOU GUESSED IT!");
                check = 1;
                break;
            } else if (rnum < guess){
                printf("LOWER\n");
                check = 0;
                continue;
            } else if (rnum > guess){
                printf("HIGHER\n");
                check = 0;
                continue;
            }
        } else {
            if (rnum == guess){
                printf("CONGRATULATIONS! YOU GUESSED IT!");
                check = 1;
                break;
            } else {
                check = 0;
                break;
            }
        }
    }

    if (check == 0)
        printf("SORRY. THE MAGIC NUMBER IS %d.", rnum);

}