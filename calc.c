#include <stdio.h>
#include <stdbool.h>

int main()
{
  double result;
  bool stop_calculating = false;

  while (stop_calculating == false)
  {
    printf("Please enter a number: ");
    scanf("%lf", &result);
    printf("You typed %lf.\n", result);
  }
}

