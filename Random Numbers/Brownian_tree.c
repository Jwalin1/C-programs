#include<graphics.h>
#include<time.h>
#include<math.h>

int main()
{
	int d,gd,gm,x,y,xf=710,yf=360;
	float s,t;
	srand(time(NULL));
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,NULL);
	putpixel(700,350,1);
	delay(2000);
	while(1)
	{
		s=sqrt(((700-xf)*(700-xf))+((350-yf)*(350-yf)));
		t=6.28*rand()/RAND_MAX;
		x=700+(s*cos(t));
		y=350+(s*sin(t));
		while(1)
		{
			d=rand()%4;
			if(d==0&&y>350-s)
			{
				if(getpixel(x,y-1)!=0)
					break;
				y=y-1;	
			}
			else if(d==1&&x<700+s)
			{
				if(getpixel(x+1,y)!=0)
					break;
				x=x+1;	
			}
			else if(d==2&&y<350+s)
			{
				if(getpixel(x,y+1)!=0)
					break;
				y=y+1;	
			}
			else if(d==3&&x>700-s)
			{
				if(getpixel(x-1,y)!=0)
					break;
				x=x-1;	
			}
		}
		putpixel(x,y,1);
		if(((700-x)*(700-x))+((350-y)*(350-y))>s*s)
		{
			xf=x;
			yf=y;
		}
	}
	getch();
	closegraph();
	return 0;
}
