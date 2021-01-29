#include <stdio.h>


double compute_sum(char *input_data) {

  // Your code goes here!
  int flag = 1;
  int i = 0;
  int end_char;
  while (flag)
  {
    if (((char) input_data[i]) == 'e')
    {
      end_char = i;
      flag = 0;
    } i++;
  }

  double sum = 0;
  int j=1;

  for (i = 0; i < end_char; i++)
  { 
    switch (input_data[i])
    {
    case 'b':
      sum += *(char *) (input_data + end_char + j);
      j++;
      break;
    case 'h':
      sum += *(short *) (input_data + end_char + j);
      j += 2;
      break;
    case 'i':
      sum += *(int *) (input_data + end_char + j);
      j += 4;
      break;
    case 'd':
      sum += *(double *) (input_data + end_char+j);
      j += 8;
      break;
    default:
      break;
    }
  }

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
  return 0; 
}

