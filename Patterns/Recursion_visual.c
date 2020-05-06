#include<graphics.h>
#include<math.h>

int main()
{
	int i,j,k,gd,gm;
	float O[21][161];
	char text[80];
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,NULL);
	setfillstyle(1,1);
	settextstyle(0,0,2);
	for(i=0;i<=160;i++)
		O[0][i]=i/20.0-4;
	delay(2000);
	for(i=0;i<20;i++)
	{
		setcolor(15);
		sprintf(text,"iteration : %d ",i+1);
		outtextxy(0,0,text);
		for(j=-4;j<=4;j++)
		{
			sprintf(text,"%d",j);
			outtextxy(168.75*j+675,580,text);
			for(k=0;k<=9;k++)
			{
				if(k%5==0)
					line(168.75*j+675+k*16.875,560,168.75*j+675+k*16.875,580);
				else
					line(168.75*j+675+k*16.875,560,168.75*j+675+k*16.875,570);	
			}
		}
		for(j=0;j<=160;j++)
		{
			O[i+1][j]=1+1/O[i][j];
			if(O[1][j]>=-4&&O[1][j]<=4)
			{
				setcolor(14);
				line((O[0][j]+4)*168.75,200,(O[1][j]+4)*168.75,550);
			}
			if(O[i+1][j]>=-4&&O[i+1][j]<=4)
			{
				setcolor(1);
				fillellipse((O[i][j]+4)*168.75,200,5,5);
				fillellipse((O[i+1][j]+4)*168.75,550,5,5);
			}
		}
		getch();
		cleardevice();
	}
	closegraph();
	return 0;
}
