#include <stdio.h>
#include <stdbool.h>

double compute_smallest_number(double, double);
double compute_largest_number(double, double);
double calculate_average(double, int);
bool is_digit(int);
void clear_buffer();

int main()
{
  int i, quantity = 20;
  double number, running_sum, largest_number, smallest_number;

  printf("I am going to ask you for %d numbers, one at a time. ", quantity);
  printf("Once you've entered the 20 numbers, I'll give you the average of ");
  printf("those numbers and also tell you the biggest and smallest.\n\n");

  for (i = 1; i <= quantity; i += 1)
  {
    printf("Enter number %d: ", i);

    if (scanf("%lf", &number))
    {
      running_sum += number;
      smallest_number = compute_smallest_number(number, smallest_number);
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

  printf("\n\nYour average is %.2lf.\n", calculate_average(running_sum, quantity));
  printf("The smallest number you entered was %.2lf.\n", smallest_number);
  printf("The largest number you entered was %.2lf.\n", largest_number);

  return 0;
}

bool is_digit(int number)
{
  return (number >= 48 && number <= 57);
}

void clear_buffer()
{
  while (getchar());
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

double compute_smallest_number(double number, double smallest_number)
{
  if (number < smallest_number) smallest_number = number;

  return smallest_number;
}

