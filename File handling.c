#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char ch;
    char filename[100] = "example.txt";
    char data[100];

    // 1. Create and write to a file
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error creating file!\n");
        return 1;
    }
    printf("Enter text to write to the file: ");
    fgets(data, sizeof(data), stdin);
    fputs(data, fp);
    fclose(fp);
    printf("Data written to file.\n");

    // 2. Read from the file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }
    printf("Contents of the file:\n");
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    fclose(fp);

    // 3. Append to the file
    fp = fopen(filename, "a");
    if (fp == NULL) {
        printf("Error opening file for appending!\n");
        return 1;
    }
    printf("\nEnter text to append to the file: ");
    fgets(data, sizeof(data), stdin);
    fputs(data, fp);
    fclose(fp);
    printf("Data appended to file.\n");

    return 0;
}
