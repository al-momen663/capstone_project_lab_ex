#include <stdio.h>

int main()
{

    struct student
    {
        int age;
        char name[30];
        int cgpa;
    };

    FILE *fptr;

    fptr = fopen("Program5.txt", "w");
    if (fptr == NULL)
    {
        printf("ERROR!!!\n");
        exit(1);
    }

    for (int i = 0; i < 5; i++)
    {
        struct student student1;

        printf("Enter student %d information:\n", i + 1);
        printf("Enter student name: ");
        scanf("%s", student1.name);
        printf("Enter student age: ");
        scanf("%d", &student1.age);
        printf("Enter student cgpa: ");
        scanf("%d", &student1.cgpa);

        fprintf(fptr, "%s\t %d\t %d\n", student1.name, student1.age, student1.cgpa);
    }

    fclose(fptr);
    return 0;
}
