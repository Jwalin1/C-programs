#include<conio.h>
#include <graphics.h>

int main()
{
    int i,A,B,P,Q,s,gd,gm;
    double p,q,a,b,x,y,t,n=200,N=20,acc=200;
    detectgraph(&gd,&gm);
    initgraph(&gd,&gm,NULL);
    N=N*n;
    for (B=0; B<=(4*n); B++)
    {
        b=2-(B/n);
        for (A=0; A<=(4*n); A++)
        {
            a=-2+(A/n);
            for (Q=(-N/(2*n)); Q<(N/(2*n)); Q++)
            {
                q=b-(Q/N);
                for (P=(-N/(2*n)); P<(N/(2*n)); P++)
                {
                    p=a+(P/N);
                    x=0;
                    y=0;
                    for (i=1; i<=acc; i++)
                    {
                        t=x;
                        x=((x*x)-(y*y))+p;
                        y=(2*t*y)+q;
                        if (((x*x)+(y*y))>4) break;
                    }
                    if (((x*x)+(y*y))<=4) s=s+1;
                }
            }
            if (s>1)
				putpixel(A,B,1);
            s=0;
        }
        printf("\n");
    }
    getch();
    closegraph();
    return 0;
}
