#include<stdio.h>

#define N 10

void print(int a[], int n)
{
	int i;
	for(i=0; i<n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

int search_binary_iter(int a[], int n, int key)
{
	int start, end, pos;
	start = 0;
	end = n-1;
	while(start <= end) {
		pos = (start + end) / 2;
		if(a[pos] == key) {
			return pos;
		}
		else if(a[pos] > key) {
			end = pos - 1;
		}
		else {
			start = pos + 1;
		}
	}
	return -1;
}

int main()
{
/*	int a[N] = {-79548, -932, -5, 0, 8, 35, 47, 5879, 7982, 8758};
	print(a, N);
	printf("search_binary_iter: %d\n", search_binary_iter(a, N, 0));
	printf("search_binary_iter: %d\n", search_binary_iter(a, N, -79548));
	printf("search_binary_iter: %d\n", search_binary_iter(a, N, 8));
	printf("search_binary_iter: %d\n", search_binary_iter(a, N, 50));
*/	
	
/*	int i;
	int n = 10;	
	for(i=0; i<n; i++) {
		printf("%d ", i);
	}
	printf("\n");
	
	i = 0;
	while(i<n) {
		printf("%d ", i);
		i++;
	}
	printf("\n");
	
	i = 0;
	if(i<n) {
		do {
			printf("%d ", i);
			i++;
		} while(i<n);
	}
	printf("\n");
*/

	int i;
	int n = 10;
	i = 0;
	do {
		printf("%d ", i);
		i++;
	} while(i<n);
	printf("\n");
	
	i = 0;
	printf("%d ", i);
	i++;
	while(i<n) {
		printf("%d ", i);
		i++;
	}
	printf("\n");
	
	i = 0;
	printf("%d ", i);
	i++;
	for(;i<n;) {
		printf("%d ", i);
		i++;
	}
	printf("\n");
		
	return 0;
}

