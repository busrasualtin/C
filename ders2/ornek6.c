#include <stdio.h>
#include <stdlib.h>

int ustel(int taban, int ust){
    if (ust == 0)
        return 1;
    return taban * ustel(taban, ust - 1);
}

int main(){
    int x, y;
    printf("Taban gir :");
    scanf("%d", &x);
    printf("Ust gir :");
    scanf("%d", &y);
    printf("Sonuc : %d", ustel(x, y));

}