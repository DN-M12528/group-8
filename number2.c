#include <stdio.h>



int main() {
	char alphabets;
	char AlphabetsUpper;
	for(alphabets = 'a'; alphabets <= 'z'; alphabets++)//iterates through the alphabets and outputs the alphabets in lowercase

	 {
		putchar(alphabets);
		

	}
	for(AlphabetsUpper = 'A'; AlphabetsUpper <= 'Z'; AlphabetsUpper++)//iterates throuth the alphabets and outputs the alphabets in uppercase
	{
		putchar(AlphabetsUpper);
	}
	putchar('\n');
	return 0;
}