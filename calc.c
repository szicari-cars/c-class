#include <stdio.h>
#include <stdbool.h>

bool parse_input(char, double, double *);

int main()
{
    double result = 0.0, number_input = 0.0;
    char command;
    bool stop_calculating = false;

    printf("Calculator is on.\n");

    while (stop_calculating == false)
    {
        printf("Please enter a number: ");
        scanf("%c", &command);
        scanf("%lf", &number_input);
        stop_calculating = parse_input(command, number_input, &result);
    }
}

bool parse_input(char command, double number_input, double *result)
{
    bool stop_calculating = false;

    printf("\n");

    switch (command)
    {
        case 'h':
        case 'H':
            printf("Help goes here.\n");
            break;

        case 'r':
        case 'R':
            printf("Result is shown and the calculation cleared.\n");
            break;

        case 'q':
        case 'Q':
            stop_calculating = true;
            break;

        default:
            printf("UnknownOperatorException is thrown.\n");
    }

    return stop_calculating;
}

