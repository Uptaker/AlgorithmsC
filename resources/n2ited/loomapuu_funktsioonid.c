#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Funktsioonid loomapuu ehitamiseks, mis peaksid andma võimaluse programm koostada kasutamata 
 * puu sõlmedes olevaid välju. Viidad on siiski vajalikud, sest selle abil antakse funktsioonidele
 * ette, millise sõlme suhtes järgnevaid tegevusi teha.
 */

/* Puu sõlme kirjeldus. Viidaväljade nimedeks on "yes" ja "no".
 * Looma nime või küsimuse jaoks on string pikkusega kuni 30 sümbolit
 */
    struct animalTree {
        char nodeText[30]; 
        struct animalTree *yes, *no;
    };

/* Funktsioon tagastab j või e tähe
 * Funktsiooni saab kasutada j/e vastuste küsimiseks 
 * Funktsioon kontrollib sisestatud sümbolit ning lõpetab küsimise vaid siis,
 * kui üks sobivatest tähtedest on sisestatud.
 * Kasutamise näide:
              printf("Kas ma arvasin õigest?");
              answer = yesNo();
              if (answer =='j') ...
*/
char yesNo(void) {
    char answer = ' ';
    while (answer != 'j' && answer != 'e') {
        scanf("%c",&answer);
        getchar();
    }
    return answer;
}


/* Funktsioon puu juure moodustamiseks
 * Sisendparameetriks on juure sisse kirjutatav tekst
 * Väljundparameetriks on juure aadress
 * Kasutamise näide:
 *              struct animalTree *root;
 *              ...
 *              root = makeRoot("Kas ta on suur?");
 */
 
struct animalTree *makeRoot(char text[30]) {
	struct animalTree *temp;
    temp = malloc(sizeof *temp);
    strcpy(temp->nodeText, text);
    temp->yes = NULL;
    temp->no = NULL;
    return temp;       
}

/* Funktsioon lisab puusse uue elemendi.
 * Uus element lisatakse parameetriga "location" (viit-muutuja) määratud elemendi no-välja külge
 * Elemendi tekstivälja kirjutatakse parameetri "text" väärtus
 * Kasutamise näide:
            struct animalTree *node;
            insertNo(node, "Hiir");
 */

void insertNo(struct animalTree *location, char text[30]) {
    struct animalTree *temp;
    temp = malloc(sizeof *temp);
    strcpy(temp->nodeText, text);
    temp->yes = NULL;
    temp->no = NULL;
    location->no = temp;       
}

/* Protseduur lisab puusse uue elemendi.
 * Uus element lisatakse parameetriga "koht" (viit-muutuja) määratud elemendi jah-välja külge
 * Elemendi nodeTextivälja kirjutatakse parameetri "s6nad" väärtus
 * Kasutamise näide: vaata eelmist funktsiooni
 */
void insertYes(struct animalTree *location, char text[30]) {
    struct animalTree *temp;
    temp = malloc(sizeof *temp);
    strcpy(temp->nodeText, text);
    temp->yes = NULL;
    temp->no = NULL;
    location->yes = temp;  
}


/* Funktsioon tagastab viida, mis on parameetriks "koht" olevale sõlmele Ei pool oleva elemendi viit.
 * Funktsiooni sobib kasutada puus liikumiseks juurest leheni.
 * Kasutamise näide:
 *              if (answer == 'e')
 *                  temp = moveToNo(temp);
 */
struct animalTree *moveToNo(struct animalTree *location) {
    return location->no;
}

/* Funktsioon tagastab viida, mis on parameetriks "location" olevale sõlmele yes pool oleva elemendi viit.
 * Funktsiooni sobib kasutada puus liikumiseks juurest leheni.
 * Kasutamise näide: vt eemine funktsioon.
 */
 
struct animalTree *moveToYes(struct animalTree *location) {
    return location->yes;
}
       
/* Funktsioon kontrollib, kas parameetri "location" abil ette antud sõlm on leht.
 * Funktsioon tagastab 1, kui parameetriks olev viit vastab lehele ja
 * 0 kui ei vasta lehele.
 * Funktsiooni saab kasutada puus liikumisel kontrolliks.
 * Kasutamise näide (kuni ei ole jõutud leheni ...):
 *              while (!isLeaf(temp)) {...
 */
 
int isLeaf(struct animalTree *location) { 
    if (location->yes == NULL && location->no == NULL) {
        return 1;
    }
    else {
    	return 0;
	}
}

/* Funktsioon tagastab parameetriga "location" määratud sõlmes oleva teksti (küsimuse või looma).
 * Kasutamise näide:
 *              animal = getTextFromNode(temp);
 */
 
char *getTextFromNode(struct animalTree *location) { 
	return location->nodeText;
}


/* Funktsioon lisab parameetriga "location" määratud sõlme teksti "text"
 * Saab kasutada valmis sõlme puhul väljas "nodeText" oleva teksti muutmiseks
 * Kasutamise näide:
 *              struct animalTree *temp;
 *              ....
 *              insertTextIntoNode(temp, "Kas ta armastab mett?);
 */
insertTextIntoNode(struct animalTree *location, char *text) {
    strcpy(location->nodeText, text);
}


/*
main()
{ struct animalTree *animals;
...
      }
      */
