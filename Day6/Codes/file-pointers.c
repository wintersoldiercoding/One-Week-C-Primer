#include <stdio.h>

int main() {
    FILE *filePointer;
    char ch;

    // Writing data to a file
    filePointer = fopen("example.txt", "w");

    if (filePointer == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    fprintf(filePointer, "Hello, World!\n");
    fprintf(filePointer, "This is a sample file.\n");

    fclose(filePointer);

    // Reading data from a file using file pointer
    filePointer = fopen("example.txt", "r");

    if (filePointer == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    while ((ch = fgetc(filePointer)) != EOF) {
        printf("%c", ch);
    }

    fclose(filePointer);

    return 0;
}
