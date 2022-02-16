#include <stdio.h>
#define max 10

void main() {

	int numbers[max];
	int sum = 0;
	int lastNum = 0;
	printf("Input %d numbers:\n", max);

	for (int i = 0; i < max; i++) {
		printf("Number %d: ", i + 1);
		scanf("%d", &numbers[i]);
		if (numbers[i] > lastNum) sum+= numbers[i];
		lastNum = numbers[i];
		printf("Sum so far is %d\n", sum);
	}

}
