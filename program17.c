#include <stdio.h>
#include <string.h>

void modify(FILE *fp) {
    char name[100];
    float val;
    long pos;
    char str[100];

    while(fscanf(fp,"%s %f\n",name,&val) != EOF)
    {
        pos = ftell(fp);
        fseek(fp,(-pos),SEEK_CUR);
        
        if (val > 2.000000)
        {
            val += 10.000000;
        }
        if (strcmp(name,"VISHAL") == 0)
        {
           strcpy(str,"VISHAL_PV");   
           fprintf(fp,"%s %f\n",str,val);
        }
        else
        {
          fprintf(fp,"%s %f\n",name,val);
        }
    }
}

int main() {
    FILE *fp = fopen("abc.txt", "r+");
    if (!fp) {
        perror("File open failed");
        return 1;
    }

    modify(fp);
    fclose(fp);
    return 0;
}
