#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Näide lausete sisselugemisest fgets käsuga.
 * Käsk on tegelikult mõeldud failide lugemiseks, kus kolmandaks argumendiks on failimuutuja
 * Klaviatuurilt (standardsisendist) lugemiseks kirjutatakse sinna stdin
 * 2. argument (näites 50) tagab, et sisendpuhvrist ei loeta rohkem kui 50 märki, mis mahub veel deklareeritud muutujasse.
 * Tegelikult loetakse fgets()-iga 50-1 märki. Ilmselt selleks, et '\0'-le ka ruumi jääks, mille funktsioon stringi lõppu lisab.
 * Funktsioon fgets() loeb sisndpuhvrist välja ka reavahetuse märgi.
 * Reavahetuse märk tuleks kuidagi kõrvaldada. Selleks võib ta üle kirjutada stringi lõppu tähistava '\0'-iga.
 * Koha, kuhu '\0' kirjutada, saame kätte stringi pikkuse kaudu (stringi viimane sümbol).
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
 * Peale getchar() funktsiooni kasutamist tuleb puhtastada sisendpuhvrit, sest sinna jäänud reavahetuse märk võib segada
 * edasist tegevust.
 * Kui teame, et puhvris peale reavahetuse rohkem midagi ei ole, võime kutsuda getchar()-i ühe korra välja.
 * Pärast seda proovime veel midagi lugeda, et veenduda õnnestumises.
 */
 	printf("Trüki üks täht! \n");
	c = getchar();
	getchar();
	printf("Trükkisid tähe %c.\n", c);
 	printf("Trüki veel üks täht! \n");
	c = getchar();
	printf("Olemas :) %c.\n",c);
	
}

