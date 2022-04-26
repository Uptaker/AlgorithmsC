/* Loeme sisse graafi kirjelduse failist.
 * Faili esimese reas on kaks arvu - tippude arv numNode ja kaarte arv numVert.
 * Järgneb N rida, kus kaks täisarvu eraldatud tühikuga - kaarte kirjeldused.
 * Eeldatakse, et graaf on orienteeritud.
 */
#include <stdio.h>
#define maxN 50

int main(void) {
   FILE *tf=NULL;
   int numEdge, numVert, i, j, k, vert1, vert2;
   int adjMatrix[maxN][maxN] = {0};
   int inDegree[maxN] = {0};
   int sorted;
   
   tf = fopen("graaf_topo1.txt","r");

/* 
   Faili esimesest reast loetakse tippude arv ja kaarte arv
 */

   fscanf(tf,"%d %d",&numVert, &numEdge);
   printf("Graafis on %d tippu ja %d kaart.\n", numVert, numEdge);

/* 
   Järgnev tsükkel loeb kõik kaared ja kannab need naabrusmaatriksisse.
 */

    for (i = 0; i < numEdge; i++) {
        fscanf(tf,"%d %d", &vert1, &vert2);
        adjMatrix[vert1][vert2] = 1;
    }
    printf("\n");
    printf("Trükime välja maatriksi ilusal kujul.\n");
    for (i = 0; i < numVert; i++) {
        for (j = 0; j < numVert; j++) {
            printf("%3d", adjMatrix[i][j]);
        }
        printf("\n");
    }
 
/* 
   Loeme kokku igasse tippu sisenevate kaarte arvu. Selleks töötleme maatriksit veergude kaupa.
 */
    for (j = 0; j < numVert; j++) {
        for (i = 0; i < numVert; i++) {
            if (adjMatrix[i][j] == 1) {
                inDegree[j]++;
            }
        }       
    }

/* 
   Trükime kontrolliks välja sisenevate kaarte arvudega massiivi
 */
    for (i = 0; i < numVert; i++) {
        printf("%2d", inDegree[i]); 	
    }
    printf("\n");

/* 
 * Väljastame tipud topoloogiliselt sorteeritud järjekorras
 * Muutuja sorted abil jälgitakse, kas on veel tippe, mis ei ole lisatud sorteeritud järjekorda.
 * Seni kuni leidub väljastamata tippe, korratakse while-tsükli tööd. Ühe while-tsükli kordusega võidakse väljastada 
 * mitu tippu.
 * -1 omistamine inDegree[] massiivi ütleb, et vastav tipp on töödeldud.
 */
    while (!sorted) {
        sorted = 1;
        for (i = 0; i < numVert; i++) {
            if (inDegree[i] == 0) {
                printf("tipp: %2d\n", i);
                inDegree[i] = -1;
                sorted = 0;
/* 
 * Peale järgmise tipu väljastamist muudetakse massiivis inDegree[] sisenevate kaarte arvud.
 */
                for (j = 0; j < numVert; j++) {
                    if (adjMatrix[i][j] == 1) {
                        inDegree[j]--;
                    }
                }
            }
        }
    }
    return 0;
}
