/* L�hima tee leidmine kaalutud graafis: Dijkstra algoritm.
   Andmeteks on Eesti kaardilt tuvastatud teel�ikude pikkused veidi suurematel teedel.
   Info on kahes failis:
   Kohtade failis on j�rjest kohtade nimed. Esimesel real kohtade arv.
   Seoste failis on esimesel real seoste ja kohtade (?) arv, edasi arvukolmikud, mis esitavad seose otspunktid ja pikkuse.
   NB! kohtade faili l�pus peab olema �ks t�hi rida (st viimane rida peab ka l�ppema Enteriga)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxN 300


int main(void) {
    int i,j, length, numberOfPlaces, numberOfDistances, begin, end, distBetween, min, minNode, prevNode;
    FILE *tf=NULL;
    char placeFromFile[30];
    char places[maxN][30];
    int distances[maxN][maxN]={0};
    int node[maxN], label[maxN], prev[maxN]; /* Abimassiivid on nimetatud samade nimedega, mida kasutati materjalis.*/
    tf = fopen("kohad_Saaremaa.txt","r");
    fscanf(tf,"%d\n", &numberOfPlaces);
    printf("%d\n",numberOfPlaces);
    for (i = 0; i < numberOfPlaces; i++) {
        fgets(placeFromFile,30,tf);
        length = strlen(placeFromFile);
        if (length > 1 && placeFromFile[length-1] == '\n'){  /* kui loetu l�pus on \n*/
            placeFromFile[length-1] = '\0';          /* tee string selle v�rra l�hemaks ja lisa stringi l�pu tunnus*/
            strcpy(places[i], placeFromFile);
        }
	}
  	fclose(tf);
  	printf("Failist loetud kohad on:\n");
  	for (i = 0; i < numberOfPlaces; i++) {
        printf("%d %s\n", i, places[i]);
    }
    tf = fopen("eesti_Saaremaa.txt","r");
    fscanf(tf,"%d %d\n", &numberOfPlaces, &numberOfDistances);
    for (i = 0; i < numberOfDistances; i++) {
        fscanf(tf,"%d %d %d",&begin, &end, &distBetween);
        distances[begin][end] = distBetween;
        distances[end][begin] = distBetween;
	}
    fclose(tf);
/*  printf("Tr�kime v�lja naabrusmaatriksi:\n");
	for (i = 0; i < numberOfPlaces; i++) {
        for (j = 0; j < numberOfPlaces; j++) {
            printf("%3d",distances[i][j]);
    	}
        printf("\n");
    }
*/
    for (i=0;i<numberOfPlaces; i++) {
        node[i] = 0;
        label[i] = 999;
        prev[i] = -1;
    }
    printf("Kust matk algab? Sisesta j�rjekorranumber! ");
    scanf("%d",&begin);
    printf("Kus matk l�ppeb? Sisesta j�rjekorranumber! ");
    scanf("%d",&end);
    label[begin] = 0;
    for (j=0;j<numberOfPlaces; j++) {
/* 
    K�igepealt otsitakse tipp, mille naabreid uurida. Selle tipu kaugus l�htepunktist on k�ige v�iksem 
    ja ta on veel uurimata. 
*/
        min = 999;
        for (i = 0; i<numberOfPlaces; i++) {
        	if (min > label[i] && node[i] == 0) {
            	minNode = i;
            	min = label[i];
        	}
       }
/*  
    N��d vaatame, millised on selle tipu naabrid ja teeme kindlaks, kas leiame nende juurde
    l�hema tee.
*/
        for (i = 0;i < numberOfPlaces; i++) {
        	if (distances[minNode][i] != 0) {
            	distBetween = label[minNode] + distances[minNode][i];
            	if (label[i] > distBetween) {
                	label[i] = distBetween;
                	prev[i] = minNode;
            	}
        	}
        }
        node[minNode] = 1;
 /*     Tr�kitakse v�lja k�ik kolm t�� k�igus tekkinud massiivi. Siit saab ka s�rmaga j�rge 
        ajades vaadata, kuidas teed leida.
 		for (i = 0; i < numberOfPlaces; i++){
            printf("%2d %2d %3d %2d\n",i,node[i],label[i],prev[i]);
        }
*/
  }
/* 
    Tee tr�kitakse v�lja tagurpidi. P�him�tteliselt v�iks tee ka esialgu massiivi salvestada 
	ja seej�rel �iges j�rgekorras v�lja tr�kkida.
*/
    printf("Tee l�pppunktist alguse poole:\n");
    prevNode = end;
    while (prevNode != -1) {
        printf("%d %s\n",prevNode, places[prevNode]);
        if (prev[prevNode] != -1) {
           printf("Eelmisesse kohta on %d kilomeetrit.\n",distances[prevNode][prev[prevNode]]);
        }
        prevNode = prev[prevNode];
  }
}
