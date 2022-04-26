#include <stdio.h>
#include <stdlib.h>

/* 
 * Näites on kirjeldatud 4 peamist pinu operatsiooni:
 * stackInit() - pinu loomine
 * stackEmpty() - kas pinu on tühi?
 * stackPush() - lisamine pinusse
 * stackPop() - eemladamine pinust
 Pinu on ülesehitatud massiivile.
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

/* Kontroll, kas pinu on tühi
   Tagastab:
      1 (true) - kui pinu on tühi
      0 (false )- kui pinu ei ole tühi
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
   item - lisatav väärtus
*/
void stackPush(int item) { 
	stack[top] = item; 
    top++;
}

/* Elemendi võtmine pinust
   Argumendid puuduvad.
   Tagastatakse pinu tipus olnud väärtus
*/
int stackPop(void) { 
	top--;
    return stack[top];
}
  

/* Näide, mis demonstreerib kõigi eelnevate funktsioonide kasutamist
   Kolm väärtust lisatakse pinusse.
   Järgneb while-tsükkel, mis võtab seni pinust väärtuseid, kuni
   pinu tühjaks saab ja trükib need ükshaaval ekraanile.
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
    printf("Arvud tagurpidi järjekorras on: ");
    while (!stackEmpty()) {
       printf("%d ", stackPop()); 
       }
    
}

