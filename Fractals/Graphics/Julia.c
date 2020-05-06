#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<graphics.h>

int main()
{
    int i,A,B,P,Q,s,s1=0,s2,gd,gm;
    double p,q,a,b,x=0,y=0,t=0,n=200,N=5,acc=100,r1,r2;
    char text[80];
    srand(time(NULL));
    detectgraph(&gd,&gm);
    initgraph(&gd,&gm,NULL);
    N=N*n;
    r1=(4.0*rand()/RAND_MAX)-2.0;
    r2=(2.0*rand()/RAND_MAX)-1.0;
    while (1)
    {
        if(r2<0)
            sprintf(text,"Julia Set for %lf%lfi",r1,r2);
        else 
			sprintf(text,"Julia Set for %lf+%lfi",r1,r2);
		outtextxy(0, 10, text);	
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
                        for (i=1; i<=acc; i++)
                        {
                            t=x;
                            x=((x*x)-(y*y))+r1;
                            y=(2*t*y)+r2;
                            if (((x*x)+(y*y))>4) break;
                        }
                        if (((x*x)+(y*y))<=4)
                        {
                        	s=s+1;
							s2=s2+i;
						}
                    }
                }
                if (GetAsyncKeyState(VK_RETURN)||GetAsyncKeyState(VK_UP)||GetAsyncKeyState(VK_DOWN)||GetAsyncKeyState(VK_LEFT)||GetAsyncKeyState(VK_RIGHT))
					goto label1;
				s2=15*s2/(acc*(N*N)/(n*n));	
                if (s>1)
				{
					putpixel(A,B,15-(s2%15));
					s1=s1+1;
				}
                s=0;
                s2=0;
            }
        }
        if (s1>=10) 
        {
            while (!GetAsyncKeyState(VK_RETURN)&&!GetAsyncKeyState(VK_UP)&&!GetAsyncKeyState(VK_DOWN)&&!GetAsyncKeyState(VK_LEFT)&&!GetAsyncKeyState(VK_RIGHT)){delay(10);}
            label1:
            if(GetAsyncKeyState(VK_RETURN))
            {
           		while (GetAsyncKeyState(VK_RETURN)){}
				r1=(4.0*rand()/RAND_MAX)-2.0;
    			r2=(2.0*rand()/RAND_MAX)-1.0;
			}
			else if(GetAsyncKeyState(VK_UP))
				r2=r2+0.0001;
			else if(GetAsyncKeyState(VK_DOWN))
    			r2=r2-0.0001;
			else if(GetAsyncKeyState(VK_LEFT))
				r1=r1-0.0001;
			else if(GetAsyncKeyState(VK_RIGHT))
				r1=r1+0.0001;
        }
        else
        {
        	r1=(4.0*rand()/RAND_MAX)-2.0;
    		r2=(2.0*rand()/RAND_MAX)-1.0;
		}
        s1=0;
        cleardevice();
    }
    return 0;
}
