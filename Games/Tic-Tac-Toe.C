#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[5][5],i,j;
	printf("Tic-Tac-Toe\nO and X\n");
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			a[i][j]=0; 
		}
	}
	while(1)
	{
	system("cls");
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(i%2==0&&j%2==0&&a[i][j]==0){printf(" ");}
			else if(a[i][j]==1){printf("O");}
			else if(a[i][j]==2){printf("X");}
			else if(j%2!=0){printf("|");}
			else {printf("-");}
		}
		printf("\n");
	}
	if(a[0][0]==1&&a[0][2]==1&&a[0][4]==1){printf("Player 2 won"); getch(); return 0;}
	if(a[2][0]==1&&a[2][2]==1&&a[2][4]==1){printf("Player 2 won"); getch(); return 0;}
	if(a[4][0]==1&&a[4][2]==1&&a[4][4]==1){printf("Player 2 won"); getch(); return 0;}
	if(a[0][0]==1&&a[2][0]==1&&a[4][0]==1){printf("Player 2 won"); getch(); return 0;}
	if(a[0][2]==1&&a[2][2]==1&&a[4][2]==1){printf("Player 2 won"); getch(); return 0;}
	if(a[0][4]==1&&a[2][4]==1&&a[4][4]==1){printf("Player 2 won"); getch(); return 0;}
	if(a[0][0]==1&&a[2][2]==1&&a[4][4]==1){printf("Player 2 won"); getch(); return 0;}
	if(a[0][4]==1&&a[2][2]==1&&a[4][0]==1){printf("Player 2 won"); getch(); return 0;}
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(i%2==0&&j%2==0&&a[i][j]==0) { break; } 
		}
		if(i%2==0&&j%2==0&&a[i][j]==0) { break; }  
	} 
		if(i==5&&j==5){printf("Draw"); getch(); return 0;}
		printf("Player 1\n");
		i=-1; j=-1;
		while(i<0||i>4||j<0||j>4||a[i][j]>0)
		{
			printf("Enter row : ");
			scanf("%d",&i);
			printf("Enter column : ");
			scanf("%d",&j);
			if(i==0||i==4||j==0||j==4){i=-1;j=-1;}
			if(i==1){i=0;} if(i==3){i=4;}
			if(j==1){j=0;} if(j==3){j=4;}
		}
		a[i][j]=2;
		system("cls");
		for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(i%2==0&&j%2==0&&a[i][j]==0){printf(" ");}
			else if(a[i][j]==1){printf("O");}
			else if(a[i][j]==2){printf("X");}
			else if(j%2!=0){printf("|");}
			else {printf("-");}
		}
		printf("\n");
	}
	if(a[0][0]==2&&a[0][2]==2&&a[0][4]==2){printf("Player 1 won"); getch(); return 0;}
	if(a[2][0]==2&&a[2][2]==2&&a[2][4]==2){printf("Player 1 won"); getch(); return 0;}
	if(a[4][0]==2&&a[4][2]==2&&a[4][4]==2){printf("Player 1 won"); getch(); return 0;}
	if(a[0][0]==2&&a[2][0]==2&&a[4][0]==2){printf("Player 1 won"); getch(); return 0;}
	if(a[0][2]==2&&a[2][2]==2&&a[4][2]==2){printf("Player 1 won"); getch(); return 0;}
	if(a[0][4]==2&&a[2][4]==2&&a[4][4]==2){printf("Player 1 won"); getch(); return 0;}
	if(a[0][0]==2&&a[2][2]==2&&a[4][4]==2){printf("Player 1 won"); getch(); return 0;}
	if(a[0][4]==2&&a[2][2]==2&&a[4][0]==2){printf("Player 1 won"); getch(); return 0;}
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(i%2==0&&j%2==0&&a[i][j]==0) { break; }  
		}
		if(i%2==0&&j%2==0&&a[i][j]==0) { break; }  
	} 
		if(i==5&&j==5){printf("Draw"); getch(); return 0;}
		printf("Player 2\n");
		i=-1; j=-1;
		while(i<0||i>4||j<0||j>4||a[i][j]>0)
		{
			printf("Enter row : ");
			scanf("%d",&i);
			printf("Enter column : ");
			scanf("%d",&j);
			if(i==0||i==4||j==0||j==4){i=-1;j=-1;}
			if(i==1){i=0;} if(i==3){i=4;}
			if(j==1){j=0;} if(j==3){j=4;}
		}
		a[i][j]=1;
	}
	return 0;
}
