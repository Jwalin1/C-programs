#include <graphics.h>

int main()
{
    int i,gd,gm;
    float x=0,y=1,t;
	detectgraph(&gd,&gm);
    initgraph(&gd,&gm,NULL);
    delay(2000);
    for(i=0;i<1000000;i++)
    {
		if(rand()%2==0)
   		{
   	 		t=(x+y)/2;
   	 		y=(y-x)/2;
   	 		x=t;
		}
		else
   	 	{
   	 		t=(x-y+1)/2;
   	 		y=(x+y-1)/2;
   	 		x=t;
		}
		putpixel((x*300)+300,(y*-300)+300,4);
		if(i%200==0)
			delay(1);
	}
	getch();
    closegraph();
    return 0;
}
