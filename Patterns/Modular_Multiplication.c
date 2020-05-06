#include<graphics.h>
#include<math.h>
#define TAU 6.283185307

int main()
{
	int i,j,N=100,r=300,e,gd,gm;
	float m,s=0.025;
	char text[80];
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,NULL);
	settextstyle(0,0,3);
	delay(2000);
	e=N/s;
	for(i=0;i<=e;i++)
	{
		cleardevice();
		setcolor(15);
		circle(650,350,r);
		m=i*s;
		sprintf(text,"%.3f",m);
		outtextxy(0,0,text);
		for(j=0;j<N;j++)
		{
			setcolor(1+((float)j/N)*14);
			line(650-r*cos(j*TAU/N),350-r*sin(j*TAU/N),650-r*cos(j*m*TAU/N),350-r*sin(j*m*TAU/N));
		}
		Sleep(50);
	}
	getch();
	closegraph();
	return 0;
}
