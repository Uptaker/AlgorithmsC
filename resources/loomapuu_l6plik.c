
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    struct AnimalTree {
        char QuestionAnimal[50];
        struct AnimalTree *yes, *no;
    };
    
main() {
	struct AnimalTree *animals, *node1, *node2, *temp;
	char answer, game;
	char question[50], animal[50];
/* Algpuuu loomine. */
	animals = malloc(sizeof *animals);
	node1 = malloc(sizeof *node1);
	node2 = malloc(sizeof *node2);
	strcpy(animals->QuestionAnimal, "Kas ta on suur?");
	strcpy(node1->QuestionAnimal, "elevant");
	strcpy(node2->QuestionAnimal, "hiir");
	animals->yes = node1;
	animals->no = node2;
	node1->yes = NULL;
	node1->no = NULL;
	node2->yes = NULL;
	node2->no = NULL;
/* M�ngu kordamise ts�kkel. */	
	game = 'j';
	while (game == 'j'){
		temp = animals;
/* �he m�ngu k�simuste esitamine. */
		while (temp->yes != NULL) {
			printf("%s [j/e]", temp->QuestionAnimal);
			scanf("%c", &answer);
			getchar();
			if (answer=='j'){
				temp = temp->yes;
			}
			else {
				temp = temp->no;
			}
		}
/* Looma pakkumine. */
		printf("Kas see loom on %s? [j/e]", temp->QuestionAnimal);
		scanf("%c", &answer);
		getchar();
		if (answer == 'j') {
			printf("Olen tubli!!\n");
		}
		else {
/* Uue looma ja k�simuse lisamine. */
			printf("Mis looma Sa m�tlesid? ");
		    fgets(animal, 49, stdin);
		    animal[strlen(animal) - 1] = '\0';  /*Likvideeritakse reavahetus*/
		    node1 = malloc(sizeof *node1);
    		node2 = malloc(sizeof *node2);
		    strcpy(node1->QuestionAnimal, animal);
		    strcpy(node2->QuestionAnimal, temp->QuestionAnimal);
		    printf("Millise k�simuse k�siksid looma %s kohta?\n", animal);
		    fgets(question, 49, stdin);
		    question[strlen(question) - 1] = '\0';
		    strcpy(temp->QuestionAnimal, question);
		    temp->yes = node1;
		    temp->no = node2;
		    node2->yes = NULL;
		    node2->no = NULL;
		    node1->yes = NULL;
		    node1->no = NULL;
		    printf("Ait�h! Olen n��d palju targem! :)\n");
		}
		
		printf("Kas tahad veel m�ngida?");
		scanf("%c", &game);
		getchar();
}
}
