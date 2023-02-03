#include<stdio.h>
#include<math.h>

//option 1
enum Color {red, green, blue};
typedef enum Color COLOR_t;

//option 2
//typedef enum Color {red, green, blue} COLOR_t;

//option 3
//typedef enum {red, green, blue} COLOR_t;



//typedef int integer;
typedef long long int integer;



typedef double Position[2];
#define X 0
#define Y 1

double distance(Position p1, Position p2)
{
	double dx = p1[X] - p2[X];
	double dy = p1[Y] - p2[Y];
	return sqrt((dx*dx)+(dy*dy));
}



//typedef int IPv4[4]; //82.222.81.161
//typedef char IPv4[4];
typedef unsigned char IPv4[4];



int main()
{
	COLOR_t c;
	integer i;
	Position p;
	IPv4 ip;
	
	c = red;
	
	p[0] = 3.333333;
	p[1] = -0.7777777;
	
	printf("%d %d %d\n", red, green, blue);
	printf("%d\n", sizeof(c));
	printf("%d\n", sizeof(COLOR_t));
	printf("\n");
	printf("%d\n", sizeof(int));
	printf("%d\n", sizeof(short int));
	printf("%d\n", sizeof(long int));
	printf("%d\n", sizeof(long long int));
	printf("%d\n", sizeof(i));
	printf("%d\n", sizeof(integer));
	printf("%d\n", sizeof(long double));
	printf("\n");
	printf("%d\n", sizeof(p));
	printf("%d\n", sizeof(Position));
	printf("\n");
	printf("%d\n", sizeof(ip));
	printf("%d\n", sizeof(IPv4));
	
	return 0;
}

