/* Ahela moodustamine "kirve meetodil".
 * Programmi eesmärk on demonstreerida viitmuutujate kasutamist ja
 * ühe hästi väikese ahela (kolm elementi) tegemist.
 * Ahel koostatakse kirjetest (struct), mille üheks koostisosaks on viida- ehk aadressi-tüüpi väli.
 * Aadresside abil ühendatakse elemendid ahelaks.
 * Sarnane näide on N. Parlante materjalis "Linked List Basics."
 */

#include <stdlib.h>
#include <stdio.h>

/* Tüüpiline näide elemendi kirjeldamiseks viitadega andmestruktuuri jaoks
 * Näites on üks aadressiväli "next", kuid neid võib ka olla rohkem (enamasti kaks)
 * Info jaoks on täisarvuline väli "info".
 */


int main(void) {
    struct node {
        int info; 
        struct node *next;
    };
/* Viida tüüpi muutujate (4 tk) deklareerimine struct element abil. Kõik nad on ettenähtud viitama eespool kirjeldatud struktuurile ehk
   neisse võib omistada struct elemendi aadressi. */
 
    struct node *first, *second, *third, *current;
    printf("Tähelepanu-tähelepanu, kohe tehakse ahel, mis koosneb kolmest sõlmest!\n");
 
/* Kolme malloc-käsuga eraldatakse kolme elemendi jagu mälu, millede algusaadressid kirjutatakse muutujatesse essa, tessa ja kossa */
    first = malloc(sizeof *first);      
    second = malloc(sizeof *second);
    third = malloc(sizeof (struct node));
 
    printf("sizeof *first %d\n", sizeof *first);      
    printf("sizeof *second%d\n", sizeof *second);
    printf("sizeof (struct node)%d\n", sizeof (struct node));
/* Loodud elementide väljadesse "info" omistatakse täisarvuline väärtus
   Noolega (->) kirjapildi võib asendada järgmisega: (*first).info = 1;
   Mõlema variandi tähendus:
   Võta muutujas first olev mäluaadress. Sellel aadressil paikneva struct'i välja "info" omista mingi väärtus.*/
    first->info = 1;    
    second->info = 2;
    third->info = 3;
 
/* Elementide väljadesse "next" kirjutatakse mäluaadressid, mis on muutujates "second" ja "third". Viimase elemendi aadressivälja
   omistatakse NULL.
   Tulemuseks on ahelalaadselt omavahel ühendatud elemendid. */

    first->next = second;
    second->next = third;  
    third->next = NULL;   
/*
    printf("%p ",first->next);
    printf("%p ",second->next);
    printf("%p\n",third->next);
*/ 
/* Siit algab standardne tsükkel ahela sisu (arvude) väljatrükkimiseks.
   Selline ahela läbimine ja trükkimine sobib üks kõik millisel viisil loodud ahela jaoks.
   Loomulikult saab trükkimise asemel ka midagi kasulikumat teha */

/* Et ahela esimese elemendi aadress first kaotsi ei läheks, kasutame liikumiseks muutujat "current".
   Kuni viimase elemendi viidaväljast talle NULL väärtuseks antakse. Selle järgi on võimalik tuvastada, et kõik elemendid töödeldud on */
    printf("Järgneb ahelas olevate andmete väljatrükkimine: \n");
    current = first;
    while (current != NULL) {               
        printf("Arv on %d\n",current->info);            
        current = current->next;              
/* Muutuja current nihutatakse ühe elemendi võrra edasi, järgmise elemendi aadress saadakse jooksva elemendi viidaväljast */
    }
}

