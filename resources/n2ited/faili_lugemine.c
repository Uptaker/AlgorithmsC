/*
 * Näites loetakse failist tekst stringidena ja trükitakse ekraanile. Ridu võib olla mitu.
 */

#include <stdio.h>

main(){

/* Muutuja line on string rea kaupa lugemiseks ja lisaks deklareeritakse faili pide */

  	char line[128];
  	FILE *fm = NULL;

/* Faili jutt.txt avamine lugemiseks - fail peab loomulikult olemas olema!!*/

  	fm = fopen("jutt.txt", "r");

/* feof() - funktsioon, mis kontrollib faili lõpu tunnust. Tagastab tõese väärtuse, kui
 * faili lõpp saabud. Seega feof()-i eitus lubab tsüklil töötada siis, kui lõppu ei paista.
 */ 

  	while (!feof(fm)) {

/* fgets loeb failist ettenähtud maksimaalse pikkusega stringi. Parameetrid vastavalt: loetav muutuja,
 * loetav maks pikkus ja failipide.
 * Reavahetus toimib ühe lugemislause jaoks lõputunnusena.
 */ 
 
    	fgets(line, 128, fm);
    	printf("%s", line);
  }
  fclose(fm);
}

/* Käivitamiseks ära edaspidist juttu kopeeri */
--------------------------------------------------
Veel kommentaare:
fscanf(fm, "%s", rida);
on ka sobiv erinevat tüüpi andmete lugemiseks ja kiireks teisendamiseks sobivasse andmetüüpi.
Antud näide töötab nii, et iga lugemisekäsk loeb failist järgmise tühikuni (või ka realõpu tunnuseni).
Seega võib ühes reas toimuda mitu lugemist.

Vt näidet faili_lugemine2.c fscanf()-i kasutamisest andmete lugemiseks ja sisendi konvertimiseks arvudeks.



