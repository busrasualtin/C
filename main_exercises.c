#include<stdio.h>

int sum3(int i1, int i2, int i3)
{
	/*int r;
	r = i1 + i2 + i3;
	return r;*/
	return (i1+i2+i3);
}

void print_hello()
{
	printf("hello\n");
}

void print_hello_thrice1()
{
	printf("hello\n");
	printf("hello\n");
	printf("hello\n");
}

void print_hello_thrice2()
{
	printf("hello\nhello\nhello\n");
}

void print_hello_thrice3()
{
	print_hello();
	print_hello();
	print_hello();
}

int main()
{
	int a,b,c,d;
	
	a = 1;
	b = 2;
	c = 3;
	d = sum3(a, b, c);
	printf("d: %d\n", d);
	
	printf("d: %d\n", sum3(4, 5, d));
	
	print_hello();
	
	print_hello_thrice1();
	print_hello_thrice2();
	print_hello_thrice3();
	
	printf(" ");
	return 0;
}

