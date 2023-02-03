#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a;
	printf("Lutfen bir deger giriniz\n");
	scanf("%d",&a);
	
	if(a==4){
		printf("a esittir 4\n");
	}
	if(a!=4){
		printf("a esit degildir 4\n");
	}
	if(a>4){
		printf("a buyuktur 4\n");
	}
	if(a>=4){
		printf("a buyuk esittir 4\n");
	}
	if(a<4){
		printf("a kucuktur 4\n");
	}
	if(a<=4){
		printf("a kucuk esittir 4\n");
	}
	else {
		exit(-1);
	}
	
	return 0;
}
