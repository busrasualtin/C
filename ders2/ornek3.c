#include <stdio.h>

int main(){ 
    int n,i,toplam;
    
    printf (" Bir sayi giriniz : " );
    scanf("%d", &n);
     
    toplam=0;

    for  (i=1; i<=n; i++ )
        toplam = toplam + i*i;

    printf (" Girilen sayinin  karelerinin toplami : %d", toplam );

}