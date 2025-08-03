#include <stdio.h>
#include <string.h>

void sort(char arr[][20], int n) {
    char temp[20];
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[i], arr[j]) > 0) 
            {
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
}

int main() {
    FILE *fp;
    fp = fopen("abc.txt", "r");
    if (fp == NULL) {
        perror("INVALID file");
        return 0;
    }

    int i = 0;
    char name[100][20];
    char str[20];
    while (fscanf(fp, "%s", str) != EOF) {
        strcpy(name[i], str);
        i++;
    }

    fclose(fp);
    sort(name, i);  

    printf("Sorted names:\n");
    for (int j = 0; j < i; j++) {
        printf("%s\n", name[j]);
    }
    
    FILE *fp1 = fopen("abc.txt","w+");
    
    for (int j = 0; j < i; j++) {
       fprintf(fp1, "%s\n", name[j]);
    }

    fclose(fp1);
    return 0;
}
