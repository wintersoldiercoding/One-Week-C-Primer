#include <stdio.h>

int main() {
    // Identifiers
    int age = 25;
    float pi = 3.14159;
    char initial = 'A';

    // Keywords (Using as identifiers would result in a compilation error)
    // int int;    // Invalid: "int" is a keyword.
    // float float;  // Invalid: "float" is a keyword.
    // char char;    // Invalid: "char" is a keyword.

    printf("Age: %d\n", age);
    printf("PI: %.5f\n", pi);
    printf("Initial: %c\n", initial);
    return 0;
}
