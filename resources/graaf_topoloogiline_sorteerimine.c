/* Topoloogiline sorteerimine.
 * Andmed loetakse tekstifailist ning graafi kirjeldus pannakse naabrusmaatriksisse.
 * Tekstifaili esimesel real on graafi servade ja tippude arvud.
 * Järgmistel ridadel (neid on sama palju, kui servi) on igas reas ühe serva kirjeldus, 
 * mis koosneb serva algustipust ja lõpptipust. 
 * Graaf on suunatud (iga serv kantakse naabrusmaatriksisse ühe korra).
 */
#include <stdio.h>
#define maxN 10

int main(void) {
    FILE *tf=NULL;
    int i, j, k, tipud, servad, algus, l6pp, summa;
    int naabrusmaatriks[maxN][maxN] = {0};  /* Sellisel viisil saab ka maatrikseid nullida. Aga ainult nullida!! */
    int sisendaste[maxN] = {0};

    tf = fopen("graaf_topo.txt","r");  
/* Faili esimesest reast loetakse graafi tippude ja servade arvud. */
    fscanf(tf, "%d %d", &servad, &tipud);
    printf("Graafis on %d tippu ja %d serva.\n", tipud, servad);

/* Ülejäänud faili lugemine ning servade märkimine naabrusmaatriksisse. 
 * Esimeselt realt loetud servade arv ütleb, mitu rida tuleb lugeda.
 */
    for (i = 0; i < servad; i++) {
        fscanf(tf,"%d %d",&algus,&l6pp);
        naabrusmaatriks[algus][l6pp] = 1;
        /* Kui graaf oleks orienteerimata, tuleks iga kaar kirjutada kaks korda. Lisaks:
        naabrusmaatriks[l6pp][algus] = 1;
        */
    }
    printf("\n");
   
/* Loetakse kokku igasse tippu sisenevad kaared. Tegelikult küll leitakse antud juhul summa,
 * sest maatriksis on vaid 0-d ja 1-d.
 */ 
	for (i = 0; i < tipud; i++) {
		for (j = 0; j < tipud; j++) {
			if (naabrusmaatriks[j][i] != 0) {
				sisendaste[i]++;
			}
		}
	}
  /* 
   * Järgnevalt trükitakse topelt tsükliga välja naabrusmaatriks ning sinna järgi kohe eellaste maatriks.
   */
    printf("Trükime välja naabrusmaatriksi ilusal kujul.\n");
    for (i = 0; i < tipud; i++) {
        for (j = 0; j < tipud; j++) {
            printf("%3d", naabrusmaatriks[i][j]);
        }
        printf("\n");
    }
    printf("Samuti trükime välja eellaste tabeli ehk sisenevate kaarte arvud.\n");
    for (i = 0; i < tipud; i++) {
        printf("%3d", sisendaste[i]);
    }
    printf("\n\n");
/*
 * Kogu järgnevat tegevust tuleb korrata, et kõik tipud jadasse saada.
 */
    for (k = 0; k < tipud; k++) {
        for (i = 0; i < tipud; i++) {

/* 
 * Ühe vabaks saanud tipu lisamine sorteritud jadasse ning tema naabrite "vabastamine" sellest tipust 
 * ehk kõigi naabrite eelaste arvu vähendamine ühe võrra.
 */
            if (sisendaste[i] == 0) {
                printf("tipp: %2d\n", i);
                sisendaste[i] = -1;
                for (j = 0; j < tipud; j++) {
                    if (naabrusmaatriks[i][j] == 1) {
                        sisendaste[j]--;
                    }
                }
/* 
 * Peale ühe tipu lisamist sorteeritud jadasse toob break täitmise tsüklist välja, 
 * et alustada järgmise vaba tipu otsmist algusest.
 */                
                break;
            }
        }
    }
    return 0;
}

