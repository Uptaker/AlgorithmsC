#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct {
    char name[MAX_NAME];
    int age;
    // .. and other stuff, you get the idea
    struct person *next;
} person;

person * hash_table[TABLE_SIZE];

unsigned int hash(char *name) {
    int length = strnlen(name, MAX_NAME);
    unsigned int hash_value = 0;
    for (int i = 0; i < length; i++) {
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }
    return hash_value;
}

bool init_hash_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = NULL;
    }
    // table is empty
}

void print_table() {
    printf("Start of table\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hash_table[i] == NULL) {
            printf("\t%i\t---\n", i);
        } else {
            printf("\t%i\t%s\n", i, hash_table[i]->name);
            person *tmp = hash_table[i];
            while (tmp != NULL) {
                printf("%s - ", tmp->name);
                tmp = tmp->next;
            }
        }
    }
}

bool insert(person *person) {
    if (person == NULL) return false;
    int index = hash(person->name);
    person->next = hash_table[index];
    hash_table[index] = person;
    return true;
}

// find by their name
person *lookup (char *name) {
    int index = hash(name);
    person *tmp = hash_table[index];
    while(tmp != NULL && strncmp(tmp->name, name, MAX_NAME) != NULL) {
        tmp = tmp->next;
    }
    return tmp;
}

person *delete(char *name) {
    int index = hash(name);
    person *tmp = hash_table[index];
    person *prev = NULL;
    while(tmp != NULL && strncmp(tmp->name, name, MAX_NAME) != NULL) {
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp == NULL) return NULL;
    if (prev == NULL) {
        // deleting the head
        hash_table[index] = tmp->next;
    } else {
        prev->next = tmp->next;
    }

    return tmp;
}

int main() {

    init_hash_table();
    print_table();

    person jacob = {.age = 50, .name = "Jacob"};
    person kate = {.age = 20, .name = "Kate"};
    person mpho = {.age = 89, .name = "Mpho"};
    person sarah = {.age = 15, .name = "Sarah"};
    person edna = {.age = 99, .name = "Edna"};
    person eliza = {.age = 29, .name = "Eliza"};
    person robert = {.age = 22, .name = "Robert"};
    person jane = {.age = 22, .name = "Jane"};

    insert(&jacob);
    insert(&kate);
    insert(&mpho);
    insert(&sarah);
    insert(&edna);
    insert(&eliza);
    insert(&robert);
    insert(&jane);

    print_table();

    person *tmp = lookup("Kate");
    if (tmp == NULL) {
        printf("Not found!\n");
    } else {
        printf("Found %s.\n", tmp->name);
    }

    
    tmp = lookup("George");
    if (tmp == NULL) {
        printf("Not found!\n");
    } else {
        printf("Found %s.\n", tmp->name);
    }

    delete("Jacob");
    print_table();




/*
    printf("Jacob => %u\n", hash("Jacob"));
    printf("Bill => %u\n", hash("Bill"));
    printf("Natalie => %u\n", hash("Natalie"));
    printf("Sara => %u\n", hash("Sara"));
    printf("Mpho => %u\n", hash("Mpho"));
    printf("Jane => %u\n", hash("Jane"));
    printf("Maren => %u\n", hash("Maren"));
    printf("Ron => %u\n", hash("Ron"));
*/

}