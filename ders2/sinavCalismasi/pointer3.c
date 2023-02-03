#include <stdio.h>

int main()
{
  
  char *cp, cd;

  cp = &cd;

  for (cd='A'; cd<'L'; cd++) printf("%c ", *cp);

  return 0;

}