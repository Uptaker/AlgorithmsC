/* Elemendi kustutamine, mille infov‰lja v‰‰rtus on "arv"
 * Moodustatakse ahel arvudest
 * Kasutaja sisestab otsitava v‰‰rtuse
 * Programm otsib ja kui leiab v‰‰rtuse "arv", siis kustutab ahelast vastava elemendi.
 * See variant sobib siis, kui loogikaavaldisi t‰ielikult arvutatakse.
 */
 
#include <stdio.h> 
    typedef struct element *viit;
    struct element {
           int info; 
           viit next;
    };

main(){
    viit head, node, curr, prev;
    int arv;
 

    head = NULL;
    printf("Sisesta arv! (Lıpetamiseks 0)");
    scanf("%d",&arv);
    while (arv != 0){
          node = malloc(sizeof *node);// Uus element
          node->next = head; 	      // Elemnt kinnitatakse pea (head) k¸lge
          node->info = arv;
          head = node; 		          // Head tıstetakse edasi
          printf("Sisesta arv! (Lıpetamiseks 0)");
          scanf("%d",&arv);
    } 
    printf("Millist arvu otsime >");
    scanf("%d",&arv);
    curr = head;
    prev = NULL;
    
// Kui otsitav element on esimene, siis kustutatakse:
       
    if (curr->info==arv) {
          node = curr;
          head = curr->next;
          free(node);
    }
    
// Otsime edasi

    else {
          while (curr->next!=NULL && curr->info!=arv) {
                prev = curr;
                curr = curr->next;
          }
// Kui info-v‰ljas on otsitav v‰‰rtus, siis tuleb element kustutada
          if (curr->info==arv) {
               node=curr;
               prev->next = curr->next;
               free(node);
          }
// Otsitavat v‰‰rtust ei leitudki
          else {
               printf("Selline element puudub\n");
          }
    }
// Tr¸kime lıpptulemuse v‰lja
    printf("Peale kustutamist on ahel j‰rgmine:\n");
    curr = head;
    while (curr != NULL) {
        printf("%d\n", curr->info);
        curr = curr->next;
 
    }
    getch();
}
