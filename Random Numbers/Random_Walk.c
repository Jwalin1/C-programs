#include<graphics.h>
#include<time.h>

int main()
{
    int i,d,gd,gm,x=700,y=350,c=1;
    srand(time(NULL));
    detectgraph(&gd,&gm);
    initgraph(&gd,&gm,NULL);
    delay(2000);
    for(i=1;i<=50000;i++)
    {
        putpixel(x,y,c);
        d=rand()%4;
        if(d==0)
            y=y-1;
        else if(d==1)
            x=x+1;
        else if(d==2)
            y=y+1;
        else if(d==3)
            x=x-1;
        if(i%100==0)
            delay(1);
        if(i%500==0)
            c=1+c%14;                   
    }
    getch();
    closegraph();
    return 0;
}
