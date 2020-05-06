#include<graphics.h>
#include<math.h>

int main()
{
    int i,j,gd,gm;
    float u=0.92,x,y,tmp,t;
    detectgraph(&gd,&gm);
    initgraph(&gd,&gm,NULL);
    setbkcolor(15);
    cleardevice();
    delay(2000);
   	for(i=0;i<1000;i++)
    {
		x=(float)rand()/RAND_MAX;
    	y=(float)rand()/RAND_MAX;
		for(j=0;j<2000;j++)
    	{
       		t=0.4-(6/(1+(x*x)+(y*y)));
	   		tmp=1+u*((x*cos(t))-(y*sin(t)));
	   		y=u*((x*sin(t))+(y*cos(t)));
	   		x=tmp; 
	   		putpixel((x*50)+500,(y*-50)+540,0);
    	}
	}
    getch();
    closegraph();
    return 0;
}
