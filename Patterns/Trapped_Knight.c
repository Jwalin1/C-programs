#include<graphics.h>

void Tline(int x, int y, int x1, int y1)
{ line(300+10*y,10*x,300+10*y1,10*x1); }

int main()
{
	int i,j,x,y,s,gd,gm;
	int v=2,d=1,G[70][70],V[2100],M[8][2];
	char text[80];
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,NULL);
	settextstyle(0,0,3);
	delay(2000);
	
	//initialise
	for(i=0;i<70;i++)
		for(j=0;j<70;j++)
			G[i][j]=0;
			
	G[35][35]=1;
	i=35; j=36;
	
	//number spiral
	while(i>0&&i<70&&j>0&&j<70)
	{
		G[i][j]=v;
		if(d==0)
		{
			if(G[i-1][j]==0)
				d=(d+1)%4;
			else
			{
				j++;
				v++;
			}	
		}
		else if(d==1)
		{
			if(G[i][j-1]==0)
				d=(d+1)%4;
			else
			{
				i--;
				v++;
			}	
		}
		else if(d==2)
		{
			if(G[i+1][j]==0)
				d=(d+1)%4;
			else
			{
				j--;
				v++;
			}	
		}
		else if(d==3)
		{
			if(G[i][j+1]==0)
				d=(d+1)%4;
			else
			{
				i++;
				v++;
			}	
		}
	}
	
	//Knight path
	x=35; y=35; d=1;
	V[0]=1;
	
	for(s=2;;s++)
	{
		//moves
		M[0][0]=G[x-1][y+2];
		M[1][0]=G[x-2][y+1];
		M[2][0]=G[x-2][y-1];
		M[3][0]=G[x-1][y-2];
		M[4][0]=G[x+1][y-2];
		M[5][0]=G[x+2][y-1];
		M[6][0]=G[x+2][y+1];
		M[7][0]=G[x+1][y+2];
		
		for(i=0;i<8;i++)
			M[i][1]=i;
			
		//sort
		for(i=0;i<7;i++)
		{
			if(M[i][0]>M[i+1][0])
			{
				for(j=0;j<2;j++)
				{
					v=M[i][j];
					M[i][j]=M[i+1][j];
					M[i+1][j]=v;
				}
				i=-1;
			}
		}
		
		//choice
		for(i=0;i<8;i++)
		{
			for(j=0;j<d;j++)
				if(M[i][0]==V[j])
					break;
			if(j==d)
			{
				V[d]=M[i][0];
				d++;
				break;
			}		
		}
		if(i==8)
			break;
			
		//update position
		if(s>1800)
			setcolor(14);
		else if(s>1300)	
			setcolor(4);
		else if(s>800)	
			setcolor(2);
		else
			setcolor(1);
		if(M[i][1]==0)
		{
			Tline(x,y,x-1,y+2);
			x=x-1; y=y+2;
		}
		else if(M[i][1]==1)
		{
			Tline(x,y,x-2,y+1);
			x=x-2; y=y+1;
		}
		else if(M[i][1]==2)
		{
			Tline(x,y,x-2,y-1);
			x=x-2; y=y-1;
		}
		else if(M[i][1]==3)
		{
			Tline(x,y,x-1,y-2);
			x=x-1; y=y-2;
		}
		else if(M[i][1]==4)
		{
			Tline(x,y,x+1,y-2);
			x=x+1; y=y-2;
		}
		else if(M[i][1]==5)
		{
			Tline(x,y,x+2,y-1);
			x=x+2; y=y-1;
		}
		else if(M[i][1]==6)
		{
			Tline(x,y,x+2,y+1);
			x=x+2; y=y+1;
		}
		else if(M[i][1]==7)
		{
			Tline(x,y,x+1,y+2);
			x=x+1; y=y+2;
		}
		printf("%d\n",V[d-1]);
		sprintf(text,"steps=%d number=%04d",s,V[d-1]);
		outtextxy(0,0,text);
		Sleep(50);
	}
	getch();
	closegraph();
	return 0;
}
