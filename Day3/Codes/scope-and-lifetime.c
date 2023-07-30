#include <stdio.h>

int globalVar = 10; // Global variable with static storage class

void demo() {
    auto int localVarAuto = 5; // Automatic (local) variable

    printf("Local auto variable: %d\n", localVarAuto);
}

int main() {
    static int staticVar = 20; // Static local variable

    printf("Global variable: %d\n", globalVar);
    printf("Static local variable: %d\n", staticVar);

    return 0;
}
