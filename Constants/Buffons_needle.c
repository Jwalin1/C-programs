#include<graphics.h>
#include<math.h>
#include<time.h>
#define TAU 6.283185307

int main()
{
	int i,x,y,x1,y1,s=0,gd,gm;
	float t;
	srand(time(NULL));
	//srand(20);
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,NULL);
	setcolor(4);
	delay(2000);
	for(i=0;i<10;i++)
		line(0,i*80,1400,i*80);
	for(i=0;i<710;i++)
	{
		x=rand()%1340;
		y=40+rand()%640;
		t=(TAU/2)*rand()/RAND_MAX-(TAU/4);
		x1=x+(20*cos(t));
		y1=y+(20*sin(t));
		setcolor(1);
		if(int(y1/80)!=int(y/80))
		{
			s=s+1;
			setcolor(14);
		}
		line(x,y,x1,y1);
		Sleep(10);	
	}
	printf("\ntotal/overlapping = %d/%d = %.7f\n",i,s,float(i)/s);	
	getch();
	closegraph();
	return 0;
}
