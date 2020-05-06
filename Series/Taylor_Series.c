#include<graphics.h>
#include<math.h>

float fact(int n)
{
	if(n==0)
		return 1;
	return n*fact(n-1);	
}

int main()
{
	int i,j,n=20,c,gd,gm;
	float x,y;
	char text[80];
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,NULL);
	settextstyle(0,0,5);
	delay(2000);
	for(i=1;i<=n;i++)
	{
		cleardevice();
		c=2+(i%12);
		setcolor(c);
		sprintf(text,"n=%d",i);
		outtextxy(0,0,text);
		setcolor(1);
		line(700,0,700,700);
		line(0,350,1400,350);
		for(x=-20;x<=20;x=x+0.01)
		{
			y=exp(x);
			putpixel(x*35+700,y*-35+350,14);
			y=0;	//summing the series
			for(j=0;j<i;j++)
				y=y+pow(x,j)/fact(j);
			putpixel(x*35+700,y*-35+350,c);	
		}
		Sleep(1000);
	}
	getch();
	closegraph();
	return 0;
}
