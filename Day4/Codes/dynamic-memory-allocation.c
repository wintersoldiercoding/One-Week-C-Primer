#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int num_elements = 5;

    // Dynamically allocate memory for an array of integers
    arr = (int*)malloc(num_elements * sizeof(int));

    if (arr != NULL) {
        for (int i = 0; i < num_elements; i++) {
            arr[i] = i + 1; // Initialize array elements
        }

        printf("Array elements: ");
        for (int i = 0; i < num_elements; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        // Free the dynamically allocated memory when no longer needed
        free(arr);
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}
