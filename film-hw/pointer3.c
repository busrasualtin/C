#include <stdio.h>

int main()
{
	int a;
	double b;
	unsigned int k[10];
	char t[3];
	
	printf("%p , %d\n\n",&a,a);
	printf("%p , %d\n\n",&b,b);
	
	printf("%p,%p,%p,%u\n\n",k,&k,&k[0],k[0]);
	printf("%p,%p,%p,%u\n\n",k+1,&k+1,&k[1],k[1]);
	printf("%p,%p,%p,%c\n\n",t,&t,&t[0],t[0]);
	printf("%p,%p,%p,%c\n\n",t+1,&t+1,&t[1],t[1]);
	
}

