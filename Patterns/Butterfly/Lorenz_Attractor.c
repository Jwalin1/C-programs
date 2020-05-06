#include<graphics.h>

int main()
{
	int gd,gm;
	float x=0.01,y,z,dx,dy,dz,dt=0.00002,t,a=10,b=28,c=8/3.0;
	char text[80];
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,NULL);
	settextstyle(0,0,5);
	setcolor(4);
	sprintf(text,"XY");
	outtextxy(155,50,text);
	setcolor(2);
	sprintf(text,"XZ");
	outtextxy(590,50,text);
	setcolor(1);
	sprintf(text,"YZ");
	outtextxy(1015,50,text);
	delay(2000);
	for(t=0;t<100;t=t+dt)
	{
		dx = a*(y-x)*dt;
		dy = (x*(b-z) - y)*dt;
		dz = (x*y - c*z)*dt;
		x = x + dx;
		y = y + dy;
		z = z + dz;
		
		putpixel(200+8*x,350-8*y,4);
		putpixel(625+8*x,525-8*z,2);
		putpixel(1050+8*y,525-8*z,1);
	}
	getch();
	closegraph();
	return 0;
}
