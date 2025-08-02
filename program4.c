#include <stdio.h>

int main() {
    FILE *fp = fopen("abc.txt", "r+");
    
    if (fp == NULL) {
        printf("INVALID FILE!");
        return 1;
    }
    
    int characters = 0, words = 0, lines = 0;
    int ch, prev;
    
    while ((ch = getc(fp)) != EOF) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
            characters++;

        if (ch == '\n')
            lines++;

        if ((ch == ' ' || ch == '\n' || ch == '\t') && (prev != ' ' || prev != '\n' || prev != '\t')) {
            words++;
        }

    }

    printf("Characters : %d, Words : %d, Lines : %d\n", characters, words, ++lines);
    fclose(fp);
    return 0;
}
