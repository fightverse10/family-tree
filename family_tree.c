#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person {
    char name[50];
    int age;
    struct Person *father;
    struct Person *mother;
} Person;

Person* create_person(const char *name, int age) {
    Person *person = malloc(sizeof(Person));

    if (person == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    strcpy(person->name, name);
    person->age = age;
    person->father = NULL;
    person->mother = NULL;

    return person;
}

int main() {
    Person *test_person = create_person("Test Person", 20);

    printf("Created: %s, Age: %d\n",
           test_person->name,
           test_person->age);

    free(test_person);

    return 0;
}
