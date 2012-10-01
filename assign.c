#include <stdio.h>

char get_grade(double);

int main()
{
  double test_value;

  // Get the numeric grade from the command prompt
  printf("Please enter your numeric grade: ");
  scanf("%lf", &test_value);
  printf("\n");

  printf("Your grade is %c\n", get_grade(test_value));

  return 0;
}

char get_grade(double grade)
{
  char letter_grade;

  if (grade >= 90.0 && grade <= 100) letter_grade = 'A';
  else if (grade >= 80.0 && grade <= 89.9) letter_grade = 'B';
  else if (grade >= 70.0 && grade <= 79.9) letter_grade = 'C';
  else if (grade >= 65.0 && grade <= 69.9) letter_grade = 'D';
  else if (grade >= 0 && grade <= 59.9) letter_grade = 'F';
  else
  {
    printf("You entered a non-standard grade. You automatically fail.\n");
    letter_grade = 'F';
  }

  return letter_grade;
}
