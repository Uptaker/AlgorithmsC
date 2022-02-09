#include<iostream>

void checkAge(int age) {
    if (age >= 18) printf("You may proceed");
    else printf("GIT OUT!");
}

int main() {
    int age;
    printf("Stop right there!\nWhat is your age?\n");
    scanf("%d", &age);
    printf("Your age is, %d. ", age);
    checkAge(age);
    return 0;
}