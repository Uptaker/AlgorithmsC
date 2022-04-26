
/* 
 * Moorsekoodi dekodeerimine, kasutades selleks puud, mis on realiseeritud d�naamiliselt.
 * Parandatud ja t�iendavalt kommenteeritud versioon 12.04.2019
 * Faili ei tohiks salvestada ringi Unicode kodeeringusse. 
 * V�i kui seda ei oska v�ltida, siis asenda massiivis LETTERS �, � ja � millegi "mittet�pilisega" ASCII tabelist.
 * Morse koodis tekst loetakse failist.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxN 100

    struct MorseTree {
        char letter;
        struct MorseTree *dot, *dash;
    };


/* globaalsed muutujad, mida puu ehitamise funktsioon vajab
 */

static int i;
char LETTERS[30]={' ','E','I','S','H','V','U','F','�','A','R','L','�','W','P','J','T','N','D','B','X','K','C','Y','M','G','Z','Q','O','�'};

/*
 * Funktsioon ehitab valmis puu, kasutades selleks rekursiooni ja �lal olevat massiivi.
 * Funktsioon tagastab viida lisatud s�lmele.
 */

struct MorseTree *BuildTree(int N) {
    struct MorseTree *newNode;
    int nl, nr;
    if (N == 0) {
        return NULL;
    }
    else {
        nl = N / 2;
        nr = N - nl - 1;
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

int main(void) {
    struct MorseTree *morse, *current;
    FILE *tf=NULL;
    char morseFromFile[MaxN];
    int j, rowLength;
    i = 0;
/*
 *  Funktsioon teeb puu tagastab viida puu juurele, st muutujas morse on kirjas puu juure aadress.
 *  Juure aadress on vajalik k�igi teiste s�lmede k�ttesaamiseks.
 */
    morse = BuildTree(30);

    tf = fopen("morse1.txt","r");
/* J�rgnev ts�kkel loeb faili rida haaval, kuni faili l�puni.
 * Funktsioon feof() kontrollib, kas on j�utud faili l�putunnuseni.
 */
    while (!feof(tf)) {
        fgets(morseFromFile, MaxN, tf);
/* Tuvastatakse stringi pikkus
 */
        rowLength = strlen(morseFromFile);
        current = morse;
/* �he rea dekodeerimine
 */
        for (j = 0; j < rowLength; j++) {
/* Kui on punkt, liigu puus punkti (dot) poole
 */
            if (morseFromFile[j] == '.') {
                current = current->dot;
            }
/* Kui on kriips, liigu puus kriipsu (dash) poole
 */
            else if (morseFromFile[j]=='-') {
                current = current->dash;
            }
/* Kui on kaldkriips, on j�utud puus t�heni, mis tr�kitakse v�lja
 */
            else if (morseFromFile[j] == '/') {
                printf("%c", current->letter);
                current = morse;
            }
        }
    }
    fclose(tf);
    return 0;
}
