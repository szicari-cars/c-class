#include <stdio.h>
#include <stdbool.h>

bool process_input(char input, double *result);
void clear_buffer();

int main()
{
    bool keep_calculating = true;
    double result = 0.0;

    printf("Calculator is on.\n");

    while (keep_calculating)
    {
        printf("Please enter your input (%.2f): ", result);
        keep_calculating = process_input(getchar(), &result);
    }
}

bool process_input(char input, double *result)
{
    bool keep_calculating = true;

    switch (input)
    {
        case 'h':
        case 'H':
            printf("Help goes here.\n");
            break;

        case 'r':
        case 'R':
            printf("End result: %.2f\nClearing result...\n", *result);
            *result = 0.0;
            break;

        case 'q':
        case 'Q':
            keep_calculating = false;
            break;

        case '\n':
            break;

        default:
            printf("UnknownOperatorException is thrown.\n");
    }

    return keep_calculating;
}

void clear_buffer()
{
    while (getchar() != '\n');
}

