/*
 *  Katsetatakse viitadega.
 *  Demonstreeritakse viitmuutujate deklareerimist, jaoks mälu eraldamist, viitade omistamist.
 */

#include <stdlib.h>
#include <stdio.h>
main()
{ 
    int k = 8;                 /* tavaline täisarv. */
    int *ptr;                  /* viitmuutuja (aadress täisarvule, pointer) */
    int *ptr1, *ptr2, *ptr3;   /* veel kolm on viitmuutujat */
  
    printf("Kas viitmutuujasse satub deklareerimisel NULL?\n");
    if (ptr == NULL){ 
        printf("Antud juhul jah.\n"); 
    }
    else {
        printf("Seekord ei.\n");
    }
    
    ptr = &k;      /* Muutujasse ptr omistatakse muutuja k aadress. */
    printf("Muutujas k olev arv tema aadressi järgi %d\n", *ptr);   
    *ptr = 12; 
    printf("Muutuja k uuesti: %d\n", k);
 
/* Funktsioon malloc() reserveerib palutud arvu baite (antud juhul 1 int-i jagu) ning nende
 * baitide algusaadressi paneb muutujasse ptr1.
 * sizeof on operaator, mille järele võib kirjutada andmetüübi (sulud vajalikud!).
 */
    ptr1 = malloc(sizeof (int));
    *ptr1 = 20;   /* Aadressi ptr1 kaudu omistatakse 20 */
    printf("Muutuja ptr1 poolt viidatavasse kohta pandi %d\n", *ptr1);

/* Mis juhtub aadresside omistamisel? */

    ptr2 = ptr1;
    printf("Viitmuutuja ptr2 kaudu leiame arvu %d.\n", *ptr2);
 
/* Formaatimise symbol %p on kasutatav viitade ehk aadresside jaoks.*/
    printf("ptr1-s olev aadress on %p ja ptr2-s olev aadress on %p.\n", ptr1, ptr2);
    if (ptr1 == ptr2) {
        printf("Muutujad ptr1 ja ptr2 viitavad samasse kohta.\n");
    }
    else {
        printf("Muutujad ptr1 ja ptr2 ei viita samasse kohta.\n");
    }

    ptr3 = malloc(sizeof (int));
    scanf("%d", ptr3);

    printf("ptr3 num %d ptr3 address %p\n", *ptr3, ptr3);
    ptr1 = ptr3;
    printf("ptr v22rtus olgu 20 pls - %d\n", *ptr);
    printf("k adr %p ja ptr sisu %d\n", &k, *ptr);
}


