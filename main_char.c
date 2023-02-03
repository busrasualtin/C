#include<stdio.h>

int main()
{
	char c;
	int i;
	
	c = 'x';
	printf("%c\n", c);
	printf("%d\n", sizeof(c));
	printf("%d\n", sizeof(char));
	printf("\n");
	
	/*for(c=0; c<=255; c++) {
		printf("%c\n", c);
	}*/
	/*for(i=0; i<=255; i++) {
		printf("(%c)", i);
	}*/
	
	c = 0;
	while(c != -1) {
		printf("enter a char (and -1 to exit): ");
		scanf("%c", &c); //instead of fflush, put one space before %c: scanf(" %c", &c).
		fflush(stdin);
		printf("%c - %d\n", c, c);
	}
	
	return 0;
}

