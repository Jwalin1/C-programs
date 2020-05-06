#include <graphics.h>

int main()
{
    int i,d,gd,gm;
    float x=0,y=0,t;
	detectgraph(&gd,&gm);
    initgraph(&gd,&gm,NULL);
    delay(2000);
    for(i=0;i<1000000;i++)
    {
    	d=rand()%100;
		if(d>14)
   	 	{
   	 		t=(0.85*x)+(0.04*y);
   	 		y=(-0.04*x)+(0.85*y)+1.6;
   	 		x=t;
		}
		else if(d>8)
	   	{
   		 	t=(0.2*x)-(0.26*y);
   	 		y=(0.23*x)+(0.22*y)+1.6;
   	 		x=t;
		}
		else if(d>1)
	   	{
   		 	t=(-0.15*x)+(0.28*y);
   	 		y=(0.26*x)+(0.24*y)+0.44;
   	 		x=t;
		}
		else
   		{
   	 		x=0;
   	 		y=0.16*y;
		}
		putpixel((x*60)+500,(y*-60)+650,2);
		if(i%100==0)
			delay(1);
	}
	getch();
    closegraph();
    return 0;
}
