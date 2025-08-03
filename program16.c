#include<stdio.h>

void read(FILE *fp)
{
    int ch;
    while((ch = getc(fp)) != -1)
    {
       printf("%c",ch);
       fseek(fp,-1,SEEK_CUR);
       fseek(fp,1,SEEK_CUR);
    }
}

int main()
{
    FILE *fp = fopen("abc.txt","r");
    if (fp == NULL)
    {
        perror("ERROR OPENING FILE");
    }
    
    read(fp);
}
