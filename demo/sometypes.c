#include <stdio.h>

char a_char;
int an_int;
double a_double;

int a_function(char a_char) {
	int an_int = 3;
	int a_second_int;
	printf("%d\n", an_int);
	return a_char;

int main()
{
	an_int = 2;
	a_char = 4;
	
	char a_second_char;
	a_second_char = a_function(a_char*2);
	printf("%d : %d : %f : %c \n", an_int, a_char, a_second_char, a_second_char);
}
