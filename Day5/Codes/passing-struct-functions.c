#include <stdio.h>

struct Rectangle {
    int length;
    int width;
};

void printRectangle(struct Rectangle r) {
    printf("Rectangle: length=%d, width=%d\n", r.length, r.width);
}

int main() {
    struct Rectangle rect = {10, 5};
    printRectangle(rect);

    return 0;
}
