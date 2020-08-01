#include<graphics.h>

float trans(float s1, float s2, float x)
{	return 100 + 1200*(x-s1)/(s2-s1);	}

int main()
{
	int i,j,n,gd,gm;
	float tmp,tmp1;
	float Q1,median,Q3,IQR,Max,Min;
	float s1,s2,s;
	char text[80];
	
	printf("enter number of entries: ");
	scanf("%d",&n);
	
	float data[n], outliers[n];
	
	for(i=0;i<n;i++)
	{
		printf("%d : ",i+1);
		scanf("%f",&data[i]);
	}
	
	//sort
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			if(data[i] < data[j])
			{
				tmp = data[i];
				data[i] = data[j];
				data[j] = tmp;
			}
		}
	}
	
	printf("\nsorted data\n");
	for(i=0; i<n; i++)
		printf("%d : %f\n",i+1,data[i]);
	
	Q1 = n%2==0 ? (data[n/4]+data[n/4-1])/2 : data[n/4];
	median = n%2==0 ? (data[n/2]+data[n/2-1])/2 : data[n/2];
	Q3 = n%2==0 ? (data[3*n/4]+data[3*n/4-1])/2 : data[3*n/4];
	IQR = Q3 - Q1;
	
	
	Max = data[0]; Min = data[0];
	for(i=0; i<n; i++)
	{
		if(data[i] > Max)
			Max = data[i];
		if(data[i] < Min)	
			Min = data[i];
	}
	tmp=Max;
	Max=Min;
	Min=tmp;
	
	j = 0;
	for(i=0; i<n; i++)
	{
		if(data[i] < (Q1 - 1.5*IQR) || data[i] > (Q3 + 1.5*IQR))
		{
			outliers[j] = data[i];
			j++;
		}
		else
		{
			if(data[i] > Max)
				Max = data[i];
			if(data[i] < Min)	
				Min = data[i];
		}
	}
	outliers[j] = '\0';
	
	//adjust scaling
	s1=Min; s2=Max;
	if(j>0)
	{
		if(outliers[0]<Min)
			s1=outliers[0];
		if(outliers[j-1]>Max)
			s2=outliers[j-1];
	}
	s = (Max-Min)/(s2-s1);
	
	printf("\n1st quartile = %f\n",Q1);
	printf("median = %f\n",median);
	printf("3rd quartile = %f\n",Q3);
	printf("inter quartile range = %f\n",IQR);
	printf("Max = %f\n",Max);
	printf("Min = %f\n",Min);
	
	printf("\noutliers : ");
	for(i=0; outliers[i]!='\0'; i++)
		printf("%f ",outliers[i]);
	
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,NULL);
	setcolor(14);
	settextstyle(0,0,1);
		
	rectangle(trans(s1,s2,Q1),350-200*s,trans(s1,s2,Q3),350+200*s);
	sprintf(text,"%.2f",Q1);
	outtextxy(trans(s1,s2,Q1),350-250*s,text);
	sprintf(text,"%.2f",Q3);
	outtextxy(trans(s1,s2,Q3),350-250*s,text);

	line(trans(s1,s2,median), 350-200*s, trans(s1,s2,median), 350+200*s);
	setfillstyle(1,1);
	floodfill(trans(s1,s2,median)-1, 350, 14);
	setfillstyle(1,4);
	floodfill(trans(s1,s2,median)+1, 350, 14);
	sprintf(text,"%.2f",median);
	outtextxy(trans(s1,s2,median),350-250*s,text);
	
	line(trans(s1,s2,Max), 350-200*s, trans(s1,s2,Max), 350+200*s);
	line(trans(s1,s2,Q3), 350, trans(s1,s2,Max), 350);
	sprintf(text,"%.2f",Max);
	outtextxy(trans(s1,s2,Max),350-250*s,text);
	
	line(trans(s1,s2,Min), 350-200*s, trans(s1,s2,Min), 350+200*s);
	line(trans(s1,s2,Min), 350, trans(s1,s2,Q1), 350);
	sprintf(text,"%.2f",Min);
	outtextxy(trans(s1,s2,Min),350-250*s,text);
	
	setfillstyle(1,14);
	for(i=0; outliers[i]!='\0'; i++)
	{
		fillellipse(trans(s1,s2,outliers[i]),350,20*s,20*s);
		sprintf(text,"%.2f",outliers[i]);
		outtextxy(trans(s1,s2,outliers[i]),350-50*s,text);
	}
	
	getch();
}
