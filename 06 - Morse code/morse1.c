#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    struct MorseTree {
        char letter;
        struct MorseTree *dot, *dash;
    };

static int i;    
char LETTERS[31]={' ','E','I','S','H','V','U','F','Ü','A','R','L','Ä','W','P','J','T','N','D','B','X','K','C','Y','M','G','Z','Q','O','Ö',''};

struct MorseTree *BuildTree(int N) {
    struct MorseTree *newNode;
    int nl, nr;
    if (N==0) {
        return NULL;
    }
    else {
        nl = N / 2;
        nr = N-nl-1;
        newNode = malloc(sizeof *newNode);
        newNode->letter = LETTERS[i];
        i++;
        newNode->dot = NULL;
        newNode->dash = NULL;
        newNode->dot = BuildTree(nl);
        newNode->dash =  BuildTree(nr);
        return newNode;
    }
}

void Preorder(struct MorseTree *RPointer) {
    printf("%c", RPointer->letter);
    if (RPointer->dot != NULL) {
        Preorder(RPointer->dot);
    }
    if (RPointer->dash != NULL) {
        Preorder(RPointer->dash);
    }
}

void traverseMorse(char code[127], struct MorseTree *mPointer, struct MorseTree *orig) {
    char ch = code[i];
    i++;
    if (ch == '.') traverseMorse(code, mPointer->dot, orig);
    if (ch == '-') traverseMorse(code, mPointer->dash, orig);
    if (ch == '/') {
        printf("%c ", mPointer->letter);
        traverseMorse(code, orig, orig);
    }
}


int main(void) {

    struct MorseTree *morse;
    printf("Kõigepealt tuleb morsepuu üles ehitada!\n");
    i = 0;
    morse = BuildTree(31);

    char line[128];
  	FILE *fm = NULL;

    fm = fopen("morse1.txt", "r");
    while (!feof(fm)) {
        i = 0;
        fgets(line, 127, fm);
        printf("\n%s\n", line);
        traverseMorse(line, morse, morse);
    }
    fclose(fm);

    printf("\n");
    return 0;
}
