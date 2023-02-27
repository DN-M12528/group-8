#include  <stdio.h>
#include <string.h>


int main(void)
{
	char Name[]="JOMO KENYATTA";
    printf("Reverse the String:");
    for(int i=(strlen(Name)-1);i>=0;i--)
 { 
 	  printf("%c",Name[i]);
 } 
 return 0;
}
