//Programm demonstreerib j�rgmisi asju:
//        1) kuidas luua kahe viidaga ahelat lisades elemente l�ppu;
//        2) kuidas l�bida ahelat ja v�ljastada tema sisu;
//       3) kuidas kahe viidaga ahelast s�lme kustutada

#include <stdio.h>
    struct element {
           int info; 
           struct element *next, *prior;
    };

int main(void){

    struct element *head, *tail, *node;
    int arv;
    
    head = NULL; tail = NULL;
    printf("Sisesta arv! (L�petamiseks 0)");
    scanf("%d",&arv);
    while (arv != 0){
          node = malloc(sizeof *node); // Uus element
          node->next = NULL; 	      // Elemnt kinnitatakse pea (head) k�lge
          node->prior = tail;
          node->info = arv;
          tail = node;
          if (node->prior==NULL) {
              head = node;
          }
          else {
               node->prior->next = node;
          }
          printf("Sisesta arv! (L�petamiseks 0)");
          scanf("%d",&arv);
    }

//  Tr�kime ahela v��lja.
  node = head;
  while (node != NULL)
  {
        printf("%d",node->info);
        node = node->next;
  }
 getch(); 



// Asume n��d otsima ja kustutama
  node = head;
  printf("Mida otsime?");        //V�tmev��rtuse sisestamine
  scanf("%d",&arv);
//  Liigume m��da ahelat �ige s�lmeni - node n�itab kustutavale s�lmele,
//  v�i j�uame ahela l�ppu sobivat leidmata
  while (node != NULL && node->info != arv)
        node = node->next;
        
//  Kui leiti vastava infoga s�lm, siis asume kustutama
  if (node != NULL) //Kontrollime selle, kas on �le ahela serva s�idetud
  {
	if (node->prior == NULL)  //Eespool pole kedagi. Kustutame algusest.
	{
          head = node->next;
          head->prior = NULL;
    }
	else 
    {
         if (node->next == NULL)  //Tagapool pole kedagi. Kustutame l�pust
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
	printf("S�lm on kustutatud!\n");
    }
  }
  else
  {

	printf("Sellist elementi ei leitud\n");
  }
// Ahel tr�kitakse v�lja
  printf("N��d on nimistu seis j�rgmine: \n");
  node = head;
  while (node != NULL)
  {
        printf("%d",node->info);
        node = node->next;
  }
 getch(); 
}
