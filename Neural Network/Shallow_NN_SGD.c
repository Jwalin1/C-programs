#include<conio.h>
#include<stdio.h>
#include<math.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
int n,n1,n2;
double I[101][11],O[101],w1[11][11],w2[11];

double S(double x)
{ return 1/(1+exp(-x)); }

double d_S(double x)
{ return x*(1-x); }

void print_weights()
{
	int i,j;
	printf("\nInput layer-Hidden layer");
	for(i=1;i<=n1;i++)
	{
		printf("\nNeuron %d",i);
		for(j=1;j<=n2;j++)
		{
			printf("\nw[%d]=%0.15lf",j,w1[i][j]);
		}
	}
	printf("\nHidden layer-Output");
	for(i=1;i<=n2;i++)
	{
		printf("\nw[%d]=%0.15lf",i,w2[i]);
	}
}

void test()
{
	int i,j;
	double s,l[11],I[11];
	printf("\nEnter test values\n");
	for(i=1;i<=n1;i++)
	{			
		printf("enter x[%d] : ",i);
		scanf("%lf",&I[i]);
	}
	for(i=1;i<=n2;i++)	
	{
		s=0;
		for(j=1;j<=n1;j++)
		{
			s=s+(I[j]*w1[j][i]);	
		}
		l[i]=S(s);	
	}
	s=0;
	for(i=1;i<=n2;i++)	
	{
		s=s+(l[i]*w2[i]);		
	}
	printf("Output : %0.15lf",S(s));
}

void shuffle()
{
	int i,j,r1,r2;
	double tmp;
	for(i=1;i<=n;i++)
	{
		r1=(rand()%n)+1; r2=r1=(rand()%n)+1;
		for(j=1;j<=n1;j++)
		{
			tmp=I[r1][j];
			I[r1][j]=I[r2][j];
			I[r2][j]=tmp;
		}
		tmp=O[r1];
		O[r1]=O[r2];
		O[r2]=tmp;
	}
}

int main()
{
	int i,j,k,l;
	double l1[101][11],l1_d[101][11],l2[101],l2_d[101],s,err,alpha=1;
	srand(time(NULL));
	printf("Enter number of neurons in input layer : ");
	scanf("%d",&n1);
	printf("Enter number of neurons in hidden layer : ");
	scanf("%d",&n2);
	printf("Enter number of entries : ");
	scanf("%d",&n); printf("\n");
	for(i=1;i<=n;i++)
	{
		printf("entry %d\n",i);
		for(j=1;j<=n1;j++)
		{			
			printf("enter x[%d] : ",j);
			scanf("%lf",&I[i][j]);
		}
		printf("enter y : ");
		scanf("%lf",&O[i]); printf("\n");
	}	
	label1:
	for(i=1;i<=n2;i++)
	{ 
		for(j=1;j<=n1;j++)	//intializing weights randomly
		{
			w1[j][i]=(sqrt(-2.0*log((double)rand()/RAND_MAX)))*(cos(6.28318530718*(double)rand()/RAND_MAX));
		}
		w2[i]=(sqrt(-2.0*log((double)rand()/RAND_MAX)))*(cos(6.28318530718*(double)rand()/RAND_MAX));
	}
	label2:
	for(i=1;;i++)
	{		
		err=0;
		for(j=1;j<=n;j++)	//n data entries
		{
			for(k=1;k<=n2;k++)	//forming l1
			{
				s=0;
				for(l=1;l<=n1;l++)
				{
					s=s+(I[j][l]*w1[l][k]);	
				}
				l1[j][k]=S(s);	
			}		
			s=0;
			for(k=1;k<=n2;k++)	//forming l2
			{
				s=s+(l1[j][k]*w2[k]);		
			}
			l2[j]=S(s);	
			err=err+fabs(l2[j]-O[j]);   	
			l2_d[j]=(l2[j]-O[j])*d_S(l2[j]); //forming l2 delta
			for(k=1;k<=n2;k++)	//forming l1 delta
			{
				l1_d[j][k]=l2_d[j]*w2[k]*d_S(l1[j][k]);
			}
			l=j;
			for(j=1;j<=n1;j++)	//updating w1
			{
				for(k=1;k<=n2;k++)
				{
					w1[j][k]=w1[j][k]-((alpha)*(I[l][j]*l1_d[l][k]));
				}
			}
			k=l;
			for(j=1;j<=n2;j++)	//updating w2
			{
				w2[j]=w2[j]-((alpha)*(l1[k][j]*l2_d[k]));
			}
			j=l;
		}
		if(i==100000) {printf("error : %0.15lf\n",err/n);i=0;} //mean absolute error
		shuffle();
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
