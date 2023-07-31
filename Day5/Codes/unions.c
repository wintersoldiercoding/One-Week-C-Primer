#include <stdio.h>
#include<string.h>
// Union declaration
union Data {
    int intValue;
    float floatValue;
    char stringValue[20];
};

int main() {
    union Data data;

    data.intValue = 42;
    printf("Int Value: %d\n", data.intValue);

    data.floatValue = 3.14;
    printf("Float Value: %.2f\n", data.floatValue);

    strcpy(data.stringValue, "Hello");
    printf("String Value: %s\n", data.stringValue);

    return 0;
}
