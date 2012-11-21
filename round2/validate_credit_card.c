#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void validate_cli_args(int argc, char *argv[]);
bool validate_cc_length(char *cc_number);
bool validate_cc_type(char *cc_number);
bool validate_cc_luhn_check(char *cc_number);
bool validate_cc_digits(char *cc_number);
int double_2nd_digits(char *cc_number);
int add_odd_digits(char * cc_number);

bool DEBUG = false;

void main(int argc, char *argv[])
{
    validate_cli_args(argc, argv);

    // TODO: Refactor using function pointers. It'll be fun!
    if (!validate_cc_length(argv[1]))
    {
        printf("The credit card number is not the right length.\n");
        exit(1);
    }

    if (!validate_cc_type(argv[1]))
    {
        printf("The credit card number is not a valid type.\n");
        exit(1);
    }

    if (!validate_cc_digits(argv[1]))
    {
        printf("The credit card number has invalid characters in it.\n");
        exit(1);
    }

    if (!validate_cc_luhn_check(argv[1]))
    {
        printf("The credit card number is not valid.\n");
        exit(1);
    }

    printf("The credit card number is valid!\n");
    exit(0);
}

/**
 * Ensures that one argument is passed on the command line.
 *
 * @return Boolean True if one argument is found, false otherwise.
 */
void validate_cli_args(int argc, char *argv[])
{
    if (argc == 3 && strcmp(argv[2], "debug") == 0) DEBUG = true;

    if (argc < 2)
    {
        printf("Please enter a credit card number.\n");
        exit(1);
    }
}

/**
 * Checks that the credit card number's length is between 13 and 16 characters.
 *
 * @return Boolean True if so, false otherwise.
 */
bool validate_cc_length(char *cc_number)
{
    int cc_num_length = strlen(cc_number);
    bool valid = false;

    if (cc_num_length >= 13 && cc_num_length <= 16) valid = true;

    return valid;
}

/**
 * Validates that the credit card is of a valid type. Valid types are deter-
 * mined by checking the first (and in one case, first and second) character
 * for certain numbers.
 *
 * Valid Types:
 *      /^4/    Visa card
 *      /^5/    Mastercard
 *      /^6/    Discover card
 *      /^37/   American Express card
 *
 * @return Boolean True if a valid type is found, false otherwise.
 */
bool validate_cc_type(char *cc_number)
{
    bool valid_type = false;

    if (cc_number[0] == '4' || cc_number[0] == '5' || cc_number[0] == '6' ||
        (cc_number[0] == '3' && cc_number[1] == '7'))
        valid_type = true;

    return valid_type;
}

/**
 * Iterates over the given string and verifies that every character is an
 * integer.
 *
 * @return Boolean False if a non-numeric character is detected. True otherwise.
 */
bool validate_cc_digits(char *cc_number)
{
    int i = 0;

    for (i = 0; i < strlen(cc_number); i++)
        if (!isdigit(cc_number[i])) return false;

    return true;
}

/**
 * Performs various mathematical checks on the numbers. Any failure indicates
 * an invalid number.
 *
 * @see http://en.wikipedia.org/wiki/Luhn_algorithm
 *
 * @return Boolean True if the number passes, false otherwise.
 */
bool validate_cc_luhn_check(char *cc_number)
{
    int doubled_digits = double_2nd_digits(cc_number),
        odd_digits = add_odd_digits(cc_number),
        sum = 0;

    sum = doubled_digits + odd_digits;
    if (DEBUG) printf("Sum of doubled digits: %d.\n", sum);

    return (sum % 10 == 0);
}

int double_2nd_digits(char *cc_number)
{
    int i = 0, digit, doubled_digit = 0, sum = 0;

    if (DEBUG) printf("Doubling and adding digits, right to left.\n");

    for (i = strlen(cc_number)-1; i >= 0; i -= 2)
    {
        doubled_digit = (cc_number[i] - '0') * 2;
        digit = doubled_digit % 10;

        if (doubled_digit > 9)
        {
            if (DEBUG) printf("   Even digit (10's place): %d.\n", doubled_digit / 10);
            digit += doubled_digit / 10;
        }

        if (DEBUG) printf("%c: Even digit (1's place): %d.\n", cc_number[i], digit);

        sum += digit;
    }

    return sum;
}

int add_odd_digits(char * cc_number)
{
    return 0;
}
