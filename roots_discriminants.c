#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	//Write a C program to find all roots of a quadratic equation using if else.
	
	float a,b,c,root1,root2,discriminant,imaginary;
	
	printf("give three numbers for quadratic equation (aX^2 + bX + c)\n");
	scanf("%f",&a);
	scanf("%f",&b);
	scanf("%f",&c);
	
	discriminant = (b*b)-(4*a*c);
	
	
	
	
	if(discriminant > 0)
	{
		root1= (-b + sqrt(discriminant)) / (2*a);
		root2= (-b - sqrt(discriminant)) / (2*a);
		printf("root 1 is %.2f and root 2 is %.2f",root1,root2);
	}
		
	else if(discriminant == 0)
	{
		printf("root1 = root2 it means %f",root1);
	}
	
	else if(discriminant < 0)
		{
			root1 = root2 = -b / (2 * a);
			imaginary = sqrt(-discriminant) / (2 * a);
			printf("Two distinct complex roots exists: %.2f + i%.2f and %.2f - i%.2f",root1, imaginary, root2, imaginary);
		}
	return 0;
}
