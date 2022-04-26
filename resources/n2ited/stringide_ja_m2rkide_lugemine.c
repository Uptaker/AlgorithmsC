#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * N�ide lausete sisselugemisest fgets k�suga.
 * K�sk on tegelikult m�eldud failide lugemiseks, kus kolmandaks argumendiks on failimuutuja
 * Klaviatuurilt (standardsisendist) lugemiseks kirjutatakse sinna stdin
 * 2. argument (n�ites 50) tagab, et sisendpuhvrist ei loeta rohkem kui 50 m�rki, mis mahub veel deklareeritud muutujasse.
 * Tegelikult loetakse fgets()-iga 50-1 m�rki. Ilmselt selleks, et '\0'-le ka ruumi j��ks, mille funktsioon stringi l�ppu lisab.
 * Funktsioon fgets() loeb sisndpuhvrist v�lja ka reavahetuse m�rgi.
 * Reavahetuse m�rk tuleks kuidagi k�rvaldada. Selleks v�ib ta �le kirjutada stringi l�ppu t�histava '\0'-iga.
 * Koha, kuhu '\0' kirjutada, saame k�tte stringi pikkuse kaudu (stringi viimane s�mbol).
 */
main(){
	char statement[50];
    char c;
    int statementLen;
	printf("Millise lausega algab Sinu lemmikraamat? ");
	fgets(statement, 50, stdin);

	statementLen = strlen(statement);
	statement[statementLen - 1] = '\0';
	printf("%s  ", statement);
	statementLen = strlen(statement);
	printf("Pikkus peale nulli lisamist: %d\n", statementLen);
	
/*
 * Peale getchar() funktsiooni kasutamist tuleb puhtastada sisendpuhvrit, sest sinna j��nud reavahetuse m�rk v�ib segada
 * edasist tegevust.
 * Kui teame, et puhvris peale reavahetuse rohkem midagi ei ole, v�ime kutsuda getchar()-i �he korra v�lja.
 * P�rast seda proovime veel midagi lugeda, et veenduda �nnestumises.
 */
 	printf("Tr�ki �ks t�ht! \n");
	c = getchar();
	getchar();
	printf("Tr�kkisid t�he %c.\n", c);
 	printf("Tr�ki veel �ks t�ht! \n");
	c = getchar();
	printf("Olemas :) %c.\n",c);
	
}

