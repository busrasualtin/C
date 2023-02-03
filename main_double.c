#include<stdio.h>

double average(double a, double b)
{
	return (a + b) / 2;
}

int main()
{
	double x,y,z;
	x = 3.14;
	y = 7.453631;
	z = average(x, y);
	printf("%lf\n", z);
	printf("%.13lf\n", z);
	printf("\n");
	return 0;
}

