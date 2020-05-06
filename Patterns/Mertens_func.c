#include<graphics.h>
#include<math.h>

bool isPrime(int n)
{
	int i;
	
	if(n<2)
		return false;
		
	for(i=2; i*i<=n; i++)
		if(n%i==0)
			return false;
			
	return true;		
}

int Mobius(int N)
{
	int i,p=1;
	
	for(i=1; i<=N; i++)
	{
		if(N%i==0 && isPrime(i))
		{
			if(N%(i*i) == 0)
				return 0;
			else
				p *= -1;	
		}
	}
	return p;
}

int main()
{
	int i,min=0,max=0,sum=0,gd,gm;
	char text[80];
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,NULL);
	setlinestyle(0,1,3);
	settextstyle(0,0,2);
	delay(2000);
	
	for(i=1; i<=100000; i++)
	{
		sum += Mobius(i);
		if(sum > max)
			max=sum;
		else if(sum < min)
			min=sum;
			
		sprintf(text,"M(%d)=%d ",i,sum);
		outtextxy(0,0,text);
		sprintf(text,"min=%d max=%d",min,max);
		outtextxy(0,20,text);
		sprintf(text,"sqrt(%d)=%.3f ",i,sqrt(i));
		outtextxy(0,40,text);
		
		putpixel(i/75,350-sum,14);
		putpixel(i/75,350-sqrt(i),1);
		putpixel(i/75,350+sqrt(i),1);
		line(0,350,1400,350);
	}
	getch();
	return 0;
}
