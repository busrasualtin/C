#include<stdio.h>

#define N 20
#define M 20

#define X 3
#define Y 5
#define Z 7
 
int sum_all(int a[][N], int m, int n) //having n here is kind of redundant because N is being used.
{
	int i, j;
	int s = 0;
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			s = s + a[i][j];
		}
	}
	return s;
}

int min(int x, int y)
{
	if(x<=y) {
		return x;
	}
	else {
		return y;
	}
}
int sum_diagonal(int a[][N], int m, int n)
{
	int i;
	int s = 0;
	int l;
	l = min(m, n);
	for(i=0; i<l; i++) {
		s = s + a[i][i];
	}
	return s;
}
 
int main()
{
	int a[N] = {0, -9, 12, 840, 98, 3, 40, -984, 3, -1879};
	int b[X][Y] = { {0, -9, 12, 840, 98},
				{3, 40, -984, 3, -1879},
					{-1, 0, 1, 0, -1} };
	int c[X][Y][Z] = {{{0}}}; //?
	
	return 0;
}
 
