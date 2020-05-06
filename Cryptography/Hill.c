#include <stdio.h>
#include <math.h>
int n,tmp[100],key[20][20];

int mod(int a, int b)
{ return a-b*floor((float)a/b); }

mul()
{
    int i,j,s[100],sum;
    for(i=0; i<100; i++)
        s[i]=0;
    for(i=0; i<n; i++)
    {
        sum=0;
		for(j=0; j<n; j++)
            sum=sum+(key[i][j]*tmp[j]);
        s[i]=mod(sum,26);    
    }    
    for(i=0; i<n; i++)
        tmp[i]=s[i];
}

int main()
{
    int i,j,t=0;
    char ch,c[100];
    printf("Enter string\n");
    scanf("%[^\n]s",&c);
    printf("\nEnter size of key : ");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("key[%d][%d] = ",i+1,j+1);
            scanf("%d",&key[i][j]);
        }
    }
        printf("\nKey matrix\n");
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                printf("%d ",key[i][j]);
            }
            printf("\n");
        }
    for(i=0; c[i]!='\0'; i++)
    {
        if(t==n)
        {
            mul();
            j=i-1;
            while(t>0)
            {
                while((c[j]<65||c[j]>90)&&(c[j]<97||c[j]>122)&&(c[j]<48||c[j]>57))
                    j=j-1;
                if(c[j]>=65&&c[j]<=90)
                    c[j]=tmp[t-1]+65;
                else if(c[j]>=97&&c[j]<=122)
                    c[j]=tmp[t-1]+97;
                else if(c[j]>=48&&c[j]<=57)
                    c[j]=tmp[t-1]+48;
                j=j-1;
                t=t-1;
            }
        }
        if(c[i]>=65&&c[i]<=90)
            tmp[t]=c[i]-65;
        else if(c[i]>=97&&c[i]<=122)
            tmp[t]=c[i]-97;
        else if(c[i]>=48&&c[i]<=57)
            tmp[t]=c[i]-48;
        else
            t=t-1;
        t=t+1;
    }
    mul();
    j=i-1;
    while(t>0)
    {
        while((c[j]<65||c[j]>90)&&(c[j]<97||c[j]>122)&&(c[j]<48||c[j]>57))
            j=j-1;
        if(c[j]>=65&&c[j]<=90)
            c[j]=tmp[t-1]+65;
        else if(c[j]>=97&&c[j]<=122)
            c[j]=tmp[t-1]+97;
        else if(c[j]>=48&&c[j]<=57)
            c[j]=tmp[t-1]+48;
        j=j-1;
        t=t-1;
    }
    printf("\nAfter encryption\n%s",c);
    getch();
    return 0;
}
