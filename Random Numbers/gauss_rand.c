#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int i,x,n,R[11];
	float U1,U2;
	srand(time(NULL));
	for(i=0;i<11;i++)
		R[i]=0;
	printf("enter n : ");
	scanf("%d",&n);	
	for(i=0;i<n;i++)
	{
		U1=(float)rand()/RAND_MAX;
		U2=(float)rand()/RAND_MAX;
		x=round(5.5+3.0276503541*(sqrt(-2.0*log(U1)))*(cos(6.28318530718*U2)));
		if(x>0&&x<11)
			R[x]=R[x]+1;
	}
	for(i=1;i<11;i++)
		printf("\nR[%d]=%f",i,(float)R[i]/n);
	getch();	
	return 0;
}
