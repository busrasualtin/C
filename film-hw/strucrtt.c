#include <stdio.h>
int main()
{
	typedef struct{
		char type[5];
		int gram;
		char brand[5];
		float price;
		char size;
	}kahve;
	typedef struct araba{
		kahve a;
	};
	struct kahve k,l,m;
	k.type[0]='f';
	k.type[1]='\0';
	l.type[0]='t';
	l.type[1]='\0';
	m.type[0]='e';
	m.type[1]='\0';
	printf("%s\n",a->k.type);
	printf("%s\n",l.type);
	printf("%s\n",m.type);
	 
}


