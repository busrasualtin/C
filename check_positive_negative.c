#include <stdio.h>
#include <stdlib.h>

int main()
{
	//Write a C program to check positive, negative or zero using simple if or if else.
	
	int a;
	
	printf("give a number\n");
	scanf("%d",&a);
	
	if(a > 0)
	{
		printf("a is positive");
	}
	else if(a<0)
	{
		printf("a is negative");
	}
	else
		printf("a is zero");
	return 0;
}
