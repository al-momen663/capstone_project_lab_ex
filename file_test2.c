#include <stdio.h>
#include <stdlib.h>

int main(){

	struct student
	{
		int age;
		char name[30];
		int cgpa;
		
	}student1;

	FILE *fptr;

	fptr = fopen("Program.txt","w");
	if (fptr == NULL)
	{
		printf("ERROR!!!");
		exit(1);

	}
	printf("Enter students name: ");
	scanf("%s", &student1.name);
	printf("Enter student age: ");
	scanf("%d", &student1.age);
	printf("Enter student cgpa: ");
	scanf("%d", &student1.cgpa);

	fprintf(fptr, "%s\t %d\t %d\t", student1.name, student1.age, student1.cgpa);
	fclose(fptr);
	return 0;
	
	

}