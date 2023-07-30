#include <stdio.h>

int main() {
    int i;

    // Loop from 1 to 10, skip even numbers, and break at 7
    for (i = 1; i <= 10; i++) {
        if (i % 2 == 0) {
            continue; // Skip even numbers
        }

        printf("%d ", i);

        if (i == 7) {
            break; // Break the loop when i is 7
        }
    }

    return 0;
}
