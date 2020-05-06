#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

int mod(int a, int b)
{ return a-b*floor((float)a/b); }

int gcd(int a, int b)
{
	int tmp;
	while(a>0)
	{
		tmp=mod(b,a);
		b=a;
		a=tmp;
	}
	return b;
}

int main()
{
	int i,j,s=0,n;
	printf("enter the value till which you want to check coprime probability : ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		for(j=i;j<=n;j++)
			if(gcd(j,i)==1)
				s=s+1;			
	printf("p(coprime)=%f",s/(n*(n+1)/2.0));		
	getch();			
	return 0;
}
