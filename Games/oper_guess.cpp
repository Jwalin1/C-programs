#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

int op(int x, int y)
{
	using namespace std;
	int r;
	r=rand()%4+1;
	if (r==1) { cout<<"+"; return x+y;}
	else if (r==2) { cout<<"*"; return x*y;}
	else if (r==3) { cout<<"-"; return x-y;}
	else if (r==4&&(x%y==0)) { cout<<"/"; return x/y;}
	else { cout<<"+"; return x+y;}
}

int main()
{
	using namespace std;
	srand(time(NULL));
	int a,b,c,d,t,r,sol,s;
	cout<<"Enter a : "; cin>>a;
	cout<<"Enter b : "; cin>>b;
	cout<<"Enter c : "; cin>>c;
	cout<<"Enter d : "; cin>>d;
	cout<<"Enter solution : "; cin>>sol;
	while (1)
	{
	r=rand()%3+1;
	if (r==1) { t=a; a=b; b=t;}
	if (r==2) { t=a; a=c; c=t;}
	if (r==3) { t=a; a=d; d=t;}	
	cout<<a; s=op(a,b);
	cout<<b; s=op(s,c);
	cout<<c; s=op(s,d); cout<<d;
	if (s==sol) { cout<<"="<<sol; break; }	
	else { system("CLS");}
	}
	getch();
}
