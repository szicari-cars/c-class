#include <stdio.h>
#include <stdbool.h>

bool process_input(char, double *);
bool validate_operand(double operand);
double do_calculation(double result, double operand, char operation);
double get_number_from_buffer();
void clear_input_buffer();
void show_help_text();

int main()
{
    bool keep_calculating = true;
    double result = 0.0;

    printf("Calculator is on.\n");
    show_help_text();

    do
    {
        printf("Please enter your input (%.2f): ", result);
    }
    while (process_input(getchar(), &result));
}

void show_help_text()
{
    printf("\n");
    printf("Valid inputs\n");
    printf("------------\n");
    printf("h -- This help text\n");
    printf("r -- get current result and clear calculator\n");
    printf("q -- quit calculator");
    printf("+num -- Add num to current result\n");
    printf("-num -- subtract num from current result\n");
    printf("/num -- divide current result by num\n");
    printf("*num -- multiply current result by num\n");
    printf("\n");
}

/**
 * Examines the first letter of input and takes action. This works because
 * the first letter is always a command, whether it be 'r', 'q' or a math
 * operation to perform. In certain cases, we will continue getting input
 * from the stdin buffer. In other cases, we will act immediately. Always,
 * we will clear the buffer before continuing.
 */
bool process_input(char input, double *result)
{
    bool keep_calculating = true, clear_buffer = true;
    double operand = 0.0;

    switch (input)
    {
        case 'h':
        case 'H':
            show_help_text();
            break;

        case 'r':
        case 'R':
            printf("End result: %.2f\nClearing result...\n", *result);
            *result = 0.0;
            break;

        case '+':
        case '-':
        case '/':
        case '*':
            operand = get_number_from_buffer();
            *result = do_calculation(*result, operand, input);
            printf("result %c %.2f = %.2f.\n", input, operand, *result);
            // The buffer is cleared as a side effect of fetching the number
            clear_buffer = false;
            break;

        case 'q':
        case 'Q':
            keep_calculating = false;
            break;

        default:
            printf("'%c' is an unknown operation.\n", input);
    }

    if (clear_buffer) clear_input_buffer();

    return keep_calculating;
}

void clear_input_buffer()
{
    while (getchar() != '\n');
}

double do_calculation(double result, double operand, char operation)
{
    if (operation == '+') result += operand;
    if (operation == '-') result -= operand;
    if (operation == '/') result /= operand;
    if (operation == '*') result *= operand;

    return result;
}

double get_number_from_buffer()
{
    int digit = 0;
    double num = 0.0;
    char ch;

    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        digit = ch - '0';
        num = (num * 10) + digit;
    }

    return num;
}

