#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  char *pdizi[5];
  int id;

  // Bellek tahsisi
  for (id=0; id<5; id++) {
       pdizi[id] = (char *) malloc(20 * sizeof(char));
  }

  // Dizi atama
  for (id=0; id<5; id++) {
       strcpy(pdizi[id], "Karakter dizisi");
  }
  // Yazdirma
  for (id=0; id<5; id++) {
       printf("%s\n", pdizi[id]);
  }

  // Bellek bosaltma
  for (id=0; id<5; id++) {
       free(pdizi[id]);
  }

  return 0;
}
