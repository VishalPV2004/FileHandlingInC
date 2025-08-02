#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp1, *fp2, *fp3;

    fp1 = fopen("abc.txt", "r+");
    if (fp1 == NULL) {
        perror("INVALID SOURCE 1");
        exit(1);
    }

    fp2 = fopen("def.txt", "r+");
    if (fp2 == NULL) {
        perror("INVALID SOURCE 2");
        exit(1);
    }

    fp3 = fopen("result.txt", "w+");
    if (fp3 == NULL) {
        perror("INVALID DESTINATION!");
        exit(1);
    }

    char *str1 = (char *)calloc(100, sizeof(char));
    char *str2 = (char *)calloc(100, sizeof(char));

    int ct1 = 0, ct2 = 0, ct3 = 0;
    int r1, r2;

    while ((r1 = fscanf(fp1, "%[^\n]%*c", str1)) != EOF &&
           (r2 = fscanf(fp2, "%[^\n]%*c", str2)) != EOF)
    {
        ct1 += 1;
        ct2 += 1;

        ct3 += 2;
        fprintf(fp3, "%s\n", str1);
        fprintf(fp3, "%s\n", str2);
    }

    while ((r1 = fscanf(fp1, "%[^\n]%*c", str1)) != EOF) {
        ct1 += 1;
        ct3 += 1;
        fprintf(fp3, "%s\n", str1);
    }

    while ((r2 = fscanf(fp2, "%[^\n]%*c", str2)) != EOF) {
        ct2 += 1;
        ct3 += 1;
        fprintf(fp3, "%s\n", str2);
    }

    if (ct3 == (ct1 + ct2))
        printf("All Data has been written\n");
    else
        printf("Inefficient copy!\n");

    free(str1);
    free(str2);
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);

    return 0;
}
