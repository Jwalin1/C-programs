#include<graphics.h>
#include<math.h>

int main()
{
	int gd,gm;
	float x=1,y=0,r=300,a,t;
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,NULL);
	circle(700,350,r);
	setcolor(1);
	line(700,350,700+x*300,350+y*300);
	while(1)
	{
		getch();
		printf("rotate by : ");
		scanf("%f",&a);
		a=a*3.1415926/180;
		setcolor(0);
		line(700,350,700+x*300,350+y*300);
		//complex multiplication
		t=x*cos(a)-y*sin(a);	//real part
		y=x*sin(a)+y*cos(a);	//imaginary part
		x=t;
		setcolor(1);
		line(700,350,700+x*300,350+y*300);
	}
	getch();
	closegraph();
	return 0;	
}
