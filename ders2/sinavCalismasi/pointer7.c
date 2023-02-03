#include <stdio.h>

int main(void){
  int *ip, id;

  id = 274;

  ip = &id;

  printf("id değişken değeri: %d\n", id);

  // ip işaretçisinin adresini gösterdiği değişken değerini artırma
  (*ip)++;

  printf("id değişken değeri: %d", id);

  return 0;
}
