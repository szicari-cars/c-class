/**
 * Given any size integer, will return each digit in sequence. Written for use
 * in while loops.
 *
 * Example input: 252
 * Example output: 2 ... 5 ... 2 (where each ellipsis is an iteration of a loop
 *
 * @return int The next digit in the sequence
 */
int get_digit(int digit, int *input_number)
{
    int num_digits = 0, temp_digit = 0;

    while (temp_digit / 10 > 0)
    {
        digit = temp_digit;
        num_digits += 1;
    }
}

