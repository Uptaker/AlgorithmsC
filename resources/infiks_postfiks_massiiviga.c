#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
 * On kirjeldatud 4 peamist pinu operatsiooni:
 * stackInit() - pinu loomine
 * stackEmpty() - kas pinu on tühi?
 * stackPush() - lisamine pinusse
 * stackPop() - eemladamine pinust
 Pinu on ülesehitatud massiivile.
*/

/* Deklareeritakse globaalsed muutujad
   stack - viit pinule
   top - pinu tipp (esimese vaba koha indeks)
*/
static int *stack;
static int top;

/* Pinu loomine
   maxSize - pinu suurus - mitu elementi on massiivis
*/
void stackInit(int maxSize) { 
    stack = malloc(maxSize * sizeof(int)); 
    top = 0; 
}

/* Kontroll, kas pinu on tühi
   Tagastab:
      1 (true) - kui pinu on tühi
      0 (false )- kui pinu ei ole tühi
*/
int stackEmpty(void) { 
    if (top == 0) {
       return 1;
    }
    else {
       return 0;
    }
}

/* Elemendi lisamine pinusse
   item - lisatav väärtus
*/
void stackPush(int item) { 
    stack[top] = item; 
    top++;
}

/* Elemendi võtmine pinust
   Argumendid puuduvad.
   Tagastatakse pinu tipus olnud väärtus
*/
int stackPop(void) { 
    top--;
    return stack[top]; 
}

int main(void) { 
    char expression[30]; 
    int i, expressionLen;
    
    printf("Sisesta tavaline aritmeetikaavaldis ");
    scanf("%29s", expression);
    expressionLen = strlen(expression);
    stackInit(expressionLen);
/* 
    Tsükkel töötleb stringi expression sümbol haaval
*/
    for (i = 0; i < expressionLen; i++) {
        if (expression[i] == ')') {
            printf("%c ", stackPop()); 
        }        
        else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' ) {
            stackPush(expression[i]);
        } 
        else if (expression[i] >= '0' && expression[i] <= '9') {
            printf("%c ", expression[i]); 
        }

/*        else if (isdigit(expression[i])) - alternatiivne variant küsimaks, kas on arvu moodi märk 
          printf("%c ", expression[i]); 
*/
    }
    printf("\n");
    return 0;
}
