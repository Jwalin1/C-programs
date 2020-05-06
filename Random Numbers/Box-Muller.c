#include<graphics.h>
#include<math.h>
#define TAU (8*atan(1))

int main()
{
	int i,j,tmp,F[2048],gd,gm,n=10000000;
	float max=0,mu=0.5,sigma=0.17,r;
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,NULL);
	delay(2000);
	for(i=1;i<=15;i++)
	{
		for(j=0;j<2048;j++)
			F[j]=0;
		sigma=i/75.0;	
		setcolor(i);
		for(j=0;j<n;j++)
		{
			r=sqrt(-2*log(rand()/(RAND_MAX+1.0)))*cos(TAU*rand()/(RAND_MAX+1.0));
			r=r*sigma+mu;
			if(r>=0&&r<1)
			{
				tmp=2048*r;
				F[tmp]++;
				if(F[tmp]>max)
					max=F[tmp];
			}
		}
		r=1365/2048.0;
		for(j=0;j<2048;j++)
			line(j*r,700,j*r,-600*F[j]/max+700);
	}
	getch();
	closegraph();
	return 0;	
}
