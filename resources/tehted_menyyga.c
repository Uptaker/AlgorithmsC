/*
 Kasutaja sisestab kaks arvu. 
 Programm esitab valikud: liitmine, lahutamine, korrutamine, jagamine. Teeb tehte ja väljastab vastuse. 
 Tegevust saab soovi korral korrata.
*/

#include <stdio.h>
#include <math.h>
main() {
    int first_number, second_number, result, menu_choice = 1;
    float div_result;
    while (menu_choice != 0) {
      	printf("\nTee valik:\n1 - liitmine\n2 - lahutamine\n3 - korrutamine\n4 - jagamine\n0 - lõpeta\n");
      	printf("Sinu valik: ");
      	scanf("%d", &menu_choice);
      	if (menu_choice != 0) {
      		printf("Sisesta tühikutega eraldatult kaks arvu ");
      		scanf("%d %d", &first_number, &second_number);
		  }
      	if (menu_choice == 1) {
      		result = first_number + second_number;
      		printf("Liitmise tulemus on %d.\n", result);
        }
      	else if (menu_choice == 2) {
      		result = first_number - second_number;
      		printf("Lahutamise tulemus on %d.\n", result);      		
		}
      	else if (menu_choice == 3) {
      		result = first_number * second_number;
      		printf("Korrutamise tulemus on %d.\n", result);      		
		}
      	else if (menu_choice == 4) {
      		div_result = (float)first_number / second_number;
      		printf("Jagamise tulemus on %0.2f.\n", div_result);      		
		}
      	else if (menu_choice == 0) {
      		printf("Kohtumiseni!!\n");      		
		}
	}
}
