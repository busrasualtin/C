#include <stdio.h>

int main(void)
{
  char cdizi[40];

  printf("Bir karakter dizisi giriniz:\n");
  fgets(cdizi, 40, stdin); // En fazla 39 adet karakter okur.

  printf(cdizi);

  return 0;
}