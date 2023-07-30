#include <stdio.h>

int main() {
    // Output using printf
    int age = 25;
    printf("My age is %d years.\n", age);

    float pi = 3.14159;
    printf("The value of PI is %.5f.\n", pi);

    char name[20];
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Welcome, %s!\n", name);

    return 0;
}
