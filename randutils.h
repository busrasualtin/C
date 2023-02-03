#ifndef ___RANDUTILSH___

#define RANDUTILSH

#include<stdlib.h>

void set_seed(unsigned int seed)
{
	srand(seed);
}

int rand_int_pos_small_n_v0(int n)
{
	int r;
	
	do {
		r = rand();
	} while(r==0 || r>=n);
	
	return r;
}

int rand_int_pos_small_n(int n)
{
	return rand() % (n-1) + 1;
}

// m <= n
int rand_int_between_m_and_n(int m, int n)
{
	return rand() % (n-m+1) + m;
}

double rand_double_between_0_and_1()
{
	return (double)rand() / (double)(RAND_MAX+1);
}

// 0 <= p <= 1
int rand_true_with_p(double p)
{
	if(rand_double_between_0_and_1() <= p) {
		return 1;
	}
	else {
		return 0;
	}
}

/* !!! double *rand_double_between_0_and_1_array(int n)
{
	int i;
	double a[n];
	
	for(i=0; i<n; i++) {
		a[i] = rand_double_between_0_and_1();
	}
	
	return a;
}*/

void rand_double_between_0_and_1_array(double a[], int n)
{
	int i;
	
	for(i=0; i<n; i++) {
		a[i] = rand_double_between_0_and_1();
	}
}

#endif

