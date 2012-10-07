#include <stdio.h>

double compute_smallest_number(double, double, int);
double compute_largest_number(double, double);
double calculate_average(double, int);
void clear_buffer();
void print_greeting(int);
void print_statistics(double, int, double, double);

/**
 * Ask for 20 numbers in a loop. When 20 valid numbers are entered, calculate
 * the average and report out the largest, smallest and average numbers.
 *
 * Control the loop by controlling the counter alone, letting the loop worry
 * about itself.
 */
int main()
{
  int i = 0, quantity = 20;
  double number = 0, running_sum = 0, largest_number = 0, smallest_number = 0;

  print_greeting(quantity);

  for (i = 1; i <= quantity; i += 1)
  {
    printf("Enter number %d: ", i);

    if (scanf("%lf", &number))
    {
      running_sum += number;
      smallest_number = compute_smallest_number(number, smallest_number, i);
      largest_number = compute_largest_number(number, largest_number);
    }
    else
    {
      printf("Please only enter numbers! Let's try again...\n");
      i -= 1;
      number = 0.00;
    }

    clear_buffer();
  }

  print_statistics(running_sum, quantity, smallest_number, largest_number);

  return 0;
}

void print_greeting(int quantity)
{
  printf("I am going to ask you for %d numbers, one at a time. ", quantity);
  printf("Once you've entered the 20 numbers, I'll give you the average of ");
  printf("those numbers and also tell you the biggest and smallest.\n\n");
}

void print_statistics(double running_sum, int quantity,
                      double smallest_number, double largest_number)
{
  printf("\n\nYour average is %.2lf.\n", calculate_average(running_sum, quantity));
  printf("The smallest number you entered was %.2lf.\n", smallest_number);
  printf("The largest number you entered was %.2lf.\n", largest_number);
}

void clear_buffer()
{
  while (getchar() != '\n');
}

double calculate_average(double total, int quantity)
{
  return total / quantity;
}

double compute_largest_number(double number, double largest_number)
{
  if (number > largest_number) largest_number = number;

  return largest_number;
}

double compute_smallest_number(double number, double smallest_number, int iteration)
{
  // Keep the current number if it's the smallest or if we're on the first
  // iteration through the loop.
  if (iteration == 1 || number < smallest_number) smallest_number = number;

  return smallest_number;
}

