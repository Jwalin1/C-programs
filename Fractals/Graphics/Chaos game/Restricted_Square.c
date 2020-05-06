#include<graphics.h>

int main()
{
    int i,d1,d2,d3,gd,gm,x,y;
    detectgraph(&gd,&gm);
    initgraph(&gd,&gm,NULL);
    delay(2000);
    x=325;
    y=325;
    for(i=0;i<1000000;i++)
    {
        d1=rand()%4;
		while((d1==(d2+1)%4||d2==(d1+1)%4)&&(d2==d3))
			d1=rand()%4;
        d3=d2;
        d2=d1;
        if(d1==0)
        {
            x=x/2;
            y=y/2;
        }
        else if(d1==1)
        {
            x=(x+650)/2;
            y=y/2;
        }
        else if(d1==2)
        {
            x=(x+650)/2;
            y=(y+650)/2;
        }
        else if(d1==3)
        {
            x=x/2;
            y=(y+650)/2;
        }
        putpixel(x+300,y+20,1+(d1+d2+d3)%4);
        if(i%200==0)
            delay(1);
    }
    getch();
    closegraph();
    return 0;
}
