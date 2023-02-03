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

//it has room for improvement. (hint: check the outputs after passes.)
void sort(int a[], int n)
{
	int pass, i, tmp;
	for(pass=1; pass<n; pass++) {
		for(i=0; i<n-1; i++) {
			if(a[i] > a[i+1]) {
				tmp = a[i];
				a[i] = a[i+1];
				a[i+1] = tmp;
			}
		}
		printf("after pass %d:", pass);
		print(a, N);
	}
}

int search_v0(int a[], int n, int key)
{
	int i;
	for(i=0; i<n; i++) {
		if(a[i] == key) {
			return i;
		}
	}
	return -1;
}

int search(int a[], int n, int key)
{
	int i;
	int pos;
	int notfound;
	pos = -1;
	notfound = 1;
	for(i=0; i<n && notfound; i++) {
		if(a[i] == key) {
			pos = i;
			notfound = 0;
		}
	}
	return pos;
}

int search_sorted(int a[], int n, int key)
{
	int i;
	int pos;
	int dontstop;
	pos = -1;
	dontstop = 1;
	for(i=0; i<n && dontstop; i++) {
		if(a[i] == key) {
			pos = i;
			dontstop = 0;
		}
		else if(a[i] > key) {
			pos = -1;
			dontstop = 0;
		}
	}
	return pos;
}

int main()
{
	int a[N] = {8, -932, 7982, 35, -5, 47, 8758, -79548 ,5879, 0};
	
	print(a, N);
	
	printf("search: %d\n", search(a, N, 0));
	printf("search: %d\n", search(a, N, -79548));
	printf("search: %d\n", search(a, N, 8));
	printf("search: %d\n", search(a, N, 50));
	
	sort(a, N);
	
	print(a, N);
	
	printf("search_sorted: %d\n", search_sorted(a, N, 0));
	printf("search_sorted: %d\n", search_sorted(a, N, -79548));
	printf("search_sorted: %d\n", search_sorted(a, N, 8));
	printf("search_sorted: %d\n", search_sorted(a, N, 50));
	
	return 0;
}

