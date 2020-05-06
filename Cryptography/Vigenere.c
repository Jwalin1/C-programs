#include <stdio.h>
#include <math.h>

int mod(int a, int b)
{ return a-b*floor((float)a/b); }

int main()
{
    int i,t=0;
    char ch,c[100],key[50];
    printf("Enter string\n");
    scanf("%[^\n]s",&c);
    printf("Enter key\n");
    scanf(" %[^\n]s",&key);
    for(i=0; key[i]!='\0'; i++)    //counting key size
        t=t+1;
    for(i=t; c[i]!='\0'; i++)    //repeating the key
        key[i]=key[i-t];
    printf("\nencrypt(e)/decrypt(d)? ");
    scanf(" %c",&ch);
    if(ch=='e')
    {
        for(i=0; c[i]!='\0'; i++)
        {
            if(c[i]>=65&&c[i]<=90)          //for capital letters
                c[i]=65+mod((c[i]-65+(key[i]-97)),26);
            else if(c[i]>=97&&c[i]<=122)    //for small letters
                c[i]=97+mod((c[i]-97+(key[i]-97)),26);
            else if(c[i]>=48&&c[i]<=57)    //for numbers
                c[i]=48+mod((c[i]-48+(key[i]-97)),10);
        }
        printf("\nAfter encryption\n%s",c);
    }
    if(ch=='d')
    {
        for(i=0; c[i]!='\0'; i++)
        {
            if(c[i]>=65&&c[i]<=90)          //for capital letters
                c[i]=65+mod((c[i]-65-(key[i]-97)),26);
            else if(c[i]>=97&&c[i]<=122)    //for small letters
                c[i]=97+mod((c[i]-97-(key[i]-97)),26);
            else if(c[i]>=48&&c[i]<=57)    //for numbers
                c[i]=48+mod((c[i]-48-(key[i]-97)),10);
        }
        printf("\nAfter decryption\n%s",c);
    }
    getch();
    return 0;
}

