/*
Open a file in read mode and print its contents.

abc.txt
--------------
Hello World!
Hello
*/

//-------------------using fscanf()-----------------------
#include<stdio.h>

int main()
{
    FILE *fp;
    fp = fopen("abc.txt","r+");
    char str[100];
    while(fscanf(fp,"%[^\n]%*c",str) != -1)
    {
      printf("%s",str); 
      printf("\n");
    }
}


//-------------------using getc()-----------------------
/*
#include<stdio.h>

int main()
{
    FILE *fp;
    fp = fopen("abc.txt","r+");
    
    if (fp == NULL)
      perror("Invalid file!");
    
    int ch;
    
    while((ch = (getc(fp))) != EOF)
    {
        printf("%c",ch);
    }
}

*/
