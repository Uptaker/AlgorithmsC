/* Topoloogiline sorteerimine.
 * Andmed loetakse tekstifailist ning graafi kirjeldus pannakse naabrusmaatriksisse.
 * Tekstifaili esimesel real on graafi servade ja tippude arvud.
 * J�rgmistel ridadel (neid on sama palju, kui servi) on igas reas �he serva kirjeldus, 
 * mis koosneb serva algustipust ja l�pptipust. 
 * Graaf on suunatud (iga serv kantakse naabrusmaatriksisse �he korra).
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

/* �lej��nud faili lugemine ning servade m�rkimine naabrusmaatriksisse. 
 * Esimeselt realt loetud servade arv �tleb, mitu rida tuleb lugeda.
 */
    for (i = 0; i < servad; i++) {
        fscanf(tf,"%d %d",&algus,&l6pp);
        naabrusmaatriks[algus][l6pp] = 1;
        /* Kui graaf oleks orienteerimata, tuleks iga kaar kirjutada kaks korda. Lisaks:
        naabrusmaatriks[l6pp][algus] = 1;
        */
    }
    printf("\n");
   
/* Loetakse kokku igasse tippu sisenevad kaared. Tegelikult k�ll leitakse antud juhul summa,
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
   * J�rgnevalt tr�kitakse topelt ts�kliga v�lja naabrusmaatriks ning sinna j�rgi kohe eellaste maatriks.
   */
    printf("Tr�kime v�lja naabrusmaatriksi ilusal kujul.\n");
    for (i = 0; i < tipud; i++) {
        for (j = 0; j < tipud; j++) {
            printf("%3d", naabrusmaatriks[i][j]);
        }
        printf("\n");
    }
    printf("Samuti tr�kime v�lja eellaste tabeli ehk sisenevate kaarte arvud.\n");
    for (i = 0; i < tipud; i++) {
        printf("%3d", sisendaste[i]);
    }
    printf("\n\n");
/*
 * Kogu j�rgnevat tegevust tuleb korrata, et k�ik tipud jadasse saada.
 */
    for (k = 0; k < tipud; k++) {
        for (i = 0; i < tipud; i++) {

/* 
 * �he vabaks saanud tipu lisamine sorteritud jadasse ning tema naabrite "vabastamine" sellest tipust 
 * ehk k�igi naabrite eelaste arvu v�hendamine �he v�rra.
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
 * Peale �he tipu lisamist sorteeritud jadasse toob break t�itmise ts�klist v�lja, 
 * et alustada j�rgmise vaba tipu otsmist algusest.
 */                
                break;
            }
        }
    }
    return 0;
}

