#include<stdio.h>
#include<conio.h>

double fact(double n)
{
	double t=1;
	if(n!=0)
	{
	while (n>0)
	{
		t=t*n; n=n-1;
	}
	return t;
	}
	else {return 1;}
}

double pow(double b, double p)
{
	double t=1;
	if(p!=0)
	{
	while (p>0)
	{
		t=t*b; p=p-1;
	}
	return t;
	}
	else {return 1;}
}

double crpow(double x, double y, double p)
{
	double tr=x,ti=y,t;
	p=p-1;
	if(p!=0&&p!=-1)
	{
	while (p>0)
	{
		t=tr;
		tr=(tr*x)-(ti*y);
		ti=(t*y)+(ti*x);
		p=p-1;
	}
	return tr;
	}
	else if (p==0) {return tr;}
	else if (p==-1) {return 1;}  
}

double cipow(double x, double y, double p)
{
	double tr=x,ti=y,t;
	p=p-1;
	if(p!=0&&p!=-1)
	{
	while (p>0)
	{
		t=tr;
		tr=(tr*x)-(ti*y);
		ti=(t*y)+(ti*x);
		p=p-1; 
	}
	return ti;
	}
	else if (p==0) {return ti;}
	else if (p==-1) {return 0;} 
}

double rsin(double x, double y)
{
	double t=0; double s=0,s1=1;
	while (x>6.2831853071795864769&&y==0)
	{
		x=x-6.2831853071795864769;
	}
	while (x<-6.2831853071795864769&&y==0)
	{
		x=x+6.2831853071795864769;
	}
	while (s1!=s)
	{
	 s1=s;
	 s=s+(((pow(-1,t))*(crpow(x,y,((2*t)+1))))/(fact((2*t)+1))); t=t+1;		
	}		
	return s;	
}

double isin(double x, double y)
{
	double t=0; double s=0,s1=1;
	while (s1!=s)
	{
	 s1=s;
	 s=s+(((pow(-1,t))*(cipow(x,y,((2*t)+1))))/(fact((2*t)+1))); t=t+1;			
	}	
	return s;	
}

double rcos(double x, double y)
{
	double t=0; double s=0,s1=1;
	while (x>6.2831853071795864769&&y==0)
	{
		x=x-6.2831853071795864769;
	}
	while (x<-6.2831853071795864769&&y==0)
	{
		x=x+6.2831853071795864769;
	}
	while (s1!=s)
	{
	 s1=s;
	 if ((crpow(x,y,((2*t))))==0) {t=t+1;}
	 s=s+(((pow(-1,t))*(crpow(x,y,((2*t)))))/(fact((2*t)))); t=t+1;		
	}		
	return s;	
}

double icos(double x, double y)
{
	double t=0; double s=0,s1=1;
	while (s1!=s)
	{
	 s1=s;
	 if ((cipow(x,y,((2*t))))==0) {t=t+1;}
	 s=s+(((pow(-1,t))*(cipow(x,y,((2*t)))))/(fact((2*t)))); t=t+1;			
	}	
	return s;	
}

double rexp(double x, double y)
{
	double t=0; double s=0,s1=1;
	while (y>6.2831853071795864769)
	{
		y=y-6.2831853071795864769;
	}
	while (y<-6.2831853071795864769)
	{
		y=y+6.2831853071795864769;
	}
	while (s1!=s)
	{
	 s1=s;
	 if ((crpow(x,y,t))==0) {t=t+1;}
	 s=s+((crpow(x,y,t))/(fact(t))); t=t+1; 
	}		
	return s;	
}

double iexp(double x, double y)
{
	double t=0; double s=0,s1=1;
	while (y>6.2831853071795864769)
	{
		y=y-6.2831853071795864769;
	}
	while (y<-6.2831853071795864769)
	{
		y=y+6.2831853071795864769;
	}
	while (s1!=s)
	{
	 s1=s;
	 if ((cipow(x,y,t))==0) {t=t+1;}
	 s=s+((cipow(x,y,t))/(fact(t))); t=t+1; 			
	}	
	return s;	
}

double root(double x, double n)
{
	double s=1,s1=0; 
	while (s1!=s)
	{
	 s1=s;
	 s=((1/n)*(((n-1)*s)+(x/(pow(s,(n-1))))));  
	}		
	return s;	
}

double arctan(double x)
{
	double t=0; double s=0,s1=1;
	x=x/(1+((root((1+(x*x)),2))));
	while (s1!=s)
	{
	 s1=s;
	 s=s+(((pow(2,(2*t)))*((fact(t))*(fact(t)))/fact((2*t)+1))*((pow(x,((2*t)+1)))/pow((1+(x*x)),(t+1)))); t=t+1;		
	}
	s=s*2;		
	return s;	
}

double rln(double x, double y)
{
	double t=1; double s=0,s1=1; x=root(((x*x)+(y*y)),2); double a=x;
	if (x==1) {return 0;}
	if ((x/(x-1))<1) {x=1/x;}
	 x=(x/(x-1));
	while (s1!=s)
	{
	 s1=s;
	 s=s+(1/(t*pow(x,t))); t=t+1;			
	}
	if ((a/(a-1))>1) {return s;} else {return -s;}
}

double iln(double x, double y)
{
	if (x>0) {return arctan(y/x);}
	else if (x<0&&y>=0) {return ((arctan(y/x))+3.14159265358979);}
	else if (x<0&&y<0) {return ((arctan(y/x))-3.14159265358979);}
	else if (x==0&&y>0) {return (3.14159265358979/2);}
	else if (x==0&&y<0) {return (-3.14159265358979/2);}
}

int main()
{
	double x,y;
	printf("Re_Arg : "); scanf("%lf",&x); printf("Im_Arg : "); scanf("%lf",&y);
	printf("sin(%lf",x); if(y>=0){printf("+");} printf("%lfi)=%lf",y,rsin(x,y)); if(isin(x,y)>=0){printf("+");} printf("%lfi\n",isin(x,y));
	printf("cos(%lf",x); if(y>=0){printf("+");} printf("%lfi)=%lf",y,rcos(x,y)); if(icos(x,y)>=0){printf("+");} printf("%lfi\n",icos(x,y));
	printf("exp(%lf",x); if(y>=0){printf("+");} printf("%lfi)=%lf",y,rexp(x,y)); if(iexp(x,y)>=0){printf("+");} printf("%lfi\n",iexp(x,y));
	printf("ln(%lf",x); if(y>=0){printf("+");} printf("%lfi)=",y); if (x!=0||y!=0) {printf("%lf",rln(x,y)); if(iln(x,y)>=0){printf("+");} printf("%lfi\n",iln(x,y));} else printf("Undefined\n");
	getch();
}
