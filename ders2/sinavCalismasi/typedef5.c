#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  char cdizi1[20];
  char cdizi2[20];
  int id;
} yap;

int main(void)
{
  yap *yp;

  yp = (yap*) malloc (sizeof(yap));

  strcpy(yp->cdizi1, "Bilgisayar");
  strcpy(yp->cdizi2, "Programlama");
  yp->id = 21;  

  printf("%s %s %d", yp->cdizi1, yp->cdizi2, yp->id);
  
  free(yp);
  
  return 0;
}