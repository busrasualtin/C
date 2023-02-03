#include<stdio.h>

enum Direction {north, east, south, west};
typedef enum Direction Direction_t;

Direction_t opposite(Direction_t d)
{
	if(d == north) {
		return south;
	}
	else if(d == east) {
		return west;
	}
	else if(d == south) {
		return north;
	}
	else { // if(d == west) {
		return east;
	}
}

Direction_t opposite_alt(Direction_t d)
{
	return (d+2) % 4;
}



typedef enum CoinFace {heads, tails} CoinFace_t;



typedef double Coordinate[2];
#define X 0
#define Y 1



#define N 10

int main()
{
	Coordinate a[N];
	printf("%d\n", sizeof(a));
	printf("\n");
	
	return 0;
}

