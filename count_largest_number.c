#include <stdio.h>
#include <stdbool.h>

bool is_valid_number(int);
void print_occurrence_string(int);

void main()
{
  int number, max_number, max_number_count = 0;

  printf("Please enter a series of numbers, separated by a single space and ending with a zero:\n\n");

  while ((number = getchar()) != EOF)
  {
    if (is_valid_number(number))
    {
      if (number > max_number)
      {
        max_number = number;
        max_number_count = 1;
      }
      else if (number == max_number)
      {
        max_number_count += 1;
      }
    }
  }

  printf("max number: %c, count: %d.\n", max_number, max_number_count);
  printf("\nThe largest number is %c, and it occurred ", max_number);
  // I know how to return a string in PHP/python, but not in C. I also don't
  // have a lot of time to get really far ahead with the class work, so for
  // now, this is how I have to do this.
  print_occurrence_string(max_number_count);
  printf(".\n");
}

/**
 * Checks the given input against the ASCII codes for 0 through 9.
 */
bool is_valid_number(int number)
{
  return (number >= 48 && number <= 57);
}

void print_occurrence_string(int occurrences)
{
  if (occurrences == 1) printf("once");
  else printf("%d times", occurrences);
}

