
// Dynamic stacks can be achieved via pointers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stackElement {
    int element;
    struct stackElement *next;
};
static struct stackElement *top;
static struct stackElement *head;


void stackInit(int maxSize) {
    top = malloc(sizeof(*top));
    top->next = NULL;
}

int stackEmpty(void) { 
	return (top == 0) ? 1 : 0;
}

void stackPush(int item) {
    struct stackElement *head = top;
    top->element = item;
    // top->next = *; TODO finish exercise 4
}

int stackPop(void) { 
	top--;
    return stack[top];
}

main() {
    int number, i, length;
    char expression[50];
    printf("Input infiks expression ");
    scanf("%49s", expression);
    getchar();
    length = strlen(expression);
    stackInit(length);

    // reversed Polish notation
    printf("\npostfix: ");
    for (i = 0; i < length; i++) {
        if (expression[i] == '(') continue;
        if (expression[i] == '+' || expression[i] == '-' ||
            expression[i] == '*' || expression[i] == '/') {
            stackPush(expression[i]);
        } else if (expression[i] == ')') printf("%c ", stackPop());
        else printf("%c ", expression[i]);
    }

    stackInit(length);

    // Polish notation - TODO fix wrong order
    printf("\nprefix: ");
    for (i = 0; i < length; i++) {
        if (expression[i] == '+' || expression[i] == '-' ||
            expression[i] == '*' || expression[i] == '/') stackPush(expression[i]);
    }
    for (i = 0; i < length; i++) {
        if (expression[i] == ')' || expression[i] == '+' || expression[i] == '-' ||
            expression[i] == '*' || expression[i] == '/') continue;
        if (expression[i] == '(') printf("%c ", stackPop());
        else printf("%c ", expression[i]);
    }
}
