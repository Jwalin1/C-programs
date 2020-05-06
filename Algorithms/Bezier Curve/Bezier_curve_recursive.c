#include<graphics.h>

int main()
{
	int i,j,n,gd,gm;
	float t,x[10][10],y[10][10],px[10],py[10];
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
		x[0][i]=px[i];
		y[0][i]=py[i];
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
	for(t=0;t<=1;t=t+0.001)
	{
		for (i=1;i<=n;i++) 
		{
			setcolor(1+(i%14));
			for(j=0;j<=n-i;j++)
			{
				x[i][j] = ((1-t) * x[i-1][j]) + (t * x[i-1][j+1]);
				y[i][j] = ((1-t) * y[i-1][j]) + (t * y[i-1][j+1]);
				if(i!=n&&j!=0)
					line(x[i][j-1]*200,700+y[i][j-1]*-200,x[i][j]*200,700+y[i][j]*-200);
			}
		}
		delay(1);
		setcolor(0);
		for (i=1;i<n;i++) 
			for(j=1;j<=n-i;j++)
				line(x[i][j-1]*200,700+y[i][j-1]*-200,x[i][j]*200,700+y[i][j]*-200);
		setcolor(15);
		for(i=0;i<=n;i++)
		{
			circle(px[i]*200,700+py[i]*-200,5);
			if(i!=n)
				line(px[i]*200,700+py[i]*-200,px[i+1]*200,700+py[i+1]*-200);
		}
		setcolor(1);
		circle(x[n][0]*200,700+y[n][0]*-200,3);
	}
	getch();
	closegraph();
	return 0;	
}
