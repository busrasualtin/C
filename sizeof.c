#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a = 3.14;
	printf("%d\n",a); //ondal�k k�sm� basmaz.
	
	float b = 3.14;
	printf("%f\n",b);
	printf("%.2f\n",b);
	
	//sizeof bellekte bir de�i�kenin ka� birim kadar yer tuttu�unu g�sterir.
	int sayi;
	char karakter;
	float ondalikSayi1;
	double ondalikSayi2;
	
	printf("int bellekte %d byte kadar yer tutar\n",sizeof(int));
	printf("char bellekte %d byte kadar yer tutar\n",sizeof(char));
	printf("float bellekte %d byte kadar yer tutar\n",sizeof(float));
	printf("double bellekte %d byte kadar yer tutar\n",sizeof(double));
	return 0;
}
