#include <stdio.h>
int main(){
    
    int x = 15;
    (x>10) ? printf("X 10'dan buyuk") : printf("X 10'dan kucuk");

    int y = (x<10) ? 30 : 50;

    printf("%d", y);

    return 0;
}