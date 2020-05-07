#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
#include<graphics.h>
#define TAU 6.283185307
int n_genes;

float y(float coeff[], float x)
{	
	int i;
	float sum=0;
	
	for(i=0; i<n_genes; i++)
		sum += coeff[i]*pow(x,i);
	
	return sum;	
}

void print_genes(float coeff[])
{
	int i;
	
	for(i=0; i<n_genes; i++)
		printf("%+f*x^%d ",coeff[i],i);	
}

void test(float coeff[])
{
	float x;
	
	printf("\nenter test value\n");
	scanf("%f",&x);
	printf("%f",y(coeff,x));	
}

int main()
{
	//hyperparameters
	int n_chromosomes=10, n_samples=11;
	float selection_percentage=10, I[100], O[100];
	float mutation_rate=0.01, mutation_normalizer=0.5, mutation_probability=0.2;
	
	int i,j,k,gd,gm,m,f,gen,survivors;
	float tmp, Chromosome[11], Population[100][11], Loss[100];
	char text[80];
	
	printf("enter the degree of polynomial model to fit : ");
	scanf("%d,",&n_genes);
	n_genes++;	//plus one for constant
	
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,NULL);
	setfillstyle(1,4);
	settextstyle(0,0,2);
	
	survivors = n_chromosomes*selection_percentage/100;
	printf("%d",survivors);
	srand(time(NULL));
	
	delay(2000);
	
	label0:
	for(i=0;i<n_samples;i++)
	{
		I[i] = ((3*TAU)/n_samples)*i-(1.5*TAU);
		//printf("\nx[%d] : %f\n",i+1,I[i]);
		O[i] = cos(I[i]);
		//printf("y[%d] : %f\n",i+1,O[i]);
	}
	
	label1:
	//initialize population with random genes
	for(i=0; i<n_chromosomes; i++)
	{
		for(j=0; j<n_genes; j++)
		{
				tmp = pow(mutation_normalizer,j);
				Population[i][j] = 2.0*tmp*rand()/RAND_MAX - tmp;
		}
	}
	
	
	for(gen=1; ; gen++)
	{				
		label2:
		//calculate RMSE loss for each chromosome
		for(i=0; i<n_chromosomes; i++)
		{		
			for(j=0; j<n_genes; j++)
					Chromosome[j] = Population[i][j];
			
			Loss[i] = 0;
			for (j=0; j<n_samples; j++)
				Loss[i] += pow(O[j] - y(Chromosome,I[j]),2);
			Loss[i] /= n_samples;	
			Loss[i] = sqrt(Loss[i]);
			
			if(gen%1000==0&&i==0)
				printf("rmse[%d] = %f\n",gen,Loss[i]);
		}
		
		//sort
		for(i=0; i<n_chromosomes; i++)
		{
			for(j=0; j<n_chromosomes; j++)
			{
				if(Loss[i] < Loss[j])
				{
					tmp = Loss[i];
					Loss[i] = Loss[j];
					Loss[j] = tmp;
					
					for(k=0; k<n_genes; k++)
					{
						tmp = Population[i][k];
						Population[i][k] = Population[j][k];
						Population[j][k] = tmp;
					}
				}
			}
		}
		
		if(gen%1000==0)
		{
			cleardevice();
			
			setcolor(14);
			sprintf(text,"degree : %d, samples : %d",n_genes-1,n_samples);
			outtextxy(500,150,text);
			
			setcolor(4);
			for(i=0; i<n_samples; i++)
				fillellipse(23.33*I[i]+700,-100*O[i]+350,5,5);
			
			for(i=0; i<n_genes; i++)
				Chromosome[i] = Population[0][i];
		
			for(tmp=-30;tmp<=30;tmp+=.01)
			{
				putpixel(23.33*tmp+700,-100*cos(tmp)+350,15);
				putpixel(23.33*tmp+700,-100*y(Chromosome,tmp)+350,14);
			}
			
		}
		
		
		//breed next generation using best chromosomes
		for(i=survivors; i<n_chromosomes; i++)
		{
			f=rand()%survivors, m=rand()%survivors;
			for(j=0; j<n_genes; j++)
			{
				//crossover
				k=rand()%3;
				if(k==0)
					Population[i][j] = (Population[f][j] + Population[m][j])/2;
				else if(k==1)
					Population[i][j] = Population[f][j];
				else if(k==2)
					Population[i][j] = Population[m][j];
				
				//mutation
				k=rand() % (int)(1/mutation_probability);
				if(k==0)
				{
					tmp = mutation_rate*pow(mutation_normalizer,j);
					Population[i][j] += 2.0*tmp*rand()/RAND_MAX - tmp;
				}
			}
		}
		
		if (GetAsyncKeyState(VK_ESCAPE)) {break;}
		
		if (GetAsyncKeyState(0x32)) {n_genes=3; goto label1;}
		else if (GetAsyncKeyState(0x33)) {n_genes=4; goto label1;}
		else if (GetAsyncKeyState(0x34)) {n_genes=5; goto label1;}
		else if (GetAsyncKeyState(0x35)) {n_genes=6; goto label1;}
		else if (GetAsyncKeyState(0x36)) {n_genes=7; goto label1;}
		else if (GetAsyncKeyState(0x37)) {n_genes=8; goto label1;}
		else if (GetAsyncKeyState(0x38)) {n_genes=9; goto label1;}
		
		if (GetAsyncKeyState(VK_RIGHT)) {n_samples++; Sleep(100); goto label0;}
		else if (GetAsyncKeyState(VK_LEFT)) {n_samples--; Sleep(100); goto label0;}
		
		if (GetAsyncKeyState(VK_UP)) {tmp=mutation_rate*10; if(fabs(tmp)<pow(10,4)) {mutation_rate=tmp;} Sleep(100);}
		else if (GetAsyncKeyState(VK_DOWN)) {tmp=mutation_rate/10; if(fabs(tmp)>=pow(10,-15)) {mutation_rate=tmp;} Sleep(100);}
	}
	
	printf("\n\n");
	for(i=0; i<n_genes; i++)
		Chromosome[i] = Population[0][i];
	
	i=0;
	while(i!=6)
	{
		printf("1) Test\n2) See best chromosome\n3) Continue evolution\n4) Re evolve\n5) Check mutation rate \n6) Exit");
		printf("\nenter choice : ");
		scanf("%d",&i);
		if (GetAsyncKeyState(VK_UP)) {tmp=mutation_rate*10; if(fabs(tmp)<pow(10,4)) {mutation_rate=tmp;}}
		else if (GetAsyncKeyState(VK_DOWN)) {tmp=mutation_rate/10; if(fabs(tmp)>=pow(10,-15)) {mutation_rate=tmp;}}
		if(i==1){test(Chromosome);}
		else if(i==2){print_genes(Chromosome);}
		else if(i==3){GetAsyncKeyState(0x33); goto label2;}
		else if(i==4){goto label1;}
		else if(i==5){printf("\nmutation_rate=%f",mutation_rate);}
		printf("\n\n");
	}
	
	getch();
	return 0;
}
