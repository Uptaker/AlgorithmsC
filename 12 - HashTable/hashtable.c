#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10
#define DELETED_NODE (person*)(0xFFFFFFFFFFFFUL)

typedef struct {
    char name[MAX_NAME];
    int age;
    // .. and other stuff, you get the idea
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
        } else if (hash_table[i] == DELETED_NODE) {
            printf("\t%i\t---<deleted>\n", i);
        } else {
            printf("\t%i\t%s\n", i, hash_table[i]->name);
        }
    }
}

bool insert(person *person) {
    if (person == NULL) return false;
    int index = hash(person->name);

    // linear probing loop
    for (int i = 0; i < TABLE_SIZE; i++) {
        int try = (i + index) % TABLE_SIZE;
        if (hash_table[try] == NULL || hash_table[try] == DELETED_NODE) {
            hash_table[try] = person;
            return true;
        }
    }

    if (hash_table[index] != NULL) return false;
    hash_table[index] = person;
    return true;
}

// find by their name
person *lookup (char *name) {
    int index = hash(name);

    // linear probing loop
    for (int i = 0; i < TABLE_SIZE; i++) {
        int try = (i + index) % TABLE_SIZE;
        if (hash_table[index] == NULL) return false;
        if (hash_table[index] == DELETED_NODE) continue;
        if (hash_table[index] != NULL && strncmp(hash_table[index]->name, name, TABLE_SIZE) == 0) {
            return hash_table[try];
        }
    }
    return NULL;
}

person *delete(char *name) {
    int index = hash(name);
    // linear probing loop
    for (int i = 0; i < TABLE_SIZE; i++) {
        int try = (i + index) % TABLE_SIZE;
        if (hash_table[index] == NULL) return false;
        if (hash_table[index] == DELETED_NODE) continue;
        if (hash_table[index] != NULL && strncmp(hash_table[index]->name, name, TABLE_SIZE) == 0) {
            person* tmp = hash_table[try];
            hash_table[try] = NULL;
            return tmp;
        }
    }
    return NULL;
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