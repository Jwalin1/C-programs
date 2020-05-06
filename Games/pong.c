#include<stdio.h>
#include <time.h>
#include<windows.h>
int G[32][62],A[6],B[6],x,y,s1=0,s2=0;

void print()
{	
	int i,j;
	printf("\t\tPlayer 1");
	if(s1==5)
		printf(" wins");
	printf("\t\t\tPlayer 2");
	if(s2==5)
		printf(" wins");
	printf("\n");	
	for(i=1;i<=31;i++)
	{
		printf("\t");
		for(j=1;j<=61;j++)
		{
			if(i==1||i==31)
				printf("|");
			else if(i==x&&j==y)
				printf("O");
			else if(i==2&&j==29)
				printf("%d",s1);		
			else if(j==31)
				printf("|");
			else if(i==2&&j==33)
				printf("%d",s2);	
			else if(G[i][j]==1)
				printf("*");			
			else
				printf(" ");	
		}
		printf("\n");
	}
}

void set()
{
	int i;
	for(i=1;i<=31;i++)
	{
		G[i][1]=2;
		G[i][61]=2;
	}
	for(i=1;i<=5;i++)
	{
		G[A[i]][1]=1;	
		G[B[i]][61]=1;	
	}
	G[x][y]=1;	
}

void main()
{
	int i,j,d1,d2;
	for(i=1;i<=31;i++)
	{
		for(j=1;j<=61;j++)
		{
			if(i==1||i==31)
				G[i][j]=1;
			else
				G[i][j]=0;	
		}
	}
	srand(time(NULL));
	label1:	
	for(i=1;i<=5;i++)
	{
		A[i]=i+13;
		G[A[i]][1]=1;
		B[i]=i+13;
		G[B[i]][61]=1;
	}
	x=16;
	y=31;
	d1=2*(rand()%2)-1;	
	d2=2*(rand()%2)-1;	
	set();
	print();
	while(!GetAsyncKeyState(VK_RETURN));
	system("CLS");
	while(1)
	{
		for(i=1;i<=2;i++)
		{
			if((GetAsyncKeyState(VK_UP))&&(B[1]-1)!=1)
			{
				for(j=1;j<=5;j++)
					{
						G[B[j]][61]=0;
						B[j]=B[j]-1;
					}
			}	
			else if((GetAsyncKeyState(VK_DOWN))&&(B[5]+1)!=31)
			{
				for(j=1;j<=5;j++)
					{
						G[B[j]][61]=0;
						B[j]=B[j]+1;
					}
			}
			if((GetAsyncKeyState(0x57))&&(A[1]-1)!=1)
			{
				for(j=1;j<=5;j++)
					{
						G[A[j]][1]=0;
						A[j]=A[j]-1;
					}
			}
			else if((GetAsyncKeyState(0x53))&&(A[5]+1)!=31)
			{
				for(j=1;j<=5;j++)
					{
						G[A[j]][1]=0;
						A[j]=A[j]+1;
					}
			}
			system("CLS");
			set();
			print();
		}
		if(G[x+d1][y+d2]==0)
		{
			G[x][y]=0;
			x=x+d1;
			y=y+d2;
		}
		else if(x+d1==1||x+d1==31)
			d1=d1*-1;
		else if(G[x+d1][y+d2]==2&&G[x][y+d2]==2)
		{
			if(y+d2==1)
				s2=s2+1;
			else
				s1=s1+1;
			G[x][y]=0;
			system("CLS");	
			if(s1==5)
				break;
			else if(s2==5)
				break;		
			else
				goto label1;	
		}
		else if(y+d2==61&&x+d1<=B[2])
		{
			G[x+d1][y+d2]=0;
			d1=-1;
			d2=d2*-1;
		}	
		else if(y+d2==61&&x+d1>=B[4])
		{
			G[x+d1][y+d2]=0;
			d1=1;
			d2=d2*-1;
		}
		else if(y+d2==61)
		{
			G[x+d1][y+d2]=0;
			d2=d2*-1;
		}
		else if(y+d2==1&&x+d1<=A[2])
		{
			G[x+d1][y+d2]=0;
			d1=-1;
			d2=d2*-1;
		}	
		else if(y+d2==1&&x+d1>=A[4])
		{
			G[x+d1][y+d2]=0;
			d1=1;
			d2=d2*-1;
		}
		else if(y+d2==1)
		{
			G[x+d1][y+d2]=0;
			d2=d2*-1;
		}
		system("CLS");
	}
	for(i=1;i<=5;i++)
	{
		A[i]=i+13;
		G[A[i]][1]=1;
		B[i]=i+13;
		G[B[i]][61]=1;
	}
	x=16;
	y=31;
	set();
	print();
	while(!GetAsyncKeyState(VK_RETURN));
}	

