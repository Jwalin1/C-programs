#include<stdio.h>
#include <time.h>
#include<windows.h>
int G[31][61],B[10],x,y,s=0;

void print()
{	
	int i,j;
	for(i=1;i<=30;i++)
	{
		for(j=1;j<=60;j++)
		{
			if(i==1)
				printf("|");
			else if(j==1||j==60)
				printf("_");
			else if(i==x&&j==y)
				printf("O");
			else if(G[i][j]==1)
				printf("*");		
			else
				printf(" ");	
		}
		if(i==1)
			printf(" score : %d",s);
		printf("\n");
	}
}

void set()
{
	int i;
	for(i=1;i<=60;i++)
		G[30][i]=2;
	for(i=1;i<=9;i++)
		G[30][B[i]]=1;	
}

void main()
{
	int i,j,d1=-1,d2=0;
	for(i=1;i<=30;i++)
	{
		for(j=1;j<=60;j++)
		{	
			if(i==1||i==6||i==7||i==8||i==9||i==10||j==1||j==60)
				G[i][j]=1;
			else
				G[i][j]=0;	
		}	
	}
	srand(time(NULL));	
	B[1]=26;
	B[2]=27;
	B[3]=28;
	B[4]=29;
	B[5]=30;
	B[6]=31;
	B[7]=32;
	B[8]=33;
	B[9]=34;
	x=29; y=30;
	set();
	print();
	getch();
	system("CLS");
	while(1)
	{
		for(i=1;i<=2;i++)
		{
			if((GetAsyncKeyState(VK_RIGHT))&&(B[9]+1)!=60)
			{
				for(j=1;j<=9;j++)
					{
						G[30][B[j]]=0;
						B[j]=B[j]+1;
					}
			}	
			else if((GetAsyncKeyState(VK_LEFT))&&(B[1]-1)!=1)
			{
				for(j=1;j<=9;j++)
					{
						G[30][B[j]]=0;
						B[j]=B[j]-1;
					}
			}
			system("CLS");
			set();
			print();
		}	
		if(s==290)
			break;
		else if(G[x+d1][y+d2]==0)
		{
			G[x][y]=0;
			if((GetAsyncKeyState(VK_RIGHT))&&x==29&&(y+1)!=60)
			{
				y=y+1; 
				d2=0;
			}
			else if((GetAsyncKeyState(VK_LEFT))&&x==29&&(y-1)!=1)
			{
				y=y-1; 
				d2=0;
			}
			x=x+d1;	
			y=y+d2;
		}
		else if(y+d2==1||y+d2==60)
			d2=d2*-1;
		else if(x+d1==1)
			d1=1;
		else if(G[x+d1][y+d2]==2&&G[x+d1][y]==2)
			break;
		else if(x+d1==30&&y+d2<=B[3])
		{
			G[x+d1][y+d2]=0;
			d1=d1*-1;
			d2=-1;
		}	
		else if(x+d1==30&&y+d2>=B[7])
		{
			G[x+d1][y+d2]=0;
			d1=d1*-1;
			d2=1;
		}
		else if(x+d1==30)
		{
			G[x+d1][y+d2]=0;
			d1=d1*-1;
			d2=0;
		}			
		else
		{
			G[x+d1][y+d2]=0;
			d1=d1*-1;
			d2=rand()%3-1;	
			s=s+1;
		}			
		system("CLS");	
	}
	G[29][y]=0;
	x=30;
	y=y+d2;
	system("CLS");
	set();
	print();
	G[30][y]=0;
	x=0;
	y=0;
	system("CLS");
	set();
	print();
	if(s==290)
		printf("You Win");
	else
		printf("Game Over");
	getchar();
}	

