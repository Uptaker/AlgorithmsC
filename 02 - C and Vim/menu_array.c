#include <stdio.h>

void choose() {
	int mode;
	printf("Select mode\n1 - To the start\n2 - To the end\n3 - Somewhere in the middle\n");
	scanf("%d", &mode);
	if (mode == 1) append();
	else if (mode == 2) prepend();
	else if (mode == 3) put();
	else printf("Command does not exist for %d", mode);
}

int getNumAmount() {
	int amount;
	printf("How many numbers?\n");
	scanf("%d", &amount);
	return amount;
}

void main() {
	int total = getNumAmount();
	int nums[];
	
	for (i = 0; i < total; i++) {
		printf("Number %d", i);
		scanf("%d", &nums[i]);
	}

	choose();
}
