#include <stdio.h>

char *my_duty(int*u)
{
	char *m = (char*)malloc(100);
	return m;
}
int main()
{
	int k;
	char *t;
	k=(int*)malloc(sizeof(int)*30);
	t=my_duty(k);
	
	free(t);
	free(k);
	return 1;
	
}
