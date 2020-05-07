#include<graphics.h>
#include<math.h>
#include<time.h>

//params[0]=a, params[1]=b, params[2]=c, params[3]=d
float y(float params[], float x)
{	return (params[0] + params[1]*x + params[2]*x*x + params[3]*x*x*x);	}

int main()
{
	//hyperparameters
	int n_chromosomes=100, n_genes=4, n_samples=20, n_iter=10000;
	float mutation_rate, selection_percentage=10, Ground_truth[] = {-0.1, 0.3, -0.7, 0.1};
	
	int i,j,k,gen,gd,gm,survivors;
	float tmp, Chromosome[4], Population[100][4], Loss[100];
	char text[80];
	
	survivors = n_chromosomes*selection_percentage/100;
	srand(time(NULL));
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,NULL);
	settextstyle(0,0,2);
	
	//initialize population with random genes
	for(i=0; i<n_chromosomes; i++)
		for(j=0; j<n_genes; j++)
			Population[i][j] = 2.0*rand()/RAND_MAX - 1;
	
	delay(2000);
	
	for(gen=1; gen<=n_iter; gen++)
	{
		for(i=0; i<n_chromosomes; i++)
			Loss[i] = 0;
		
		//calculate RMSE loss for each chromosome
		for(i=0; i<n_samples; i++)
		{	
			tmp = 2.0*rand()/RAND_MAX - 1;
			
			for (j=0; j<n_chromosomes; j++)
			{	
				for(k=0; k<n_genes; k++)
					Chromosome[k] = Population[j][k];
				
				Loss[j] += pow(y(Ground_truth,tmp) - y(Chromosome,tmp),2);
			}	
		}
		
		for(i=0; i<n_chromosomes; i++)
		{
			Loss[i] /= n_samples;
			Loss[i] = sqrt(Loss[i]);
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
		
		//plot avg log of RMSE loss of the population
		tmp=0;
		for(i=0; i<n_chromosomes; i++)
			tmp += Loss[i];
		tmp /= n_chromosomes;
		putpixel(.14*gen,-93*log(tmp),14);
		
		sprintf(text,"Model : a + b*x + c*x^2 + d*x^3");
		outtextxy(400,200,text);
		sprintf(text,"Ground truth : %f %f %f %f", Ground_truth[0],Ground_truth[1],Ground_truth[2],Ground_truth[3]);
		outtextxy(250,250,text);
		sprintf(text,"Best fit : %f %f %f %f", Population[0][0],Population[0][1],Population[0][2],Population[0][3]);
		outtextxy(300,300,text);
		sprintf(text,"RMSE loss : %f", Loss[0]);
		outtextxy(500,350,text);
		
		//breed next generation using best chromosomes
		for(i=survivors; i<n_chromosomes; i++)
		{
			for(j=0; j<n_genes; j++)
			{
				//crossover
				Population[i][j] = (Population[rand()%survivors][j] + Population[rand()%survivors][j])/2;
				
				//mutation
				mutation_rate = 10/(100.0 + gen);
				Population[i][j] += 2.0*mutation_rate*rand()/RAND_MAX - mutation_rate;
			}
		}
	}
	
	getch();
	return 0;
}
