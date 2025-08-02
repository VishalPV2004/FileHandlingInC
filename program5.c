//---------------------using getc()------------------------

#include<stdio.h>

int main()
{
    FILE *fp1;
    FILE *fp2;
    
    fp1 = fopen("file1.txt","r+");
    if (fp1 == NULL)
       perror("INVALID FILE 1");
       
    fp2 = fopen("file2.txt","w+");
    if (fp2 == NULL)
       perror("INVALID FILE 2");
    
    int ch;
    while((ch = getc(fp1)) != EOF)
    {
        putc(ch,fp2);
    }
    
}

//----------------------using fscanf()-----------------------
/*
#include<stdio.h>

int main()
{
    FILE *fp1;
    FILE *fp2;
    
    fp1 = fopen("file1.txt","r+");
    if (fp1 == NULL)
       perror("INVALID FILE 1");
       
    fp2 = fopen("file2.txt","w+");
    if (fp2 == NULL)
       perror("INVALID FILE 2");
    
    char str[100];
    
    while(fscanf(fp1,"%[^\n]%*c",str) != -1)
    {
        fprintf(fp2,"%s\n",str);
    }
    
}
*/
