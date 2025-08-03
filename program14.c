#include<stdio.h>
#include<stdlib.h>

void write(FILE *fp)
{
    printf("1 for entry, -1 for termination!\n");
    int ch;
    char name[50];
    float marks;
    
    while (1)
    {
        scanf("%d", &ch);
        
        if (ch == -1)
        {
            printf("Terminated!\n");
            break;
        }
        else if (ch == 1)
        {
            printf("Enter your name: ");
            scanf("%s", name); // or use fgets for full name
            printf("Enter your marks: ");
            scanf("%f", &marks);
            
            int result = fprintf(fp, "%s %f\n", name, marks);
            
            if (result > 0)
            {
                printf("Write successful!\n");
            }
        }
        else
        {
            printf("Invalid type :(\n");
        }
    }
}

void read(FILE *fp)
{
    fseek(fp, 0, SEEK_SET);
    long begin = ftell(fp);
    fseek(fp, 0, SEEK_END);
    long end = ftell(fp);
    
    if (begin == end)
    {
        printf("File Empty!\n");
        return;
    }

    fseek(fp, 0, SEEK_SET);  // Go back to beginning before reading

    char str[50];
    float f;
    printf("\n--- Reading from File ---\n");
    while (fscanf(fp, "%s %f", str, &f) != EOF)
    {
        printf("%s %.2f\n", str, f);
    }
}

int main()
{
    FILE *fp = fopen("abc.txt", "w+");
    if (fp == NULL)
    {
        perror("INVALID FILE!");
        return 1;
    }
    
    write(fp);
    read(fp);
    
    fclose(fp);
    return 0;
}
