#include <stdio.h>

// a++ -> a = a+1 , a+75 -> a = a +75 ...
// a-- -> a = a-1 , a-75 -> a = a -75 ...
void matrix(int limit) {
    for (int i = 0; i < limit; i++) {
        for (int j = 0; j < limit; j++) {
            printf("[%d%d]", i, j);
        }
        printf("\n");
    }
    printf("\n");
}


// * - - - - - - - - -
// * * - - - - - - - -
// * - * - - - - - - -
// * - - * - - - - - -
// * - - - * - - - - -
// * - - - - * - - - -
// * - - - - - * - - -
// * - - - - - - * - -
// * - - - - - - - * -
// * * * * * * * * * *
void shape1() {
    int limit = 10;
    for (int row = 0; row < limit; row++) {
        for (int column = 0; column < limit; column++) {
            if ((column == 0) || (row == (limit - 1)) || (row == column)) {
                printf("* ");
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
    printf("\n");
}


// * - - - - - - - - -
// * * - - - - - - - -
// * - * - - - - - - -
// * - - * - - - - - -
// * - - - * - - - - -
// * - - - - * - - - -
// * - - - - - * - - -
// * - - - - - - * - -
// * - - - - - - - * -
// * * * * * * * * * *
// * - - - - - - - * -
// * - - - - - - * - -
// * - - - - - * - - -
// * - - - - * - - - -
// * - - - * - - - - -
// * - - * - - - - - -
// * - * - - - - - - -
// * * - - - - - - - -
// * - - - - - - - - -
void shape2() {
    int column_limit = 10; // the number of characters in row
    int row_limit = column_limit * 2; //the number of rows (lines)
    for (int row = 0; row < row_limit; row++) {
        for (int column = 0; column < column_limit; column++) {
            if ((column == 0) || (row == (column_limit - 1)) || (row == column) ||
                ((row + column) == (row_limit - 2))) {
                printf("* ");
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
    printf("\n");
}


int power(int base, int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result = result * base;
    }
    return result;
}


//							   1
//                         1   2   1
//                     1   2   4   2   1
//                 1   2   4   8   4   2   1
//             1   2   4   8  16   8   4   2   1
//         1   2   4   8  16  32  16   8   4   2   1
//     1   2   4   8  16  32  64  32  16   8   4   2   1
// 1   2   4   8  16  32  64 128  64  32  16   8   4   2   1
void shape3() {
    //%xd -> x is the aligning option for character count to print numbers to the screen
    int row_limit = 8;
    for (int row = 0; row < row_limit; row++) {
        //Print gap
        for (int gap = 0; gap < (row_limit - row - 1); gap++) {
            printf("    ");
        }
        //Print increasing number
        for (int increasing = 0; increasing < row; increasing++) {
            printf("%4d", power(2, increasing));
        }
        //Print middle number
        printf("%4d", power(2, row));
        //Print decreasing number
        for (int decreasing = row - 1; decreasing >= 0; decreasing--) {
            printf("%4d", power(2, decreasing));
        }
        //New line
        printf("\n");
    }
    printf("\n");
}


//  Write a code that prints numbers in the given form
//  1 1  1  1  1
//  4 7  13 25 49
//  9 17 33 65 129

void shape4() {
    int row_limit = 3;
    int column_limit = 5;
    for (int row = 0; row < row_limit; row++) {
        //First number
        int first_number = power(row + 1, 2);
        printf("%4d", first_number);
        //Other numbers
        int number = first_number;
        for (int column = 0; column < column_limit - 1; column++) {
            number = number * 2 - 1;
            printf("%4d", number);
        }
        //New line
        printf("\n");
    }
    printf("\n");
}

// a++ -> a = a+1 , a+75 -> a = a +75 ...
// a-- -> a = a-1 , a-75 -> a = a -75 ...
void main() {
    shape1();
    shape2();
    shape3();
    shape4();
    matrix(5);
}
