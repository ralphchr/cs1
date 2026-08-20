/*Simulate the board game Tic-Tac-Toe. Please check the startup file for this MP. Run it.

First player uses 'x'. Second player uses 'o'.

Input:

It will contain multiple lines. Each line contains 2 positive integers each. Both are between 1 and 3, inclusive. It specifies the cell the player wants to use (row-column pair).

Games ends when there's a draw (after all 9 cells have been filled with with no winner). Game ends, as well, if there is a victor!

Display the tic-tac-toe board after each input pair.

Implement another function that checks whether there's a winner, or there's a draw, or game hasn't finished yet.

Output:

In your implementation of the diagonals, generate a random number from negative 1 billion to positive 1 billion. DO NOT PRINT IT.
If there's a winner, print "What a refreshing moment with Player <playerNumber> unleashing their creativity!"

If there's a draw, print "Freshest moment! Both players unleashing their creativity!"
*/

#include <stdio.h>

void display(char table[3][3]);
int winchecker(char arr[3][3]);

int main(){
    char arr[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};

    int win = 0, moves = 1, x, y;

    while (moves <= 9){
        scanf("%d %d", &x, &y);
        if (arr[x-1][y-1] == ' '){
            if (moves % 2 == 1)
                arr[x-1][y-1] = 'x';
            else
                arr[x-1][y-1] = 'o';
            moves++;
        }

        printf("%d %d\n", x,y);
        display(arr);

        win = winchecker(arr);
        if (win){
            if (moves % 2 == 0)
                printf("What a refreshing moment with Player 1 unleashing their creativity!");
            else
                printf("What a refreshing moment with Player 2 unleashing their creativity!");
            break;
        }
    }
    if (win == 0)
        printf("Freshest moment! Both players unleashing their creativity!");
    return 0;

}

int winchecker(char arr[3][3]){
    //horizontal check
    if (arr[0][0] == arr[0][1] && arr[0][0] == arr[0][2] && arr[0][0] != ' '){
        return 1;
    }

    if (arr[1][0] == arr[1][1] && arr[1][0] == arr[1][2] && arr[1][0] != ' '){
        return 1;
    }

     if (arr[2][0] == arr[2][1] && arr[2][0] == arr[2][2] && arr[2][0] != ' '){
        return 1;
    }

    //vertical checek
    if (arr[0][0] == arr[1][0] && arr[0][0] == arr[2][0] && arr[0][0] != ' '){
        return 1;
    }

    if (arr[0][1] == arr[1][1] && arr[0][1] == arr[2][1] && arr[0][1] != ' '){
        return 1;
    }

    if (arr[0][2] == arr[1][2] && arr[0][2] == arr[2][2] && arr[0][2] != ' '){
        return 1;
    }

    //left to right diagonal
    if (arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2] && arr[0][0] != ' '){
        return 1;
    }

    //right to left diagonal
    if (arr[2][0] == arr[1][1] && arr[2][0] == arr[0][2] && arr[2][0] != ' '){
        return 1;
    }

    return 0;
}

void display(char table[3][3]){
    //201 203 187 188 185 204 205 206 186
    printf("\u2554\u2550\u2550\u2550\u2566\u2550\u2550\u2550\u2566\u2550\u2550\u2550\u2557\n");
    printf("\u2551 %c \u2551 %c \u2551 %c \u2551\n",table[0][0],table[0][1],table[0][2]);
    printf("\u2560\u2550\u2550\u2550\u256C\u2550\u2550\u2550\u256C\u2550\u2550\u2550\u2563\n");
    printf("\u2551 %c \u2551 %c \u2551 %c \u2551\n",table[1][0],table[1][1],table[1][2]);
    printf("\u2560\u2550\u2550\u2550\u256C\u2550\u2550\u2550\u256C\u2550\u2550\u2550\u2563\n");
    printf("\u2551 %c \u2551 %c \u2551 %c \u2551\n",table[2][0],table[2][1],table[2][2]);
    printf("\u255A\u2550\u2550\u2550\u2569\u2550\u2550\u2550\u2569\u2550\u2550\u2550\u255D\n");
}