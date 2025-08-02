#include <stdio.h>

int main() {
    FILE *fp = fopen("abc.txt", "r");

    if (fp == NULL) {
        perror("Unable to open file");
        return 1;
    }

    int ch;
    while ((ch = fgetc(fp)) != -1) {
        printf("%c",ch);
    }

    fclose(fp);
    return 0;
}
