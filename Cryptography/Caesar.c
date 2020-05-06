#include <stdio.h>
#include <math.h>

int mod(int a, int b)
{ return a-b*floor((float)a/b); }

int main()
{
    int i,n;
    char ch,c[100];
    printf("Enter string\n");
    scanf("%[^\n]s",&c);
    printf("Enter key : ");
    scanf("%d",&n);
    printf("\nencrypt(e)/decrypt(d)? ");
    scanf(" %c",&ch);
    if(ch=='e')
    {
        for(i=0; c[i]!='\0'; i++)
        {
            if(c[i]>=65&&c[i]<=90)          //for capital letters
                c[i]=65+mod((c[i]-65+n),26);
            else if(c[i]>=97&&c[i]<=122)    //for small letters
                c[i]=97+mod((c[i]-97+n),26);
            else if(c[i]>=48&&c[i]<=57)    //for numbers
                c[i]=48+mod((c[i]-48+n),10); 
        }
        printf("\nAfter encryption\n%s",c);
    }
    if(ch=='d')
    {
        for(i=0; c[i]!='\0'; i++)
        {
            if(c[i]>=65&&c[i]<=90)          //for capital letters
                c[i]=65+mod((c[i]-65-n),26);
            else if(c[i]>=97&&c[i]<=122)    //for small letters
                c[i]=97+mod((c[i]-97-n),26);
            else if(c[i]>=48&&c[i]<=57)    //for numbers
                c[i]=48+mod((c[i]-48-n),10);
        }
        printf("\nAfter decryption\n%s",c);
    }
    getch();
    return 0;
}
