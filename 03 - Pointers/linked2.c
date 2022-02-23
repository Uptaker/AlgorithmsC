/* Programm moodustab täisarvuliste väärtuste jaoks ahela.
 * Vaata, millises järjekorras andmeid lisatakse ehk lisa väljatrükk
 * eelmisest näitest lähtudes 
 */

#include <stdio.h>
#include <stdlib.h>

struct element {
       int info;
       struct element *next;
};


void printNodes(struct element *current) {
    while (current != NULL) {
        printf("%d\n", current->info);
        current = current->next;
    }
}

struct element *readNotes() {
    struct element *head, *node;
    int arv;
    head = NULL;

    printf("Sisesta arv! (Lõpetamiseks 0)");
    scanf("%d",&arv);
    while (arv != 0){
          node = malloc(sizeof *node);
          node->next = head;
          node->info = arv;
          head = node;
          printf("Sisesta arv! (Lõpetamiseks 0)");
          scanf("%d",&arv);
    }
    return head;
}

int main(void){
    struct element *head = readNotes();
    printNodes(head);
}
