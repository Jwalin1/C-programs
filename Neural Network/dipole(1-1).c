#include<conio.h>
#include<stdio.h>
#include<math.h>
#include <time.h>
#include <stdlib.h>

double S(double x)
{ return 1/(1+(exp(-x)));}

double d_S(double x)
{ return x*(1-x);}

int main()
{
	int n,i,j;
	double I[101],O[101],w,tmp;
	srand(time(NULL));
	w=(sqrt(-2.0*log((double)rand()/RAND_MAX)))*(cos(6.28318530718*(double)rand()/RAND_MAX));
	printf("Enter number of entries : ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("\nentry %d",i);
		printf("\nenter x : ");
		scanf("%lf",&I[i]);
		printf("enter y : ");
		scanf("%lf",&O[i]);
	}
	for(i=1;i<=100000;i++)
	{		
		for(j=1;j<=n;j++)
		{
			tmp=S(w*I[j]);
			tmp=(tmp-O[j])*(d_S(tmp));
			w=w-(I[j]*tmp);
		}
	}
	printf("\nw=%0.15lf",w);
	getch();
	return 0;
}
