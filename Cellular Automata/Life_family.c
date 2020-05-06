#include<stdio.h>
#include <time.h>
#include<windows.h>
int G[26][76],G1[26][76],B[10],S[10],s=100,pr;

void print()
{
	int i,j;
	printf("Life family : B");
	for(i=1;B[i]!=9&&i<=9;i++)
		printf("%d",B[i]);
	printf("/S");
	for(i=1;S[i]!=9&&i<=9;i++)
		printf("%d",S[i]);	
	printf("\n");	
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
	if(pr>0)
		printf("\nseed probabilty : 1/%d",pr);	
	else
		printf("\nseed probabilty : %d/%d",(pr*-1)-1,(pr*-1));	
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
	int i,j,k;
	for(i=1;i<=25;i++)
	{
		for(j=1;j<=75;j++)
		{
			if(G[i][j]==1)
			{
				G[i][j]=0;
				for(k=1;k<=9;k++)
				{
					if(G1[i][j]==S[k])
						G[i][j]=1;
				}
			}
			else
			{
				for(k=1;k<=9;k++)
				{
					if(G1[i][j]==B[k])
						G[i][j]=1;
				}
			}	
		}
	}
}

void main()
{
	int i,j;
	srand(time(NULL));
	B[0]=0;
	S[0]=0;
	for(i=1;i<=9;i++)
	{
		B[i]=9;
		S[i]=9;
	}
	printf("\t\t\t\tLife family\n");
	printf("enter conditions, 9 to stop\n\n");
	printf("Birth :\n");
	for(i=1;B[i-1]!=9&&i<=9;i++)
	{
		scanf("%d",&B[i]);
	}
	printf("\nSurvival :\n");
	for(i=1;S[i-1]!=9&&i<=9;i++)
	{
		scanf("%d",&S[i]);
	}
	printf("\nprobabilty of initial random life : 1/");
	scanf("%d",&pr);	
	label1:
	system("CLS");
	for(i=1;i<=25;i++)
	{
		for(j=1;j<=75;j++)
		{
			if(pr>0)
			{
				if(rand()%pr==1)
					G[i][j]=1;
				else
					G[i][j]=0;
			}
			else
			{
				if(rand()%(pr*-1)==1)
					G[i][j]=0;
				else
					G[i][j]=1;
			}
		}
	}
	count();
	print();
	while(1)
	{
		if((GetAsyncKeyState(VK_UP))&&(pr+1<=100))
		{
			pr=pr+1;
			if(pr==-1)
				pr=2;
			if(s==100)
			{
				system("CLS");
				print();
			}
		}
		else if((GetAsyncKeyState(VK_DOWN))&&(pr-1>=-100))
		{
			pr=pr-1;
			if(pr==1)
				pr=-2;
			if(s==100)
			{
				system("CLS");
				print();
			}
		}
		else if((GetAsyncKeyState(VK_RIGHT))&&(s-10>=0))
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

