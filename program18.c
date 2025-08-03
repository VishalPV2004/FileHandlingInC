#include<stdio.h>

int main()
{
    FILE *fp = fopen("abc.txt","r");
    if (fp == NULL)
    {
        perror("ERROR OPENING FILE");
    }
    
    long begin = ftell(fp);
    fseek(fp,0,SEEK_END);
    long end = ftell(fp);
    printf("No of bytes : %ld",(end-begin));
}
