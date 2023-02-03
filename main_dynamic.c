#include<stdio.h>
#include<stdlib.h>

int example1()
{
	char *p;
	
	printf("%p\n", p);
	p = (char *)malloc(sizeof(char));
	if(p == NULL) {
		printf("malloc error\n");
		return -1;
	}
	printf("%p\n", p);
	
	printf("%c\n", *p);
	*p = 'z';
	printf("%c\n", *p);
	
	free(p);
	
	printf("%p\n", p);
	printf("%c\n", *p);
	//*p = 'x'; //!!! address is not valid anymore. crash!
	printf("%c\n", *p);
	
	return 0;
}

#define N 5

void print_array_int(int *a, int n)
{
	int i;
	for(i=0; i<n; i++) {
		printf("%p: %d\n", (a+i), *(a+i));
	}
}

int example2()
{
	int *p;
	
	p = (int *)malloc(N*sizeof(int));
	if(p == NULL) {
		printf("malloc error\n");
		return -1;
	}
	
	print_array_int(p, N);
	printf("\n");
	p[0] = -1;
	*(p+1) = 0;
	*(p+2) = 1;
	p[3] = 2;
	p[4] = 3;
	print_array_int(p, N);
	
	free(p);
	
	return 0;
}

int main()
{
	//return example1();
	return example2();
}
