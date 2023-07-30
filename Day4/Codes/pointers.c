#include <stdio.h>

int main() {
    int num = 42;
    int *ptr = &num; // Pointer pointing to the address of 'num'

    printf("Address of 'num': %p\n", &num);
    printf("Value of 'num': %d\n", num);
    printf("Address stored in 'ptr': %p\n", ptr);
    printf("Value pointed by 'ptr': %d\n", *ptr);

    return 0;
}
