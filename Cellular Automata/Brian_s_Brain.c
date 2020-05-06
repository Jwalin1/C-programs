#include<stdio.h>
#include <time.h>
#include<windows.h>
int G[26][76],G1[26][76],s=100;

void print()
{
	int i,j;
	for(i=1;i<=25;i++)
	{
		for(j=1;j<=75;j++)
		{
			if(G[i][j]==1)
				printf("*");
			else
				printf(" ");	
		}
		printf("\n");
	}
	printf("\n\nspeed : <");
	for(i=1;i<=(10-(s/10));i++)
		printf("|");
	printf(">");	
}

void count()
{
	int i,j,p,q,x,y,t;
	for(i=1;i<=25;i++)
	{
		for(j=1;j<=75;j++)
		{
			t=0;
			for(p=-1;p<=1;p++)
			{
				for(q=-1;q<=1;q++)
				{
					if(p==0&&q==0)
						continue;
					x=i+p; y=j+q;
					if(x==0)
						x=25;
					else if(x==26)
						x=1;
					if(y==0)
						y=75;	
					else if(y==76)
						y=1;		
					if(G[x][y]==1)
						t=t+1;	
				}
			}
			G1[i][j]=t;
		}
	}
}

void update()
{
	int i,j;
	for(i=1;i<=25;i++)
	{
		for(j=1;j<=75;j++)
		{
			if(G[i][j]==1)
					G[i][j]=-1;
			else if(G[i][j]==0)
			{
				if(G1[i][j]==2)
					G[i][j]=1;
			}
			else
				G[i][j]=0;	
		}
	}
}

void main()
{
	int i,j;
	srand(time(NULL));
	label1:
	system("CLS");
	for(i=1;i<=25;i++)
	{
		for(j=1;j<=75;j++)
		{
			if(rand()%10==1)
				G[i][j]=1;
			else
				G[i][j]=0;	 
		}
	}
	count();
	print();
	while(1)
	{
		if((GetAsyncKeyState(VK_RIGHT))&&(s-10>=0))
			s=s-10;
		else if((GetAsyncKeyState(VK_LEFT))&&(s+10<=100))
		{
			s=s+10;
			if(s==100)
			{
				system("CLS");
				print();
			}
		}
		else if(GetAsyncKeyState(0x52))
			goto label1;
		else if(GetAsyncKeyState(0x50))
		{
			s=100;
			system("CLS");
			print();
		}		
		else if(GetAsyncKeyState(VK_ESCAPE))
			break;
		if(s==100&&!(GetAsyncKeyState(0x53)))
			continue;
		system("CLS");	
		update();
		count();
		print();	
		Sleep(s);			
	}
	getch();
}	

