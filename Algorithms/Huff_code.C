#include<stdio.h> 
#include<conio.h>  
#include <math.h>
int min,place,sc,count=1,I,N=0,F=0,uc[128],b[128][15];
char c[100000],s[128];

void same_count()
{
	int i,j; 
	sc=1;
	for(i=0;i<127;i++)
 {
 	if(uc[i]==0){continue;}
 	for(j=i+1;j<=127;j++)
 {
 	if(uc[j]==0){continue;}
	if(uc[i]==uc[j]){sc=sc+1;}
 	else break;
 }break;
}
}

void disp()
{
	int i;
	for(i=0;i<=127;i++)
 {
 	if(uc[i]==0){continue;}
	printf("%d ",uc[i]);
 }
 printf("\n");
}

void sort()
{
	 int i,j,temp;
	 for(i=0;i<127;i++)
 {
 	if(uc[i]==0){continue;}
	 for(j=i+1;j<=127;j++)
 	{
 	  if(uc[j]==0){continue;}
	  if(uc[j]<uc[i])
	  {
	  	if(i==place){place=j;}
	  	else if(j==place){place=i;}
		temp=uc[i];
		uc[i]=uc[j];
		uc[j]=temp;
		temp=s[i];
		s[i]=s[j];
		s[j]=temp;
	  }
 	}
 }		
}

void sort1()
{
	 int i,j,k,temp[15];
	 for(i=0;i<127;i++)
 {
 	if(b[i][0]==-1){continue;}
	 for(j=i+1;j<=127;j++)
 	{
 	  if(b[j][0]==-1){continue;}
	  if(b[j][0]<b[i][0])
	  {
		for(k=0;k<15;k++){temp[k]=b[i][k];}
		for(k=0;k<15;k++){b[i][k]=b[j][k];}
		for(k=0;k<15;k++){b[j][k]=temp[k];}
	  }
 	}
 }		
}

void prep()
{
	int i;
	for(i=0;i<=127;i++){uc[i]=0;}	
	for(i=0;i<N;i++)
 	{
 		uc[c[i]]=uc[c[i]]+1;
 	}
 	sort(); 
}

void generate()
{
	int i,A,B,f=0,F1=0;
	same_count();
	for(i=0;i<=127;i++)
 {
	if(uc[i]==0){continue;}
	if(f==0)
	{
		A=uc[i]; 
		if(i==place){F1=1;}
	}
	if(f==1)
	{
		B=uc[i];
		if(i==place){F1=2;}
		if(F1>0)
		{
			place=i;
			if(F1==2){b[I][count]=1;}
			else {b[I][count]=0;}
			count=count+1;
			F1=0;
		}	
	}
	f=f+1; 
	uc[i]=0; 
	if(f==2)
	{
		uc[i]=A+B;  
		sort(); 
		sc=sc-2;
		if(sc<2&&F==0) { if(F==0){disp();} same_count(); }
		f=0; i=0; F1=0;
	}
 }
 F=1;
}

int main() 
{ 
 int i,j=0,n=0,sum=0;
 char sorted[128]; 	
 //clrscr(); 
 for(i=0;i<=127;i++){s[i]=0; sorted[i]=0;}
 printf("Enter string\n"); 
 scanf("%[^\n]s",c);
 for(i=0;;i++)
 { if(c[i]=='\0'){break;} N=N+1; }
 printf("Length of string  : %d\n",N); 
 for(i=0;i<N;i++)
 	{
 		s[c[i]]=c[i];
 	}  
 prep(); 
  for(i=0;i<=127;i++)
 {
 	if(uc[i]==0){continue;}
	n=n+1;
 }  
 printf("Unique characters : %d\n",n);
 printf("\nHuffman tree\n"); 
  for(i=0;i<=127;i++)
 {
 	if(s[i]==0){continue;}
	sorted[j]=s[i]; printf("%c ",sorted[j]);
	j=j+1; 
 } 
 printf("\n"); disp();                            
 generate(); printf("\nHuffman code       Bits\n");
 for(i=0;i<=127;i++){for(j=0;j<15;j++){b[i][j]=-1;}}
 for(i=0;;i++)
 {	I=i;
 	if(sorted[i]==0){break;}
 	place=sorted[i]; 
 	prep(); generate(); 
	for(j=0;j<=127;j++) {uc[j]=0;}	
	for(j=0;j<N;j++) {uc[c[j]]=uc[c[j]]+1;}
	count=count-1;
	b[I][0]=count; b[I][count+1]=sorted[i];
	sum=sum+(uc[sorted[i]]*count);
	count=1;
 }
 sort1();
  for(i=0;i<=127;i++)
 {	
 	if(b[i][0]==-1){continue;}
 	printf("%c : ",b[i][1+b[i][0]]);
	for(j=b[i][0];j>=1;j--)
 	{
 		printf("%d",b[i][j]);
	}
	for(j=0;j<=15-b[i][0];j++){printf(" ");}
	printf("%d\n",b[i][0]); 
 }
 printf("\nSimple encoding  : %d bits",N*(int)ceil((double)log(n)/(double)log(2)));
 printf("\nHuffman encoding : %d bits",sum);
 printf("\nBits saved       : %d bits",N*(int)ceil((double)log(n)/(double)log(2))-sum);
 getch(); 
 return 0; 
}
