#include<graphics.h>
#include<math.h>
#define TAU 6.283185307
int N=5,coeff[11];

class complex {
public:
	float real, imag;
    complex(float r=0, float i=0)  
	{
		real = r;
		imag = i;
	}
    complex operator + (complex const &obj) 
	{
         complex res;
         res.real = real + obj.real;
         res.imag = imag + obj.imag;
         return res;
    }
    complex operator - (complex const &obj) 
	{
         complex res;
         res.real = real - obj.real;
         res.imag = imag - obj.imag;
         return res;
    }
    complex operator * (complex const &obj) 
	{
         complex res;
         res.real = real*obj.real - imag*obj.imag;
         res.imag = real*obj.imag + imag*obj.real;
         return res;
    }
    complex operator / (complex const &obj) 
	{
         complex res;
         res.real = (real*obj.real + imag*obj.imag) / (obj.real*obj.real + obj.imag*obj.imag);
         res.imag = (-real*obj.imag + imag*obj.real) / (obj.real*obj.real + obj.imag*obj.imag);
         return res;
    }
};

float abs(complex z)
{
	return sqrt(z.real*z.real+z.imag*z.imag);
}

float arg(complex z)
{
	return atan2(z.imag,z.real);
}

complex pow(complex z, int n)
{
	int i;
	complex z1=complex(1,0);
	for(i=0;i<n;i++)
		z1=z1*z;
	return z1;	
}

complex f(complex z)
{
	int i;
	complex z1=complex(0,0);
	for(i=0;i<=N;i++)
		z1=z1+pow(z,i)*coeff[i];
	return z1;	
}

complex df(complex z)
{
	int i;
	complex z1=complex(0,0);
	for(i=0;i<=N;i++)
		z1=z1+pow(z,i-1)*i*coeff[i];
	return z1;
}

void randomize()
{
	int i;
	coeff[0]=(-1+2*(rand()%2))*(1+rand()%5);
	for(i=1;i<=N;i++)
		coeff[i]=-4+rand()%9;
}

int main()
{
	int i,j,k,iter=100,gd,gm;
	float a,tol=0.00001;
	complex z;
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,NULL);
	delay(2000);
	while(1)
	{
		randomize();
		a=TAU*rand()/RAND_MAX;
		z = complex(.1*cos(a),.1*sin(a));
		for(k=0;k<iter;k++)
		{
			if(abs(f(z)) < tol)
				break;
			z=z-f(z)/df(z);
		}
		if(k!=iter)
		{
			if(fabs(z.real) < 0.01 || fabs(z.imag) < 0.01 || abs(z) < 0.35)
				putpixel(325+z.real*175+350,z.imag*175+350,1);
			else
				putpixel(325+z.real*175+350,z.imag*175+350,4);	
		}
	}
	getch();
	closegraph();
	return 0;
}
