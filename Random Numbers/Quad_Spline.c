#include<graphics.h>
#include<time.h>

int main()
{
    int i,j,n,steps=50000,gd,gm;
    float x,X[1000],Y[1000];
	float a[1000][3];
    printf("enter number of points : ");
    scanf("%d",&n);
    steps=50000;
    srand(time(NULL));
    
    detectgraph(&gd,&gm);
    initgraph(&gd,&gm,NULL);
    delay(2000);
	
	for(i=0;i<n;i++)
    {
    	X[i]=i/(n-1.0);
    	Y[i]=1.0*rand()/RAND_MAX;
    	printf("%f %f\n",X[i],Y[i]);
    	//putpixel(1350*X[i],705*(1.0-Y[i]),14);
    	
		setfillstyle(1,4);
		fillellipse(1350*X[i],705*(1.0-Y[i]),5,5);
	}
	
	for(i=0;i<n-2;i++)	//solving using Cramer's rule
    {
    	a[i][0] = (Y[i]*(X[i+1]-X[i+2])                    - X[i]*(Y[i+1]-Y[i+2])                             + Y[i+1]*X[i+2]-X[i+1]*Y[i+2])                      / (X[i]*X[i]*(X[i+1]-X[i+2]) - X[i]*(X[i+1]*X[i+1]-X[i+2]*X[i+2]) + X[i+1]*X[i+1]*X[i+2]- X[i+2]*X[i+2]*X[i+1]);
    	a[i][1] = (X[i]*X[i]*(Y[i+1]-Y[i+2])               - Y[i]*(X[i+1]*X[i+1]-X[i+2]*X[i+2])               + X[i+1]*X[i+1]*Y[i+2]-X[i+2]*X[i+2]*Y[i+1])        / (X[i]*X[i]*(X[i+1]-X[i+2]) - X[i]*(X[i+1]*X[i+1]-X[i+2]*X[i+2]) + X[i+1]*X[i+1]*X[i+2]- X[i+2]*X[i+2]*X[i+1]);
    	a[i][2] = (X[i]*X[i]*(X[i+1]*Y[i+2]-X[i+2]*Y[i+1]) - X[i]*(X[i+1]*X[i+1]*Y[i+2]-X[i+2]*X[i+2]*Y[i+1]) + Y[i]*(X[i+1]*X[i+1]*X[i+2]-X[i+2]*X[i+2]*X[i+1])) / (X[i]*X[i]*(X[i+1]-X[i+2]) - X[i]*(X[i+1]*X[i+1]-X[i+2]*X[i+2]) + X[i+1]*X[i+1]*X[i+2]- X[i+2]*X[i+2]*X[i+1]);
    	
    	//printf("%f %f %f\n",a[i][0],a[i][1],a[i][2]);
	}
		
	
	
	for(i=0;i<n-1;i++)
    {
    	
		if(i>n-3)	//last 2 points
		{
			for(j=0;j<steps;j++)
    		{
    			x=X[i]+(j/(steps-1.0))/(n-1.0);
				putpixel(1350*x,705*(1-(a[n-3][0]*x*x+a[n-3][1]*x+a[n-3][2])),14);
			}
		}
		else
		{
			for(j=0;j<steps;j++)
	    	{
   		 		x=X[i]+(j/(steps-1.0))/(n-1.0);
				putpixel(1350*x,705*(1-(a[i][0]*x*x+a[i][1]*x+a[i][2])),14);
			}
		}
		//Sleep(100);
	}
	
	getch();
	return 0;
}
