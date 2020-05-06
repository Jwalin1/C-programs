#include<graphics.h>
#include<math.h>
#define TAU 6.283185307

int main()
{
	int i,j,r=15,gd,gm;
	float x,y,d,a;
	char text[80];
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,NULL);
	setbkcolor(2);
	cleardevice();
	setcolor(0);
	settextstyle(0,0,5);
	setfillstyle(1,10);
	delay(2000);
	for(i=1;i<=6500;i++)
	{
		a=0; d=30;
		cleardevice();
		sprintf(text,"%f",i/6500.0);
		outtextxy(0,0,text);
		for(j=0;j<120;j++)
		{
			x=700+d*cos(TAU*a);
			y=350+d*sin(TAU*a);
			fillellipse(x,y,15,15);
			a=a+i/6500.0;
			d=d+2.5;
		}
		Sleep(30);
	}
	getch();
	closegraph();
	return 0;
}
