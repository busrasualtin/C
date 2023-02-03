#include<stdio.h>

void increment_v0(int x)
{
	x++;
}

void increment(int *p)
{
	(*p)++;
	//*p = *p + 1;
}

void swap_v0(int x, int y)
{
	int tmp;
	tmp = x;
	x = y;
	y = tmp;
}

void swap(int *x, int *y)
{
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

void print_array_int(int *a, int n)
{
	int i;
	for(i=0; i<n; i++) {
		//printf("%d ", a[i]);
		printf("%d ", *(a+i));
	}
}

void capitalize_char(char *c)
{
	if(*c >= 'a' && *c <= 'z') {
		*c = *c - 32;
	}
}

#define N 5

int main()
{
	int j, i;
	int *pi;
	int **ppi;
	char *pc;
	double *pd;
	void *p;
	
	int a[N] = {-3, 0, 9, 123, -845};
	int *pa;
	
	char c;

	printf("%d %d %d %d\n", sizeof(int *), sizeof(char *), sizeof(double *), sizeof(void *));	

	i = 3;
	j = 5;
	printf("&i: %p\n&j: %p\n", &i, &j);
	
	printf("%p - %d\n", pi, sizeof(pi));
	pi = &i;
	printf("%p\n", pi);	
	printf("i: %d\n", i);
	i = i + 1;
	printf("i: %d\n", i);
	*pi = *pi + 1;
	printf("i: %d\n", i);
	printf("i: %d (*pi)\n", *pi);
	printf("i: %d (pi[0])\n", pi[0]);
	
	printf("%p - %d %d\n", ppi, sizeof(ppi), sizeof(int **));
	ppi = &pi;
	printf("%p\n", ppi);
	printf("%p\n", &ppi);
	**ppi = **ppi + 1;
	printf("i: %d\n", i);
	printf("i: %d (*pi)\n", *pi);
	printf("i: %d (pi[0])\n", pi[0]);
	printf("i: %d (**ppi)\n", **ppi);
	printf("i: %d (ppi[0][0])\n", ppi[0][0]);
	
	printf("i: %d %d\n", *pi, pi[0]);
	printf("j: %d %d\n", *(pi+1), pi[1]);
	
	increment_v0(i);
	increment_v0(j);
	printf("i: %d\n", i);
	printf("j: %d\n", j);
	
	increment(&i);
	increment(&j);
	printf("i: %d\n", i);
	printf("j: %d\n", j);
	
	print_array_int(a, N);
	printf("\n");
	increment(a);
	print_array_int(a, N);
	printf("\n");
	increment(a+2);
	increment(&a[3]);
	print_array_int(a, N);
	printf("\n");
	pa = a+4;
	increment(pa);
	print_array_int(a, N);
	printf("\n");
	
	printf("i: %d\n", i);
	printf("j: %d\n", j);
	swap(&i, &j);
	printf("i: %d\n", i);
	printf("j: %d\n", j);
	
	c = 'i';
	printf("c: %c\n", c);
	capitalize_char(&c);
	printf("c: %c\n", c);
	capitalize_char(&c);
	printf("c: %c\n", c);
	
	return 0;
}

