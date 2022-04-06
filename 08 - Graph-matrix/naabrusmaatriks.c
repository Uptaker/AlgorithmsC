#include <stdio.h>
#include <string.h>
#define maxN 10

// tipp = vertex, kaar = edge

int main(void) {
   FILE *tf = NULL;
    int i, j, vertex, edge;
    int AdjMatrix[maxN][maxN];
    int e;
    int v;
   
   tf = fopen("graaf_topo1.txt","r");  

   fscanf(tf,"%d %d",&vertex, &edge);

    // create matrix with nulls
    for (i = 0; i < vertex; i++) {
        for (j = 0; j < edge; j++) {
            AdjMatrix[i][j] = 0;
        }
    }
    printf("\n");

    // fill empty matrix with 1's where needed
    for (i = 0; i < vertex; i++) {
        fscanf(tf,"%d %d", &v, &e);
        AdjMatrix[v][e] = 1;
    }
    printf("\n");

    // print matrix
	for (i = 0; i < vertex; i++) {
        for (j = 0; j < edge; j++) {
        	printf("%3d", AdjMatrix[i][j]);
        }
        printf("\n");
    }
 
	return 0; 
 
}