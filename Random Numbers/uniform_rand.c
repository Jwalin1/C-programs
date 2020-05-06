#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int i,x,n,R[11];
	srand(time(NULL));
	for(i=0;i<11;i++)
		R[i]=0;	
	printf("enter n : ");
	scanf("%d",&n);	
	for(i=0;i<n;i++)
	{
		x=rand()%10+1;
		R[x]=R[x]+1;
	}
	for(i=1;i<11;i++)
		printf("\nR[%d]=%f",i,(float)R[i]/n);
	getch();	
	return 0;
}
