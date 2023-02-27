#include <stdio.h>


int AreaOfRectangle(int Length, int widht) {
	
	return Length * widht;
	
}

int main () {
	int Length;
	int widht;
	int area;
	printf("Enter the Length:\n");
	scanf("%d", &Length);
	printf("Enter the widht:\n");
	scanf("%d", &widht);
	area = AreaOfRectangle(Length, widht);
	printf("the area is %d", area);
	
	
}