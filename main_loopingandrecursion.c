#include<stdio.h>

//assumptions:
// - m,n are nonnegative integers.
int multiply(int m, int n)
{
	int i;
	int res;
	res = 0;
	for(i=0; i<m; i++) {
		res = res + n;
	}
	return res;
}
int multiply_recursive(int m, int n)
{
	if(m <= 0) { //base case (termination case)
		return 0;
	}
	else { //recursive case
		return multiply_recursive(m-1, n) + n;
	}
}

//assumptions:
// - m is a nonnegative integer.
unsigned int factorial(unsigned int m)
{
	int res;
	res = 1;
	for(; m>0; m--) {
		res = res * m;
	}
	return res;
}
unsigned int factorial_recursive(unsigned int m)
{
	if(m <= 0) {
		return 1;
	}
	else {
		return m * factorial_recursive(m-1);
	}
}

int main()
{
	
	return 1;
}

