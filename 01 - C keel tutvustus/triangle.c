#include <stdio.h>
#include <math.h>

int main() {
    int side1, side2;
    printf("Please input the triangle base and height:\n");
    scanf("%d %d", &side1, &side2);
    float area = (float) (side1 * side2) / 2;
    float hypotenuse = sqrt(pow(side1, 2) + pow(side2, 2));
    printf("Triangle area is %0.1f. Hypotenuse is %0.1f", area, hypotenuse);
}