#include <stdio.h>

int main () {
   char alphabets;
   //the programm has set a variable called alphabets and of the type character.

   for(alphabets = 'a' ; alphabets <= 'z' ; alphabets++)
   //the first statement sets the first value of the alphabet to a
   //the second statement is the condition followed to execute the code
   //the third statement is used add the next character one step at a time
    {
      putchar(alphabets);
      //this line of code outputs the value of alphabet every time the code in the loop is executed.
   }
   putchar('\n');
   //this is used to set a new line
   return 0;
}