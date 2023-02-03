#include <stdio.h>

int main(void)
{
  int *ip1, *ip2, id1, id2;

  ip1 = &id1; // id1 değişkeninin adresini ip1 işaretçisine atama
  ip2 = &id2; // id2 değişkeninin adresini ip2 işaretçisine atama
  id1 = 42;   // id1 değişkenine değer atama
  *ip2 = 67;  // id2 değişkenine ip2 işaretçisi yoluyla değer atama

  printf("id1 değişkeninin değeri: %d\n", *ip1);
  printf("id2 değişkeninin değeri: %d\n", *ip2);
  printf("id1 değişkeninin bellek adresi: %p\n", ip1);
  printf("id2 değişkeninin bellek adresi: %p", ip2);

  printf("\n\n");

  printf("ip1 işaretçisinin bellek adresi: %p\n", &ip1);
  printf("ip2 işaretçisinin bellek adresi: %p", &ip2);

  return 0;
}