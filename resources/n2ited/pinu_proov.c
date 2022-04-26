#include <stdio.h>
#include <stdlib.h>

/* 
 * N�ites on kirjeldatud 4 peamist pinu operatsiooni:
 * stackInit() - pinu loomine
 * stackEmpty() - kas pinu on t�hi?
 * stackPush() - lisamine pinusse
 * stackPop() - eemladamine pinust
 Pinu on �lesehitatud massiivile.
*/

/* Deklareeritakse globaalsed muutujad
   stack - viit pinule
   top - pinu tipp (esimese vaba koha indeks)
*/
static int *stack;
static int top;

/* Pinu loomine
   maxSize - pinu suurus - mitu elementi on massiivis
*/
void stackInit(int maxSize) { 
	stack = malloc(maxSize*sizeof(int)); 
    top = 0; 
}

/* Kontroll, kas pinu on t�hi
   Tagastab:
      1 (true) - kui pinu on t�hi
      0 (false )- kui pinu ei ole t�hi
      */
int stackEmpty(void) { 
	if (top == 0) {
		return 1;
	}
    else {
    	return 0;
	}
}

/* Elemendi lisamine pinusse
   item - lisatav v��rtus
*/
void stackPush(int item) { 
	stack[top] = item; 
    top++;
}

/* Elemendi v�tmine pinust
   Argumendid puuduvad.
   Tagastatakse pinu tipus olnud v��rtus
*/
int stackPop(void) { 
	top--;
    return stack[top];
}
  

/* N�ide, mis demonstreerib k�igi eelnevate funktsioonide kasutamist
   Kolm v��rtust lisatakse pinusse.
   J�rgneb while-ts�kkel, mis v�tab seni pinust v��rtuseid, kuni
   pinu t�hjaks saab ja tr�kib need �kshaaval ekraanile.
*/

main()
  { int number;
    stackInit(1000);
    printf("Sisesta arv ");
    scanf("%d",&number);
    stackPush(number);
    printf("Sisesta arv ");
    scanf("%d",&number);
    stackPush(number);
    printf("Sisesta arv ");
    scanf("%d",&number);
    stackPush(number);
    printf("Arvud tagurpidi j�rjekorras on: ");
    while (!stackEmpty()) {
       printf("%d ", stackPop()); 
       }
    
}

