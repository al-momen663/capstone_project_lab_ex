#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Medicine
{
    char medicine_name[50];
    int price;
} medicine1;

void insert()
{
    FILE *fptr;
    fptr = fopen("medicine.txt", "w");
    if (fptr == NULL)
    {
        printf("ERROR!!!\n");
        exit(1);
    }

    for (int i = 0; i < 3; i++)
    {
        printf("Enter medicine %d information:\n", i + 1);
        printf("Enter medicine name: ");
        scanf("%s", medicine1.medicine_name);
        printf("Enter medicine price: ");
        scanf("%d", &medicine1.price);
        fprintf(fptr, "%s\t%d\n", medicine1.medicine_name, medicine1.price);
    }
    fclose(fptr);
}

void display()
{
    FILE *fp1;
    fp1 = fopen("medicine.txt", "r");
    if (fp1 == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    printf("\nMedicine name\t\tprice\n");
    while (fscanf(fp1, "%s %d", medicine1.medicine_name, &medicine1.price) != EOF)
        printf("   %s\t\t%d\n", medicine1.medicine_name, medicine1.price);
    fclose(fp1);
}

void search_medicine()
{
    FILE *fp2;
    char search_name[50];
    fp2 = fopen("medicine.txt", "r");
    if (fp2 == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    printf("Enter the medicine name to search: ");
    scanf("%s", search_name);

    int found = 0; // Flag to indicate whether medicine is found or not

    printf("\nSearching for %s...\n", search_name);
    while (fscanf(fp2, "%s %d", medicine1.medicine_name, &medicine1.price) != EOF)
    {
        if (strcmp(medicine1.medicine_name, search_name) == 0)
        {
            printf("Medicine found:\n");
            printf("Medicine Name: %s\n", medicine1.medicine_name);
            printf("Price: %d\n", medicine1.price);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Medicine '%s' not found.\n", search_name);
    }

    fclose(fp2);
}

int main()
{
    char c;
    do
    {
        printf("\n\t------Select your choice----\n");
        printf("\n\t1. INSERT\n\t2. DISPLAY\n\t3. SEARCH\n\t4. EXIT\n");
        printf("Enter your choice: ");
        scanf(" %c", &c);
        printf("\n");
        switch (c)
        {
        case '1':
            insert();
            break;
        case '2':
            display();
            break;
        case '3':
            search_medicine();
            break;
        case '4':
            break;
        default:
            printf("Invalid selection\n");
            break;
        }
    } while (c != '4');
    return 0;
}
