#include <stdio.h>

int globalVar = 10; // Global variable with static storage class

void demo() {
    auto int localVarAuto = 5; // Automatic (local) variable
    static int localVarStatic = 20; // Static local variable

    printf("Local auto variable: %d\n", localVarAuto);
    printf("Local static variable: %d\n", localVarStatic);
}

int main() {
    extern int externVar; // Declaration of an external variable (defined elsewhere)

    demo();

    printf("Global variable: %d\n", globalVar);
    printf("Extern variable: %d\n", externVar);

    return 0;
}