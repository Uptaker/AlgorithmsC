#include <stdio.h>
/*
   suuruselt_teine.c
   Programm leiab sisestatud arvude hulgast suurusekt teise v��rtuse.
   Eeldatakse, et k�ik arvud on positiivsed (algv��rtustamine!).
*/
void main(void) {
/* Muutujate deklareerimisega koos on v�imalik need ka algv��rtustada*/
        int input = 0, max1 = 0, max2 = 0;
      
        while (input != -999) {
            printf("Sisesta positiivne arv, l�petamiseks -999 ");
            scanf("%d",&input);
/* Kui on suurimast suurem, siis l�heb esimeseks ja vana saab teiseks.*/
            if (input > max1) {
                max2 = max1;
                max1 = input;
            }
            else {
/* Kui ei olnud, siis kui on teisest suurem, l�heb teiseks (�lej��nud ei huvita).*/
                if (input > max2) {
                    max2 = input;
                }
            }
        }
       printf("Suuruselt teine arv on %d\n",max2);
       printf("Ja suuruselt esimene on %d\n",max1);    
      
}
