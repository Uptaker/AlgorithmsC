#include <stdio.h>

main() {
    int side1, side2;
    printf("Please input the triangle base and height:\n");
    scanf("%d %d", &side1, &side2);
    float area = (side1 * side2) / 2;
    printf("Triangle area is %0.2f", area);
}