#include<stdio.h>
#include<conio.h>
#include<windows.h>
int n,R[51];

int check(int x, int y)
{
	int i;
	for(i=1;i<x;i++)
	{
		if(R[i]==y)
		{
			y=y+1;
			i=0;
		}
		else if(i-R[i]==x-y)
		{
			y=y+1;
			i=0;
		}
		else if(i-x==y-R[i])
		{
			y=y+1;
			i=0;
		}
	}
	if(y>n)
		return 0;
	else
		return y;	
}

void main()
{
	int i,f,f2=0,t=0,t2=1;
	printf("enter the size of chess board : ");
	scanf("%d",&n);
	if(n<4){printf("Not possible"); exit(0);}
	for(i=1;i<=n;i++){R[i]=1;}
	printf("enter 1 to set intial positions and 0 to continue... ");
	scanf("%d",&f);
	if(f==1)
	{
		t=-1;
		for(i=1;i<=n;i++)
		{
			printf("Row[%d]=",i);
			scanf("%d",&R[i]);
		}
	}	
	printf("\n");
	for(i=1;i<=n;i++)
	{
		label1:
		f=check(i,R[i]);
		if(f!=0)
		{
			R[i]=f;
		}
		else
		{
			R[i]=1;
			R[i-1]=R[i-1]+1;
			i=i-2;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(f=1;f<=n;f++)
		{
			if(f==R[i])
			{
				printf("Q ");
			}
			else
				printf("- ");
		}
		printf("\n");
	}
	printf("\n[");
	for(i=1;i<n;i++)
	{
		printf("%d,",R[i]);
	}
	printf("%d]",R[n]);
	if(t>=0)
	{
		if(R[1]>=t2)
		{ 
			t=t+1; 
			t2=R[1];
		}
		else 
			t2=R[1]+2;
		printf("\nTotal solutions : %d",t);	
		
	}
	if (GetAsyncKeyState(VK_ESCAPE)){f2=0;}
	if(f2==0)
	{
		printf("\n\n1)find next\n2)loop\nenter choice : ");
		scanf("%d",&f);
	}
	if(f==1)
	{
		printf("\n");
		R[n]=R[n]+1;
		i=n;
		goto label1;
	}
	if(f==2||f2==1)
	{
		printf("\n\npress ESC to stop...");
		Sleep(100);
		system("CLS");
		printf("Solution for size %d\n\n",n);
		R[n]=R[n]+1;
		i=n;
		f2=1;
		goto label1;
	}
}
