/*INPUT:
The first line of input is a positive number t. This number represents the number of test cases. Then t test cases will follow. Each test case has 3 sets of input. 2 positive integers specifying the size of the test matrix. Then the matrix will follow. The matrix represents an image in black (1 - foreground pixel) and white (0 - background pixel).

OUTPUT:
If there are t test cases, there should be t lines of output as well. Print the total number of objects found in the image. An object is found when foreground pixels are 8-connected with each other. Below images demonstrate connectivity. The left shows 4-connectivity and 8-connectivity on the right.



To solve this, we will do recursive component labeling. Implement these two:

int countObjects(int[100][100], int, int); //the 2 integers are the row size and column size
void labeling(int[100][100], int, int, int, int, int); //the first 2 integers are the row size and column size, the second 2 are the row-column combo identifying the pixel of interest, and the last int is the current label
What labeling does is it labels every foreground pixel it sees. If the foreground pixels are all 8-connected, they should have the same label. What we can do is begin labeling the pixels with a label = 2. This means that the first foreground pixel encountered will be labeled 2, and all the foreground pixels connected to it (8-connectedness, that means the 3 pixels above it, the one to its left, the other one to its right, and the 3 pixels below it). This is where you can do the recursion. Recursively label the 8 neighboring pixels.

At some point, the recursive labeling is going to stop. This means that one object has been found. The first object found should now be labeled 2 (all the connect pixels). This means the label should be incremented by 1. label should now be 3. Take a look at the image below:

0 0 0 0 0
0 1 1 1 0
1 1 1 0 0
0 0 0 0 1
1 1 1 1 1
After the first round of labeling, the image looks like so:

0 0 0 0 0
0 2 2 2 0
2 2 2 0 0
0 0 0 0 1
1 1 1 1 1
The next time it sees a foreground pixel, the image now looks like so:

0 0 0 0 0
0 2 2 2 0
2 2 2 0 0
0 0 0 0 3
3 3 3 3 3
countObjects exhausts all the pixels of the image. This means, labeling should be called in countObjects.
*/


#include <stdio.h>

int countObjects(int[100][100], int, int);
void labeling(int[100][100], int, int, int, int, int);

int main(){
    int testcases, columns, rows, x, y;
    scanf("%d",  &testcases);

    for (int test = 1; test <= testcases; test++){
        scanf("%d %d", &rows, &columns);

        int matrix[100][100];

        for (int i = 0; i < rows; i++){
            for (int j = 0; j < columns; j++){
                scanf("%d", &matrix[i][j]);
            }
        }

        printf("%d Objects found", countObjects(matrix, rows, columns));
        printf("\n");
    }

    return 0;
}

void labeling(int matrix[100][100], int rows, int columns, int x, int y, int label){
    if (x - 1< -1 || y - 1 < -1 || x > rows || y > columns || matrix[x][y] != 1)
        return;

    matrix[x][y] = label;

    int topx = x - 1, botx = x + 1;
    int topy = y - 1, boty = y - 1;
    for (int i = 0; i < 3; i++){
        labeling(matrix, rows, columns, topx, topy, label);
        topy++;
    }
    y -= 1;
    for (int i = 0; i < 3; i++){
        labeling(matrix, rows, columns, x, y, label);
        y++;
    }

    for (int i = 0; i < 3; i++){
        labeling(matrix, rows, columns, botx, boty, label);
        boty++;
    }

}

int countObjects(int matrix[100][100], int rows, int columns){
    int label = 2, count = 0;

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            if (matrix[i][j] == 1){
                labeling(matrix, rows, columns, i, j, label);
                label+=1;
                count+=1;

            }
        }
    }

    return count;
}