#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[20];
    float salary;
} employee;

#define FILE_NAME "employees.bin"

void add_employee() {
    employee e;
    FILE *fp = fopen(FILE_NAME, "ab");
    if (!fp) {
        perror("File open failed");
        return;
    }
    printf("Enter ID, Name, Salary: ");
    scanf("%d %s %f", &e.id, e.name, &e.salary);
    fwrite(&e, sizeof(employee), 1, fp);
    fclose(fp);
}

void display_all() {
    employee e;
    FILE *fp = fopen(FILE_NAME, "rb");
    printf("\nAll Employees:\n");
    while (fread(&e, sizeof(employee), 1, fp)) {
        printf("ID: %d\tName: %s\tSalary: %.2f\n", e.id, e.name, e.salary);
    }
    fclose(fp);
}

void update_employee(int id) {
    employee e;
    FILE *fp = fopen(FILE_NAME, "r+b");
    
    while (fread(&e, sizeof(employee), 1, fp)) {
        if (e.id == id) {
            printf("Enter new name and salary: ");
            scanf("%s %f", e.name, &e.salary);
            fseek(fp, -sizeof(employee), SEEK_CUR);
            fwrite(&e, sizeof(employee), 1, fp);
            printf("Record updated.\n");
            fclose(fp);
            return;
        }
    }
    printf("Record not found.\n");
    fclose(fp);
}

void search_employee(int id) {
    employee e;
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        perror("File open failed");
        return;
    }
    while (fread(&e, sizeof(employee), 1, fp)) {
        if (e.id == id) {
            printf("Found: ID: %d, Name: %s, Salary: %.2f\n", e.id, e.name, e.salary);
            fclose(fp);
            return;
        }
    }
    printf("Record not found.\n");
    fclose(fp);
}

void delete_employee(int id) {
    employee e;
    FILE *fp = fopen(FILE_NAME, "rb");
    FILE *temp = fopen("temp.bin", "wb");

    if (!fp || !temp) {
        perror("File open failed");
        return;
    }

    int found = 0;
    while (fread(&e, sizeof(employee), 1, fp)) {
        if (e.id != id) {
            fwrite(&e, sizeof(employee), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove(FILE_NAME);
    rename("temp.bin", FILE_NAME);

    if (found) printf("Record deleted.\n");
    else printf("Record not found.\n");
}


int main() {
    int choice, id;

    while (1) {
        printf("\n1. Add\n2. Display All\n3. Update\n4. Search\n5. Delete\n6. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_employee(); break;
            case 2: display_all(); break;
            case 3:
                printf("Enter ID to update: ");
                scanf("%d", &id);
                update_employee(id);
                break;
            case 4:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                search_employee(id);
                break;
            case 5:
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                delete_employee(id);
                break;
            case 6: exit(0);
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}
