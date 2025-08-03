#include<stdio.h>

void read(FILE *fp)
{
    char str[100];
    float f;
    float sum = 0;
    int ct = 1;
    while(fscanf(fp,"%s %f",str,&f) != EOF)
    {
        printf("marks %d : %f",ct,f);
        sum = sum + f;
        ct++;
    }
    
    printf("Average : %f",(sum/ct));
}

int main()
{
    FILE *fp;
    
    fp = fopen("abc.txt","r");
    if (fp == NULL)
       perror("INVALID FILE");
    
    read(fp);
}
