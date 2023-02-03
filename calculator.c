#include <stdio.h>

void menu() {
    printf("Mini Calculator \n");
    printf("You can perform +,-,*,/,mod \n");
    printf("Enter 1 for + \n");
    printf("Enter 2 for - \n");
    printf("Enter 3 for * \n");
    printf("Enter 4 for / \n");
    printf("Enter 5 for mod \n");
    printf("Enter 6 to exit \n");
}


void calculate(int option) {
    int number1, number2, result;
    if (option == 1) {
        printf("Please enter numbers to calculate the summation \n");
        printf("Please enter the first integer number \n");
        scanf("%d", &number1);
        printf("Please enter the second integer number \n");
        scanf("%d", &number2);
        result = number1 + number2;
        printf("The result is %d \n", result);
    } else if (option == 2) {
        printf("Please enter numbers to calculate the extraction \n");
        printf("Please enter the first integer number \n");
        scanf("%d", &number1);
        printf("Please enter the second integer number \n");
        scanf("%d", &number2);
        result = number1 - number2;
        printf("The result is %d \n", result);
    } else if (option == 3) {
        printf("Please enter numbers to calculate the multiplication \n");
        printf("Please enter the first integer number \n");
        scanf("%d", &number1);
        printf("Please enter the second integer number \n");
        scanf("%d", &number2);
        result = number1 * number2;
        printf("The result is %d \n", result);
    } else if (option == 4) {
        printf("Please enter numbers to calculate the division \n");
        printf("Please enter the first integer number \n");
        scanf("%d", &number1);
        printf("Please enter the second integer number \n");
        scanf("%d", &number2);
        result = number1 / number2;
        printf("The result is %d \n", result);
    } else if (option == 5) {
        printf("Please enter numbers to calculate the mod \n");
        printf("Please enter the first integer number \n");
        scanf("%d", &number1);
        printf("Please enter the second integer number \n");
        scanf("%d", &number2);
        result = number1 % number2;
        printf("The result is %d \n", result);
    }
}

void main() {
    int limit = 1000000000;
    int option;
    for (int i = 0; i < limit; i = i + 1) {
        menu();
        scanf("%d", &option);
        if (option == 6) {
            i = limit + 1;
        } else if ((option >= 1) && (option <= 5)) {
            calculate(option);
        } else {
            printf("Please enter a valid option between 1-6 \n");
        }
    }
}

