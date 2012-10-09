#include <stdio.h>
#include <stdbool.h>

bool parse_input(char *);
bool do_input(char *input);

int main()
{
    double result = 0.0;
    char *input;
    bool stop_calculating = false;

    printf("Calculator is on.\n");

    while (stop_calculating == false)
    {
        printf("Please enter your input: ");
        scanf("%s", input);
        stop_calculating = parse_input(input);
    }
}

bool do_input(char *input)
{
    bool stop_calculating = false;

    printf("\n");

    //switch (input)
    //{
    //    case 'h':
    //    case 'H':
    //        printf("Help goes here.\n");
    //        break;

    //    case 'r':
    //    case 'R':
    //        printf("Result is shown and the calculation cleared.\n");
    //        break;

    //    case 'q':
    //    case 'Q':
    //        stop_calculating = true;
    //        break;

    //    default:
    //        printf("UnknownOperatorException is thrown.\n");
    //}

    return stop_calculating;
}

/**
 * Scan the input string for commands to perform.
 */
bool parse_input(char *input)
{
    char command;
    double input_number;
    printf(input);
}

