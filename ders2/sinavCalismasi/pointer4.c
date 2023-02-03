#include <stdio.h>

int main(void)
{
  char cdizi[] = { 'A', 'B', 'C', 'D', 'E', 'F' };
  char *cp;
  int len, id;

  cp = cdizi; // cp = &cdizi[0];

  len = sizeof(cdizi) / sizeof(char);

  for (id=0; id<len; id++){
    printf("%c ", *cp++);
    printf("%p\n", cp);
  } 
  
  return 0;
}