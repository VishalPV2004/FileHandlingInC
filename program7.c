#include<stdio.h>

int main()
{
    FILE *fp1, *fp2;
    fp1 = fopen("abc.txt","r+");
    if (fp1 == NULL)
       perror("File 1 doesnt exist!");
    
    fp2 = fopen("def.txt","r+");
    if (fp2 == NULL)
       perror("File 2 doesnt exist!");
    
    int ch1;
    int ch2;
    
    while((ch1 = getc(fp1)) == (ch2 = getc(fp2)))
    {
        if (ch1 == EOF || ch2 == EOF)
          break;
    }
    
    if (ch1 == EOF || ch2 == EOF)
      printf("No difference");
    else  
      printf("Difference : %c %c",ch1,ch2);
}
