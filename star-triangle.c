#include <stdio.h>

// Prints indices for a nested loop
void indices(int limit) {
	// i stands for row number since it is the outer loop
	// j stands for row number since it is the inner loop
    int i;
    int j;
    for (i=0; i < limit; i=i+1) {
        for (j = 0; j < limit; j=j+1) {
            printf("[%d,%d] ", i, j);
        }
        printf("\n\n");
    }
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
void shape(int limit) {
    //i==j -> Diagonal
    //i==limit -> Horizontal
    //j==0 -> Vertical
    // We bind logical statemens with and &&  or ||
    for (int i = 0; i < limit; i=i+1) {
        for (int j = 0; j < limit; j=j+1) {
            if(i == j || i == limit-1 || j == 0) {
                printf("* ");
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
}

// Calculates the square root of an integer N
// If N is a perfect square,
// 		then returns the square root
// If N is not a perfect square,
// 		then returns the closest integer to the exact
// 		square root, as an approximation
// 16 -> 4 | 15 -> 4
int squareRootInt(int N) {
    int i;
    
// This commented part is a longer way of lines 62-63
//    for (i = 0; i < N; i=i+1) {
//        if (i*i == N) {
//            break;
//        }
//    }
//    return i;

    for (i = 0; i*i < N; i=i+1);
    return i;
}

// Calculates the square root of a double N
// If N is a perfect square,
// 		then returns the square root
// If N is not a perfect square,
// 		then returns a close double to the exact square
// 		root as an approximation
// More precise than the squareRootInt
//      since double values are also considered
double squareRootDouble(double N) {
    double i;

    for (i = 0; i*i < N; i=i+10e-3);
    return i;
}

// Calculates pow-th power of base
// If base = 2, pow = 5,
// 		then returns 2^5 = 32
int ourpow(int base, int pow) {
    int tempRoot = 1;
    for (int j = 0; j < pow; j=j+1) {
        tempRoot = tempRoot * base;
    }
    return tempRoot;
}

// Calculates n-th root of an integer N
// If N = 81 = 3*3*3*3, n = 4
// 		then returns 4
int nRootInt(int N, int n) {
    int i;
    for (i = 0; i < N; i=i+1) {

        if (ourpow(i, n) == N) {
            break;
        }
    }
    return i;
}

int main() {
    indices(3);
    
    shape(10);
    
    int res1 = squareRootInt(16);
    printf("Square root of %d = %d\n", 16, res1);
    res1 = squareRootInt(15);
    printf("Square root of %d = %d\n", 15, res1);
    
    double res2 = squareRootDouble(17);
    printf("Square root of %d = %f\n", 17, res2);
    
    int res3 = ourpow(3, 3);
    printf("3^3 = %d\n", res3);
    
    int res4 = nRootInt(8, 3);
    printf("3rd root of 8 = %d\n", res4);
    
    return 0;
}
