#include <stdio.h>
#include <stdlib.h>

int main()
{
	//Write a C program to find maximum between two numbers using if else
	int a,b;
	
	printf("Give me two numbers which are a and b\n");
	
	printf("a?\n");
	scanf("%d",&a);
	
	printf("b?\n");
	scanf("%d",&b);
	
	if(a>b)
	{
		printf("Max is %d",a);
	}
	else if(b>a)
	{
		printf("Max is %d",b);
	}
	else
		printf("They are equal");
		
	return 0;
}
