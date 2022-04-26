/*
   Mõisted: muutujate deklaratsioonid, andmete lugemine ja väljatrükk.
   Lihtne rehkendamine.
   Sisend: 2 täisarvu
   Väljund: arvude korrutis ja jagatis (NB! täisarvulise jagamise tulemus)
*/
#include <stdio.h>
main()
{  int k1,k2;
   float tulemus;
   printf("Sisesta kaks arvu ");
   scanf("%d %d",&k1,&k2);
   printf("Arvud on %d %d \n",k1,k2);
   tulemus = k1*k2;
   printf("Korrutis: %0.2f\n",tulemus);
   tulemus = k1/k2;
   printf("Jagatis: %0.2f\n",tulemus);
   getch();
   }
