#include<conio.h>
#include<stdio.h>
#include<math.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
int n1;
double w[11];

double S(double x)
{ return 1/(1+(exp(-x)));}

double d_S(double x)
{ return x*(1-x);}

void test()
{
	int i;
	double s,I;
	printf("\nEnter test values\n");
	s=0;
	for(i=1;i<=n1;i++)
	{			
		printf("enter x[%d] : ",i);
		scanf("%lf",&I);
		s=s+(I*w[i]);
	}
	printf("Output : %0.15lf",S(s));
}

void print_weights()
{
	int i;
	for(i=1;i<=n1;i++)
	{
		printf("\nw[%d]=%0.15lf",i,w[i]);
	}
}

int main()
{
	int n,i,j,k;
	double I[101][11],O[101],l[101],s,err,alpha=1;
	srand(time(NULL));
	printf("Enter number of neurons in input layer : ");
	scanf("%d",&n1);
	printf("Enter number of entries : ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("\nentry %d\n",i);
		for(j=1;j<=n1;j++)
		{			
			printf("enter x[%d] : ",j);
			scanf("%lf",&I[i][j]);
		}
		printf("enter y : ");
		scanf("%lf",&O[i]);
	}
	label1:
	for(i=1;i<=n1;i++)
	{ w[i]=(sqrt(-2.0*log((double)rand()/RAND_MAX)))*(cos(6.28318530718*(double)rand()/RAND_MAX)); }
	label2:	
	for(i=1;;i++)
	{	
		err=0;
		for(j=1;j<=n;j++)
		{
			s=0;
			for(k=1;k<=n1;k++)
			{
				s=s+(I[j][k]*w[k]);
			}
			l[j]=S(s);
			err=err+fabs(l[j]-O[j]);
			l[j]=(l[j]-O[j])*(d_S(l[j]));
		}
		for(j=1;j<=n1;j++)
		{
			s=0;
			for(k=1;k<=n;k++)
			{
				s=s+(I[k][j]*l[k]); 
			}
			w[j]=w[j]-(alpha*s);
		}
		if(i==1000000){i=0; printf("\nerror : %.15lf",err);}
		if (GetAsyncKeyState(VK_ESCAPE)) {break;}
		if (GetAsyncKeyState(VK_UP)) {s=alpha*10; if(fabs(s)<11) {alpha=s;} Sleep(100);}
		else if (GetAsyncKeyState(VK_DOWN)) {s=alpha/10; if(fabs(s)>=pow(10,-15)) {alpha=s;} Sleep(100);}
	}
	printf("\n\n");
	i=0;
	while(i!=6)
	{
		printf("1) Test\n2) See weights\n3) Continue training\n4) Retrain\n5) Check learning rate \n6) Exit");
		printf("\nenter choice : ");
		scanf("%d",&i);
		if (GetAsyncKeyState(VK_UP)) {s=alpha*10; if(fabs(s)<11) {alpha=s;}}
		else if (GetAsyncKeyState(VK_DOWN)) {s=alpha/10; if(fabs(s)>=pow(10,-15)) {alpha=s;}}
		if(i==1){test();}
		else if(i==2){print_weights();}
		else if(i==3){goto label2;}
		else if(i==4){goto label1;}
		else if(i==5){printf("\nalpha=%0.15lf",alpha);}
		printf("\n\n");
	}
	getch();
	return 0;
}
