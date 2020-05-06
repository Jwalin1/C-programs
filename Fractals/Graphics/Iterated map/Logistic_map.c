#include <graphics.h>

int main()
{
    int i,j,gd,gm;
    float x,r;
	detectgraph(&gd,&gm);
    initgraph(&gd,&gm,NULL);
    delay(2000);
    for(i=0;i<=1200;i++)
    {
    	r=i/300.0;
    	x=0.5;
    	for(j=1;j<1000;j++)
			x=r*x*(1.0-x);
		for(j=0;j<300;j++)
		{
			x=r*x*(1.0-x);
			putpixel(i,(x*-300)+500,4);
		}
		if(i%10==1||i>850)
			delay(1);				
	}
	getch();
    closegraph();
    return 0;
}
