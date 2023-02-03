#include<stdio.h>
#include"example1.h"
#include"example2.h"

#include"example1.h"
#include"example1.h"
#include"example1.h"
#include"example1.h"
#include"example1.h"
#include"example1.h"
#include"example1.h"
#include"example1.h"
#include"example2.h"
#include"example2.h"
#include"example2.h"
#include"example2.h"
#include"example2.h"

#define N 5

int main()
{
	double r[N] = {1.0, 2.0, 3.0, 4.0, 5.0};
	double a[N];
	double c[N];
	
	printf("%lf\n", area_circle(3));
	printf("%lf\n", circumference_circle(3));
	
	print_array_double(r, N);
	print_array_double(a, N);
	print_array_double(c, N);
	printf("\n");
	area_circle_array(r, N, a);
	circumference_circle_array(r, N, c);
	print_array_double(r, N);
	print_array_double(a, N);
	print_array_double(c, N);
	
	return 0;
}

