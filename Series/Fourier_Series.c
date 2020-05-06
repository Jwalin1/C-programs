#include<graphics.h>
#include<math.h>
#define TAU 6.283185307

int main()
{
	int i,n,gd,gm;
	float x,y,t,c=5,f[100],r[100];
	printf("enter number of circles : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\ncircle %d\n",i+1);
		printf("freq = ");
		f[i]=2*(i+1)-1;
		printf("%f\n",f[i]);
		printf("radius = ");
		r[i]=100.0/f[i];
		printf("%f\n",r[i]);
	}
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,NULL);
	setfillstyle(1, 0);
	delay(2000);
	for(t=0;t<=c*TAU;t=t+0.001)
	{
		bar(0, 0, 700, 700);
		x=0; y=0;
		for(i=0;i<n;i++)
		{
			setcolor(1+(i%15));
			circle(x+350,-y+350,fabs(r[i]));
			x=x+r[i]*cos(f[i]*t);
			y=y+r[i]*sin(f[i]*t);
		}
		putpixel(x+350,-y+350,14);
		putpixel(700+t*20,-y+350,14);
	}
	getch();
	closegraph();
	return 0;
}
