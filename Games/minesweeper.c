#include<stdio.h>
#include <time.h>
#include<windows.h>
int G[24][30],Mx[668],My[668],l,b,m,f1=0,x=0,y=0,r=0;

void print()
{
	int i,j;
	if(r!=-1&&r!=m)
	{
		r=l*b;
		f1=0;
	}
	printf("mines:%d\n",m);
	for(j=0;j<b;j++)		// first dash
			printf(" -");
	for(i=0;i<l;i++)
	{
		printf("\n|");		//first bar
		for(j=0;j<b;j++)
		{
			if((G[i][j]==-1||G[i][j]==-2)&&(r==-1||r==m))
				printf("*");	
			else if(G[i][j]>=0)
			{
				if(G[i][j]>0)
					printf("%d",G[i][j]);
				else if(i==x&&j==y)
					printf(".");		
				else
					printf(" ");	
				if(r!=-1&&r!=m)
					r=r-1;
			}
			else if(G[i][j]==-2||G[i][j]==-3)
			{
				printf("?");
				f1=f1+1;
			}
			else if(i==x&&j==y)
				printf(".");		
			else
				printf(" ");
			if((j==b-1)||(G[i][j]!=0)||(G[i][j+1]!=0))		//next bar	
				printf("|");		
			else	
				printf(" ");		
		}
		printf("\n");
		for(j=0;j<b;j++)
		{
			if((i==l-1)||(G[i][j]!=0)||(G[i+1][j]!=0))	//bottom dash
				printf(" -");
			else
				printf("  ");		
		}		
	}
	printf("\n");
	if(r!=-1&&r!=m)
	{
		printf("x:%d y:%d ",x,y);
		printf("tiles:%d ",r);
		printf("marks:%d ",f1);
	}
}

void set()
{
	int i,j,f;		
	for(i=0;i<l;i++)
	{
		for(j=0;j<b;j++)
		{
			if(G[i][j]==0)
			{
				if(G[i+1][j]<=-1&&G[i+1][j]>=-2&&i+1!=l)
					G[i][j]=G[i][j]+1;
				if(G[i][j+1]<=-1&&G[i][j+1]>=-2&&j+1!=b)
					G[i][j]=G[i][j]+1;
				if(G[i-1][j]<=-1&&G[i-1][j]>=-2&&i-1!=-1)
					G[i][j]=G[i][j]+1;
				if(G[i][j-1]<=-1&&G[i][j-1]>=-2&&j-1!=-1)
					G[i][j]=G[i][j]+1;
				if(G[i+1][j+1]<=-1&&G[i+1][j+1]>=-2&&i+1!=l&&j+1!=b)
					G[i][j]=G[i][j]+1;
				if(G[i-1][j-1]<=-1&&G[i-1][j-1]>=-2&&i-1!=-1&&j-1!=-1)
					G[i][j]=G[i][j]+1;
				if(G[i+1][j-1]<=-1&&G[i+1][j-1]>=-2&&i+1!=l&&j-1!=-1)
					G[i][j]=G[i][j]+1;
				if(G[i-1][j+1]<=-1&&G[i-1][j+1]>=-2&&i-1!=-1&&j+1!=b)
					G[i][j]=G[i][j]+1;
				if(G[i][j]==0)
				{
					f=0;
					if(i+1!=l&&G[i+1][j]<=-3)
						{ G[i+1][j]=0; f=1; }
					if(j+1!=b&&G[i][j+1]<=-3)
						{ G[i][j+1]=0; f=1; }
					if(i-1!=-1&&G[i-1][j]<=-3)
						{ G[i-1][j]=0; f=1; }
					if(j-1!=-1&&G[i][j-1]<=-3)
						{ G[i][j-1]=0; f=1; }
					if(i+1!=l&&j+1!=b&&G[i+1][j+1]<=-3)	
						{ G[i+1][j+1]=0; f=1; }
					if(i-1!=-1&&j-1!=-1&&G[i-1][j-1]<=-3)	
						{ G[i-1][j-1]=0; f=1; }
					if(i+1!=l&&j-1!=-1&&G[i+1][j-1]<=-3)	
						{ G[i+1][j-1]=0; f=1; }
					if(i-1!=-1&&j+1!=b&&G[i-1][j+1]<=-3)	
						{ G[i-1][j+1]=0; f=1; }
					if(f==1)
					{
						j=b;
						i=-1;
					}	
				}					
			}
		}
	}
}

void main()
{
	int i,j,f=1;
	srand(time(NULL));
	printf("\tHow to play\n");
	printf("The rules in Minesweeper are simple:\n");
	printf(" -Uncover a mine, and the game ends.\n");
	printf(" -Uncover an empty square, and you keep playing.\n");
	printf(" -Uncover a number, and it tells you how many mines\n  lay hidden in the adjacent squares.\n");
	printf("\nControls\n");
	printf(" -Use arrow keys to move\n");
	printf(" -Enter : reveal tile\n");
	printf(" -Space : mark tile\n");
	printf(" -R     : reset marks\n");
	printf("\nChoose difficulty");
	printf("\n1) Beginner\n   10 mines\n   9x9 tile grid\n");
	printf("\n2) Intermediate\n   40 mines\n   16x16 tile grid\n");
	printf("\n3) Expert\n   99 mines\n   16x30 tile grid\n");
	printf("\n4) Custom\n");
	printf("\nEnter choice(1/2/3/4) : ");
	scanf("%d",&i);
	system("CLS");
	if(i==1)
	{
		l=9;
		b=9;
		m=10;
	}
	else if(i==2)
	{
		l=16;
		b=16;
		m=40;
	}
	else if(i==3)
	{
		l=16;
		b=30;
		m=99;
	}
	else if(i==4)
	{
		printf("Custom\n\n");
		printf("Height (9-24)   : ");
		scanf("%d",&l);
		printf("Width  (9-30)   : ");
		scanf("%d",&b);
		printf("Mines  (10-668) : ");
		scanf("%d",&m);
		if(l<9||l>24||b<9||b>24||m<10||m>668)
			exit(0);
	}
	else
		exit(0);
	while(GetAsyncKeyState(VK_RETURN));
	for(i=0;i<668;i++)
	{
		Mx[i]=0;
		My[i]=0;
	}
	for(i=0;i<m;i++)
	{
		Mx[i]=rand()%l;
		My[i]=rand()%b;
		for(j=0;j<i;j++)
		{
			if((Mx[i]==Mx[j])&&(My[i]==My[j]))
			{
				i=i-1;
				continue;
			}
		}
	}
	for(i=0;i<24;i++)
		for(j=0;j<30;j++)
			G[i][j]=-4;
	for(i=0;i<m;i++)
		G[Mx[i]][My[i]]=-1;	
	system("CLS");
	set();
	print();
	getch();
	system("CLS");
	while(1)
	{
		if(f==1)
		{
			set();
			print();
		}
		f=1;
		if(GetAsyncKeyState(VK_RIGHT))
			y=y+1;
		else if(GetAsyncKeyState(VK_UP))
			x=x-1;
		else if(GetAsyncKeyState(VK_LEFT))
			y=y-1;
		else if(GetAsyncKeyState(VK_DOWN))
			x=x+1;
		else if(GetAsyncKeyState(VK_RETURN))
		{
			for(i=0;i<m;i++)
			{
				if(Mx[i]==x&&My[i]==y)
					break;
			}
			if(i!=m)
			{
				r=-1;
				break;
			}
			else if(G[x][y]==-4)
				G[x][y]=0;
		}
		else if(GetAsyncKeyState(VK_SPACE))
		{
			if(G[x][y]==-4)
				G[x][y]=-3;
			else if(G[x][y]==-3)
				G[x][y]=-4;	
			else if(G[x][y]==-2)
				G[x][y]=-1;		
			else if(G[x][y]==-1)
				G[x][y]=-2;		
		}
		else if(GetAsyncKeyState(0x52))
		{
			for(i=0;i<l;i++)
			{
				for(j=0;j<b;j++)
				{
					if(G[i][j]==-3)
						G[i][j]=-4;	
					else if(G[i][j]==-2)
						G[i][j]=-1;	
				}
			}
		}
		else
			f=0;
		if(x==l)
			x=0;
		if(y==b)
			y=0;
		if(x<0)
			x=l-1;
		if(y<0)
			y=b-1;
		if(r==m)
			break;
		if(f==1)
		{
			Sleep(100);					
			system("CLS");
		}					
	}
	Sleep(100);					
	system("CLS");
	print();
	if(r==m)
		printf("You win");
	else
		printf("You lose");	
	while(GetAsyncKeyState(VK_RETURN));
	while(!GetAsyncKeyState(VK_RETURN));
}	

