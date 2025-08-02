
//--------------------------using fprintf()---------------------------

#include<stdio.h>
int main()
{
    FILE *fp;
    fp = fopen("file1.txt","w+");
    
    if (fp == NULL)
    {
        printf("Not able to open file!");
    }
    
    char *str = "Hello World!";
    
    int result = fprintf(fp,"%s",str);
    
    if (result == 0)
       printf("Write not successful!");
    else
       printf("Write completed!");
    return 0;
}

//-------------------------using putc()----------------------------------
/*

#include<stdio.h>

int main()
{
    FILE *fp = fopen("file1.txt","r+");
    
    if (fp == NULL)
    {
        perror("File invalid!");
    }
    
    char *str = "PHello";
    
    while(*str != '\0')
    {
        putc(*str,fp);
        str++;
    }
}

*/

