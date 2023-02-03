#include <stdio.h>

int main(void){
  int *ip;
  int idizi[5] = { 15, 72, 154, 298, 345 };

  printf("İşaretçi bellek adresi: %p\n\n", &ip);

  ip = &idizi[4];

  printf("İşaretçinin içerdiği adres: %p\n", ip);
  printf("İşaretçinin gösterdiği değişken değeri: %d\n\n", *ip);

  ip-=3; // ip -= (4 * sizeof (int));

  printf("İşaretçinin içerdiği adres: %p\n", ip);
  printf("İşaretçinin gösterdiği değişken değeri: %d\n\n", *ip);

  return 0;
}