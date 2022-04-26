#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Funktsioonid loomapuu ehitamiseks, mis peaksid andma v�imaluse programm koostada kasutamata 
 * puu s�lmedes olevaid v�lju. Viidad on siiski vajalikud, sest selle abil antakse funktsioonidele
 * ette, millise s�lme suhtes j�rgnevaid tegevusi teha.
 */

/* Puu s�lme kirjeldus. Viidav�ljade nimedeks on "yes" ja "no".
 * Looma nime v�i k�simuse jaoks on string pikkusega kuni 30 s�mbolit
 */
    struct animalTree {
        char nodeText[30]; 
        struct animalTree *yes, *no;
    };

/* Funktsioon tagastab j v�i e t�he
 * Funktsiooni saab kasutada j/e vastuste k�simiseks 
 * Funktsioon kontrollib sisestatud s�mbolit ning l�petab k�simise vaid siis,
 * kui �ks sobivatest t�htedest on sisestatud.
 * Kasutamise n�ide:
              printf("Kas ma arvasin �igest?");
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
 * V�ljundparameetriks on juure aadress
 * Kasutamise n�ide:
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
 * Uus element lisatakse parameetriga "location" (viit-muutuja) m��ratud elemendi no-v�lja k�lge
 * Elemendi tekstiv�lja kirjutatakse parameetri "text" v��rtus
 * Kasutamise n�ide:
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
 * Uus element lisatakse parameetriga "koht" (viit-muutuja) m��ratud elemendi jah-v�lja k�lge
 * Elemendi nodeTextiv�lja kirjutatakse parameetri "s6nad" v��rtus
 * Kasutamise n�ide: vaata eelmist funktsiooni
 */
void insertYes(struct animalTree *location, char text[30]) {
    struct animalTree *temp;
    temp = malloc(sizeof *temp);
    strcpy(temp->nodeText, text);
    temp->yes = NULL;
    temp->no = NULL;
    location->yes = temp;  
}


/* Funktsioon tagastab viida, mis on parameetriks "koht" olevale s�lmele Ei pool oleva elemendi viit.
 * Funktsiooni sobib kasutada puus liikumiseks juurest leheni.
 * Kasutamise n�ide:
 *              if (answer == 'e')
 *                  temp = moveToNo(temp);
 */
struct animalTree *moveToNo(struct animalTree *location) {
    return location->no;
}

/* Funktsioon tagastab viida, mis on parameetriks "location" olevale s�lmele yes pool oleva elemendi viit.
 * Funktsiooni sobib kasutada puus liikumiseks juurest leheni.
 * Kasutamise n�ide: vt eemine funktsioon.
 */
 
struct animalTree *moveToYes(struct animalTree *location) {
    return location->yes;
}
       
/* Funktsioon kontrollib, kas parameetri "location" abil ette antud s�lm on leht.
 * Funktsioon tagastab 1, kui parameetriks olev viit vastab lehele ja
 * 0 kui ei vasta lehele.
 * Funktsiooni saab kasutada puus liikumisel kontrolliks.
 * Kasutamise n�ide (kuni ei ole j�utud leheni ...):
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

/* Funktsioon tagastab parameetriga "location" m��ratud s�lmes oleva teksti (k�simuse v�i looma).
 * Kasutamise n�ide:
 *              animal = getTextFromNode(temp);
 */
 
char *getTextFromNode(struct animalTree *location) { 
	return location->nodeText;
}


/* Funktsioon lisab parameetriga "location" m��ratud s�lme teksti "text"
 * Saab kasutada valmis s�lme puhul v�ljas "nodeText" oleva teksti muutmiseks
 * Kasutamise n�ide:
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
