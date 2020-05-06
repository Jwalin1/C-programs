#include<graphics.h>
#include<math.h>
 
int main()
{
    int i,n=12,gd,gm;
    double x,delx=0.008,y1,y2,s=0;
    char text[80];
    detectgraph(&gd,&gm);
    initgraph(&gd,&gm,NULL);
    settextstyle(0,0,3);
    delay(2000);
    for(x=1;x<=n;x=x+delx)
    {
    	i=x*1350.0/(n-1)-1350.0/(n-1);
    	y1=1/x;
    	y2=1/floor(x);
    	setcolor(14);
    	line(i,y2*-600+650,i,650);
    	setcolor(1);
    	line(i,y1*-600+650,i,650);
    	if(x==1||x+delx>n)
			s=s+(-y1+y2);
		else
			s=s+2*(-y1+y2);		
		//Sleep(10);
	}
	s=s*delx/2;
	setcolor(14);
	sprintf(text,"gamma = %f",s);
	outtextxy(550,200,text);
	getch();
	closegraph();
    return 0;
}
