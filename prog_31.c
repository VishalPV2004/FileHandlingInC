#include <stdio.h>
#include <string.h>

int compare(char *s, char *j)
{
    while (*s && (*s == *j)) {
        s++;
        j++;
    }

    if (*s > *j)
        return 1;
    if (*s < *j)
        return -1;
    return 0;
}

void copy(char *s, char *p)
{
    while(*p)
    {
        *s = *p;
        s++;
        p++;
    }
    *s = '\0';
}

void sort(char name[100][20], int i) {
    for (int j = 0; j < i - 1; j++) {
        for (int k = j + 1; k < i; k++) {
            if (compare(name[j], name[k]) > 0) {
                char str[20];
                copy(str, name[j]);
                copy(name[j], name[k]);
                copy(name[k], str);
            }
        }
    }
}

void modify(char name[100][20], int i) {
    FILE *fp = fopen("abc.txt", "w");
    if (fp == NULL) {
        perror("Cannot open file to write");
        return;
    }

    for (int j = 0; j < i; j++) {
        fprintf(fp, "%s\n", name[j]);
    }

    fclose(fp);
}

int main() {
    FILE *fp = fopen("abc.txt", "r");
    if (fp == NULL) {
        perror("INVALID file");
        return 0;
    }

    int i = 0;
    char name[100][20];
    while (fscanf(fp, "%s", name[i]) != EOF) {
        i++;
    }

    fclose(fp);

    sort(name, i);  
    modify(name, i);
    return 0;
}
