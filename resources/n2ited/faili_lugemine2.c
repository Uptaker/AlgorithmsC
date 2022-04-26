/* Näide arvude ja stringide lugemisest tekstifailist ning tööst kahemõõtmelise massiiviga.
 * Loetavad andmed teisendatakse lugemise käigus sellesse tüüpi, nagu neid pärast vaja kasutada.
 * Näiteks arvud muudetakse peale lugemist kohe int-ideks jne.
 * Vaata ka faili proov.txt
 */
#include <stdio.h>
#include <string.h>
#define maxN 10

int main(void) {
   FILE *tf=NULL;
   int i, j, m, n, number;
   char name[20];
   int matrix[maxN][maxN];
   
   tf = fopen("proov.txt","r");  

/* Peale avamist loetakse esimeselt realt 2 tühikutega eraldatud täisarvu
 * Seda näitab formaat "%d %d" 
 * Arvud loetakse muutujatesse m ja n 
 */

   fscanf(tf,"%d %d",&m,&n);
   printf("%d %d\n",m,n);

/* Järgnev tsükkel loeb m reast ja n veerust andmeid.
 * Eeldus: andmed on täpselt lubatud koguses.
 * Loetud arvud kirjutatakse massiivi. 
 */

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
        	fscanf(tf,"%d", &number);
        	printf("%d ", number);
        	matrix[i][j] = number;
        }
    }
    printf("\n");
   
/* Loeme while-tsükliga kuni faili lõpuni - ridade kaupa ja stringideks 
 */

    while (!feof(tf)) {
    	fgets(name, 20, tf);
    	printf("%d",strlen(name));
    	printf("%s", name);
    }

	printf("Trükime välja maatriksi ilusal kujul.\n");
	for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
        	printf("%3d", matrix[i][j]);
        }
        printf("\n");
    }
 
	return 0; 
 
}
