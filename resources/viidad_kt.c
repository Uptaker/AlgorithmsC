/*
 *  Programm joonistuse juurde. Lisatud reanumbrid. Puuduvad include'd. Sel kujul programm ei käivitu.
 */
 
main()
{ 
    int k = 8;
    int *ptr;
    int *ptr1, *ptr2, *ptr3;
 
1    ptr = &k;
2    printf("Muutujas k olev arv tema aadressi järgi %d\n", *ptr);   
3    *ptr = 12; 
4    printf("Muutuja k uuesti: %d\n", k);
5    ptr1 = malloc(sizeof (int));
6    *ptr1 = 20;
7    printf("Muutuja ptr1 poolt viidatavasse kohta pandi %d\n", *ptr1);
8    ptr2 = ptr1;
9    printf("Viitmuutuja ptr2 kaudu leiame arvu %d.\n", *ptr2);
 
}



