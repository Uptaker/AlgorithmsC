/* Loeme sisse graafi kirjelduse failist.
 * Faili esimese reas on kaks arvu - tippude arv numNode ja kaarte arv numVert.
 * J�rgneb N rida, kus kaks t�isarvu eraldatud t�hikuga - kaarte kirjeldused.
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
   J�rgnev ts�kkel loeb k�ik kaared ja kannab need naabrusmaatriksisse.
 */

    for (i = 0; i < numEdge; i++) {
        fscanf(tf,"%d %d", &vert1, &vert2);
        adjMatrix[vert1][vert2] = 1;
    }
    printf("\n");
    printf("Tr�kime v�lja maatriksi ilusal kujul.\n");
    for (i = 0; i < numVert; i++) {
        for (j = 0; j < numVert; j++) {
            printf("%3d", adjMatrix[i][j]);
        }
        printf("\n");
    }
 
/* 
   Loeme kokku igasse tippu sisenevate kaarte arvu. Selleks t��tleme maatriksit veergude kaupa.
 */
    for (j = 0; j < numVert; j++) {
        for (i = 0; i < numVert; i++) {
            if (adjMatrix[i][j] == 1) {
                inDegree[j]++;
            }
        }       
    }

/* 
   Tr�kime kontrolliks v�lja sisenevate kaarte arvudega massiivi
 */
    for (i = 0; i < numVert; i++) {
        printf("%2d", inDegree[i]); 	
    }
    printf("\n");

/* 
 * V�ljastame tipud topoloogiliselt sorteeritud j�rjekorras
 * Muutuja sorted abil j�lgitakse, kas on veel tippe, mis ei ole lisatud sorteeritud j�rjekorda.
 * Seni kuni leidub v�ljastamata tippe, korratakse while-ts�kli t��d. �he while-ts�kli kordusega v�idakse v�ljastada 
 * mitu tippu.
 * -1 omistamine inDegree[] massiivi �tleb, et vastav tipp on t��deldud.
 */
    while (!sorted) {
        sorted = 1;
        for (i = 0; i < numVert; i++) {
            if (inDegree[i] == 0) {
                printf("tipp: %2d\n", i);
                inDegree[i] = -1;
                sorted = 0;
/* 
 * Peale j�rgmise tipu v�ljastamist muudetakse massiivis inDegree[] sisenevate kaarte arvud.
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
