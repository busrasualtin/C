#include <stdio.h>

int main(){
  int i,n,sonuc ;
   
   printf("Bir sayi giriniz :");
   
   scanf("%d", &n);
   
   sonuc=0;

   for (i=1; i<=n; i++ )
   sonuc = sonuc + i;
   
   printf("istediginiz toplam: %d ", sonuc  );  

}   