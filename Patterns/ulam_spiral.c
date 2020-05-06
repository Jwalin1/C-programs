#include<stdio.h>
#include<windows.h>
#include<math.h>

int digits(int n)
{
	int x=1;
	while(n>=10)
	{
		x=x+1;
		n=n/10;
	}
	return x;
}

void main()
{
	int i,N,x,y,U[51][51],n,t,f=0;
	printf("Enter size of spiral : ");
	scanf("%d",&N);
	label1:
	n=1; t=1;
	for(x=1;x<=50;x++)
	{
		for(y=1;y<=50;y++)
		{
			U[x][y]=0;
		}
	}	
	x=(1+sqrt(N))/2; y=(1+sqrt(N))/2;
	x=x+1; y=y+1;
	U[x][y]=n;
	while(N!=1)
	{	
		for(i=1;i<t;i++)
		{
			n=n+1;
			x=x-1;
			U[x][y]=n;
			if (n==N)
				goto label2;
		}
		for(i=1;i<t;i++)
		{
			n=n+1;
			y=y-1;
			U[x][y]=n;
			if (n==N)
				goto label2;
		}
		for(i=1;i<t;i++)
		{
			n=n+1;
			x=x+1;
			U[x][y]=n;
			if (n==N)
				goto label2;
		}
		for(i=1;i<t;i++)
		{
			n=n+1;
			y=y+1;
			U[x][y]=n;
			if (n==N)
				goto label2;
		}	
		x=x+1; y=y+1;
		t=t+2;
	}
	label2:
	n=t+2;
	for(x=1;x<=n;x++)
	{
		for(y=1;y<=n;y++)
		{
			t=U[x][y];
			if(t==0)
			{
				while(t<=digits(N))
				{
					printf(" ");
					t=t+1;
				}
			}
			else
			{	
				while(digits(t)<digits(N))
				{
					printf("0");
					t=t*10;
				}
				printf("%d ",U[x][y]);
			}
		}
		printf("\n");	
	}
	if (GetAsyncKeyState(VK_ESCAPE)){f=0;}
	if(f==0)
	{
		printf("enter 1 to loop : ");
		scanf("%d",&n);
	}
	if(n==1||f==1)
	{
		N=N+1;
		Sleep(50);
		system("CLS");
		f=1;
		goto label1;
	}
}	

