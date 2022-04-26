/* 
 sorteerimine_valik.c: 
 J�rjestab arvumassiivi elemendid mittekahanevalt kasutades valiksorteerimise meetodit.
 */

#include <stdio.h>
#define MaxN 10
main()
{
    int data[MaxN]; /* massiiv MaxN elemendist */
    int i, j, minIndex, temp;

    /* Ettevalmistused, massiivi andmete lugemine. */
    for (i = 0; i < MaxN; i++) {
        printf("data[%d]: ", i); 
        scanf("%d", &data[i]);
    }

    /* j�rjestamine */
    for (i = 0; i < MaxN; i++) {
     /* Leitakse v�hima v��rtuse indeks */
        minIndex = i;
        for (j = i; j < MaxN; j++)  {
            if (data[j] < data[minIndex]) {
                minIndex = j;
            } 
        }
    /* V�him v��rtus vahetatakse "oma kohale", st otsimispiirkonna algusesse. */
        temp = data[i]; 
		data[i] = data[minIndex]; 
		data[minIndex] = temp;
    }
  
    printf("Sorteeritud tulemus:\n");
    for (i = 0; i < MaxN; i++) {
    	printf("data[%d] = %d\n", i, data[i]);
	}
}
