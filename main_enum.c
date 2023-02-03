#include<stdio.h>

//enum day {mon, tue, wed, thu, fri, sat, sun};
//enum day {mon=1, tue, wed, thu, fri, sat, sun};
enum day {mon=1, tue, wed=9, thu, fri, sat, sun};

enum direction {north, west, south, east};

enum cointoss {heads, tails};

enum color {red, green, blue};


int main()
{
	enum day d;
	enum direction dir;
	
	printf("%d %d %d %d %d %d %d\n", mon, tue, wed, thu, fri, sat, sun);
	d = mon;
	
	if(d == fri) {
		d = sun;
	}
	
	d = 200;
	
	return 0;	
}

