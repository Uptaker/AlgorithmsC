/*  while-ts�kli ja stringi kasutamise n�ide
 *   Kasutajalt k�sitakse parooli
 *   programmi ei saa edasi kasutada, kuni ei ole sisestatud �ge parool
 *   Edasi annab programm v�maluse parooli muuta - sisestada uus parool 2 korda
 *   ja kui m�lemad katsed on �hesugused, siis muudetaksegi �ra
 *   NB! Reaalselt muidugi nii parooliga k�tuda ei tohiks.
 */

#include <stdio.h>
#include <string.h>

main() {
/* 
 *  J�rgneval kahel real deklareeritakse stringid (m�rkide massiiv)
 *  Esimene lause demonstreerib muutuja algv��rtustamise v�imalust deklareerimise k�igus
 *  Kolmandal real aga m�rgit��pi (char) muutuja.
 */
 
    char password[10] = "kalasalat";
    char trayPasswd[10], newPasswd1[10], newPasswd2[10];
    char answer;

/* Stringi sisestamiseks on formaat %s. scanf() ei ole stringide puhul turvaline - loeb sisse ka 
 * pikema teksti kui stringi pikkus lubab ja kirjutab massiivi �le serva. Selle vastu aitab formaadis maks pikkuse m��ramine.
 * Teine probleem on, et ta loeb esimese "whitespace'ini", seega t�hikut sisaldavat stringi scanf()-iga
 * sisse lugeda ei saa.
 */
 
    printf("Sisesta parool ");
    scanf("%9s", trayPasswd);
    printf("%s\n", trayPasswd);
    getchar();   /* Loeb sisendpuhvrist �ra reavahetuse, mida ta kuhugi ei pane.*/
/* Stringe ei saa tavalisel viisil v�rrelda. Selle asemel on funktsioon (vt t�psemalt selgitusest allpool) */

    while (strcmp(trayPasswd, password)) {
        printf("Parool on vale. Programmi ei saa edasi kasutada.\n");
        printf("Sisesta parool uuesti \n");
        scanf("%9s", trayPasswd);
        getchar();
    }
        
/* 
 *   M�rkide ja stringide lugemisel v�ib tuhti tekkida olukord, kus koos andmetega
 *   ei loeta klaviatuuripuhvrist v�lja reavahetuse m�rki.
 *   Tulemuseks on, et j�rgnev sisendfunktsioon leiab puhvrist nn Enteri ja kui t�hi string funktsioonile sobib, siis
 *   see ka sisse loetakse (kasutajalt sisendit ei oodata).
 *   Siin n�ites on kasutatud funktsiooni getchar() puhvrist �he m�rgi v�lja lugemiseks.
 */
 
    printf("Kas soovid parooli muuta [j/e]?");
    answer = getchar();   /* scanf("%c",&soov);*/
    getchar();
    if (answer == 'j') { 
        printf("Sisesta uus parool ");
        scanf("%9s", newPasswd1);
	    printf("Uue parooli pikkus on %d.\n", strlen(newPasswd1));
        printf("Sisesta uus parool teist korda ");
        scanf("%9s", newPasswd2);
        if (!strcmp(newPasswd1, newPasswd2)) {
        
/* Tavalist omistamist stringidega teha ei saa, selle asemel on funktsioon, mis m�luv�lju kopeerib */

            strcpy(password,newPasswd1);
            printf("Parool muudetud");
        }
        else {
        	printf("Paroolid olid erinevad");
		}
    }
}
/* Programmi k�ivitamiseks kopeeri siia maani */
/*------------------------------------------------------------
Selgitusi stringidest (ja massiividest)

Et string ei ole eraldi andmet��p, ei ole tema jaoks ka kirjeldatud tavalisi tehteid (nt omistamine v�i
v�rdlemine). Seda rolli t�idavad standardfunktsioonid. Nende kasutamiseks on vaja teeki string (#include <string.h>,
kuid m�nes keskkonnas v�ib see teek olla ka automaatselt lisatud.
M�ned n�ited:

int strlen(string) - leiab stringi pikkuse
strcpy(koopia, originaal) - stringi kopeerimine �helt m�luv�ljalt teise, sisuliselt omistamine
strcat(string1, string2) - 1. stringi j�rele sidurdatakse 2. string (eeldusel, et ta peab �ra mahtuma)
int strcmp(string1, string2) - kahe stringi v�rdlemine. Tagastatav arv n�itab:
    0 - stringid on v�rdsed
    neg arv - 1. string on v�iksem kui 2. string
    pos arv - 1. string on suurem kui 2. string

Pane veel t�hele, et stringkonstandi eraldajad on jutum�rgid: "" 
ja m�rgikonstandi eraldajad on �lakomad: ''

*/

