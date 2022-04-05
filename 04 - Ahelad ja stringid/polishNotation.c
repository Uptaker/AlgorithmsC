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
	return (top == 0) ? 1 : 0;
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
    char postfix[50];

    // reversed Polish notation
    printf("\npostfix: ");
    for (i = 0; i < length; i++) {
        if (expression[i] == '(') continue;
        if (expression[i] == '+' || expression[i] == '-' ||
            expression[i] == '*' || expression[i] == '/') {
            stackPush(expression[i]);
        } else if (expression[i] == ')') {
            char operator = stackPop();
            // printf("%c ", operator);
            strcat(postfix , operator);
            }
        else {
            // printf("%c ", expression[i]);
            strcat(postfix ,expression[i]);
            }
    }
    printf("%s", postfix);


    stackInit(length);

    // Calculate postfix
    printf("\npostfix answer is: ");
    int answer = 0;
    char ch = expression[i];
    for (i = 0; i < length; i++) {
        if (ch == '(' || ch == ')') continue;
        if (ch == '+' || ch == '-' ||
            ch == '*' || ch == '/') {
            int first = stackPop() - '0';
            int last = stackPop() - '0';
            if (ch == '+') answer += last + first;
            if (ch == '-') answer += last - first;
            if (ch == '*') answer += last * first;
            if (ch == '/') answer += last / first;
        } else stackPush(ch);
    }
    printf("%s", postfix);


    // Polish notation - TODO fix wrong order
    // printf("\nprefix: ");
    // for (i = 0; i < length; i++) {
    //     if (expression[i] == '+' || expression[i] == '-' ||
    //         expression[i] == '*' || expression[i] == '/') stackPush(expression[i]);
    // }
    // for (i = 0; i < length; i++) {
    //     if (expression[i] == ')' || expression[i] == '+' || expression[i] == '-' ||
    //         expression[i] == '*' || expression[i] == '/') continue;
    //     if (expression[i] == '(') printf("%c ", stackPop());
    //     else printf("%c ", expression[i]);
    // }
}
