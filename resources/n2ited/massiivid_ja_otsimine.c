/*
 *  massiivid_ja_otsimine.c
 *
 *  Programm demonstreerib j�rgmisi olulisemaid C-keele osi:
 *  Muutujate deklareerimine (t�isarvud)
 *  Massiivi deklareerimine ja kasutamine
 *  Massiivi suuruse m��ramine preprotsessori k�su abil (C-s puudub konstandi kasutamise v�imalus)
 *  Sisend ja v�ljund
 *  for-ts�kkel ja while-ts�kkel
 *  Loogikaavaldis
 *  if-lause
 *
 */
 
#include <stdio.h>
/* Preprotsessori k�su (asendusdirektiiv) abil �eldakse, MaxN asendab 10 (mugav kasutada massiivi m��tmena deklareerimisel ja t��tlemisel) */
#define MaxN 10

main() {
/* Programmi alguses deklareeritakse k�ik programmis kasutatavad muutujad koos oma andmet��pidega.
 * Antud juhul on k�ik muutujad t�isarvud ning int arvud[MaxN] t�hendab t�isarvudest koosnevale massiivile m�lu eraldamist.
 */

   int numbers[MaxN];
   int sum, x, max, min;
   int i, lost, found;
   
/* Andmete sisestuse ts�kkel
 * ts�klimuutujale i antakse v��rtus 0, m��ratakse ts�kli kordumise tingimus (i<MaxN) 
 * ning iga korduse l�pus tehtav tegevus - i++ ehk i v��rtuse suurendamine 1 v�rra.
 * See on t��piline viis, kuidas saavutada m��ratud arv kordi t��tav ts�kkel
 */
 
   
   for (i = 0; i < MaxN; i++) {
/* printf-i abil tr�kitakse ekraanile k�sk kasutaja jaoks ning muutuja sisestamiseks on vaja scanf-funktsiooni
 * "%d" m��rab sisendi teisendamise formaadi - sisend teisendatakse t�isarvuks
 * &numbers[i] t�hendab massiivi arvud elementi nr i, kuhu kasutaja sisestus pannakse, & on seotud aadresside ehk viitadega (selgitus edaspidi)
 */
 
       printf("Sisesta element nr %d >> ", i);
       scanf("%d", &numbers[i]);
   }
   printf("Millist v��rtust otsime?");
   scanf("%d", &lost);
   found = 0;
   
/* J�rgnevas for-ts�klis on vaid 1 lause ja seet�ttu pole kohustuslik ts�kli piire {}-sulgudega m��rata (vt eelmist ts�klit)
 * Siiski on {} kasutamine tavaliselt otstarbekas ja ka soovitatav.
 * Koodi treppimine (ts�kli sisu taandega) kuulub aga heade tavade hulka
 */
 
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
   
/* while-ts�kkel algab loogikaavaldisega (!found && i<MaxN)
 * && on and (loogiline ja)
 * ! t�hendab eitust 
 * t�isarve k�sitleb C ka boolean-v��rtustena - 0 on false ja 1 on true 
 * muutujaga leitud esitatav v��rtus t�lgendatakse true-ks v�i false-ks ning seej�rel "p��ratakse vastupidi"
 * J�rgnev ts�kkel l�petab t�� siis, kui massiivist leitakse otsitav v��rtus
 */
   while (!found && i < MaxN) {
       if (numbers[i] == lost) {
           found = 1;
       }
       else {
           i++;
       }
   }
   
/* V�rdle ka omavahel eelmist v�ljatr�ki if-lauset ja j�rgmist
 * Nad teevad t�pselt sama asja, kuid on  erinevalt kirja pandud.
 * Eelmise if-lause vormistus on korrektne. J�rgneval if-lausel EI OLE!!
 */
 
   if (found) printf("Oli olemas\n");
   else printf("Pole olemas\n");

}


