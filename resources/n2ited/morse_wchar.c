#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
/*
 * Unicode märkide toetusega versioon  12.03.2019
 */
    struct MorseTree {
           wchar_t letter;
           struct MorseTree *dot, *dash;
    };

/* 
 * globaalsed muutujad, mida puu ehitamise funktsioon vajab
 */

static int i;
wchar_t LETTERS[31]={' ','E','I','S','H','V','U','F',L'Ü','A','R','L',L'Ä','W','P','J','T','N','D','B','X','K','C','Y','M','G','Z','Q','O',L'Ö',' '};

/* 
 * Funktsioon ehitab valmis puu, kasutatdes selleks rekursiooni ja 
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
 * Järgnev funktsioon trükib välja kõik puu sõlmed preorder järjekorras 
 * (juur -> vasak alampuu -> parem alampuu.
 */

void Preorder(struct MorseTree *RPointer) {
    printf("%lc", RPointer->letter);
    if (RPointer->dot != NULL) {
       Preorder(RPointer->dot);}
/*    printf("%c",RPointer->letter); Siin oleks Inorderi väljatrükk
 */
    if (RPointer->dash != NULL) {
       Preorder(RPointer->dash);}
/*    printf("%c",RPointer->letter);  Ja siin oleks Postorderi väljatrükk
 */
}

main(void) {
    struct MorseTree *morse;
    char text[] = ".-/-./-../--/-/.../-/.-./..-/--./-/..-/..-/.-./../-../";
    setlocale(LC_ALL, "");	
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
}
