#include<stdio.h>
#include<conio.h>
#include<math.h>

int mod(int a, int b)
{ return a-b*floor((float)a/b); }

int main()
{
	int a,b,tmp;
	printf("enter two integers : \n");
	scanf("%d%d",&a,&b);
	while(a>0)
	{
		tmp=mod(b,a);
		printf("\n%d = %d*%d + %d",b,a,(int)floor((float)b/a),tmp);
		b=a;
		a=tmp;
	}
	printf("\n\ngreatest common divisor of the two numbers is %d",b);
	getch();
	return 0;
}
