#include<graphics.h>

int main()
{
	int i,d=3,gd,gm,x=600,y=320,s=10;
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,NULL);
	delay(2000);
	for(i=0;i<11000;i++)
	{
		if(getpixel(x,y)==0)
		{
			d=(d+1)%4;
			setfillstyle(1,4);
		}
		else if(getpixel(x,y)==4)
		{
			d=(d+3)%4;
			setfillstyle(1,0);
		}
		bar(x-s/2,y-s/2,x+s/2,y+s/2);
		if(d==0)
			y=y-s;
		else if(d==1)
			x=x+s;
		else if(d==2)
			y=y+s;
		else if(d==3)
			x=x-s;
		if(i%10==0)
			delay(1);				
	}
	getch();
	closegraph();
	return 0;
}
