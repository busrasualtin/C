#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

#define ARRAY_COUNT 1000
#define RND_LOWER 1
#define RND_UPPER 10

int * fillArray();
int getRandomNumber(int,int);
bool isPerfectSquare(int);
bool isPrimeNumber(int);
void printResult(int,int,int,unsigned long long,int);
unsigned long long getTotalGoldForSpecialStatus(unsigned long long);

int main() {
	srand(time(NULL));

	int *array;
	int position,prevPosition = -1,positionGold = 0,visitedCityCount = 0,zeroCount = 0, tempPosition;
	unsigned long long totalGold = 0;
	array = fillArray();

	position = getRandomNumber(1,ARRAY_COUNT);
	while(1) {
		visitedCityCount++;
		positionGold = array[position];
		totalGold += positionGold;

		totalGold = getTotalGoldForSpecialStatus(totalGold);

		printResult(position,prevPosition,positionGold,totalGold,visitedCityCount);

		if(positionGold == 0) {
			zeroCount++;
		} else {
			zeroCount = 0;
		}
		if(zeroCount == 3) {
			break;
		} else {
			array[position] = 0;
			tempPosition = position;
			if((positionGold % 2) == 0) {
				position = abs((prevPosition + position + positionGold)) % ARRAY_COUNT;
			} else {
				position = abs((prevPosition + position - positionGold)) % ARRAY_COUNT;
			}
			prevPosition = tempPosition;
		}
	}

	return 0;
}
int * fillArray() {
	static int array[ARRAY_COUNT];
	int i;


	for(i = 0; i < ARRAY_COUNT; i++) {
		array[i] = getRandomNumber(RND_LOWER,RND_UPPER);
	}

	return array;
}
int getRandomNumber(int lower,int upper) {
	return (rand() %
	        (upper - lower + 1)) + lower;
}
bool isPerfectSquare(int number) {
	int iVar;
	float fVar;
	fVar=sqrt((double)number);
	iVar=fVar;
	if(iVar==fVar)
		return true;
	else
		return false;

}
bool isPrimeNumber(int number) {
	int i, flag = 0;
	for (i = 2; i <= number / 2; ++i) {
		if (number % i == 0) {
			flag = 1;
			break;
		}
	}

	if (number == 1) {
		return false;
	} else {
		if (flag == 0)
			return true;
		else
			return false;
	}
}
void printResult(int position,int prevPosition,int positionGold,unsigned long long totalGold,int visitedCityCount) {
	printf("The current city index (pn) = %d \n", position);
	printf("The previous city index (pn-1) = %d \n", prevPosition);
	printf("The number of golds at the current city (gn). = %d \n", positionGold);
	printf("The current total gold collected = %llu \n", totalGold);
	printf("The number of cities visited = %d \n", visitedCityCount);
	printf("---------------------------------------\n");
}
unsigned long long getTotalGoldForSpecialStatus(unsigned long long totalGold) {
	if(isPerfectSquare(totalGold)) {
		printf("PERFECT!\n");
		totalGold *= 2;
	}
	if(isPrimeNumber(totalGold)) {
		printf("PRIME!\n");
		totalGold *= 3;
	}
	return totalGold;
}
