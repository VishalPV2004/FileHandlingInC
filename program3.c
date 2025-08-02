//-------------------------------using fprintf()---------------------------

#include<stdio.h>
int main()
{
    FILE *fp;
    
    fp = fopen("abc.txt","a+");
    if (fp == NULL)
    {
        perror("Invalid file!");
    }
    
    char *str = "Hello World2";
    int result = fprintf(fp,"%s",str);
    if (result == 0)
    {
        printf("Write incomplete!");
    }
    else
    {
        printf("Write complete!");
    }
}

//-------------------------using putc--------------------------------------
/*
#include<stdio.h>

int main()
{
    FILE *fp;
    fp = fopen("abc.txt","a+");
    
    if (fp == NULL)
    {
        perror("Invalid FILE");
    }
    
    char *str = "Hello bro!";
    
    while(*str != '\0')
    {
        putc(*str,fp);
        str++;
    }
}
*/
