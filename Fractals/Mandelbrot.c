#include<stdio.h>
#include<conio.h>

int main()
{
    int i,A,B,P,Q;
    double s,p,q,a,b,x,y,t,n=20,N=30;
    N=N*n;
    printf ("The Mandelbrot Set\n");
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
                    for (i=1; i<=1000; i++)
                    {
                        t=x;
                        x=((x*x)-(y*y))+p;
                        y=(2*t*y)+q;
                        if (((x*x)+(y*y))>4) break;
                    }
                    if (((x*x)+(y*y))<=4) s=s+1;
                }
            }
            if (s==((N*N)/(n*n)))printf("o");
            else if (s>((N*N)/(n*n)/2))printf("x");
            else if (s>((N*N)/(n*n)/4))printf("+");
            else if (s>((N*N)/(n*n)/8))printf("-");
            else if (s>1)printf(".");
            else {
                printf(" ");
            }
            s=0;
        }
        printf("\n");
    }
    getch();
    return 0;
}
