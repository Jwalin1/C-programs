#include<conio.h>
#include<stdio.h>
#include<math.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
int n,h,nl[6];
double L[101][6][21],O[101][21],w[6][21][21],b[6][21];

double S(double x)
{ return 1/(1+exp(-x)); }

double d_S(double x)
{ return x*(1-x);}

void print_weights()
{
	int i,j,k;
	if(h!=0)
	{ printf("\nInput layer -> Hidden layer 1"); }
	else
	{ printf("\nInput layer -> Output layer"); }
	for(i=1;i<=nl[0];i++)
	{
		for(j=1;j<=nl[1];j++)
		{
			printf("\nw[%d][%d]=%0.15lf",i,j,w[1][i][j]);
		}
	}
	for(i=1;i<=nl[1];i++)
	{
		printf("\nb[%d]=%0.15lf",i,b[1][i]);
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
			for(j=1;j<=nl[i+1];j++)
			{
				printf("\nb[%d]=%0.15lf",j,b[i+1][j]);
			}
		}
	}
	if(h!=0)
	{
		printf("\n\nHidden layer %d -> Output layer",h);
		for(j=1;j<=nl[h];j++)
		{
			for(k=1;k<=nl[h+1];k++)
			{
				printf("\nw[%d][%d]=%0.15lf",j,k,w[h+1][j][k]);
			}
		}
		for(j=1;j<=nl[h+1];j++)
		{
			printf("\nb[%d]=%0.15lf",j,b[h+1][j]);
		}
	}
}

void test()
{
	int i,j,k;
	double s,L[6][21];
	printf("\nEnter test values\n");
	for(i=1;i<=nl[0];i++)
	{			
		printf("enter x[%d] : ",i);
		scanf("%lf",&L[0][i]);
	}
	for(i=1;i<=h;i++)	
	{
			for(j=1;j<=nl[i];j++)	
			{
				s=0;
				for(k=1;k<=nl[i-1];k++)
				{
					s=s+(L[i-1][k]*w[i][k][j]);	
				}
				L[i][j]=S(s+b[i][j]);
			}
	}	//now i=h+1
	for(j=1;j<=nl[i];j++)	
	{
		s=0;
		for(k=1;k<=nl[i-1];k++)
		{
			s=s+(L[i-1][k]*w[i][k][j]);	
		}
		L[i][j]=S(s+b[i][j]);
		printf("Output[%d] : %0.15lf\n",j,L[h+1][j]);
	}
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
		for(j=1;j<=nl[h+1];j++)
		{
			tmp=O[r1][j];
			O[r1][j]=O[r2][j];
			O[r2][j]=tmp;
		}
	}
}

int main()
{
	int i,j,k,l,m;
	double L_d[101][6][21],s,err[21],alpha=1;
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
	printf("Enter number of neurons in output layer : ");
	scanf("%d",&nl[h+1]);
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
		for(j=1;j<=nl[h+1];j++)
		{			
			printf("enter y[%d] : ",j);
			scanf("%lf",&O[i][j]);
		}
		printf("\n");
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
		for(j=1;j<=nl[i];j++)	//intializing bias weights randomly
		{
			b[i][j]=(sqrt(-2.0*log((double)rand()/RAND_MAX)))*(cos(6.28318530718*(double)rand()/RAND_MAX));
		}
	}
	label2:	
	for(i=1;;i++)
	{	
		for(k=1;k<=nl[h+1];k++){ err[k]=0; }
		for(k=1;k<=n;k++)	
		{
			for(j=1;j<=h;j++)	//forming output matrix L
			{
				for(l=1;l<=nl[j];l++)	
				{
					s=0;
					for(m=1;m<=nl[j-1];m++)
					{
						s=s+(L[k][j-1][m]*w[j][m][l]);	
					}
					L[k][j][l]=S(s+b[j][l]);
				}
			}	//now j=h+1	
			for(l=1;l<=nl[j];l++)	
			{
				s=0;
				for(m=1;m<=nl[j-1];m++)
				{
					s=s+(L[k][j-1][m]*w[j][m][l]);	
				}
				L[k][j][l]=S(s+b[j][l]);
				err[l]=err[l]+fabs(L[k][h+1][l]-O[k][l]);
				L_d[k][h+1][l]=(L[k][h+1][l]-O[k][l])*d_S(L[k][h+1][l]); //forming L_delta of last layer
			}	   	
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
				for(k=1;k<=nl[j];k++)	//updating bias weights
				{
					b[j][k]=b[j][k]-((alpha)*(L_d[m][j][k]));
				}
			}
			k=m;
		}
		if(i==100000) 
		{
			for(k=1;k<=nl[h+1];k++)
			{ printf("error[%d] : %0.15lf\n",k,err[k]/n);i=0; }	//mean absolute error
			if(nl[h+1]>1){printf("\n");}
		} 
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
