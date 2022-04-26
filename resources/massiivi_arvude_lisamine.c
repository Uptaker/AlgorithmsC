/*
 Programm laseb sisestada soovitud koguse arve.
 Seejärel kuvab menüü, millega saab lisada uusi arve:
 1. Massiivi algusesse
 2. Massiivi lõppu
 3. Massiivi keskele soovitud kohale (nt kolmandale kohale) - koha annab ette kasutaja
*/

#include <stdio.h>
#define MaxN 20

void main(void) {
    int numbers[MaxN];
    int i, numbers_count = MaxN + 1, position, new_number, menu_choice = 1;
    int *ptr;
	while (numbers_count > MaxN) {
		printf("Mitu arvu sisestad? ");
    	scanf("%d", &numbers_count);
	}
    
    for (i = 0; i < numbers_count; i++) {
        printf("Arv ");
		scanf("%d", &numbers[i]);
    }
	while (menu_choice != 0) {
		printf("Massiiv on selline:\n");
    	for (i = 0; i < numbers_count; i++) {
    		printf("numbers[%d] = %d\n", i, numbers[i]);
    	}
      	printf("\nTee valik:\n1 - lisamine algusesse\n2 - lisamine lõppu\n3 - lisamine keskele\n0 - lõpeta\n");
      	printf("Sinu valik: ");
      	scanf("%d", &menu_choice);
		if (menu_choice == 1) {
			printf("Lisatav arv ");
    		scanf("%d", &new_number);
    		for (i = numbers_count-1; i >= 0; i--) {
        		numbers[i+1] = numbers[i];
    		}
    		numbers[0] = new_number;
    		numbers_count++;
		}
		else if (menu_choice == 2) {
			printf("Lisatav arv ");
    		scanf("%d", &new_number);
    		numbers[numbers_count] = new_number;
    		numbers_count++;	
		}
		else if (menu_choice == 3) {
		    printf("Lisatav arv ");
		    scanf("%d", &new_number);
		    printf("Positsioon ");
		    scanf("%d", &position);
		    for (i = numbers_count-1; i>position-1; i--) {
		        numbers[i+1] = numbers[i];
		    }
		    numbers[position] = new_number;
		    numbers_count++;
		}
		if (numbers_count == MaxN) {
			printf("Massiiv sai täis, rohkem arve lisada ei saa.");
			menu_choice = 0;
		}
	}
}
