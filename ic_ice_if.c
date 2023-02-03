#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a,b;
	printf("Lutfen ilk sayiyi giriniz\n");
	scanf("%d",&a);
	
	printf("Lutfen ikinci sayiyi giriniz\n");
	scanf("%d",&b);
	
	if(a%2==1){
		if(b%2==1){
			printf("iki sayi da tektir.");
		}
		else{
			printf("ilk sayi tek ikinci sayi cifttir.");
		}
	}
	else{
		if(b%2==1){
			printf("ilk sayim cift ikinci sayi tektir.");
		}
		else{
			printf("iki sayi da cifttir.");
		}
		
	}
	return 0;
}
