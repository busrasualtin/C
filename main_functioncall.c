#include<stdio.h>

int f(int x, int y, int z)
{
	int r;
	r = x*y*z;
	return r;
}

int main()
{
	int a,b,c,d;
	
	a = 2;
	b = 5;
	c = 9;
	d = f(a, b, c);
	printf("%d\n", d);
	printf("%d\n", f(2,5,9));
	a++;
	b--;
	d = f(a, b, c);
	printf("%d\n", d);
	printf("\n");
	
	return 0;
}

