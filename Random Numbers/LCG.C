#include<stdio.h>
#include<conio.h>

int main()
{
  int m,a,x,i,j;
  printf("enter m : ");
  scanf("%d",&m);
  printf("enter initial value : ");
  scanf("%d",&x);
  a=1;
  i=2;
  j=m;
  while(j>1)
  {
	if(j%i==0)
  	{
  		j=j/i;
		if(a%i!=0)
  			a=a*i;
  		i=2;	
	}
	else
		i=i+1;
  }
  if(m%4==0&&a%4!=0)
  	a=a*2;
  if(m%4==0&&a%4!=0)
  	a=a*2;
  a=a+1; 
  printf("a=%d\n",a); 	
  for(i=0;i<m;i++)
  {
  	printf("\n%d",x);
  	x=((a*x)+1)%m;
  }
  getch();
  return 0;
}
