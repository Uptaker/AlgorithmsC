/* 
 * Moorsekoodi dekodeerimine, kasutades selleks kahendpuud, mis on realiseeritud massiivina.
 * Parandatud ja täiendavalt kommenteeritud versioon 12.04.2019
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxN 100

main() {
    FILE *tf=NULL;
   
/* Massiivis morse on tähed sellises järjekorras, et nad moodustavad staatilise "morsepuu". Tuleta meelde, et puud sai ka realiseerida massiiviga!
 * Puu juur on esimene element, sellele järgnevad juure vasak laps ja parem laps jne. 
 * Tipu i vasaku lapse indeksi leidmiseks sobib valem (i + 1) * 2 - 1, parema lapse indeks on (i + 1) * 2
 */
  
    char morseTree[] = {' ','E','T','I','A','N','M','S','U','R','W','D','K','G','O','H','V','F','Ü','L','Ä','P','J','B','X','C','Y','Z','Q','Ö'};
    char morseFromFile[MaxN];
    int j, rowLength, current;
	
    tf = fopen("morse1.txt","r");
/* 
 * Järgnev tsükkel loeb faili ridade kaupa, kuni faili lõpuni 
 * Funktsioon feof() kontrollib, kas on jõutud faili lõputunnuseni
 */
    while (!feof(tf)) {
        fgets(morseFromFile, MaxN, tf);
        rowLength = strlen(morseFromFile);
        current = 0;
/* Ühe rea dekodeerimine
 */
        for (j = 0; j < rowLength; j++) {
/* Kui on punkt, liigu puus tipu vasakusse alampuusse
 */
            if (morseFromFile[j] == '.') {
                current = (current + 1) * 2 - 1;
            }
/* Kui on kriips, liigu puus tipu paremasse alampuusse
 */
            else if (morseFromFile[j] == '-') {
                current = (current + 1) * 2;
            }
/* Kui on kaldkriips, on jõutud puus täheni, mis trükitakse välja
 */
            else if (morseFromFile[j] == '/') {
                printf("%c", morseTree[current]);
                current = 0;
            }
        }
    }
    fclose(tf);
}

