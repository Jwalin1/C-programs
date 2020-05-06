#include<stdio.h>

int main()
{
	int n,a=0,b=0,c,d,a1,b1,c1,d1,B=0,C,ch=0;
	srand(time(NULL));
	while(a==b||a==c||a==d||b==c||b==d||c==d)
	{
		d=rand()%10;
		c=rand()%10;
		b=rand()%10;
		a=rand()%10;
	}
	while(B!=4)
	{
		n=0;
		while(a1==b1||a1==c1||a1==d1||b1==c1||b1==d1||c1==d1||n<123||n>9876)
		{
			printf("\nGuess : ");
			scanf("%d",&n);
			d1=n%10;
			c1=(n/10)%10;
			b1=(n/100)%10;
			a1=(n/1000)%10;
		}
		B=0; C=0;
		if(a1==b||a1==c||a1==d) { C=C+1; } else if(a1==a) { B=B+1; }
		if(b1==a||b1==c||b1==d) { C=C+1; } else if(b1==b) { B=B+1; }
		if(c1==b||c1==a||c1==d) { C=C+1; } else if(c1==c) { B=B+1; }
		if(d1==b||d1==c||d1==a) { C=C+1; } else if(d1==d) { B=B+1; }
		ch=ch+1;
		printf("Bulls\tCows\n  %d  \t  %d\n",B,C);
		if(B==4)
			printf("\nYou won in %d chances",ch);
	}
	getch();
	return 0;
}
