/*
 *  hello.c
 *
 *  Tervitame maailma! Programm trükib ekraanile "Hallo world!", lisab reavahetuse ja lõpetab töö.
 */

#include <stdio.h>

int main(void)
{
        printf("Hello world!\n");
        return 0;
}


/* Mõned selgitused:
 *
 * main - peaprogrammi nimi
 * int - peaprogramm, mida võib vaadelda ka funktsioonina, oskab tagastada täisarvulise väärtuse opsüsteemi tasandile
 * return 0; - konkreetne tagastatav väärtus on 0, mis tavapäraselt tähendab perogrammi õnnelikku lõppemist (vigu ei tekkinud)
 * main(void) - mais järele sulgudesse saab lisada sisendparameetrite loetelu; void tähendab, et parameetreid ei ole
 * printf("Hello world!\n"); - väljatrükifunktsioon, \n stringi lõpus tähistab reavahetust
 * #include <stdio.h> - printf on kasutatav tänu sellele, et kasutusele on võetud teek stdio (standard input/output)
 * Windowsis kirjutades võime mõned funktsiooni käitumist lisavad osad ära jätta - vt hallo1.c
 *
 */
