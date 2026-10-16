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

void link_parents(Person *child, Person *father, Person *mother) {
    child->father = father;
    child->mother = mother;
}

void print_family_relationships(const Person *me) {

    printf("\n");
    printf("=== FAMILY TREE RELATIONSHIPS ===\n\n");

    printf("1. YOURSELF:\n");
    printf("   - Name: %s | Age: %d\n\n",
           me->name, me->age);

    printf("2. PARENTS:\n");
    printf("   - Father: %s | Age: %d\n",
           me->father->name,
           me->father->age);

    printf("   - Mother: %s | Age: %d\n\n",
           me->mother->name,
           me->mother->age);

    printf("3. PATERNAL GRANDPARENTS (via Father's Pointers):\n");
    printf("   - Grandfather: %s | Age: %d\n",
           me->father->father->name,
           me->father->father->age);

    printf("   - Grandmother: %s | Age: %d\n\n",
           me->father->mother->name,
           me->father->mother->age);

    printf("4. MATERNAL GRANDPARENTS (via Mother's Pointers):\n");
    printf("   - Grandfather: %s | Age: %d\n",
           me->mother->father->name,
           me->mother->father->age);

    printf("   - Grandmother: %s | Age: %d\n",
           me->mother->mother->name,
           me->mother->mother->age);
}

void print_tree_visual(const Person *root) {

    printf("\n");
    printf("=== VISUAL FAMILY TREE ===\n\n");

    printf("%s (Age: %d)\n",
           root->name,
           root->age);

    printf("├── Father: %s (Age: %d)\n",
           root->father->name,
           root->father->age);

    printf("│   ├── Grandfather: %s (Age: %d)\n",
           root->father->father->name,
           root->father->father->age);

    printf("│   └── Grandmother: %s (Age: %d)\n",
           root->father->mother->name,
           root->father->mother->age);

    printf("└── Mother: %s (Age: %d)\n",
           root->mother->name,
           root->mother->age);

    printf("    ├── Grandfather: %s (Age: %d)\n",
           root->mother->father->name,
           root->mother->father->age);

    printf("    └── Grandmother: %s (Age: %d)\n",
           root->mother->mother->name,
           root->mother->mother->age);
}

void free_family_tree(Person *people[], int count) {

    for (int i = 0; i < count; i++) {
        free(people[i]);
    }
}

int main() {

    char name[50];
    int age;

    printf("====================================\n");
    printf("       FAMILY TREE PROGRAM\n");
    printf("====================================\n\n");

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

    link_parents(
        father,
        paternal_grandfather,
        paternal_grandmother
    );

    link_parents(
        mother,
        maternal_grandfather,
        maternal_grandmother
    );

    link_parents(
        me,
        father,
        mother
    );

    print_family_relationships(me);

    print_tree_visual(me);

    Person *people[7] = {
        paternal_grandfather,
        paternal_grandmother,
        maternal_grandfather,
        maternal_grandmother,
        father,
        mother,
        me
    };

    free_family_tree(people, 7);

    printf("\nMemory cleanup completed successfully.\n");

    return 0;
}
