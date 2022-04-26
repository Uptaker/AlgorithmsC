
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    struct AnimalTree {
        char QuestionAnimal[50];
        struct AnimalTree *yes, *no;
    };

struct AnimalTree *BuildTree(void) {
	struct AnimalTree *root, *node1, *node2;
	
	root = malloc(sizeof *root);
	node1 = malloc(sizeof *node1);
	node2 = malloc(sizeof *node2);
	strcpy(root->QuestionAnimal, "Kas ta on suur?");
	strcpy(node1->QuestionAnimal, "elevant");
	strcpy(node2->QuestionAnimal, "hiir");
	root->yes = node1;
	root->no = node2;
	node1->yes = NULL;
	node1->no = NULL;
	node2->yes = NULL;
	node2->no = NULL;
	return root;
}

void AddInformation(struct AnimalTree *current, char *animal, char *question) {
	struct AnimalTree *node1, *node2;
	
	node1 = malloc(sizeof *node1);
    node2 = malloc(sizeof *node2);
	strcpy(node1->QuestionAnimal, animal);
	strcpy(node2->QuestionAnimal, current->QuestionAnimal);
	strcpy(current->QuestionAnimal, question);
    current->yes = node1;
    current->no = node2;
    node2->yes = NULL;
    node2->no = NULL;
    node1->yes = NULL;
    node1->no = NULL;
}
    
void main(void) {
	struct AnimalTree *animals, *node1, *node2, *temp;
	char answer, game;
	char question[50], animal[50];
/* Algpuuu loomine. */
	animals = BuildTree();	
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
		    printf("Millise k�simuse k�siksid looma %s kohta?\n", animal);
		    fgets(question, 49, stdin);
		    question[strlen(question) - 1] = '\0';
		    /* Kahe s�lme lisamine */
		    AddInformation(temp, animal, question);
		    printf("Ait�h! Olen n��d palju targem! :)\n");
		}
		
		printf("Kas tahad veel m�ngida?");
		scanf("%c", &game);
		getchar();
}
}
