#include <stdio.h>

typedef int tms;
typedef tms tams;

int main(void)
{
  int id1;

  tms id2;
  tams id3;

  id2 = 4;
  id3 = 11;

  for (id1=0; id1<5; id1++, id2++, id3++) printf("%d ", id2+id3);

  return 0;
}
