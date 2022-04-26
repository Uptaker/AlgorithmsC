//Programm demonstreerib järgmisi asju:
//        1) kuidas luua kahe viidaga ahelat lisades elemente lõppu;
//        2) kuidas läbida ahelat ja väljastada tema sisu;
//       3) kuidas kahe viidaga ahelast sõlme kustutada

#include <stdio.h>
    struct element {
           int info; 
           struct element *next, *prior;
    };

int main(void){

    struct element *head, *tail, *node;
    int arv;
    
    head = NULL; tail = NULL;
    printf("Sisesta arv! (Lõpetamiseks 0)");
    scanf("%d",&arv);
    while (arv != 0){
          node = malloc(sizeof *node); // Uus element
          node->next = NULL; 	      // Elemnt kinnitatakse pea (head) külge
          node->prior = tail;
          node->info = arv;
          tail = node;
          if (node->prior==NULL) {
              head = node;
          }
          else {
               node->prior->next = node;
          }
          printf("Sisesta arv! (Lõpetamiseks 0)");
          scanf("%d",&arv);
    }

//  Trükime ahela väölja.
  node = head;
  while (node != NULL)
  {
        printf("%d",node->info);
        node = node->next;
  }
 getch(); 



// Asume nüüd otsima ja kustutama
  node = head;
  printf("Mida otsime?");        //Võtmeväärtuse sisestamine
  scanf("%d",&arv);
//  Liigume mööda ahelat õige sõlmeni - node näitab kustutavale sõlmele,
//  või jõuame ahela lõppu sobivat leidmata
  while (node != NULL && node->info != arv)
        node = node->next;
        
//  Kui leiti vastava infoga sõlm, siis asume kustutama
  if (node != NULL) //Kontrollime selle, kas on üle ahela serva sõidetud
  {
	if (node->prior == NULL)  //Eespool pole kedagi. Kustutame algusest.
	{
          head = node->next;
          head->prior = NULL;
    }
	else 
    {
         if (node->next == NULL)  //Tagapool pole kedagi. Kustutame lõpust
	     {
	         tail = tail->prior;
	         tail->next = NULL;
          }
	     else                   //Pole see ega teine. Kustutame keskelt
	     {
	         node->prior->next = node->next;
             node->next->prior = node->prior;
          }
	free(node);                //Tegelik kustutamine
	printf("Sõlm on kustutatud!\n");
    }
  }
  else
  {

	printf("Sellist elementi ei leitud\n");
  }
// Ahel trükitakse välja
  printf("Nüüd on nimistu seis järgmine: \n");
  node = head;
  while (node != NULL)
  {
        printf("%d",node->info);
        node = node->next;
  }
 getch(); 
}
