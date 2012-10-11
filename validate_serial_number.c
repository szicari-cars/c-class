#include <stdio.h>
#include <stdbool.h>

bool is_alpha(char ch);
bool is_digit(char ch);
bool validate_character(char ch, int hyphen_count);
void clear_input_buffer();
void highlight_bad_character(int char_count);

/**
 * Assignment: Validate a serial number
 * Author: Sean Zicari
 */

int main()
{
    bool valid_serial_number = true;
    int hyphen_count = 0, char_count = 0;
    char ch;

    while ((ch = getchar()) != '\n')
    {
        char_count += 1;

        if (ch == '-')
        {
            hyphen_count += 1;
        }
        else if (validate_character(ch, hyphen_count) == false)
        {
            highlight_bad_character(char_count);
            printf("\nInvalid character found.\n");
            valid_serial_number = false;
            break;
        }
    }

    if (valid_serial_number) printf("\nSerial number is valid.\n");
    else printf("Serial number not valid.\n");
}

void highlight_bad_character(int char_count)
{
    int i = 0;
    while (i < char_count - 1)
    {
        printf(" ");
        i += 1;
    }
    printf("^\n");
}

void clear_input_buffer()
{
    while (getchar() != '\n');
}

bool validate_character(char ch, int hyphen_count)
{
    bool valid = true;

    if (hyphen_count == 0 || hyphen_count == 2) valid = is_alpha(ch);
    if (hyphen_count == 1) valid = is_digit(ch);

    return valid;
}

bool is_alpha(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

bool is_digit(char ch)
{
    return (ch >= '0' && ch <= '9');
}

