
/* 
 * Moorsekoodi dekodeerimine, kasutades selleks puud - algus.
 * Koodis tehaks evalmis puu, milles t�hed on paigutatud vajalikul viisil.
 * Lisaks on n�idisena funktsioon, mis puu preorder j�rjekorras v�lja tr�kib.
 * Parandatud ja t�iendavalt kommenteeritud versioon 12.04.2019
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
char LETTERS[31]={' ','E','I','S','H','V','U','F','�','A','R','L','�','W','P','J','T','N','D','B','X','K','C','Y','M','G','Z','Q','O','�','�'};

/*
 * Funktsioon ehitab valmis puu, kasutades selleks rekursiooni ja
 * �lal olevat massiivi.
 * Funktsioon tagastab viida lisatud s�lmele.
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
 * J�rgnev funktsioon tr�kib v�lja k�ik puu s�lmed eesj�rjekorras (preorder).
 * (juur -> vasak alampuu -> parem alampuu.
 * NB! Funktsioon ei ole tegelikult morse teisendamiseks vajalik.
 * Ta lihtsalt demosntreerib �hte puu k�igi s�lmede l�bimise v�imalust
 */

void Preorder(struct MorseTree *RPointer) {
    printf("%c", RPointer->letter);
    if (RPointer->dot != NULL) {
        Preorder(RPointer->dot);
/*     printf("%c",RPointer->letter); Siin oleks Inorder-l�bimise t��tlemise / v�ljatr�ki koht
*/
    }
    if (RPointer->dash != NULL) {
        Preorder(RPointer->dash);
/*    printf("%c",RPointer->letter);  Siin oleks Postorder-l�bimise t��tlemise / v�ljatr�ki koht
 */
    }
}


int main(void) {
    struct MorseTree *morse;
    printf("K�igepealt tuleb morsepuu �les ehitada!\n");
    i = 0;
/*
 *  Funktsioon teeb puu tagastab viida puu juurele, st muutujas morse on kirjas puu juure aadress.
 *  Juure aadress on vajalik k�igi teiste s�lmede k�ttesaamiseks.
 */
    morse = BuildTree(31);
    printf("Puu v�ljatr�kk preorder j�rjekorras, mis ei ole morse dekodeerimiseks vajalik.\n");
    Preorder(morse);
    printf("\n");
    return 0;
}

