#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  char *cp;

  cp = (char*) malloc(40);

  if (!cp) {
      printf("Bellek tahsis hatasi");
      exit(1);
  }

  strcpy(cp, "Bilgisayar");
  printf("%s", cp);

  free(cp);

  return 0;
}
