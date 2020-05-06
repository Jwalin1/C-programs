#include<graphics.h>
#include<math.h>
#include<time.h>
#define TAU (8*atan(1))

int main()
{
	int i,gd,gm,x0=350,y0=350;
	srand(time(NULL));
	float x1,y1,a1=TAU/2,a1_v,a1_a,l1=100,m1=200;
	float x2,y2,a2=TAU*rand()/RAND_MAX,a2_v,a2_a,l2=50+50.0*rand()/RAND_MAX,m2=200+50.0*rand()/RAND_MAX;
	float g=0.0005;
	char text[80];
	printf("Pendulum 1\n");
	printf("angle = %f\n",a1);
	printf("length = %f\n",l1);
	printf("mass = %f\n",m1);
	printf("\nPendulum 2\n");
	printf("angle = %f\n",a2);
	printf("length = %f\n",l2);
	printf("mass = %f\n",m2);
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,NULL);
	settextstyle(0,0,3);
	delay(2000);
	for(i=0;i<100000;i++)
	{
		setcolor(4);
		setfillstyle(1,0);
		fillellipse(x0,y0,l1+l2+m2/20,l1+l2+m2/20);
		
		a1_a = (-g*(2*m1+m2)*sin(a1) - m2*g*sin(a1-2*a2) - 2*sin(a1-a2)*m2*(a2_v*a2_v*l2 + a1_v*a1_v*l1*cos(a1-a2))) / (l1*(2*m1 + m2 - m2*cos(2*a1-2*a2)));
		a2_a = 2*sin(a1-a2)*(a1_v*a1_v*l1*(m1+m2) + g*(m1+m2)*cos(a1) + a2_v*a2_v*l2*m2*cos(a1-a2)) / (l2*(2*m1 + m2 - m2*cos(2*a1-2*a2)));
		
		a1_v = a1_v + a1_a;
		a2_v = a2_v + a2_a;
		a1 = a1 + a1_v;
		a2 = a2 + a2_v;
		
		x1 = x0 + l1*sin(a1);
		y1 = y0 + l1*cos(a1);
		x2 = x1 + l2*sin(a2);
		y2 = y1 + l2*cos(a2);
	
		line(x0,y0,x1,y1);
		line(x1,y1,x2,y2);
		putpixel(x2+2*x0,y2,14);
		setfillstyle(1,1);
		fillellipse(x1,y1,m1/20,m1/20);
		fillellipse(x2,y2,m2/20,m2/20);
		setcolor(15);
		sprintf(text,"x2=%.0f y2=%.0f",x2,y2);
		outtextxy(200,y0-l1-l2-m2/20-50,text);
	}	
	getch();
	closegraph();
	return 0;	
}
