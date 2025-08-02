/*
Open a file in read mode and print its contents.

abc.txt
--------------
Hello World!
Hello
*/

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
