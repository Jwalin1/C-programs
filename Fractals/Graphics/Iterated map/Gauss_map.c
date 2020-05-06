#include<graphics.h>
#include<math.h>

int main()
{
	int i,j,gd,gm;
	float x,a=4.9,b;
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,NULL);
	delay(2000);
	for(i=-600;i<=600;i++)
	{
		b=i/600.0;
		x=0;
		for(j=0;j<1000;j++)
			x=exp(-a*x*x)+b;
		for(j=0;j<600;j++)
		{
			x=exp(-a*x*x)+b;
			putpixel(i+600,(x*-300)+500,14);
		}
		delay(1);	
	}
	getch();
	closegraph();
	return 0;
}


