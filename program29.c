#include<stdio.h>

int main()
{
    FILE *fp = fopen("abc.txt","r+");
    
    if (fp == NULL)
    {
        perror("INVALID File");
        return 0;
    }
    
    int ch;
    while((ch = getc(fp)) != EOF)
    {
        if (ch >= 'a' && ch <= 'z')
        {
            ch = ch - 32;
        }
        printf("%c",ch);
    }
    
    return 0;
}
