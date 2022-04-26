/* 
 * Näide tööst tekstifailiga
 * Fail avatakse, siis kirjutatakse tekst ja see järel suletakse
 * Pärast on fail programmiga samas kataloogis ja kõik on õnnelikud
 */

#include <stdio.h>

main(){

/* Faili pide (faili muutuja) deklareeritakse ja nullitakse. NULL-i kaudu peab saama
 * hiljem kontrollida, kas avamine õnnestus. */

  FILE *fm = NULL;
  
/* Faili avamine kirjutamiseks */

  fm = fopen("failinimi.txt", "w");

/* Faili trükitakse string */

  fprintf(fm, "Tere talv!\n");

/* Fail suletakse */

  fclose(fm);
}
