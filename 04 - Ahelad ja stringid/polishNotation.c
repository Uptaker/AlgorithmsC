#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int *stack;
static int top;

void stackInit(int maxSize) { 
	stack = malloc(maxSize*sizeof(int)); 
    top = 0; 
}

int stackEmpty(void) { 
	if (top == 0) {
		return 1;
	}
    else {
    	return 0;
	}
}

void stackPush(int item) { 
	stack[top] = item; 
    top++;
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
