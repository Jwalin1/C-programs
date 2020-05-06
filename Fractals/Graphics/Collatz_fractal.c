#include<graphics.h>
#include<math.h>
#define TAU 6.283185307

class complex {
public:
	float real, imag;
    complex(float r = 0, float i =0)  
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

int approxequals(complex z, complex z1, float tol)
{
	if(fabs(z.real-z1.real)<tol && fabs(z.imag - z1.imag)<tol)
		return 1;
	return 0;	
}

complex cos(complex z)
{
	complex z1;
	z1.real = cos(z.real)*cosh(z.imag);
	z1.imag = -sin(z.real)*sinh(z.imag);
	return z1;
}

int main()
{
	int i,j,k,iter=20,gd,gm;
	float tol=0.01;
	complex z;
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,NULL);
	delay(2000);
	for(i=0;i<=1350;i++)
	{
		for(j=0;j<=675;j++)
		{			
			z = complex(i*4.0/1350,-j*2.0/675+1);
			for(k=0;k<iter;k++)
			{
				z = (z*4-(z*2+1)*cos(z*TAU/2)+1)*.25;
				if(approxequals(z,complex(1,0),tol)==1)
					break;
			}
			if(k!=iter)
				putpixel(i,j,1);
		}
	}
	getch();
	closegraph();
	return 0;
}
