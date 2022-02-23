/* Programm moodustab täisarvuliste väärtuste jaoks ahela.
 * Vaata, millises järjekorras andmeid lisatakse ehk lisa väljatrükk
 * eelmisest näitest lähtudes 
 */

#include <stdio.h>
#include <stdlib.h>


int main(void){
    struct element {
           int info; 
           struct element *next;
    };
/* Kaks muutujat - head selleks, et seal ahela esimese elemendi aadressi säilitada ning node abimuutujaks uue elemendi lisamisel. */
    struct element *head, *node, *first;
    int arv;
    
    head = NULL;

    printf("Sisesta arv! (Lõpetamiseks 0)");
/* Andmete sisestus (täisarvud!) töötab seni, kuni kasutaja trükib arvu 0 */
    scanf("%d",&arv);
    while (arv != 0){
          node = malloc(sizeof *node); 
          node->next = head; 	       
          node->info = arv;
          head = node; 		          
          printf("Sisesta arv! (Lõpetamiseks 0)");
          scanf("%d",&arv);
    }

    printf("Now printing backwards:\n");
    current = head;
    while (current != NULL) {
    	printf("%d\n", current->info);
	current = current->next;
    }


}
