#include<stdio.h>
#include<conio.h>
#include<math.h>

int exp_mod(int a, int b, int c)
{
	if(b==1)
		return a%c;
	else if(b%2==0)
		return (exp_mod(a,b/2,c)*exp_mod(a,b/2,c))%c;	
	else if(b%2==1)
		return (exp_mod(a,b-1,c)*(a%c))%c;	
}

int main()
{
	int a,b,c;
	printf("a^b mod c\n");
	printf("enter a : ");
	scanf("%d",&a);
	printf("enter b : ");
	scanf("%d",&b);
	printf("enter c : ");
	scanf("%d",&c);
	printf("\n%d^%d mod %d = %d",a,b,c,exp_mod(a,b,c));
	getch();
	return 0;
}
