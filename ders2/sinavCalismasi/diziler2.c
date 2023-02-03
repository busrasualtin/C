#include <stdio.h>

int main(void){
  int idizi[10];
  int id;

  // Dizinin elemanlarına 1-10 arasındaki değerleri sıra ile atama
  for (id=0; id<10; id++) {
       idizi[id] = id+1;
  }

  // Dizi değerlerini ekrana yazma
  for (id=0; id<10; id++) {
       printf("%d ", idizi[id]);
  }

  return 0;
}