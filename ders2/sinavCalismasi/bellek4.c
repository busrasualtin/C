#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int *ip, id;

  ip = (int *) calloc(5, sizeof(int));

  for (id=0; id<5; id++) {
       *(ip+id) = (id+1) * 10;
       printf("%p adresindeki deger: %d\n", (ip+id), *(ip+id));
  }

  free(ip);

  return 0;
}
