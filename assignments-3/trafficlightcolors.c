#include <stdio.h>


int main () {
	char ColorLight;
	printf("Enter the first letter of the color:");
	scanf("%c", &ColorLight);
	if (ColorLight == 'r') {
		printf("Stop\n");
	}
	else if (ColorLight == 'y'){
		printf("Get ready\n");
	}
	else {
		printf("Move\n");
	}
	return 0;
}