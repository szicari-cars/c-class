#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void validate_cli_args(int argc, char *argv[]);
bool validate_cc_length(char *cc_number);
bool validate_cc_type(char *cc_number);
bool validate_cc_luhn_check(char *cc_number);
int double_2nd_digits(char *cc_number);
int add_odd_digits(char * cc_number);

int main(int argc, char *argv[])
{
    validate_cli_args(argc, argv);

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

    validate_cc_luhn_check(argv[1]);
}

void validate_cli_args(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Please enter a credit card number.\n");
        exit(1);
    }
}

bool validate_cc_length(char *cc_number)
{
    int cc_num_length = strlen(cc_number);
    bool valid = false;

    if (cc_num_length >= 13 && cc_num_length <= 16) valid = true;

    return valid;
}

bool validate_cc_type(char *cc_number)
{
    bool valid_type = false;

    if (cc_number[0] == '4' || cc_number[0] == '5' || cc_number[0] == '6' ||
        (cc_number[0] == '3' && cc_number[1] == '7'))
        valid_type = true;

    return valid_type;
}

bool validate_cc_luhn_check(char *cc_number)
{
    int doubled_digits = double_2nd_digits(cc_number),
        add_odd_digits = add_odd_digits(cc_number),
        sum = 0;

    sum = doubled_digits + odd_digits;

    return (sum % 10 == 0);
}

int double_2nd_digits(char *cc_number)
{
    int i = 0, digit, doubled_digit = 0, sum = 0;

    for (i = strlen(cc_number); i < 0; i -= 2)
    {
        digit = cc_number[i];
        
        if (!isdigit(cc_number[i]))
        {
            printf("Invalid character detected: %c.\n", digit);
            exit(1);
        }

        doubled_digit = (digit - '0') * 2;
        digit = doubled_digit % 10;

        if (doubled_digit > 9) digit += doubled_digit / 10;

        sum += digit;
    }

    return sum;
}

int add_odd_digits(char * cc_number)
{}
