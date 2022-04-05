#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    struct AnimalTree {
        char text[100];
        struct AnimalTree *yes, *no;
    };

int main() {

    struct AnimalTree *root, *node1, *node2, *current;
    char answer;
    char question[100], animal[100];

    root = malloc(sizeof *root);
    node2 = malloc(sizeof *node2);
    node1 = malloc(sizeof *node1);
    strcpy(node1->text, "Elephant");
    strcpy(node2->text, "Cat");
    root->yes = node1;
    root->no = node2;

    strcpy(root->text, "Is it large?");

    current = root;
    while (current->no  && current->yes) {
        printf("%s\n", current->text);
        scanf(" %c", &answer);
        if (answer == 'y') {
                current = current->yes;
        } else if (answer == 'n') {
                current = current->no;
        }
    }
    printf("The answer is: %s\n", current->text);

}