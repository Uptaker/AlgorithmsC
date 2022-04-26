/*
 * Sorteeritud massiivi loomine kohe andmetesisestamise käigus.
 */
#include <stdio.h>
#define MAXN 10

main() {
 int data[MAXN];
 int i, j, number, k;
 
 for (i = 0; i < MAXN; i++)
 {
    printf("\n\nSisesta järgmine arv ");
    scanf("%d", &number);
    printf("Lisatav %d.\n", number);
    for (j = i; data[j - 1] > number && j > 0; j--) {     
        data[j] = data[j-1];
        //printf("Tsüklis %d %d\n",j, arvud[j]);
    }
    data[j] = number;
    for (k = 0; k < MAXN; k++) {
     	 printf("%d ", data[k]);
	} 
 }
 }
