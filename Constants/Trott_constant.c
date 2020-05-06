#include<stdio.h>
#include<math.h>
#include<time.h>
int N=10,coeff[101];

void randomize()
{
	int i;
	for(i=1;i<N;i++)
		coeff[i]=rand()%10;
	coeff[N]=1+rand()%9;
}

double deci()
{
	int i;
	double s=0;
	for(i=0;i<=N;i++)
		s=s+coeff[i]/pow(10.0,i);
	return s;	
}

double cont_frac()
{
	int i;
	double s=coeff[N];
	for(i=N-1;i>=0;i--)
		s=coeff[i]+1/s;
	return s;	
}

void print()
{
	int i;
	for(i=0;i<=N;i++)
		printf("c[%d]=%d ",i,coeff[i]);
}

int main()
{
	int i;
	double d,c,diff,err=.1;
	srand(time(NULL));
	coeff[0]=0;
	while(1)
	{
		randomize();
		d=deci();
		c=cont_frac();
		diff=fabs(d-c);
		if(diff<err)
		{
			print();
			err=diff;
			printf("\ndeci = %.15lf",d);
			printf("\ncf   = %.15lf",c);
			printf("\nerr  = %.15f",err);
			printf("\nmatch = %d.5 +/- 0.5\n\n",(int)(-2-floor(log10(err))));
		}
	}
	getch();
	return 0;
}
