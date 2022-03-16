#include <stdio.h>

main(){

/* Muutuja line on string rea kaupa lugemiseks ja lisaks deklareeritakse faili pide */

  	char line[128];
  	FILE *fm = NULL;

/* Faili jutt.txt avamine lugemiseks - fail peab loomulikult olemas olema!!*/

  	fm = fopen("morse2.txt", "r");

/* feof() - funktsioon, mis kontrollib faili lõpu tunnust. Tagastab tõese väärtuse, kui
 * faili lõpp saabud. Seega feof()-i eitus lubab tsüklil töötada siis, kui lõppu ei paista.
 */ 

  	while (!feof(fm)) {

/* fgets loeb failist ettenähtud maksimaalse pikkusega stringi. Parameetrid vastavalt: loetav muutuja,
 * loetav maks pikkus ja failipide.
 * Reavahetus toimib ühe lugemislause jaoks lõputunnusena.
 */ 
 
    	fgets(line, 127, fm);
    	printf("%s", line);
  }
  fclose(fm);
}