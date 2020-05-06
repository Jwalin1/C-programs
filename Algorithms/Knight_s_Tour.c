#include<graphics.h>

int n,x,y,s,M[1000000],G[1000][1000];

void Tline(float x, float y, float x1, float y1)
{ line(100+(580.0/n)*x,80+(580.0/n)*y,100+(580.0/n)*x1,80+(580.0/n)*y1); }

void jump(int d)
{
	if(M[s]==0)
	{
		x = x - 1*d;
		y = y + 2*d;
	}
	else if(M[s]==1)
	{
		x = x - 2*d;
		y = y + 1*d;
	}
	else if(M[s]==2)
	{
		x = x - 2*d;
		y = y - 1*d;
	}
	else if(M[s]==3)
	{
		x = x - 1*d;
		y = y - 2*d;
	}
	else if(M[s]==4)
	{
		x = x + 1*d;
		y = y - 2*d;
	}
	else if(M[s]==5)
	{
		x = x + 2*d;
		y = y - 1*d;
	}
	else if(M[s]==6)
	{
		x = x + 2*d;
		y = y + 1*d;
	}
	else if(M[s]==7)
	{
		x = x + 1*d;
		y = y + 2*d;
	}
}

int count()
{
	int count=0;
	if((x-1)>=0 && (y+2)<n && G[x-1][y+2]==-1)
		count++;
	if((x-2)>=0 && (y+1)<n && G[x-2][y+1]==-1)
		count++;
	if((x-2)>=0 && (y-1)>=0 && G[x-2][y-1]==-1)
		count++;
	if((x-1)>=0 && (y-2)>=0 && G[x-1][y-2]==-1)
		count++;
	if((x+1)<n && (y-2)>=0 && G[x+1][y-2]==-1)
		count++;
	if((x+2)<n && (y-1)>=0 && G[x+2][y-1]==-1)
		count++;
	if((x+2)<n && (y+1)<n && G[x+2][y+1]==-1)
		count++;
	if((x+1)<n && (y+2)<n && G[x+1][y+2]==-1)
		count++;
	return count;	
}

int main()
{
	int x1,y1,c,d,min=8,dist,min_dist,gd,gm;
	
	printf("enter size of board : ");
	scanf("%d",&n);
	
	//initialise
	for(x=0;x<n;x++)
		for(y=0;y<n;y++)
			G[x][y] = -1;
			
	//initial position
	printf("enter starting position (0-%d)\n",n-1);
	printf("row : ");
	scanf("%d",&x);
	printf("col : ");
	scanf("%d",&y);
	
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,NULL);
	
	//print grid
	setcolor(1);
	for(s=0;s<n+1;s++)
	{
		Tline(s-0.5,-0.5,s-0.5,n-0.5);
		Tline(-0.5,s-0.5,n-0.5,s-0.5);
	}
	
	x1=x; y1=y;
	setcolor(14);
	delay(2000);
	
	//Knight's tour
	for(s=0;;s++)
	{
		G[x][y]=s;
		min=8;
		d=0;
		for(M[s]=0;M[s]<8;M[s]++)
		{
			jump(1);
			if(x>=0&&x<n && y>=0&&y<n && G[x][y]==-1)
			{
				c=count();
				dist=(x-n/2)*(x-n/2)+(y-n/2)*(y-n/2);
				if(c<min || (c==min&&dist>min_dist))
				{
					min=count();
					d=M[s];
					min_dist=dist;
				}
			}
			jump(-1);	
		}
		
		if(min==8)
			break;
		
		M[s]=d;
		jump(1);
		Tline(y,x,y1,x1);
		x1=x; y1=y;
		Sleep(800/n);
	}
	
	if(s+1==n*n)
		printf("\nsolution found");
	else
		printf("\nstuck");
	
	getch();
	closegraph();
	return 0;
}
