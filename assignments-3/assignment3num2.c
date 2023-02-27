#include <stdio.h>


int main() {
	int length;
	int width;
	int area;
	int perimeter;
	printf("Enter length:\n");
	scanf("%d", &length);
	printf("Enter width\n");
	scanf("%d", &width);
	while (length > 0) {

		while (width > 0){
			
	        area = length * width;
	        perimeter = 2*(width+length);
	        
	        printf("The area is equal to %d\n", area);
	        printf("The perimeter is equal to %d\n", perimeter);
	        break;
	       
	        

		}
		break;

	}
   return 0;
}