#include<graphics.h>
#include<math.h>
#define TAU (8*atan(1))

xtrans(float x)
{ return 700+100*x; }

ytrans(float y)
{ return 420-100*y; }

int main()
{
	int gd,gm;
	float t,x=0,y=0;
	char text[80];
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,NULL);
	settextstyle(0,0,3);
	delay(2000);
	for(t=0;t<=12*TAU;t=t+0.0001)
	{
		x = sin(t) * (exp(cos(t)) - 2*cos(4*t) - pow(sin(t/12),5));
		y = cos(t) * (exp(cos(t)) - 2*cos(4*t) - pow(sin(t/12),5));
		putpixel(xtrans(x),ytrans(y),1);
		sprintf(text,"t=%.3f",t);
		outtextxy(0,0,text);
	}
	
	Sleep(1000);
	setfillstyle(1,15);
	floodfill(xtrans(0),ytrans(0.5),1);
	floodfill(xtrans(0.5),ytrans(0),1);
	floodfill(xtrans(-0.5),ytrans(0),1);
	
	Sleep(1000);
	setfillstyle(1,4);
	floodfill(xtrans(1),ytrans(1),1);
	floodfill(xtrans(-1),ytrans(1),1);
	floodfill(xtrans(1),ytrans(-1),1);
	floodfill(xtrans(-1),ytrans(-1),1);
	floodfill(xtrans(1.2),ytrans(0),1);
	floodfill(xtrans(-1.2),ytrans(0),1);
	floodfill(xtrans(0),ytrans(1.4),1);
	floodfill(xtrans(0.3),ytrans(1.4),1);
	floodfill(xtrans(-0.3),ytrans(1.4),1);
	
	Sleep(1000);
	setfillstyle(1,10);
	floodfill(xtrans(0),ytrans(1),1);
	
	Sleep(1000);
	setfillstyle(1,5);
	floodfill(xtrans(1.9),ytrans(0),1);
	floodfill(xtrans(-1.9),ytrans(0),1);
	
	Sleep(1000);
	setfillstyle(1,1);
	floodfill(xtrans(2.5),ytrans(3),1);
	floodfill(xtrans(-2.5),ytrans(3),1);
	floodfill(xtrans(1.5),ytrans(-1.5),1);
	floodfill(xtrans(-1.5),ytrans(-1.5),1);
	floodfill(xtrans(0),ytrans(1.5),1);
	floodfill(xtrans(0.1),ytrans(0.8),1);
	floodfill(xtrans(-0.1),ytrans(0.8),1);
	
	Sleep(1000);
	setfillstyle(1,15);
	floodfill(xtrans(3.1),ytrans(3.1),1);
	floodfill(xtrans(-3.1),ytrans(3.1),1);
	floodfill(xtrans(2),ytrans(-2.3),1);
	floodfill(xtrans(-2),ytrans(-2.3),1);
	floodfill(xtrans(0.3),ytrans(1),1);
	floodfill(xtrans(-0.3),ytrans(1),1);
	
	Sleep(1000);
	setfillstyle(1,14);
	floodfill(xtrans(3.5),ytrans(3.5),1);
	floodfill(xtrans(-3.5),ytrans(3.5),1);
	floodfill(xtrans(2.3),ytrans(-2.4),1);
	floodfill(xtrans(-2.3),ytrans(-2.4),1);
	floodfill(xtrans(0),ytrans(-0.1),1);
	floodfill(xtrans(0),ytrans(1.8),1);
	floodfill(xtrans(0.3),ytrans(1.3),1);
	floodfill(xtrans(-0.3),ytrans(1.3),1);
	
	Sleep(1000);
	setfillstyle(1,3);
	floodfill(xtrans(0),ytrans(2),1);
	
	Sleep(1000);
	setcolor(0);
	setfillstyle(1,0);
	fillellipse(xtrans(0.2),ytrans(2.2),7,7);
	fillellipse(xtrans(-0.2),ytrans(2.2),7,7);
	Sleep(1000);
	setcolor(14);
	setfillstyle(1,14);
	fillellipse(xtrans(0.2),ytrans(2.2),2,2);
	fillellipse(xtrans(-0.2),ytrans(2.2),2,2);
	Sleep(1000);
	setlinestyle(1,0,1);
	line(xtrans(0.15),ytrans(2.4),xtrans(0.5),ytrans(3.2));
	line(xtrans(-0.15),ytrans(2.4),xtrans(-0.5),ytrans(3.2));
	
	Sleep(1000);
	setcolor(15);
	for(;t>=0;t=t-0.0001)
	{
		x = sin(t) * (exp(cos(t)) - 2*cos(4*t) - pow(sin(t/12),5));
		y = cos(t) * (exp(cos(t)) - 2*cos(4*t) - pow(sin(t/12),5));
		putpixel(xtrans(x),ytrans(y),0);
		sprintf(text,"t=%.3f",t);
		outtextxy(0,0,text);
	}	
	
	getch();
	closegraph();
	return 0;
}
