#include <stdio.h>
#include <stdlib.h>

int main()
{
	float a,b;
	printf("Lutfen bir sayi giriniz \n");
	scanf("%f",&a);
	
	printf("Lutfen bir sayi daha giriniz \n");
	scanf("%f",&b);
	
	printf("Sayilarin toplami %.2f\n",a+b);
	printf("Sayilarin farki %.2f\n",a-b);
	printf("Sayilarin carpimi %.2f\n",a*b);
	printf("Sayilarin bolumu %.2f\n",a/b);
	return 0;
}
