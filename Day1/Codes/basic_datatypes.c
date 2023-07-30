#include <stdio.h>

int main() {
    // Integer Data Types
    int age = 25;
    short distance = 100;
    long population = 789654320;
    long long largeNumber = 98765432109876LL;

    // Floating-Point Data Types
    float weight = 75.5;
    double pi = 3.14159265359;
    long double bigPi = 3.14159265358979323846L;

    // Character Data Type
    char grade = 'A';

    printf("Age: %d\n", age);
    printf("Distance: %hd\n", distance);
    printf("Population: %ld\n", population);
    printf("Large Number: %lld\n", largeNumber);

    printf("Weight: %.1f\n", weight);
    printf("PI: %.11f\n", pi);
    printf("Big PI: %.20Lf\n", bigPi);

    printf("Grade: %c\n", grade);
    return 0;
}
