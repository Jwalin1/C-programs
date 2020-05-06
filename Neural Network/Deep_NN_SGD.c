#include<conio.h>
#include<stdio.h>
#include<math.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
int n,h,nl[6];
double L[101][6][11],O[101],w[6][11][11];

double S(double x)
{ return 1/(1+exp(-x)); }

double d_S(double x)
{ return x*(1-x); }

void print_weights()
{
	int i,j,k;
	printf("\nInput layer -> Hidden layer 1");
	for(i=1;i<=nl[0];i++)
	{
		for(j=1;j<=nl[1];j++)
		{
			printf("\nw[%d][%d]=%0.15lf",i,j,w[1][i][j]);
		}
	}
	if(h>=2)
	{
		for(i=1;i<=h-1;i++)
		{
			printf("\n\nHidden layer %d -> Hidden layer %d",i,i+1);
			for(j=1;j<=nl[i];j++)
			{
				for(k=1;k<=nl[i+1];k++)
				{
					printf("\nw[%d][%d]=%0.15lf",j,k,w[i+1][j][k]);
				}
			}
		}
	}
	printf("\n\nHidden layer %d -> Output",h);
	for(i=1;i<=nl[h];i++)
	{
		printf("\nw[%d]=%0.15lf",i,w[h+1][i][1]);
	}
}

void test()
{
	int i,j,k;
	double s,L[6][11];
	printf("\nEnter test values\n");
	for(i=1;i<=nl[0];i++)
	{			
		printf("enter x[%d] : ",i);
		scanf("%lf",&L[0][i]);
	}
	for(i=1;i<=h+1;i++)	
	{
			for(j=1;j<=nl[i];j++)	
			{
				s=0;
				for(k=1;k<=nl[i-1];k++)
				{
					s=s+(L[i-1][k]*w[i][k][j]);	
				}
				L[i][j]=S(s);
			}
	}
	printf("Output : %0.15lf",L[h+1][1]);
}

void shuffle()
{
	int i,j,r1,r2;
	double tmp;
	for(i=1;i<=n;i++)
	{
		r1=(rand()%n)+1; r2=r1=(rand()%n)+1;
		for(j=1;j<=nl[0];j++)
		{
			tmp=L[r1][0][j];
			L[r1][0][j]=L[r2][0][j];
			L[r2][0][j]=tmp;
		}
		tmp=O[r1];
		O[r1]=O[r2];
		O[r2]=tmp;
	}
}

int main()
{
	int i,j,k,l,m;
	double L_d[101][6][11],s,err,alpha=1;
	srand(time(NULL));
	printf("Enter number of neurons in input layer : ");
	scanf("%d",&nl[0]);
	printf("Enter number of hidden layers : ");	//not more than 4 as [5] is output layer
	scanf("%d",&h);
	for(i=1;i<=h;i++)
	{
		printf("Enter number of neurons in hidden layer %d : ",i);		
		scanf("%d",&nl[i]);
	}
	nl[h+1]=1;
	printf("Enter number of entries : ");
	scanf("%d",&n); printf("\n");
	for(i=1;i<=n;i++)
	{
		printf("entry %d\n",i);
		for(j=1;j<=nl[0];j++)
		{			
			printf("enter x[%d] : ",j);
			scanf("%lf",&L[i][0][j]);
		}
		printf("enter y : ");
		scanf("%lf",&O[i]); printf("\n");
	}	
	label1:
	for(i=1;i<=h+1;i++)	//intializing weights randomly
	{ 
		for(j=1;j<=nl[i-1];j++)	
		{
			for(k=1;k<=nl[i];k++)	
			{
				w[i][j][k]=(sqrt(-2.0*log((double)rand()/RAND_MAX)))*(cos(6.28318530718*(double)rand()/RAND_MAX));
			}
		}
	}
	label2:	
	for(i=1;;i++)
	{	
		err=0;
		for(k=1;k<=n;k++)	
		{
			for(j=1;j<=h+1;j++)	//forming output matrix L
			{
				for(l=1;l<=nl[j];l++)	
				{
					s=0;
					for(m=1;m<=nl[j-1];m++)
					{
						s=s+(L[k][j-1][m]*w[j][m][l]);	
					}
					L[k][j][l]=S(s);
				}
			}		
			err=err+fabs(L[k][h+1][1]-O[k]);   	
			L_d[k][h+1][1]=(L[k][h+1][1]-O[k])*d_S(L[k][h+1][1]); //forming L_delta of last layer
			for(j=h;j>=1;j--)	//layer
			{
				for(l=1;l<=nl[j];l++)	//number of neurons
				{
					s=0;
					for(m=1;m<=nl[j+1];m++)	   //number of neurons		
					{
						s=s+(L_d[k][j+1][m]*w[j+1][l][m]);	//backpropagating error
					}
					L_d[k][j][l]=s*d_S(L[k][j][l]);		//forming L_delta of remaining layers
				}
			}
			m=k;
			for(j=0;j<=h+1;j++)	//layer
			{
				for(k=1;k<=nl[j-1];k++)	//updating weights
				{
					for(l=1;l<=nl[j];l++)
					{
						w[j][k][l]=w[j][k][l]-((alpha)*(L[m][j-1][k]*L_d[m][j][l]));
					}
				}
			}
			k=m;
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
