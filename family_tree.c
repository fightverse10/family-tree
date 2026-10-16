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

void read_person_info(const char *role, char *name_out, int *age_out) {
    printf("Enter name for %s: ", role);
    fgets(name_out, 50, stdin);

    name_out[strcspn(name_out, "\n")] = '\0';

    printf("Enter age for %s: ", role);
    scanf("%d", age_out);

    getchar();
}

int main() {

    char name[50];
    int age;

    printf("=== FAMILY TREE INPUT ===\n\n");

    read_person_info("Paternal Grandfather", name, &age);
    Person *paternal_grandfather = create_person(name, age);

    read_person_info("Paternal Grandmother", name, &age);
    Person *paternal_grandmother = create_person(name, age);

    read_person_info("Maternal Grandfather", name, &age);
    Person *maternal_grandfather = create_person(name, age);

    read_person_info("Maternal Grandmother", name, &age);
    Person *maternal_grandmother = create_person(name, age);

    read_person_info("Father", name, &age);
    Person *father = create_person(name, age);

    read_person_info("Mother", name, &age);
    Person *mother = create_person(name, age);

    read_person_info("Yourself", name, &age);
    Person *me = create_person(name, age);

    printf("\nAll 7 people have been successfully created.\n");

    return 0;
}
