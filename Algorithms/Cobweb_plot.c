#include<graphics.h>
#include<math.h>

float logistic(float r,float x)
{
	return r*x*(1-x);
}

int main()
{
  
  int i,gd,gm;
  float x,y,x1,y1,r;
  char text[80];
  detectgraph(&gd,&gm);
  initgraph(&gd,&gm,NULL);	
  settextstyle(0, 0, 3);
  delay(2000);
  
  for(r=0;r<4.005;r=r+0.005)
  {
	cleardevice();
	setcolor(15);
	sprintf(text,"r = %.3f",r);
	outtextxy(0,0,text);
	sprintf(text,"y= r*x*(1-x)",r);
	outtextxy(0,30,text);
    for(x=0;x<=1;x=x+0.001)	//plot the function
    {
    	y=logistic(r,x);
		putpixel(200+700*x,700-700*y,14);
    }
	setcolor(1);
	line(200, 700, 900, 0);		//plot the diagonal
	setcolor(15);
  
	x=0.08; y=0;	//initialize
	for(i=0;i<50;i++)
	{
    	setcolor(2+i%14);
		y1=logistic(r,x);
		line(200+700*x, 700-700*y, 200+700*x, 700-700*y1);
		x1=y1;
		line(200+700*x1, 700-700*y1, 200+700*x, 700-700*y1);
		x=x1;	y=y1;
	}
	Sleep(50);
  }
  getch();
  return 0;
}
