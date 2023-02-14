#include <stdio.h>


int main() {
	char alphabets;
	for (alphabets = 'a'; alphabets <= 'z'; alphabets++) {
		if (alphabets == 'e') {
			continue;
			//this skips the letter e 

		}
		else if (alphabets == 'q') {
			continue; 
			//this skips the letter q
		}

		putchar(alphabets);

	}
	putchar('\n');
	return 0;


}