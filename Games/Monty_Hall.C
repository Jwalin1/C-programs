#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<time.h>

int main()
{
	int i,n,car,goat,door,wins=0;
	char ch,ch1;
	printf("enter number of test cases : ");
	scanf("%d",&n);
	printf("simulate (y/n) : ");
	scanf(" %c",&ch1);
	if(ch1=='y')
	{
		printf("always change (y/n) : ");
		scanf(" %c",&ch);
	}
	if(ch1!='y')
	{
		system("CLS");
		for(i=1;i<=n;i++)
		{
			car=1+rand()%3;
			do
			{
				printf("choose door (1-3) : ");
				scanf("%d",&door);
			} while(door<1||door>3);
			do
				goat=1+rand()%3;
			while(goat==door||goat==car);
			printf("door %d has a goat\n",goat);
			printf("would you like to change your choice? (y/n) : ");
			scanf(" %c",&ch);
			if(ch=='y')
			{
				do
					door=1+door%3;
				while(door==goat);
			}
			if(door==car)
			{
				printf("\nyou win a car");
				wins++;
			}
			else
				printf("\nyou win a goat");
			getch();
			system("CLS");
			printf("win percentage = %f\n",100.0*wins/i);
			printf("test cases = %d\n\n",i);
		}
	}
	else
	{
		for(i=1;i<=n;i++)
		{
			car=1+rand()%3;
			door=1+rand()%3;
			do
				goat=1+rand()%3;
			while(goat==door||goat==car);
			if(ch=='y')
			{
				do
					door=1+door%3;
				while(door==goat);
			}
			if(door==car)
				wins++;
		}
		printf("\n\nwin percentage = %f",100.0*wins/n);
	}
	getch();
	return 0;
}
