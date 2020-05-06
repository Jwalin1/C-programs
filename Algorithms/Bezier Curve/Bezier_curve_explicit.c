#include<graphics.h>
#include<math.h>

int fact(int n)
{
	if(n==0)
		return 1;
	else
		return n*fact(n-1);	
}

int comb(int n, int r)
{ return (fact(n))/((fact(n-r))*(fact(r))); }

int main()
{
	int i,n,gd,gm;
	float t,x,y,px[10],py[10];
	printf("enter number of points : ");
	scanf("%d",&n);
	n=n-1;
	for(i=0;i<=n;i++)
	{
		printf("\nP%d\n",i);
		printf("x=");
		scanf("%f",&px[i]);
		printf("y=");
		scanf("%f",&py[i]);
	}
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,NULL);
	setcolor(15);
	for(i=0;i<=n;i++)
	{
		circle(px[i]*200,700+py[i]*-200,5);
		if(i!=n)
			line(px[i]*200,700+py[i]*-200,px[i+1]*200,700+py[i+1]*-200);
	}
	delay(2000);
	for(t=0;t<=1;t=t+0.000001)
	{
		x=0; y=0;
		for (i=0;i<=n;i++) 
		{
			x = x + (comb(n,i) * pow (1 - t, n - i) * pow (t, i) * px[i]);
			y = y + (comb(n,i) * pow (1 - t, n - i) * pow (t, i) * py[i]);
		}
		putpixel(x*200,700+y*-200,1);
	}
	getch();
	closegraph();
	return 0;	
}
