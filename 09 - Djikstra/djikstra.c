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

    // save number of edges & places from file's first line
    tf = fopen("seosed_Eesti.txt", "r");
    fscanf(tf,"%d %d",&numOfPlaces,&numOfEdges);
    printf("places: %d edges: %d\n",numOfPlaces, numOfEdges);

    // create empty matrix with nulls
    for (i = 0; i < numOfPlaces; i++) {
        for (j = 0; j < numOfPlaces; j++) {
            matrix[i][j] = 0;
        }
    }

    // fill matrix with distances
    int start, end, dist;
    for (i = 0; i < numOfEdges; i++) {
        fscanf(tf, "%d %d %d", &start, &end, &dist);
        matrix[start][end] = dist;
        matrix[end][start] = dist;
    }
    fclose(tf);

    // print matrix to output.txt (because it's too large for terminal)
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

    // ask user for start and end positions
    printf("Input city index to start from\n");
    scanf("%d", &start); start--;
    printf("Input city index to end in\n");
    scanf("%d", &end); end--;

    // allowed index check
    if (start > (numOfPlaces - 1) || start < 0 || end > (numOfPlaces - 1) || end < 0) {
        printf("Can only select indexes from 1 to %d!", numOfPlaces);
        printf("%d %d", start, end);
        return 0;
    } else if (start == end) {
        printf("Start and end cannot be the same!");
        return 0;
    }

    printf("You want to go from %s to %s", places[start], places[end]);

	return 0; 

}
