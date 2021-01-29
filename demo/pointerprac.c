#include <stdio.h>

int main(void) {
	int number = 5;
	int *point = &number;

	printf("number: %d \n", number);
	printf("point: %d \n", point);

	//printf("*number: %d \n", *number);
	printf("*number isn't allowed bc number is just an int \n");
	printf("*point: %d \n", *point);

	printf("&number: %d \n", &number);
	printf("&point: %d \n", &point);

	printf("My guess is that the next line will print the same as just 'point' \n");
	printf("&*point: %d \n", &*point);

	printf("&*point == point : %s", &*point == point ? "true" : "false");
}
