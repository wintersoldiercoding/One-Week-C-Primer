#include <stdio.h>

struct Point {
    int x;
    int y;
};

void printPoint(struct Point p) {
    printf("Coordinates: (%d, %d)\n", p.x, p.y);
}

int main() {
    struct Point p1 = {5, 8};
    printPoint(p1);

    return 0;
}
