//Bulls and Cows Solver
#include<stdio.h>
	void main()
	{
		int r=123,n,a[10],b[10],c[10],d[10],B[10],C[10],i=-1,j=0,t=0;
		printf("\t\t\tBulls and Cows Solver\n\n");
		printf("\t\t\tHow to Play\n");
		printf("You have to think of a 4 digit number and I will try to guess it.\n");
		printf("All digits have to be different.\n");
		printf("The first digit can be zero.\n");
		printf("Bulls : Digits present at correct places\n");
		printf("Cows : Digits present at wrong places\n");
		srand(time(NULL));
		t=i;
		while(B[i]!=4)
		{
			label2:
			if(r==10000)
			{
				printf("\nThere must be something wrong with the given responses");
				break;
			}
			if (j==0||(rand()%10)!=9) // 9/10 times a random number will be chosen
			{ 
				d[j]=rand()%10;
				c[j]=rand()%10;
				b[j]=rand()%10;
				a[j]=rand()%10;
			}
			// 1/10 the smallest number that satisfies the given responses will be chosen
			else
			{
				n=r;
				d[j]=n%10; n=n/10;
				c[j]=n%10; n=n/10;
				b[j]=n%10; n=n/10;
				a[j]=n%10; n=n/10;
				r=r+1;
			}
			if ((a[j]==b[j]||a[j]==c[j]||a[j]==d[j]) || (b[j]==c[j]||b[j]==d[j]) || (c[j]==d[j])) {goto label2;}
			label3:
			if (a[j]==b[i]||a[j]==c[i]||a[j]==d[i]) {C[j]=C[j]+1;} if(a[j]==a[i]) {B[j]=B[j]+1;}
			if (b[j]==a[i]||b[j]==c[i]||b[j]==d[i]) {C[j]=C[j]+1;} if(b[j]==b[i]) {B[j]=B[j]+1;}
			if (c[j]==b[i]||c[j]==a[i]||c[j]==d[i]) {C[j]=C[j]+1;} if(c[j]==c[i]) {B[j]=B[j]+1;}
			if (d[j]==b[i]||d[j]==c[i]||d[j]==a[i]) {C[j]=C[j]+1;} if(d[j]==d[i]) {B[j]=B[j]+1;}
			while(i>=0)
			{
				if (B[j]!=B[i]||C[j]!=C[i])
				{	 
					B[j]=C[j]=0;
					i=t;
					goto label2; 
				}
				i=i-1;
				B[j]=C[j]=0;
				goto label3;
			}
			i=t+1; t=i; r=1000;
			printf("\nI guess %d%d%d%d\nBulls : ",a[j],b[j],c[j],d[j]);
			a[i]=a[j];
			b[i]=b[j];
			c[i]=c[j];
			d[i]=d[j];
			scanf("%d",&B[i]);
			if (B[i]!=4)
			{
				printf("Cows : ");
				scanf("%d",&C[i]);
			}
			j=j+1;
		}
		if (B[i]==4){ printf("I won in %d chances",j); }
		getch();
	}
