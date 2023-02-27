#include <stdio.h>


int  main()
{
	char StudentName[32];
	int English;
	int Maths;
	int Science;
	int average;
	printf("Enter students name:\n");
	fgets(StudentName, sizeof(StudentName), stdin);
	printf("Enter English marks:\n");
	scanf("%d", &English);
	printf("Enter Maths marks:\n");
	scanf("%d", &Maths);
	printf("Enter Science marks:\n");
	
	scanf("%d", &Science);
	average = (English+Maths+Science)/3;
	printf("The average for %s is %d", StudentName, average);
	

	
	return 0;
}