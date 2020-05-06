#include <graphics.h>
#include <math.h>

int main()
{
    int i,n,gd,gm,x,y,s,R[8]; 
    printf("Wolfram code [0-255] : ");
	scanf("%d",&n);
	for(i=0;i<8;i++)
	{
		R[i]=n%2;
		n=n/2;
	}
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,NULL);
	delay(2000);
	putpixel(685,0,1);
	for(y=1;y<=700;y++)
	{
		for(x=10;x<=1360;x++)
		{
			s=0;
			for(i=-1;i<=1;i++)	
				s=s+getpixel(x+i,y-1)*pow(2,1-i);
			putpixel(x,y,R[s]);			
		}
	}
	getch();
    closegraph();
    return 0;
}
