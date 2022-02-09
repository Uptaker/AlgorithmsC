#include <stdio.h>

void add(int x, int y) {
    printf("%d + %d = %d", x, y, (x + y));
}

void subtract(int x, int y) {
    printf("%d - %d = %d\n", x, y, (x - y));
    printf("%d - %d = %d", y, x, (y - x));
}

void multiply(int x, int y) {
    printf("%d * %d = %d\n", x, y, (x * y));
}

void divide(int x, int y) {
    printf("%d / %d = %0.1f\n", x, y, ((float) x / y));
    printf("%d / %d = %0.1f\n", y, x, ((float) y / x));
}

void chooseMode(int x, int y) {
    int mode;
    scanf("%d", &mode);

    if (mode == 1) add(x, y);
    else if (mode == 2) subtract(x, y);
    else if (mode == 3) multiply(x, y);
    else if (mode == 4) divide(x, y);
    else printf("Mode %d does not exist", mode);
}

int main() {
    int num1, num2;
    printf("Input two numbers:\n");
    scanf("%d%d", &num1, &num2);

    printf("Your numbers are %d and %d. Select your next action\n"
        "1 - addition\n"
        "2 - subtraction\n"
        "3 - multiplication\n"
        "4 - division\n", num1, num2);
    chooseMode(num1, num2);
}