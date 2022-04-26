/* Näide kirje (struct) kasutamisest (jälgi väljade kasutamist punkti abil.
 * Lisaks kirjele figureerivad näites ka ujukomaarvud.
 * Sisendiks on kahe punkti x ja y koordinaadid.
 * Üks punkt on ringi keskpunkt ja teine suvaline punkt ringjoonel.
 * Leida tuleb ringi pindala.
 * Vajalik on punktide vaheline kaugus - raadius (Pythagorase teoreemist tuletatud).
 */

/* Struktuur seob üheks punkti koordinaadid */

#include <stdio.h>
#include <math.h>

/* math-teegi lisamise asemel võib pi ka ise defineerida: 
 * #define pi 3.1415926 */
 
       
main(){
   struct punkt {
          int x,y;};

   struct punkt joonel, keskp;
   double raadius, pindala;
   
   printf("Järgnev programm arvutab koordinaatide järgi kahe punkti vahelise kauguse.\n");
   printf("Leitud kaugus on ringile raadiuseks\n");
   printf("\n");
   printf("Sisesta 1. punkti koordinaadid tühikuga eraldatult ");
   scanf("%d %d", &joonel.x,&joonel.y);
   printf("Sisesta 2. punkti koordinaadid tühikuga eraldatult ");
   scanf("%d %d", &keskp.x,&keskp.y);

/* Raadiuse leidmiseks kasutatakse muuhulgas sqrt()-funktsiooni. Astendamistehet C-s ei ole, seda asendab siin korrutamine */

   printf("Järgnevalt leiame raadiuse\n");
   raadius = sqrt((keskp.x - joonel.x)*(keskp.x - joonel.x) + (keskp.y - joonel.y)*(keskp.y - joonel.y));
   printf("Raadius on %f\n", raadius);
   printf("\n");
   
/* Pindala leimine - M_PI on kirjeldatud teegis math, mille päis eelnevalt lisati. */

   pindala = M_PI * raadius * raadius;
   printf("Pindala on %f\n", pindala);
}


 
