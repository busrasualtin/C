#include <stdio.h>


// Shape 1
// * * * * * * * * * *
// * * - - - - - - * *
// * - * - - - - * - *
// * - - * - - * - - *
// * - - - * * - - - *
// * - - - * * - - - *
// * - - * - - * - - *
// * - * - - - - * - *
// * * - - - - - - * *
// * * * * * * * * * *

/* Representing the shape as a matrix and taking advantage of each index (coordinate) to
   find a relation between the position of symbols to decide which symbol to print*/
void shape1(int limit) {
    for (int row = 0; row < limit; row++) {
        for (int column = 0; column < limit; column++) {
            if ((row == 0) || (row == (limit - 1)) || (column == 0) || (column == limit - 1) || (row == column) ||
                ((row + column) == (limit - 1))) {
                printf("* ");
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

//  Write a code that prints numbers in the given form
//  1 1  2  3  5  8  13
//  2 4  6  10 16 26 42
//  3 9  12 21 33 54 87
/*  In general, the outer loop is used for arranging the amount of lines in shape and
    all of the inner loops is used for arranging symbol sequence in that row.
    Sometimes you may have to relate the loop indexes with the symbols to print symbols properly.
*/
void shape2() {
    for (int row = 0; row < 3; row++) {
        int firstNumber = (row + 1);
        int secondNumber = firstNumber * firstNumber;
        printf("%.2d %.2d ", firstNumber, secondNumber);
        int thirdNumber = firstNumber + secondNumber;
        for (int count = 0; count < 5; count++) {
            printf("%.2d ", thirdNumber);
            firstNumber = secondNumber;
            secondNumber = thirdNumber;
            thirdNumber = firstNumber + secondNumber;
        }
        printf("\n");
    }
    printf("\n");
}

void shape2TooEasy(int array[], int size) {
    for (int index = 0; index < size; index++) {
        printf("%d ", array[index]);
        if ((index == 6) || (index == 13) || (index == 20)) {
            printf("\n");
        }
    }
    printf("\n");
}

void matrix(int limit) {
    for (int i = 0; i < limit; i++) {
        for (int j = 0; j < limit; j++) {
            printf("[%d,%d]", i, j);
        }
        printf("\n");
    }
    printf("\n");
}


void main() {
    int limit = 20;
    matrix(limit);
    shape1(limit);
    shape2();
    int numbers[] = {1, 1, 2, 3, 5, 8, 13, 2, 4, 6, 10, 16, 26, 42, 3, 9, 12, 21, 33, 54, 87};
    shape2TooEasy(numbers, sizeof(numbers) / sizeof(numbers[0]));
}

