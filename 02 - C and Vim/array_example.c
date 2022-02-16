/*
 *  massiivid_ja_otsimine.c
 *
 *  Programm demonstreerib järgmisi olulisemaid C-keele osi:
 *  Muutujate deklareerimine (täisarvud)
 *  Massiivi deklareerimine ja kasutamine
 *  Massiivi suuruse määramine preprotsessori käsu abil (C-s puudub konstandi kasutamise võimalus)
 *  Sisend ja väljund
 *  for-tsükkel ja while-tsükkel
 *  Loogikaavaldis
 *  if-lause
 *
 */
 
#include <stdio.h>
/* Preprotsessori käsu (asendusdirektiiv) abil öeldakse, MaxN asendab 10 (mugav kasutada massiivi mõõtmena deklareerimisel ja töötlemisel) */
#define MaxN 10

main() {
/* Programmi alguses deklareeritakse kõik programmis kasutatavad muutujad koos oma andmetüüpidega.
 * Antud juhul on kõik muutujad täisarvud ning int arvud[MaxN] tähendab täisarvudest koosnevale massiivile mälu eraldamist.
 */

   int numbers[MaxN];
   int sum, x, max, min;
   int i, lost, found;
   
/* Andmete sisestuse tsükkel
 * tsüklimuutujale i antakse väärtus 0, määratakse tsükli kordumise tingimus (i<MaxN) 
 * ning iga korduse lõpus tehtav tegevus - i++ ehk i väärtuse suurendamine 1 võrra.
 * See on tüüpiline viis, kuidas saavutada määratud arv kordi töötav tsükkel
 */
 
   
   for (i = 0; i < MaxN; i++) {
	printf("%p\n", &numbers[i]);
   }
   for (i = 0; i < MaxN; i++) {
/* printf-i abil trükitakse ekraanile käsk kasutaja jaoks ning muutuja sisestamiseks on vaja scanf-funktsiooni
 * "%d" määrab sisendi teisendamise formaadi - sisend teisendatakse täisarvuks
 * &numbers[i] tähendab massiivi arvud elementi nr i, kuhu kasutaja sisestus pannakse, & on seotud aadresside ehk viitadega (selgitus edaspidi)
 */
 
       printf("Sisesta element nr %d >> ", i);
       scanf("%d", &numbers[i]);
   }
   printf("Millist väärtust otsime?");
   scanf("%d", &lost);
   found = 0;
   
/* Järgnevas for-tsüklis on vaid 1 lause ja seetõttu pole kohustuslik tsükli piire {}-sulgudega määrata (vt eelmist tsüklit)
 * Siiski on {} kasutamine tavaliselt otstarbekas ja ka soovitatav.
 * Koodi treppimine (tsükli sisu taandega) kuulub aga heade tavade hulka
 
   for (i = 0; i < MaxN; i++)
       if (numbers[i] == lost) 
           found = 1;
       
/* Kahe poolega if-lause.
 * Ka siin on vajalikud {}, kui lauseid rohkem kui 1
 */ 
 
   if (found == 1) {
       printf("Oli olemas\n");
   }
   else {
       printf("Pole olemas\n");
   }

   found = 0;
   i = 0;
   
/* while-tsükkel algab loogikaavaldisega (!found && i<MaxN)
 * && on and (loogiline ja)
 * ! tähendab eitust 
 * täisarve käsitleb C ka boolean-väärtustena - 0 on false ja 1 on true 
 * muutujaga leitud esitatav väärtus tõlgendatakse true-ks või false-ks ning seejärel "pööratakse vastupidi"
 * Järgnev tsükkel lõpetab töö siis, kui massiivist leitakse otsitav väärtus
 */
   while (!found && i < MaxN) {
       if (numbers[i] == lost) {
           found = 1;
       }
       else {
           i++;
       }
   }
   
/* Võrdle ka omavahel eelmist väljatrüki if-lauset ja järgmist
 * Nad teevad täpselt sama asja, kuid on  erinevalt kirja pandud.
 * Eelmise if-lause vormistus on korrektne. Järgneval if-lausel EI OLE!!
 */
 
   if (found) printf("Oli olemas\n");
   else printf("Pole olemas\n");

}


