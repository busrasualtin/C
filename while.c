#include <stdio.h>
#include <stdlib.h>

int main()
{ /*
	int a=4;
	while(a<50){
		printf("%d\n",a);
		a++; //bunu yazmazsak sonsuza kadar 4 basar.
	} */
	
	int elma=10;
	while(elma>0){
		printf("Cebimde %d tane elma var\n",elma);
		elma--; 
	}
	printf("Cebimde elma yok");
	return 0;
}
