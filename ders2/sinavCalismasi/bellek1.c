#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int *ip;

  // int veri turu boyutu kadar kadar bellek tahsisi
  ip = (int*) malloc(sizeof(int));
  *ip = 126;

  printf("Tahsis edilen bellek adres baslangici: %p\n", ip);
  printf("Tahsis edilen bellekteki degisken degeri: %d", *ip);

  free(ip);

  return 0;
}
