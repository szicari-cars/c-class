#include <math.h>
#include <stdio.h>
#include <stdbool.h>

/**
 * Given any size integer, will return each digit in sequence. Written for use
 * in while loops.
 *
 * Example input: 252
 * Example output: 2 ... 5 ... 2 (where each ellipsis is an iteration of a loop
 *
 * @return int The next digit in the sequence
 */
int get_digit(int *input_number)
{
    int digit = 0,
        num_digits = 0,
        temp_digit = *input_number;

    while ((temp_digit = temp_digit / 10) > 0)
    {
        digit = temp_digit;
        num_digits += 1;
    }

    // We still have a valid number, but it's in the 10's place.
    if (num_digits == 0)
    {
        digit = *input_number;
        *input_number = false;
    }
    else
    {
        *input_number = *input_number % (num_digits * (int)pow(10, num_digits));
    }

    return digit;
}

