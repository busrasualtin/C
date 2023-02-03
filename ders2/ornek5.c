#include <stdio.h>
int main()
{
    int sayi, toplam, k, ilksayi;
    printf("Sayiyi giriniz: ");
    scanf("%d", &sayi);
    toplam = 0;
    ilksayi = sayi;
    while (sayi > 0){
        k = sayi % 10;
        sayi = sayi / 10;
        toplam = toplam + k;
    }
    printf("%d sayisinin rakamlari toplami: %d", ilksayi, toplam);
}

/*
k = 2
sayi = 34
toplam = 2

k = 4
sayi = 3
toplam = 6

k = 3
sayi = 0
toplam = 9
*/