#include <stdio.h>
#include <stdlib.h> 

struct Medicine {
    char medicine_name[50];
    int price;
} medicine1;

void insert() {
    FILE *fptr;
    fptr = fopen("medicine.txt", "w");
    if (fptr == NULL) {
        printf("ERROR!!!\n");
        exit(1);
    }

    for (int i = 0; i < 3; i++) {
        printf("Enter medicine %d information:\n", i + 1);
        printf("Enter medicine name: ");
        scanf("%s", medicine1.medicine_name);
        printf("Enter medicine price: ");
        scanf("%d", &medicine1.price);
        fprintf(fptr, "%s\t%d\n", medicine1.medicine_name, medicine1.price);
    }
    fclose(fptr);
}

void display() {
    FILE *fp1;
    fp1 = fopen("medicine.txt", "r");
    printf("\nMedicine name\t\tprice\n");
    while (fscanf(fp1, "%s %d", medicine1.medicine_name, &medicine1.price) != EOF)
	printf("   %s\t\t%d\n", medicine1.medicine_name, medicine1.price);
    fclose(fp1);
}

int main() {
    char c;
    do {
        printf("\n\t------Select your choice----\n");
        printf("\n\t1. INSERT\n\t2. DISPLAY\n\t3. EXIT\n");
        printf("Enter your choice: ");
        scanf(" %c", &c);
        printf("\n");
        switch (c) {
            case '1':
                insert();
                break;
            case '2':
                display();
                break;
            case '3':
                break;
            default:
                printf("Invalid selection\n");
                break;
        }
    } while (c != '3');
    return 0;
}
// updated
// new ssh key updated

