#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp = fopen("abc.txt", "a+");
    if (fp == NULL) {
        perror("Failed to open the file!");
        return 1;
    }

    char *str = (char *)calloc(100, sizeof(char));
    if (str == NULL) {
        printf("Memory Allocation failed\n");
        exit(1);
    }

    int choice;

    while (1)
    {
        printf("Enter 1 to add phone number, -1 to stop: ");
        scanf("%d", &choice);           //scanf leaves /n in stdin, so we consume it
        getchar(); // consume the leftover '\n'

        if (choice == -1)
            break;
        else if (choice == 1)
        {
            printf("Enter your phone number: ");
            fgets(str, 100, stdin);

            // Remove trailing newline
            str[strcspn(str, "\n")] = '\0';   //fgets() adds /n at end like "Hello\n\0"

            int result = fprintf(fp, "+91 %s\n", str);
            if (result > 0)
                printf("Write successful!\n");
            else
                printf("Write not successful!\n");
        }
        else
        {
            printf("Invalid input!\n");
        }
    }

    fclose(fp);
    free(str);
    return 0;
}
