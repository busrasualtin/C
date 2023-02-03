#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int game(char name_surname[99])
{
	int s1,s2,result,i,point=0,chance=2;
	srand(time(NULL));
	printf("\nHello. This Program is the multiplication table game.\n");
	printf("You have only three chance.\n");
	printf("You lost 5 points for one wrong answer and win 5 points for one right answer..\n");
	printf("Good luck!!\n");
	
	BSA:s1=1+rand()%10; s2=1+rand()%10;
	
	printf("%d*%d = ",s1,s2);
	scanf("%d",&result);

	if(result==s1*s2)
	{
		point+=5;
		printf("Congratulations, right answer. You'r point is :%d\n",point);
		if(point==100)
		{
			printf("Congratulations. You answered all the questions.\n");
			
		}
		else
		{
			goto BSA;
		}

	}
	else

	{
		if(chance!=0)
		{
			point-=5;
			printf("Sorry you'r answer is wrong. You'r point is :%d\nChance :%d\n\n",point,chance);
			chance--;

			goto BSA;

		}
		else
		{
			printf("You'r answer is wrong.YOu have last %d chance.\n",chance);
			printf("Game was over.%s",strupr(name_surname));
			printf("\n\nYour point: %d",point);
		}
	}
	printf("\n\n");
	system("PAUSE");
}
int main()

{
	char name_surname[99];
	printf("Name and Surname :");
	gets(name_surname);
	game(name_surname);
	getch();

}
