#include <stdio.h>

void main() {

	int array[5] = {4, 8, 1, 5, 8};
	
	for (int i = 0; i < 5 - 1; i++) {
		int min = i;
		for (int j = i + 1; j < 5; j++) {
			if (array[min] > array[j]) {
				min = j;
			}
		}
		int temp = array[min];	
		array[min] = array[i];		
		array[i] = temp;
	}
	
	for (int i = 0; i < 5; i++) {
		printf("%d\n", array[i]);
	}

}
