/* N�ide arvude ja stringide lugemisest tekstifailist ning t��st kahem��tmelise massiiviga.
 * Loetavad andmed teisendatakse lugemise k�igus sellesse t��pi, nagu neid p�rast vaja kasutada.
 * N�iteks arvud muudetakse peale lugemist kohe int-ideks jne.
 * Vaata ka faili proov.txt
 */
#include <stdio.h>
#include <string.h>
#define maxN 20

int main(void) {
    FILE *tf=NULL;
    int i, j, len, placeIndex = 0;
    char name[20];
    int numOfPlaces, numOfEdges;
    char x;
    
    tf = fopen("kohad_Eesti.txt","r");

    // save number of edges & places
    fscanf(tf,"%d",&numOfPlaces);
    char places[numOfPlaces][maxN];
    int matrix[numOfPlaces][numOfPlaces];

    // save place names to places array
    fscanf(tf, "%c", &x);
    while (!feof(tf)) {
    	fgets(name, 20, tf);
        len = strlen(name);
        if (name[len-1] == '\n') name[len-1] = '\0';
        strcpy(places[placeIndex], name);
        placeIndex++;
    }
    fclose(tf);

    // checking places array
    for (i = 0; i < placeIndex; i++) {
        printf("%d %s\n", i, places[i]);
    }

    tf = fopen("seosed_Eesti.txt", "r");

    fscanf(tf,"%d %d",&numOfPlaces,&numOfEdges);
    printf("places: %d edges: %d\n",numOfPlaces, numOfEdges);

    // empty matrix with nulls
    for (i = 0; i < numOfPlaces; i++) {
        for (j = 0; j < numOfPlaces; j++) {
            matrix[i][j] = 0;
        }
    }

    // fill matrix with distance
    int start, end, dist;
    for (i = 0; i < numOfEdges; i++) {
        fscanf(tf, "%d %d %d", &start, &end, &dist);
        matrix[start][end] = dist;
        matrix[end][start] = dist;
    }
    fclose(tf);

    // print matrix (save output to file because it's too large)
    tf = fopen("output.txt", "w");
    printf("Printing matrix...\n");
	for (i = 0; i < numOfPlaces; i++) {
        for (j = 0; j < numOfPlaces; j++) {
        	fprintf(tf, "%3d", matrix[i][j]);
        }
        fprintf(tf, "\n");
    }
    printf("Matrix printed to output.txt\n");
    fclose(tf);

    int input; 
    printf("Input city index to return its name\n");
    scanf("%d", &input);
    input--;
    printf("City is %s", places[input]);

	return 0; 

}
