#include <stdio.h>
#include<string.h>
int main() {
    char str1[20] = "Hello";
    char str2[] = " World";

    // Concatenate str2 to str1
    strcat(str1, str2);
    printf("Concatenated string: %s\n", str1); // Output: Hello World

    // Get the length of the string
    int length = strlen(str1);
    printf("Length of the string: %d\n", length); // Output: 11

    // Copy one string to another
    char copy[20];
    strcpy(copy, str1);
    printf("Copied string: %s\n", copy); // Output: Hello World

    // Compare two strings
    int result = strcmp(str1, "Hello World");
    if (result == 0) {
        printf("The strings are equal.\n");
    } else {
        printf("The strings are not equal.\n");
    }

    return 0;
}
