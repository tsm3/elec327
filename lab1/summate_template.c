#include <stdio.h>


double compute_sum(char *input_data) {

  // Your code goes here!
  // printf("*input_data: %d \n", *input_data);
  // printf("input_data[0]: %d \n", input_data[0]);
  // printf("&input_data[0]: %d \n", &input_data[0]);
  // printf("&input_data: %d \n", &input_data);
  // printf("input_data: %d \n", input_data);
  // printf("first byte : %d or %c \n", input_data[0], input_data[0]);
  // printf("second byte : %d or %c \n", input_data[1], input_data[1]);

  // printf("uh %c or %d \n", *(int *)input_data[0], *(char *)input_data[0]);
  
  // char attempt = *(input_data[0]);
  int flag = 1;
  int i = 0;
  int end_char;
  while (flag)
  {
    printf("In while loop : char %c is at pos %d \n", input_data[i], i);
    if (((char) input_data[i]) == 'e')
    {
      end_char = i;
      flag = 0;
    } i++;
  }
  // printf("end_char : %d \n", end_char);
  // printf("i : %d \n", i);
  // printf("input_data[end_char] : %c \n", input_data[end_char]);
  // printf("input_data[i] : %c \n", input_data[i]);

  double sum = 0;
  int j=1;

  printf("======\nStart for loop\n");

  for (i = 0; i < end_char; i++)
  { 
    printf("j : %d \n", j);
    switch (input_data[i])
    {
    case 'b':
      printf("char : %c = %d \n", *(char *) (input_data + (end_char + j)));
      sum += *(char *) (input_data + end_char + j);
      j++;
      printf("Add 1 to j \n");
      break;
    case 'h':
      printf("short : %hi \n", *(short *) (input_data + (end_char + j)));
      sum += *(short *) (input_data + end_char + j);
      j += 2;
      printf("Add 2 to j \n");
      break;
    case 'i':
      printf("int : %i \n", *(int *) (input_data + (end_char + j)));
      sum += *(int *) (input_data + end_char + j);
      j += 4;
      printf("Add 4 to j \n");
      break;
    case 'd':
      // printf("double : %d \n", (int) input_data[end_char+j]);
      // printf("double : %f \n", (double) input_data[end_char+j]);
      // printf("double lu : %lu \n", input_data[end_char+j]);
      // printf("double as hex: 0x%x \n", (double) input_data[end_char+j]);
      sum += *(double *) (input_data + end_char+j);
      j += 8;
      printf("Add 8 to j \n");
      break;
    default:
      printf("Hit default case. \n");
      printf("input_data[i] : %c \n", input_data[i]);
      printf("input_data[end_char+j] : %c \n", input_data[end_char+j]);
      break;
    }
    // printf("sum : %d \n", sum);
    printf("sum : %f \n", sum);
    printf("i : %d \n", i);
    printf("input_data[i] : %c \n", input_data[i]);
    printf("\nEnd iteration\n \n");
  }

  printf("End for loop\n");
  return sum;
}


int main(int argc, char *argv[])
{

  FILE *inf; // file pointer for input file
  char input_data[100]; // input data, length defined by problem
  double sum;  // variable which represents the sum of the numbers


  // Make sure filename has been supplied
  if (argc < 2) {
    fprintf(stderr, "You need to enter filename to be processed.\n");
    return -1;
  }

  // Open input file
  inf = fopen(argv[1],"rb");
  if (inf == NULL) {
    fprintf(stderr, "Error opening file %s\n", argv[1]);
    return -1;
  }

  // Read in input data
  if (fread(&input_data, 1, 100, inf) < 1) {
    fprintf(stderr, "Error reading.\n");
    return -1;
  }

  sum = compute_sum(input_data);

  printf("Sum is: %f\n", sum);

  printf("size of char %lu \n", sizeof(char));
  printf("size of short %lu \n", sizeof(short));
  printf("size of int %lu \n", sizeof(int));
  printf("size of double %lu \n", sizeof(double));

  printf("===================================== \n===================================== \n");

  return 0; 
}

