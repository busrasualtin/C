#include <stdio.h>
#include <stdlib.h>

int main()
{
	int yas,sayi;
	printf("lutfen yasinizi girin\n");
	scanf("%d",&yas);
	
	printf("lutfen ugurlu sayinizi girin\n");
	scanf("%d",&sayi);
	
	if( ((yas>30) && (yas<60)) || (sayi==13)){
		printf("yas 30 dan buyuk ve 60 dan kucuktur yada sayiniz 13 dur.");
	}
	
	return 0;
}
