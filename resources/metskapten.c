#include <stdio.h>
#include <stdlib.h>

/* Lahendus ülesandele Metskapten
Kasutatakse ringahelat ja imiteeritakse elementide
ringist välja viskamist
*/

struct element {
   int info; 
   struct element *next;
};

/* Moodustab ringahela etteantud arvust (numOfElements) elementidest,
tagastab esimesena lisatud elemendi (elemendi nr 1) aadressi.
*/

struct element *MakeCircle(int numOfElements) {
	int i;
	struct element *node, *begin, *end;
	begin = malloc(sizeof *begin);
	begin->info = 1;
	begin->next = begin;
	end = begin;
	for (i=1; i<numOfElements; i++) {
		node = malloc(sizeof *node);
		node->info = i + 1;
		end->next = node;
		node->next = begin;
		end = node;
	}
	return begin;
}

/* Trükib välja ahelasse (ringi) alles jäänud elemendid.
*/
void PrintCircle(struct element *begin) {
	struct element *node;
	int i;
	node = begin;
	do {
		printf("%d ", node->info);
		node = node->next;
	}
	while (node != begin);
}

/* Kustutab ringist n-nda elemendi,
tagastab järgmise elemendi aadressi.
*/
struct element *DropOut(struct element *begin, int n) {
	int i;
	struct element *curr, *prev;
	curr = begin;
	for (i = 0; i < n-1; i++) {
		prev = curr;
		curr = curr->next;
	}
	/*printf("Deleting %dth element.\n", curr->info);*/
	prev->next = curr->next;
	free(curr);
	return prev->next;
	
}

void main(void) {
	int people, relatives, nth, i;
	struct element *begin, *curr;
	printf("Mitu inimest on laeval? ");
	scanf("%d", &people);
	printf("Mitu nendest on metskapteni sugulased? ");
	scanf("%d", &relatives);
	printf("Mitmes visatakse üle parda? ");
	scanf("%d", &nth);
	begin = MakeCircle(people);
	printf("Ringis on järgmised elemendid: \n");
	PrintCircle(begin);
	for (i = 0; i < people - relatives; i++) {
		begin = DropOut(begin, nth);
/*		PrintCircle(begin);*/
	}
	printf("\nKindlamad asukohad ringis on ");
	PrintCircle(begin);
}
