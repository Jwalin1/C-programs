#include<graphics.h>

float G[201][201][2];

float Laplace(int i, int j, int c)
{
	float sum=0;
	sum += G[i][j][c]*-1.0;
	sum += G[i-1][j][c]*0.2;
	sum += G[i+1][j][c]*0.2;
	sum += G[i][j-1][c]*0.2;
	sum += G[i][j+1][c]*0.2;
	sum += G[i-1][j-1][c]*0.05;
	sum += G[i-1][j+1][c]*0.05;
	sum += G[i+1][j-1][c]*0.05;
	sum += G[i+1][j+1][c]*0.05;
	return sum;
}

int main()
{
	int i,j,s,gd,gm;
	float G1[201][201][2];
	float DA=1.0,DB=0.5,f=0.0545,k=0.062,dt=1.0,ta,tb;
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,NULL);
	for(i=1;i<200;i++)
		{
			for(j=1;j<200;j++)
			{
				G1[i][j][0]=1;
				G1[i][j][1]=0;
			}
		}
	for(i=95;i<105;i++)
		for(j=95;j<105;j++)
			G1[i][j][1]=1;
	delay(2000);
	for(s=0;;s++)
	{
		//print and copy
		for(i=1;i<200;i++)
		{
			for(j=1;j<200;j++)
			{
				G[i][j][0]=G1[i][j][0];
				G[i][j][1]=G1[i][j][1];
				if(s%50==0)
				{
					ta=G[i][j][0]-G[i][j][1];
					if(ta>0.8)
						putpixel(i,j,15);
					else if(ta>0.5)
						putpixel(i,j,7);
					else if(ta>0.1)
						putpixel(i,j,8);
					else
						putpixel(i,j,0);	
				}
			}
		}
	
		//update
		for(i=1;i<200;i++)
		{
			for(j=1;j<200;j++)
			{
				ta=G[i][j][0];
				tb=G[i][j][1];
				G1[i][j][0] = ta + (DA*Laplace(i,j,0) - ta*tb*tb + f*(1-ta)) * dt;
				G1[i][j][1] = tb + (DB*Laplace(i,j,1) + ta*tb*tb - (k+f)*tb) * dt;
			}
		}
	}
	getch();
	closegraph();
	return 0;
}
