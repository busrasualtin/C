#include <stdio.h>

#define LENGTH 10   
#define WIDTH  5
#define NEWLINE '\n'
#define TAB '\t'

int main() {
   int area;  
  
   area = LENGTH * WIDTH;
   printf("value of area:%c%d", TAB, area);
   printf("%c", NEWLINE);

   return 0;
}