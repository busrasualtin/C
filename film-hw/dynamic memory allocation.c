#include <stdio.h>
int main()
{
	
	int *k;
	k=(int*)malloc(sizeof(int)*30);
	
	k[0]=10;
	k[1]=23;
	k[29]=23;
	printf("%d, %d\n", *(k+0),*(k+1));
	
	*(k+0)=432;
	*(k+1)=432;
	*(k+29)=432;
	printf("%d, %d",k[0],k[1]);
	free(k);
}
