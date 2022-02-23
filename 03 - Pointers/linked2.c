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

void checkNodeForInt(struct element *current, int numToCheck) {
    int index = 0;
    while (current != NULL) {
	if (current->info == numToCheck) return printf("Element exists at index %d", index);
	current = current->next;
	index++;
    }
    printf("Element does not exist");
    
}

int scanInt() {
    printf("Enter a new number:\n");
    int num;
    scanf("%d", &num);
    printf("Entered %d\n", num);
    return num;
}

int main(void) {
    struct element *head = readNotes();
    printNodes(head);
    int newInt = scanInt();
    checkNodeForInt(head, newInt);
}
