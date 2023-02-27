#include <stdio.h>


int main () {
	char Name[32];
	int Programming;
	int Maths;
	int OS;
	int average;
	

	printf("Enter students name:\n");
	fgets(Name, sizeof(Name), stdin);
	printf("Marks scored in programming:\n");
	scanf("%d", &Programming);
	printf("Marks scored in maths:\n");
	scanf("%d", &Maths);
	printf("Marks scored in OS:\n");
	scanf("%d", &OS);

	average = (Programming+Maths+OS)/3;

	if (average >= 80) {
		printf("Grade = 1,  Distinction\n");	
	}
	else if (average >= 60) {
		printf("Grade = 3, Credit\n");
	}
	else if (average >= 40) {
		printf("Grade = 5, Pass\n");
	}
	else {
		printf("Grade = 7, Fail\n");
	}
	return 0;

}