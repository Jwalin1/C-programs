#include <stdio.h>
#include <math.h>

int mod(int a, int b)
{ return a-b*floor((float)a/b); }

int main()
{
    int i,j,t,R[25],C[25];
    char ch,c[100],key[50];
    printf("Enter string\n");
    scanf("%[^\n]s",&c);
    printf("Enter key\n");
    scanf(" %[^\n]s",&key);
    for(i=0; key[i]!='\0'; i++)
    {
        if((key[i]<97||key[i]>122)&&(key[i]!=32))    //check for invalid key
        {
            printf("Something is wrong with the key.");
            return 0;
        }
        if(key[i]==106)
        	key[i]=105;
        for(j=i-1; j>=0; j--)    //remove repetitions from key
        {
            if((key[i]==key[j])||(key[i]==32))
            {
                for(t=i; key[t]!='\0'; t++)
                    key[t]=key[t+1];
                i=i-1;
            }
        }
    }
    t=i;
    for(i=0; i<26; i++)        //adding remaining alphabets to the key
    {
        for(j=t-1; j>=0; j--)
        {
            if(key[j]==i+97||i==9)
                break;
        }
        if(j==-1)
        {
            key[t]=i+97;
            t=t+1;
        }
    }
    printf("\nKey Table\n");
    for(i=0; i<5; i++)
    {
        for(j=0; j<5; j++)
        {
            printf("%c ",key[(i*5)+j]);
        }
        printf("\n");
    }
    for(i=0; i<25; i++)        //forming row and column matrices
    {
        R[key[i]-97]=i/5;
        C[key[i]-97]=i-(5*(i/5));
    }
    printf("\nencrypt(e)/decrypt(d)? ");
    scanf(" %c",&ch);
    if(ch=='e')
    {
        t=0;
        for(i=0; c[i]!='\0'; i++)    //counting total alphabets
            t=t+1;
        for(i=0; c[i]!='\0';)    //inserting 'x' between same letters
        {
            while(c[i]<97||c[i]>122)
                i=i+1;
            i=i+1;
            while(c[i]<97||c[i]>122)
                i=i+1;
            j=i-1;
            while(c[j]<97||c[j]>122)
                j=j-1;
            if(c[i]==c[j])
            {
                for(j=t; j!=i; j--)
                {
                    c[j]=c[j-1];
                }
                c[t+1]='\0';
                c[i]=120;
                for(i=0; c[i]!='\0'; i++)    //counting total alphabets
                    t=t+1;
                i=-1;
            }
            i=i+1;
        }
        t=0;
        for(i=0; c[i]!='\0'; i++)    //counting total to check odd/even
            if(c[i]>=97&&c[i]<=122)
                t=t+1;
        if(t%2==1)        //adding 'x' in the end if odd
        {
            c[i]=120;
            c[i+1]='\0';
        }
        printf("\nString after adding null 'x'\n%s",c);
        i=0;
        while(c[i]!='\0')
        {
            while(c[i]<97||c[i]>122)
                i=i+1;
            j=i+1;
            while(c[j]<97||c[j]>122)
                j=j+1;
            if(R[c[i]-97]==R[c[j]-97])        //if same row
            {
                c[i]=key[(R[c[i]-97]*5)+mod((C[c[i]-97]+1),5)];
                c[j]=key[(R[c[j]-97]*5)+mod((C[c[j]-97]+1),5)];
            }
            else if(C[c[i]-97]==C[c[j]-97])    //if same column
            {
                c[i]=key[(mod((R[c[i]-97]+1),5)*5)+C[c[i]-97]];
                c[j]=key[(mod((R[c[j]-97]+1),5)*5)+C[c[j]-97]];
            }
            else
            {
                t=key[(mod(R[c[i]-97],5)*5)+C[c[j]-97]];
                c[j]=key[(mod(R[c[j]-97],5)*5)+C[c[i]-97]];
                c[i]=t;
            }
            i=j+1;
        }
        printf("\n\nAfter encryption\n%s",c);
    }
    if(ch=='d')
    {
        i=0;
        while(c[i]!='\0')
        {
            while(c[i]<97||c[i]>122)
                i=i+1;
            j=i+1;
            while(c[j]<97||c[j]>122)
                j=j+1;
            if(R[c[i]-97]==R[c[j]-97])        //if same row
            {
                c[i]=key[(R[c[i]-97]*5)+mod((C[c[i]-97]-1),5)];
                c[j]=key[(R[c[j]-97]*5)+mod((C[c[j]-97]-1),5)];
            }
            else if(C[c[i]-97]==C[c[j]-97])    //if same column
            {
                c[i]=key[(mod((R[c[i]-97]-1),5)*5)+C[c[i]-97]];
                c[j]=key[(mod((R[c[j]-97]-1),5)*5)+C[c[j]-97]];
            }
            else
            {
                t=key[(mod(R[c[i]-97],5)*5)+C[c[j]-97]];
                c[j]=key[(mod(R[c[j]-97],5)*5)+C[c[i]-97]];
                c[i]=t;
            }
            i=j+1;
        }
        printf("\n\nAfter decryption\n%s",c);
    }
    getch();
    return 0;
}

