/*  3. praktikumi �lesanded:
    Loo ahel N elemendist, lisades elemente ahela l�ppu
    Tagasta ahela esimene element
    Leia ahelas olevate elementide arv.
    Uue elemendi lisamine M-dale kohale.
*/
#include <stdio.h>
#include <stdlib.h>
/* stdlib.h-i lisamist ei n�ua k�ik keskkonnad, gcc greenys n�iteks tahab. 
   Teegi stdlib p�ises on kirjeldatud n�iteks 
   funktsioon malloc()
*/

int main(void) {
	struct element {
        int info; 
        struct element *next;
    };
    struct element *head, *tail, *node, *current;
    
    int inputNumber, numberOfElements, position, i, countElements;
/* 
   1. osa: Loome ahela N elemendist, N sisestab kasutaja. Elemendid lisatakse ahela l�ppu.
*/    
    head = NULL; tail = NULL;
    printf("Sisesta elementide arv ");
    scanf("%d", &numberOfElements);
/* 
    Esimene element tuleb lisada eraldi, muidu ei saa aadressi "head" paika 
*/
    printf("Sisesta arv ");
    scanf("%d", &inputNumber);
    head = malloc(sizeof *head); 
    head->next = NULL; 	      
    head->info = inputNumber;
    tail = head;
    for (i = 0; i < numberOfElements - 1; i++) {
        printf("Sisesta arv ");
        scanf("%d", &inputNumber);
        node = malloc(sizeof *node);
        node->next = NULL; 	      
        node->info = inputNumber;
        tail->next = node;
        tail = node;
    }
/* 
    Kas �nnestus? Ahel tr�kitakse v�lja.
*/
    current = head;
    while (current != NULL) {               
        printf("Arv on %d\n", current->info);            
        current = current->next;
    }   
/* 
   2. osa: J�rgnevalt kustutatakse ahela esimene element ja tr�kitakse v�lja temas olnud v��rtus 
*/
    node = head;
    head = head->next;
    printf("Eemaldatud arv on %d\n", node->info);
    free(node);
   
/* 
    Kas �nnestus? 
    3. osa: �hitame sellega listis olevate elementide arvu leidmise
*/
    countElements = 0;
    current = head;
    while (current != NULL) {               
        printf("Arv on %d\n", current->info);            
        current = current->next;
        countElements++;
    }
    printf("Kokku on arve %d.\n", countElements);
/*
4. osa: uus element lisatakse ahelasse kohale N
*/
    printf("Sisesta uus arv ");
    scanf("%d", &inputNumber);
    printf("Mitmendaks ta paigutame? ");
    scanf("%d", &position);
	node = malloc(sizeof *node);
	node->info = inputNumber;   
/* Uus element lisatakse ahela algusesse */
    if (position == 1) {
        node->next = head; 	      
        head = node;         
    }
    else {
/* Uus element lisatakse ahela l�ppu */
        if (position >= numberOfElements + 1) {
            node->next = NULL; 	      
            tail->next = node;
            tail = node;
        }
/* Uus element lisatakse ahela keskele */
        else {
            current = head;
            for (i = 1; i < position - 1; i++) {
                current = current->next;
          	}
            node->next = current->next; 	      
            current->next = node;               
        } 
    }
/*
   Tr�kime v�lja, mis sai peale lisamist
*/
    current = head;
    while (current != NULL) {               
        printf("Arv on %d\n", current->info);            
        current = current->next;  
    }  
}
