#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  char *cp1 = "ilk karakter dizisi";
  char *cp2, *cp3;
  char cdizi[30];

  cp2 = "ikinci karakter dizisi";

  cp3 = (char*) malloc(50);
  strcpy(cp3, "ucuncu karakter dizisi"); // malloc() ve free() fonksiyonlari kullanilmadiginda hata verir.
  strcpy (cdizi, "Dorduncu karakter dizisi");

  printf("%s\n%s\n%s\n%s", cp1, cp2, cp3, cdizi);

  free(cp3);

  return 0;
}

