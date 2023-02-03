#include <stdio.h>
#include <stdlib.h>

int main()
{
	//Write a C program to find maximum between three numbers using ladder if else or nested if.
	int a,b,c,max;
	
	printf("Give me three numbers which are a , b and c \n");
	
	printf("a?\n");
	scanf("%d",&a);
	
	printf("b?\n");
	scanf("%d",&b);
	
	printf("c?\n");
	scanf("%d",&c);
	
	if(a>b)
	{
		if(a>c)
		{
			max=a;	
		}
		else
			max=c;
	}
	else
	{
		if(b>c)
		{
			max=b;
		}
		else
			max=c;
	}
	printf("max is %d\n",max);
	
		
	return 0;
}
