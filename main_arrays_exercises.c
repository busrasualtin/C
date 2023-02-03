#include<stdio.h>
#include<float.h> //contains DBL_MAX

#define SIZE 10

void print_arr_double(double arr[], int num)
{
	int i;
	for(i=0; i<num; i++) {
		printf("%lf ", arr[i]);
	}
	printf("\n");
}

void print_arr_int(int arr[], int num)
{
	int i;
	for(i=0; i<num; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

double average_arr_double(double arr[], int num)
{
	int i;
	double sum = 0.0;
	
	for (i=0; i<num; i++) {
		sum = sum + arr[i];
	}
	
	return sum / num;
}

double max_arr_double_val_v1(double arr[], int num)
{
	int i;
	double m;
	m = -DBL_MAX; //minimum double value
	for(i=0; i<num; i++) {
		if(arr[i] > m) {
			m = arr[i];
		}
	}
	return m;
}

double max_arr_double_val_v2(double arr[], int num)
{
	int i;
	double m;
	m = arr[0];
	for(i=1; i<num; i++) {
		if(arr[i] > m) {
			m = arr[i];
		}
	}
	return m;
}

int max_arr_double_ind(double arr[], int num)
{
	int i;
	int m;
	m = 0;
	for(i=1; i<num; i++) {
		if(arr[i] > arr[m]) {
			m = i;
		}
	}
	return m;
}

int digitize_into_arr(int n, int arr[])
{
	int i;
	if(n!=0) {
		for(i=0; n!=0; i++) {
			arr[i] = n % 10;
			n = n / 10;
		}
	}
	else {
		arr[0] = 0;
		i = 1;
	}
	return i;
}

// this function is not working correctly.
int digitize_into_arr_rev(int n, int arr[])
{
	int i;
	int tn;
	int m;
	int r;
	tn = n;
	if(n!=0) {
		r = 1;
		for(i=0; n!=0; i++) {
			n = n / 10;
			r = r * 10;
		}
		m = i;
		r = r / 10;
	}
	else {
		m = 1;
		r = 10;
	}
	n = tn;
	for(i=0; i<m; i++) {
		arr[i] = n / r;
		n = n - arr[i] * r;
		r = r / 10;
		m = m - 1;
	}
	return i;
}

int main()
{
	int i;
	double a[SIZE];
	double avg;
	double maxv;
	int maxi;
	
	int n;
	int d[SIZE];
	int m;
	
	for(i=0; i<SIZE; i++) {
		a[i] = (double)(i+1) / SIZE;
		//a[SIZE-1-i] = (double)(i+1) / SIZE;
	}
	print_arr_double(a, SIZE);
	//print_arr_double(a, SIZE-2);
	
	avg = average_arr_double(a, SIZE);
	printf("avg = %lf\n", avg);
	
	maxv = max_arr_double_val_v1(a, SIZE);
	printf("maxv = %lf\n", maxv);
	maxv = max_arr_double_val_v2(a, SIZE);
	printf("maxv = %lf\n", maxv);
	
	maxi = max_arr_double_ind(a, SIZE);
	printf("maxi = %d, maxv = %lf\n", maxi, a[maxi]);
	
	n = 135791;
	m = digitize_into_arr(n, d);
	printf("%d: ", n);
	print_arr_int(d, m);
	n = 0;
	m = digitize_into_arr(n, d);
	printf("%d: ", n);
	print_arr_int(d, m);
	n = -135791;
	m = digitize_into_arr(n, d);
	printf("%d: ", n);
	print_arr_int(d, m);
	
	n = 135791;
	m = digitize_into_arr_rev(n, d);
	printf("%d: ", n);
	print_arr_int(d, m);
	n = 0;
	m = digitize_into_arr_rev(n, d);
	printf("%d: ", n);
	print_arr_int(d, m);

	return 0;
}

