#include <stdio.h>
#include <ctype.h>


int main () {
	char AnyName[20];
	int j = 0;
	char ch;

	printf("Enter any word:\n");
	fgets(AnyName, sizeof(AnyName), stdin);
	while (AnyName[j]){
	         ch = AnyName[j];
	         putchar(toupper(ch));
	         j++;
	}
	return 0;
}