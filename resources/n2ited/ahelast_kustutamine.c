/* Elemendi kustutamine, mille infov‰lja v‰‰rtus on "arv"
 * Moodustatakse ahel arvudest
 * Kasutaja sisestab otsitava v‰‰rtuse
 * Programm otsib ja kui leiab v‰‰rtuse "arv", siis kustutab ahelast vastava elemendi.
 */
#include <stdio.h> 
/* J‰rgnevalt on n‰ha C-keele vıimalus uute andmet¸¸pide kirjeldamiseks
 * Vıtmesına on typedef ja kirjeldatava andmet¸¸bi nimi on viit
 * Uut andmet¸¸pi viit kasutatakse edaspidi uute muutujate deklareerimiseks 
 */
    typedef struct element *viit;
    struct element {
           int info; 
           viit next;
    };

main(){
    viit head, node, curr, prev;
    int arv;
 
/* J‰rgneva ahela loomis ts¸kkel peaks olema tuttav eespool olevatest n‰idetest */
    head = NULL;
    printf("Sisesta arv! (Lıpetamiseks 0)");
    scanf("%d",&arv);
    while (arv != 0){
          node = malloc(sizeof *node);
          node->next = head;
          node->info = arv;
          head = node;
          printf("Sisesta arv! (Lıpetamiseks 0)");
          scanf("%d",&arv);
    } 
    printf("Millist arvu otsime >");
    scanf("%d",&arv);
    curr = head;
    prev = NULL;
    
/* J‰rgnevat ts¸klit vıib kasutada vaid juhul, kui loogikaavaldisi arvutatakse osaliselt
 * st kui peale esimese poole arvutamist on lıpptulemus selge, siis edasi ei arvutata.
 * Vastasel juhul tekib peale viimase elemendi kontrollimist viga.
 * Ts¸kkel tˆˆtab niikaua, kuni viit curr on otsitava elemendi peal ja prev sellele eelneval elemendil
 * Vaata ka programmi ahelast_kustutamine_ver2.c
 */
 
    while (curr != NULL && curr->info != arv) {
        prev = curr;
        curr = curr->next;
    }

    if (curr != NULL) {                   //Leiti otsitava v‰‰rtusega element
    	if (prev == NULL) {               //Kustutamine algusest
            	head = head->next;
        }
    	else {  
            	prev->next = curr->next;  //Kustutamine keskelt vıi lıpust
        }
    	free(curr);
    }
    else {                                //Otsitav element puudub
         printf("Selline element puudub\n");
    }
    printf("Peale kustutamist on ahel j‰rgmine:\n");
    
/* Tuttav v‰ljatr¸kkimise ts¸kkel */

    curr = head;
    while (curr != NULL) {
        printf("%d\n", curr->info);
        curr = curr->next; 
    }
    getch();
}
