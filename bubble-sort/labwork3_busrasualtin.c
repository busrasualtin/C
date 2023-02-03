//Busra Su Altin 19070001018

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char a[], char b[])
{
	char temp [100];
    strcpy (temp,a);
	strcpy (a,b);
	strcpy (b,temp);
}

void bubble_sort(char a[100][100], int n)
{
	int high;
	while (n!=0)
    {
    	high=0;
        for (int i=0; i<=(n-2); i++)
        {
            if(strcmp(a[i], a[i+1]) > 0)
			{
                swap(a[i], a[i+1]);
                high = i+1;
            }
        }
        n = high;
    }
}

/*
int main()
{
	char students[100][100]={"Ayberk" , "Busra" , "Murat" , "Mustafa" , "Ozan"};
	
	
	printf("After being sorted in alphabetical order: \n");
	
	bubble_sort(students, 5);
	
	for(int i=0;i<5;i++)
	{
		printf("%s ",students[i]);
	}
	return 0;
	
}
*/
