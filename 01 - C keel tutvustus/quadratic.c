#include <stdio.h>
#include <math.h>

void fail() {
    printf("Not a valid quadratic function");
}

void success(float x1, float x2) {
    printf("x1 is %0.1f and x2 is %0.1f", x1, x2);
}

void calculateQuadratic(int a, int b, int c) {
    float sqr = pow(b, 2) - (4 * a * c);
    if (sqr < 0) return fail();
    float x1 = ((-1 * b) + sqrt(sqr)) / (2 * a);
    float x2 = ((-1 * b) - sqrt(sqr)) / (2 * a);
    success(x1, x2);
}

void main() {
    int a, b, c;
    printf("A quadraric function looks like this -> ax2 + bx + c = 0. Let's find x.\n");

    printf("a: ");
    scanf("%d", &a);

    printf("b: ");
    scanf("%d", &b);

    printf("c: ");
    scanf("%d", &c);

    calculateQuadratic(a, b, c);
}