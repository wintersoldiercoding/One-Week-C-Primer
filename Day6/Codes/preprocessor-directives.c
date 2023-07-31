#include <stdio.h>

#define PI 3.14159
#define SQUARE(x) ((x) * (x))

#ifndef DEBUG
    #define DEBUG // Uncomment to enable debugging
#endif

int main() {
    #ifdef DEBUG
        printf("Debugging mode is enabled.\n");
    #else
        printf("Debugging mode is not enabled.\n");
    #endif

    printf("Area of a circle with radius 5: %.2f\n", PI * SQUARE(5));

    return 0;
}
