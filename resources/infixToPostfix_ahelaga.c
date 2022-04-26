/* Programm lahendab ülesande infiks avalise teisendamisest postfiks avaldiseks
 * Pinu on realiseeritud dünaamiliselt, st kasutades ahelat
 * Sisendiks olevas infiks-avaldises peab iga tehte kohta olema oma sulupaar
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/* 
 * On kirjeldatud 4 peamist pinu operatsiooni:
 * stackInit() - pinu loomine
 * stackEmpty() - kas pinu on tühi?
 * stackPush() - lisamine pinusse
 * stackPop() - eemladamine pinust
 Pinu on ülesehitatud ahelana.
*/

/* Deklareeritakse struct element - ahela ühe elemendi tüüp
   Samuti deklareeritakse globaalne muutuja top, mis on pinu tipp / ahela esimese elemendi aadress
   top - pinu tipp (esimese vaba koha indeks)
*/
struct element { 
       char info; 
       struct element *next;
};

struct element *top;

/* Pinu loomine
   Pinus (ahelas) ei ole ühtegi elementi.
*/
void stackinit(void) {
    top = NULL; 
    }
    
/* Kontroll, kas pinu on tühi
   Tagastab:
    1 (true) - kui pinu on tühi
    0 (false )- kui pinu ei ole tühi
*/
int stackempty(void) {
    if (top == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

/* Elemendi lisamine pinusse
   item - lisatav väärtus
*/
void stackpush(char item) {
    struct element *node; 
    node = malloc(sizeof *node);
    node->info = item;
    node->next = top;
    top = node;
}

/* Elemendi võtmine pinust
   Argumendid puuduvad.
   Tagastatakse pinu tipus olnud väärtus
*/
char stackpop(void) {
    int item;
    struct element *node; 
    item = top->info;
    node = top->next; 
    free(top);
    top = node;
    return item;
}

int main(void) { 
    char expression[30]; 
    int i, expressionLen;
    
    printf("Sisesta infix avaldis (ära kasuta tühikuid!) ");
    scanf("%s", &expression);
    expressionLen = strlen(expression);
    stackinit();

    for (i = 0; i < expressionLen; i++) {
        if (expression[i] == ')') {
            printf("%c ", stackpop());
        }
        else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' ) {
            stackpush(expression[i]);
        } 
        else if (isdigit(expression[i])) {
            printf("%c ", expression[i]); 
        }
    }
    printf("\n");
    return 0;
}       
