#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a;
	printf("Lutfen bir deger giriniz.\n");
	scanf("%d",&a);
	printf("Girdiginiz deger %d\n",a);
	
	float b;
	printf("Lutfen bir deger giriniz.\n");
	scanf("%f",&b);
	printf("Girdiginiz deger %f\n",b); 
	
	char d;
	printf("Lutfen bir karakter giriniz.\n");
	scanf("%c",&d);
	printf("Girdiginiz karakter %c\n",d);
	
	
	char e[5];
	printf("Lutfen bir karakter dizisi giriniz.\n");
	scanf("%s",&e);
	printf("Girdiginiz karakter dizisi %s\n",e);
	
	printf("Sirasiyla girdikleriniz %d %f %c %s\n",a,b,d,e);
	
	printf("Sayilarin toplami %f",a+b);

}
