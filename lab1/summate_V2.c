#include <stdio.h>


double update_sum_char(double sum, char num, char op){
  switch (op)
  {
  case '+':
    sum += num;
    break;
  case '-':
    sum -= num;
    break;
  case '*':
    sum *= num;
    break;
  case '/':
    sum /= num;
    break;
  
  default:
    break;
  }
}

double update_sum_short(double sum, short num, char op){
  switch (op)
  {
  case '+':
    sum += num;
    break;
  case '-':
    sum -= num;
    break;
  case '*':
    sum *= num;
    break;
  case '/':
    sum /= num;
    break;
  
  default:
    break;
  }
}

double update_sum_int(double sum, int num, char op){
  switch (op)
  {
  case '+':
    sum += num;
    break;
  case '-':
    sum -= num;
    break;
  case '*':
    sum *= num;
    break;
  case '/':
    sum /= num;
    break;
  
  default:
    break;
  }
}

double update_sum_double(double sum, double num, char op){
  switch (op)
  {
  case '+':
    sum += num;
    break;
  case '-':
    sum -= num;
    break;
  case '*':
    sum *= num;
    break;
  case '/':
    sum /= num;
    break;
  
  default:
    break;
  }
}

double compute_sum(char *input_data) {
  /*
  General algorithm:
    1. Run through the chars until you find the 'e' (iterate over i).
    2. Note the position of the 'e' in end_char (relative to the start of input_data pointer)
    3. Run through chars again (reusing i), this time decyphering the appropriate number of bytes, according to 
       the letter at position i.
       -That is, use int j to track how many bytes after end_char we should be at (which is determined by the bytes we've already read)
        and read the pointer at position (end_char + j)
       -When you progress from char k to char k+1 in the header, add to j the number of bytes that char k 's data uses
        Such as: 1 byte for char, 4 bytes for int, etc (see switch statement below) 
    4. Add the value of the appropriate bytes to a running sum
  */

  // Your code goes here!
  int flag = 1; // This lets us break out the while loop
  int i = 0;
  int end_char;
  int j = 1;
  double sum = 0;

  // First time iterating through the char array, to find the 'e' char
  while ( (char) input_data[i] != 'e' )
    i++;
  
  // Noting the last char in the header
  end_char = i;

  // Here, we iterate through the header char's again, while also working with the pointer to the rest of the data
  // such that we read the correct group of bytes by allowing the header char to dictate how many bytes we read at once, and as what data type
  for (i = 0; i < end_char; i += 2)
  { 
    switch (input_data[i])
    {
    case 'b':
      sum = update_sum_char(sum, *(char *) (input_data + end_char + j), input_data[i+1]); 
      j++;
      break;
    case 'h':
      sum = update_sum_char(sum, *(int *) (input_data + end_char + j), input_data[i+1]);
      j += 2;
      break;
    case 'i':
      sum = update_sum_char(sum, *(short *) (input_data + end_char + j), input_data[i+1]);
      j += 4;
      break;
    case 'd':
      sum = update_sum_char(sum, *(double *) (input_data + end_char + j), input_data[i+1]);
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

