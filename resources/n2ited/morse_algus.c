
/* 
 * Moorsekoodi dekodeerimine, kasutades selleks puud - algus.
 * Koodis tehaks evalmis puu, milles tähed on paigutatud vajalikul viisil.
 * Lisaks on näidisena funktsioon, mis puu preorder järjekorras välja trükib.
 * Parandatud ja täiendavalt kommenteeritud versioon 12.04.2019
 */
 
#include <stdio.h>
#include <stdlib.h>

    struct MorseTree {
        char letter;
        struct MorseTree *dot, *dash;
    };


/* globaalsed muutujad, mida puu ehitamise funktsioon vajab
 */

static int i;    
char LETTERS[31]={' ','E','I','S','H','V','U','F','Ü','A','R','L','Ä','W','P','J','T','N','D','B','X','K','C','Y','M','G','Z','Q','O','Ö','™'};

/*
 * Funktsioon ehitab valmis puu, kasutades selleks rekursiooni ja
 * ülal olevat massiivi.
 * Funktsioon tagastab viida lisatud sõlmele.
 */

struct MorseTree *BuildTree(int N) {
    struct MorseTree *newNode;
    int nl, nr;
    if (N==0) {
        return NULL;
    }
    else {
        nl = N / 2;
        nr = N-nl-1;
        newNode = malloc(sizeof *newNode);
        newNode->letter = LETTERS[i];
        i++;
        newNode->dot = NULL;
        newNode->dash = NULL;
        newNode->dot = BuildTree(nl);
        newNode->dash =  BuildTree(nr);
        return newNode;
    }
}



/*
 * Järgnev funktsioon trükib välja kõik puu sõlmed eesjärjekorras (preorder).
 * (juur -> vasak alampuu -> parem alampuu.
 * NB! Funktsioon ei ole tegelikult morse teisendamiseks vajalik.
 * Ta lihtsalt demosntreerib ühte puu kõigi sõlmede läbimise võimalust
 */

void Preorder(struct MorseTree *RPointer) {
    printf("%c", RPointer->letter);
    if (RPointer->dot != NULL) {
        Preorder(RPointer->dot);
/*     printf("%c",RPointer->letter); Siin oleks Inorder-läbimise töötlemise / väljatrüki koht
*/
    }
    if (RPointer->dash != NULL) {
        Preorder(RPointer->dash);
/*    printf("%c",RPointer->letter);  Siin oleks Postorder-läbimise töötlemise / väljatrüki koht
 */
    }
}


int main(void) {
    struct MorseTree *morse;
    printf("Kõigepealt tuleb morsepuu üles ehitada!\n");
    i = 0;
/*
 *  Funktsioon teeb puu tagastab viida puu juurele, st muutujas morse on kirjas puu juure aadress.
 *  Juure aadress on vajalik kõigi teiste sõlmede kättesaamiseks.
 */
    morse = BuildTree(31);
    printf("Puu väljatrükk preorder järjekorras, mis ei ole morse dekodeerimiseks vajalik.\n");
    Preorder(morse);
    printf("\n");
    return 0;
}

