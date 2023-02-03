#include <stdio.h>

void coffee_menu() {
    printf("Coffee Shop\n");
    printf("Please select an option \n");
    printf("1 - Add Sugar \n");
    printf("2 - Add Milk \n");
    printf("3 - Add Caffeine \n");
    printf("4 - Complete Order\n");
}

void size_menu() {
    printf("Please select a size\n");
    printf("1 - Small \n");
    printf("2 - Medium \n");
    printf("3 - Large \n");
}

int add_material(int price, int option) {
    if (option == 1) {
        price = price + 1;
    } else if (option == 2) {
        price = price + 2;
    } else if (option == 3) {
        price = price + 3;
    }
    return price;
}

int final_price(int price, int size) {
    if (size == 2) {
        price = price * 2;
    } else if (size == 3) {
        price = price * 3;
    }
    return price;
}


void main() {
    int limit = 1000000000;
    int option, size_option;
    int price = 0;
    for (int i = 0; i < limit; i = i + 1)
	{
        coffee_menu();
        scanf("%d", &option);
        if (option == 4) {
            size_menu();
            scanf("%d", &size_option);
            price = final_price(price, size_option);
            i = limit + 1;
        } else if ((option >= 1) && (option <= 3)) {
            price = add_material(price, option);
        }
    }
    printf("The total price for coffee : %d TL\n", price);
}



