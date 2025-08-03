#include <stdio.h>
#include <stdlib.h>

void delete_line(const char *filename, int line_to_delete) {
    FILE *fp = fopen(filename, "r");
    FILE *temp = fopen("temp.txt", "w");

    if (!fp || !temp) {
        perror("File error");
        return;
    }

    char buffer[1024];
    int line = 1;

    while (fgets(buffer, sizeof(buffer), fp)) {
        if (line != line_to_delete)
            fputs(buffer, temp);
        line++;
    }

    fclose(fp);
    fclose(temp);

    remove(filename);
    rename("temp.txt", filename);
}


void insert_line(const char *filename, const char *newline, int position) {
    FILE *fp = fopen(filename, "r");
    FILE *temp = fopen("temp.txt", "w");

    if (!fp || !temp) {
        perror("File error");
        return;
    }

    char buffer[1024];
    int line = 1;

    while (fgets(buffer, sizeof(buffer), fp)) {
        if (line == position)
            fprintf(temp, "%s\n", newline);  // insert before this line
        fputs(buffer, temp);
        line++;
    }

    // if position is after EOF
    if (position >= line)
        fprintf(temp, "%s\n", newline);

    fclose(fp);
    fclose(temp);

    remove(filename);
    rename("temp.txt", filename);
}

int main() {
    delete_line("abc.txt", 3);                   // delete line 3
    insert_line("abc.txt", "This is inserted", 2); // insert at line 2
    return 0;
}
