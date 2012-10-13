#include <stdio.h>
#include <stdbool.h>

bool is_valid_number(int);
void print_occurrence_string(int);
void print_results(int max_number, int max_number_count, int total_numbers, int bad_numbers);

void main()
{
    int number, max_number, max_number_count = 0, total_numbers = 0, bad_numbers = 0;

    printf("Please enter a series of numbers, separated by a single space and ending with a zero:\n\n");

    while ((number = getchar()) != EOF)
    {
        // Count the total numbers so we can track this against the bad 
        // numbers. If the total equals the bad count, then the user
        // didn't enter even a single good digit.
        total_numbers += 1;

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
        else bad_numbers += 1;
    }

    print_results(max_number, max_number_count, total_numbers, bad_numbers);
}

void print_results(int max_number, int max_number_count, int total_numbers, int bad_numbers)
{
    printf("\n");

    if (total_numbers == bad_numbers)
    {
        printf("There was not a single usable number among all %d characters you entered.\n", total_numbers);
    }
    else
    {
        printf("The largest number is %c, and it occurred ", max_number);

        print_occurrence_string(max_number_count);
        printf(".\n");
    }
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

