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
	return pow(z,3)-1;
}

complex df(complex z)
{
	return z*z*3;
}

int main()
{
	int i,j,k,iter=100,shift=5,gd,gm;
	float tol=0.0001;
	complex z;
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,NULL);
	delay(2000);
	for(i=0;i<=675;i++)
	{
		for(j=0;j<=675;j++)
		{
			z = complex(i*4.0/675-2,-j*4.0/675+2);
			for(k=0;k<iter;k++)
			{
				if(abs(f(z)) < tol)
					break;
				z=z-f(z)/df(z);
			}
			if(k!=iter)
			{
				putpixel(i,j,1+(k+shift)%14);
				putpixel(i+675,j,1+int(shift+tol+(arg(z)*14/TAU+8))%14);
			}
		}
	}
	getch();
	closegraph();
	return 0;
}
