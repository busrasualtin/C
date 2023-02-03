#include <stdio.h>

void iterativeIncreasingForLoop(int number) {
    printf("Iterative-Increasing-ForLoop\n");
    for (int i = 0; i <= number; i++) {
        printf("%d\n", i);
    }
    printf("\n");
}

void iterativeIncreasingWhileLoop(int number) {
    printf("Iterative-Increasing-WhileLoop\n");
    int counter = 0;
    while (counter <= number) {
        printf("%d\n", counter);
        counter++;
    }
    printf("\n");
}

void recursiveDecreasing(int number) {
    printf("%d\n", number);
    if (number != 0) {
        recursiveDecreasing(number - 1);
    }
}

void recursiveIncreasing(int startNumber, int finishNumber) {
    printf("%d\n", startNumber);
    if (startNumber != finishNumber) {
        recursiveIncreasing(startNumber + 1, finishNumber);
    }
}




void main() {
    int number = 5;
    iterativeIncreasingForLoop(number);
    iterativeIncreasingWhileLoop(number);
    printf("Recursive-Decreasing\n");
    recursiveDecreasing(number);
    printf("\n");
    printf("Recursive-Increasing\n");
    recursiveIncreasing(0, number);
    printf("\n");
}

