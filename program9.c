#include<stdio.h>

int main()
{
    FILE *fp;
    fp = fopen("abc.txt","r+");
    
    if (fp == NULL)
       perror("INVALID FILE");
    
    char buffer[100];
    
    while(fgets(buffer,sizeof(buffer),fp) != NULL)
    {
        printf("%s",buffer);
    }
    
    return 0;
}
