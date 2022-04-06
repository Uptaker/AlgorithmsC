#include <stdio.h>
#include <string.h>
#define maxN 10

// tipp = vertex, kaar = edge

int main(void) {
   FILE *tf = NULL;
    int i, j, vertex, edge, vert1, vert2, input;
    int AdjMatrix[maxN][maxN];
   
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
    for (i = 0; i < edge; i++) {
        fscanf(tf,"%d %d", &vert1, &vert2);
        AdjMatrix[vert1][vert2] = 1;
    }
    printf("\n");

    // print matrix
	for (i = 0; i < vertex; i++) {
        for (j = 0; j < edge; j++) {
        	printf("%3d", AdjMatrix[i][j]);
        }
        printf("\n");
    }

    // user selects vertex
    printf("%s ", "Which vertex neighbors to display?");
    scanf("%d", &input);

    // print adjacent vertexes from matrix
    for (i = 0; i < vertex; i++) {
        
        if (AdjMatrix[input][i] == 1) {
            printf("%d\n", i);
        }
    }
 
	return 0; 
 
}