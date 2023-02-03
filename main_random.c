#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "randutils.h"

void example1()
{
   int i, n;
   time_t t;
   
   n = 5;
   
   /* Intializes random number generator */
   srand((unsigned) time(&t));

   /* Print 5 random numbers from 0 to 49 */
   for( i = 0 ; i < n ; i++ ) {
      printf("%d\n", rand() % 50);
   }
}

#define N 10

void print_array_double(double a[], int n)
{
	int i;
	for(i=0; i<n; i++) {
		printf("%lf ", a[i]);
	}
}
int main ()
{
	int i;
	unsigned int s;
	double a[N];
	printf("maximum random value: %d\n", RAND_MAX);
	
	//s = 1234567890;
	s = time(NULL);
	srand(s);
	printf("%u: ", s);
	for(i=0; i<N; i++) {
		printf("%d ", rand());
	}
	printf("\n");
	
	set_seed(s);
	printf("%u: ", s);
	for(i=0; i<N; i++) {
		printf("%d ", rand_int_pos_small_n(10));
	}
	printf("\n");
	
	set_seed(s);
	printf("%u: ", s);
	for(i=0; i<N; i++) {
		printf("%d ", rand_int_between_m_and_n(-2, 7));
	}
	printf("\n");
	
	set_seed(s);
	printf("%u: ", s);
	for(i=0; i<N; i++) {
		printf("%d ", rand_true_with_p(0.1));
	}
	printf("\n");
	
	print_array_double(a, N);
	printf("\n");
	set_seed(s);
	printf("%u: ", s);
	rand_double_between_0_and_1_array(a, N);
	print_array_double(a, N);
	printf("\n");
	
	return 0;
}

