#include <stdio.h>

char get_letter_grade(double);
void print_error_string();

int main()
{
    double test_value = 0.0;
    char letter_grade = 0.0;

    // Get the numeric grade from the command prompt
    printf("Please enter your numeric grade: ");
    if (scanf("%lf", &test_value))
        letter_grade = get_letter_grade(test_value);
    else
    {
        // You lied?! Automatic failure.
        letter_grade = get_letter_grade(0.0);
        print_error_string();
    }

    printf("\nYour grade is %c\n", letter_grade);

    return 0;
}

char get_letter_grade(double grade)
{
    char letter_grade;

    if (grade >= 90.0 && grade <= 100) letter_grade = 'A';
    else if (grade >= 80.0 && grade <= 89.9) letter_grade = 'B';
    else if (grade >= 70.0 && grade <= 79.9) letter_grade = 'C';
    else if (grade >= 65.0 && grade <= 69.9) letter_grade = 'D';
    else if (grade >= 0 && grade <= 59.9) letter_grade = 'F';

    return letter_grade;
}

void print_error_string()
{
    printf("\nYou entered a non-standard grade. You automatically fail.\n");
}
