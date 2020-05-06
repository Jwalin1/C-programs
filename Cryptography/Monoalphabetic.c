#include <stdio.h>

int main()
{
    int i,j;
    char ch,c[100],key[26],key1[26];
    printf("Enter string\n");
    scanf("%[^\n]s",&c);
    printf("Enter key\n");
    for(i=0; i<26; i++)
    {
        printf("%c : ",i+97);
        scanf(" %c",&key[i]);
        if(key[i]<97||key[i]>122)
        {
            printf("Something is wrong with the key.");
            return 0;
        }
        key[i]=key[i]-97;
        key1[key[i]]=i;
    }
    for(i=0; i<26; i++)
    {
        for(j=0; j<26; j++)
        {
            if(i!=j&&(key[i]==key[j]))
            {
                printf("Something is wrong with the key.");
                return 0;
            }
        }
    }
    printf("\nencrypt(e)/decrypt(d)? ");
    scanf(" %c",&ch);
    if(ch=='e')
    {
        for(i=0; c[i]!='\0'; i++)
        {
            if(c[i]>=65&&c[i]<=90)          //for capital letters
                c[i]=65+key[(c[i]-65)%26];
            else if(c[i]>=97&&c[i]<=122)    //for small letters
                c[i]=97+key[(c[i]-97)%26];
        }
        printf("\nAfter encryption\n%s",c);
    }
    if(ch=='d')
    {
        for(i=0; c[i]!='\0'; i++)
        {
            if(c[i]>=65&&c[i]<=90)          //for capital letters
                c[i]=65+key1[(c[i]-65)%26];
            else if(c[i]>=97&&c[i]<=122)    //for small letters
                c[i]=97+key1[(c[i]-97)%26];
        }
        printf("\nAfter decryption\n%s",c);
    }
    getch();
    return 0;
}
