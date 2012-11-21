#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void validate_cli_args(int argc, char *argv[]);
bool validate_cc_length(char *cc_number);
bool validate_cc_type(char *cc_number);
bool validate_cc_luhn_check(char *cc_number);

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
    bool valid_type = true;

    if (cc_number[0] != '4' || cc_number[0] != '5' || cc_number[0] != '6' ||
        !(cc_number[0] == '3' && cc_number[1] == '7'))
        valid_type = false;

    return valid_type;
}

bool validate_cc_luhn_check(char *cc_number)
{}
