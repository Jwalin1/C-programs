#include<stdio.h>
#include <time.h>
#include<windows.h>
int G[26][76],X[1771],Y[1771],l=5,s=0,x,y,f=0,d=1;

void print()
{
	int i,j;
	for(i=1;i<=25;i++)
	{
		for(j=1;j<=75;j++)
		{	
			if((i==1||i==25)&&(j<35||j>39))
				printf("|");
			else if((j==1||j==75)&&(i<10||i>14))
				printf("-");
			else if(G[i][j]==1)
				printf("*");
			else if(G[i][j]==2)
				printf("O");
			else if(G[i][j]==3)
				printf(">");
			else if(G[i][j]==4)
				printf("^");
			else if(G[i][j]==5)
				printf("<");
			else if(G[i][j]==6)
				printf("v");				
			else
				printf(" ");	
		}
		printf("\n");
	}
	printf("\nscore : %d",s);
}

void set()
{
	int i,j;
	for(i=1;i<=25;i++)
	{
		for(j=1;j<=75;j++)
		{	
			if(i==1||i==25||j==1||j==75)
				G[i][j]=1;
			else
				G[i][j]=0;	
		}	
	}
	for(i=10;i<=14;i++)
	{
		if((i!=X[i])||(j!=Y[j]))
		{
			G[i][1]=0;
			G[i][75]=0;
		}
	}
	for(i=35;i<=39;i++)
	{
		if((i!=X[i])||(j!=Y[j]))
		{
			G[1][i]=0;
			G[25][i]=0;
		}
	}
	G[X[0]][Y[0]]=1;
	if(d==1)
		G[X[1]][Y[1]]=3;
	else if(d==2)
		G[X[1]][Y[1]]=4;
	else if(d==3)
		G[X[1]][Y[1]]=5;
	else if(d==4)
		G[X[1]][Y[1]]=6;
	for(i=2;i<=l;i++)
	{
		G[X[i]][Y[i]]=1;
	}
	if(f>0)
	{
		G[x][y]=2;
		f=f-1;
	}
}

void main()
{
	int i,j,k;
	srand(time(NULL));	
	X[0]=0;
	Y[0]=0;
	X[1]=12; Y[1]=12;
	X[2]=12; Y[2]=11;
	X[3]=12; Y[3]=10;
	X[4]=12; Y[4]=9;
	X[5]=12; Y[5]=8;
	i=12; j=12;
	set();
	while(G[X[0]][Y[0]]>=1)
	{
		X[0]=rand()%23+2;
		Y[0]=rand()%73+2;
	}
	set();
	print();
	getch();
	system("CLS");
	while(1)
	{
		set();
		print();
		if(d==1)
		{
			if(Y[1]==75)
				Y[1]=0;
			if(G[X[1]][Y[1]+1]==0)
			{
				for(k=l;k>1;k--)
				{
					X[k]=X[k-1];
					Y[k]=Y[k-1];
				}
				Y[1]=Y[1]+1;
				i=X[1]; j=Y[1];
			}
			else if((X[1]==X[0])&&(Y[1]+1==Y[0]))
			{
				for(k=l+1;k>1;k--)
				{
					X[k]=X[k-1];
					Y[k]=Y[k-1];
				}
				Y[1]=Y[1]+1;
				i=X[1]; j=Y[1];
				x=X[0]; y=Y[0];
				f=l;
				while(G[X[0]][Y[0]]>=1)
				{
					X[0]=rand()%23+2;
					Y[0]=rand()%73+2;
				}
				l=l+1;
				s=s+1;
			}
			else
				break;
		}
		else if(d==2)
		{
			if(X[1]==1)
				X[1]=26;
			if(G[X[1]-1][Y[1]]==0)
			{
				for(k=l;k>1;k--)
				{
					X[k]=X[k-1];
					Y[k]=Y[k-1];
				}
				X[1]=X[1]-1;
				i=X[1]; j=Y[1];
			}
			else if((X[1]-1==X[0])&&(Y[1]==Y[0]))
			{
				for(k=l+1;k>1;k--)
				{
					X[k]=X[k-1];
					Y[k]=Y[k-1];
				}
				X[1]=X[1]-1;
				i=X[1]; j=Y[1];
				x=X[0]; y=Y[0];
				f=l;
				while(G[X[0]][Y[0]]>=1)
				{
					X[0]=rand()%23+2;
					Y[0]=rand()%73+2;
				}
				l=l+1;
				s=s+1;
			}
			else
				break;
		}
		else if(d==3)
		{
			if(Y[1]==1)
				Y[1]=76;
			if(G[X[1]][Y[1]-1]==0)
			{
				for(k=l;k>1;k--)
				{
					X[k]=X[k-1];
					Y[k]=Y[k-1];
				}
				Y[1]=Y[1]-1;
				i=X[1]; j=Y[1];
			}
			else if((X[1]==X[0])&&(Y[1]-1==Y[0]))
			{
				for(k=l+1;k>1;k--)
				{
					X[k]=X[k-1];
					Y[k]=Y[k-1];
				}
				Y[1]=Y[1]-1;
				i=X[1]; j=Y[1];
				x=X[0]; y=Y[0];
				f=l;
				while(G[X[0]][Y[0]]>=1)
				{
					X[0]=rand()%23+2;
					Y[0]=rand()%73+2;
				}
				l=l+1;
				s=s+1;
			}
			else
				break;
		}
		else if(d==4)
		{
			if(X[1]==25)
				X[1]=0;
			if(G[X[1]+1][Y[1]]==0)
			{
				for(k=l;k>1;k--)
				{
					X[k]=X[k-1];
					Y[k]=Y[k-1];
				}
				X[1]=X[1]+1;
				i=X[1]; j=Y[1];
			}
			else if((X[1]+1==X[0])&&(Y[1]==Y[0]))
			{
				for(k=l+1;k>1;k--)
				{
					X[k]=X[k-1];
					Y[k]=Y[k-1];
				}
				X[1]=X[1]+1;
				i=X[1]; j=Y[1];
				x=X[0]; y=Y[0];
				f=l;
				while(G[X[0]][Y[0]]>=1)
				{
					X[0]=rand()%23+2;
					Y[0]=rand()%73+2;
				}
				l=l+1;
				s=s+1;
			}
			else
				break;
		}
		if((GetAsyncKeyState(VK_RIGHT))&&(d!=3))
			d=1;
		else if((GetAsyncKeyState(VK_UP))&&(d!=4))
			d=2;
		else if((GetAsyncKeyState(VK_LEFT))&&(d!=1))
			d=3;
		else if((GetAsyncKeyState(VK_DOWN))&&(d!=2))
			d=4;	
		Sleep(18);	
		system("CLS");		
	}
	getchar();
}	

