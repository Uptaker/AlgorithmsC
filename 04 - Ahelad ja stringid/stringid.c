/*  while-tsükli ja stringi kasutamise näide
 *   Kasutajalt küsitakse parooli
 *   programmi ei saa edasi kasutada, kuni ei ole sisestatud õge parool
 *   Edasi annab programm võmaluse parooli muuta - sisestada uus parool 2 korda
 *   ja kui mõlemad katsed on ühesugused, siis muudetaksegi ära
 *   NB! Reaalselt muidugi nii parooliga kätuda ei tohiks.
 */

#include <stdio.h>
#include <string.h>

main() {
/* 
 *  Järgneval kahel real deklareeritakse stringid (märkide massiiv)
 *  Esimene lause demonstreerib muutuja algväärtustamise võimalust deklareerimise käigus
 *  Kolmandal real aga märgitüüpi (char) muutuja.
 */
 
    char password[10] = "kalasalat";
    char trayPasswd[10], newPasswd1[10], newPasswd2[10];
    char answer;

/* Stringi sisestamiseks on formaat %s. scanf() ei ole stringide puhul turvaline - loeb sisse ka 
 * pikema teksti kui stringi pikkus lubab ja kirjutab massiivi üle serva. Selle vastu aitab formaadis maks pikkuse määramine.
 * Teine probleem on, et ta loeb esimese "whitespace'ini", seega tühikut sisaldavat stringi scanf()-iga
 * sisse lugeda ei saa.
 */
 
    printf("Sisesta parool ");
    scanf("%9s", trayPasswd);
    printf("%s\n", trayPasswd);
    getchar();   /* Loeb sisendpuhvrist ära reavahetuse, mida ta kuhugi ei pane.*/
/* Stringe ei saa tavalisel viisil võrrelda. Selle asemel on funktsioon (vt täpsemalt selgitusest allpool) */

    while (strcmp(trayPasswd, password)) {
        printf("Parool on vale. Programmi ei saa edasi kasutada.\n");
        printf("Sisesta parool uuesti \n");
        scanf("%9s", trayPasswd);
        getchar();
    }
        
/* 
 *   Märkide ja stringide lugemisel võib tuhti tekkida olukord, kus koos andmetega
 *   ei loeta klaviatuuripuhvrist välja reavahetuse märki.
 *   Tulemuseks on, et järgnev sisendfunktsioon leiab puhvrist nn Enteri ja kui tühi string funktsioonile sobib, siis
 *   see ka sisse loetakse (kasutajalt sisendit ei oodata).
 *   Siin näites on kasutatud funktsiooni getchar() puhvrist ühe märgi välja lugemiseks.
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
        
/* Tavalist omistamist stringidega teha ei saa, selle asemel on funktsioon, mis mäluvälju kopeerib */

            strcpy(password,newPasswd1);
            printf("Parool muudetud");
        }
        else {
        	printf("Paroolid olid erinevad");
		}
    }
}
/* Programmi käivitamiseks kopeeri siia maani */
/*------------------------------------------------------------
Selgitusi stringidest (ja massiividest)

Et string ei ole eraldi andmetüüp, ei ole tema jaoks ka kirjeldatud tavalisi tehteid (nt omistamine või
võrdlemine). Seda rolli täidavad standardfunktsioonid. Nende kasutamiseks on vaja teeki string (#include <string.h>,
kuid mõnes keskkonnas võib see teek olla ka automaatselt lisatud.
Mõned näited:

int strlen(string) - leiab stringi pikkuse
strcpy(koopia, originaal) - stringi kopeerimine ühelt mäluväljalt teise, sisuliselt omistamine
strcat(string1, string2) - 1. stringi järele sidurdatakse 2. string (eeldusel, et ta peab ära mahtuma)
int strcmp(string1, string2) - kahe stringi võrdlemine. Tagastatav arv näitab:
    0 - stringid on võrdsed
    neg arv - 1. string on väiksem kui 2. string
    pos arv - 1. string on suurem kui 2. string

Pane veel tähele, et stringkonstandi eraldajad on jutumärgid: "" 
ja märgikonstandi eraldajad on ülakomad: ''

*/
