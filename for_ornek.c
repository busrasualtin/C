#include <stdio.h>
#include <stdlib.h>

int main()
{
	// 1den 5e kadar olan sayýlarýn çarpýmý
	int i,j,carpim=1;
	printf("1den kaca kadar olan sayilarin carpimini hesaplamak istiyorsunuz\n");
	scanf("%d",&j);
	
	for(i=1;i<=j;i++){
		carpim=carpim*i;
	}
	 printf("1 den %d ye kadar olan sayilarin carpimi %d",j,carpim);
	return 0;
}
