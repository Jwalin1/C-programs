#include<graphics.h>
#include<math.h>

int main()
{
  int i,j,c,n=500,gd,gm;
  double f,p,K=2.685452001;
  char text[80];
  detectgraph(&gd,&gm);
  initgraph(&gd,&gm,NULL);
  settextstyle(0,0,3);
  line(0,-700*K+2240,1350,-700*K+2240);
  setcolor(14);
  delay(2000);
  for(i=1;i<=n;i++)
  {
  	f=8*atan(1)-6;
  	p=1;
	for(j=1;j<=i;j++)
	{
		f=1/f;
  		c=f;
  		p=p*pow(c,1.0/i);
  		f=f-c;
	}
	putpixel(i*1350.0/n,-700*p+2240,14);
	sprintf(text,"%lf",p);
  	outtextxy(800,100,text);
  	Sleep(50);
  }
  getch();
  closegraph();
  return 0;
}
