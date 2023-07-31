#include <stdio.h>
#include<string.h>
// Structure declaration
struct Person {
    char name[50];
    int age;
    float height;
};

int main() {
    // Structure variable declaration
    struct Person person1;

    // Accessing structure members using the dot operator
    strcpy(person1.name, "John");
    person1.age = 25;
    person1.height = 5.9;

    // Printing structure members
    printf("Name: %s\n", person1.name);
    printf("Age: %d\n", person1.age);
    printf("Height: %.2f\n", person1.height);

    return 0;
}
