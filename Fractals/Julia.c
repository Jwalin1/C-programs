#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int i,A,B,P,Q,s1=0;
    double s,p,q,a,b,x=0,y=0,t=0,n=20,N=5,r1,r2;
    srand(time(NULL));
    N=N*n;
    while (1)
    {
        r1=rand()%2000;
        r2=rand()%1000;
        r1=r1/1000;
        r2=r2/1000;
        if (((rand()%2)==1)||r1>1) r1=-r1;
        if ((rand()%2)==1)
        {
            r2=-r2;
            printf("Julia Set for %lf%lfi\n",r1,r2);
        }
        else printf("Julia Set for %lf+%lfi\n",r1,r2);
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
                        x=p;
                        y=q;
                        for (i=1; i<=1000; i++)
                        {
                            t=x;
                            x=((x*x)-(y*y))+r1;
                            y=(2*t*y)+r2;
                            if (((x*x)+(y*y))>4) break;
                        }
                        if (((x*x)+(y*y))<=4) s=s+1;
                    }
                }
                if (s>1) s1=s1+1;
                if (s==((N*N)/(n*n)))printf("o");
                else if (s>=((N*N)/(n*n)/2))printf("x");
                else if (s>=((N*N)/(n*n)/4))printf("+");
                else if (s>=((N*N)/(n*n)/8))printf("-");
                else if (s>=1)printf(".");
                else {
                    printf(" ");
                }
                s=0;
            }
            printf("\n");
        }
        if (s1>=10) {
            s1=0;
            getch();
        }
        system("CLS");
    }
    return 0;
}
