#include <stdio.h>

#define true 1
#define false 0

void loop() {
    int highest = 0;
    int secondHighest = 0;
    int input;
    while (true) {
        printf("Enter a number\n");
        scanf("%d", &input);
        if (input > highest) {
            secondHighest = highest;
            highest = input;
            }
        else if (input > secondHighest) secondHighest = input;
        printf("Second highest number is %d\n", secondHighest);
    }
}

void main() {
    printf("This program will always show the 2nd highest number inputted so far\n");
    loop();
}