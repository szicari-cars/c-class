#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef int (*Processor)(float *, size_t, int);
typedef float (*CalculatorFunction)(float *, size_t, int);

typedef struct
{
    CalculatorFunction calculate;
    char * calculation_name;
} Calculator;

void display_menu();
int process_user_choice(int, float [], size_t, int);
int collect_data(float [], size_t, int);
int print_statistics(float [], size_t, int);
char * get_input();
void sort_array(float data_array[], size_t array_size, int data_position);

// Calculation functions
float calculate_high_number(float data_array[], size_t array_size, int data_position);
float calculate_low_number(float data_array[], size_t array_size, int data_position);
float calculate_mean(float data_array[], size_t array_size, int data_position);
float calculate_median(float data_array[], size_t array_size, int data_position);
float calculate_mode(float data_array[], size_t array_size, int data_position);
float calculate_variance(float data_array[], size_t array_size, int data_position);
float calculate_standard_deviation(float data_array[], size_t array_size, int data_position);

void main()
{
    int user_choice = false, data_position = 0;
    float data_array[200];
    size_t array_size = sizeof data_array / sizeof data_array[0];

    do
    {
        display_menu();
        user_choice = get_user_choice();

        if (user_choice < 3 && user_choice > 0)
            data_position = process_user_choice(user_choice, data_array, array_size, data_position);

        else if (user_choice > 3 || user_choice < 0)
            printf("%d is not a valid menu option.\n", user_choice);
    }
    while (user_choice != 3);

    printf("Program terminated.\n");
}

void display_menu()
{
    printf("\n~~~~~~~ Main Menu ~~~~~~~\n\n");
    printf("%4s) Enter Data\n", "1");
    printf("\n");
    printf("%4s) Display Data\n", "2");
    printf("\n");
    printf("%4s) Quit\n", "3");
    printf("\n");
}

char * get_input()
{
    int input_length = 100;
    char * unsanitized_input = (char *) malloc(input_length + 1);

    getline(&unsanitized_input, &input_length, stdin);

    return unsanitized_input;
}

int get_user_choice()
{
    int user_choice = 0;

    do printf("Make your choice, knave! ");
    while (sscanf(get_input(), "%d", &user_choice) != 1);

    return user_choice;
}

int process_user_choice(int user_choice, float data_array[], size_t array_size, int data_position)
{
    int i = 0;
    Processor processors[] = {/* 0 */ NULL, // There is no menu option 0...YET!!!
                              /* 1 */ &collect_data,
                              /* 2 */ &print_statistics};

    return processors[user_choice](data_array, array_size, data_position);
}

int collect_data(float data_array[], size_t array_size, int data_position)
{
    int input_length = 100;

    while (data_position < array_size)
    {
        printf("Item #%d: ", data_position+1);

        if (sscanf(get_input(), "%f", &data_array[data_position]) < 1)
        {
            printf("You didn't give valid input! Stopping.\n");
            break;
        }

        else data_position++;
    }

    if (data_position == array_size)
        printf("You are at your limit of %d numbers!\n", array_size);

    return data_position;
}

int print_statistics(float data_array[], size_t array_size, int data_position)
{
    int i = 0;
    Calculator calculators[] = {{&calculate_high_number, "Highest Number"},
                                {&calculate_low_number, "Lowest Number"},
                                {&calculate_mean, "Mean"},
                                {&calculate_median, "Median"},
                                {&calculate_mode, "Mode"},
                                {&calculate_variance, "Variance"},
                                {&calculate_standard_deviation, "Standard Deviation"}};

    sort_array(data_array, array_size, data_position);

    if (data_position == 0)
        printf ("You haven't entered any numbers yet.\n");
    else
    {
        printf("+--------------+\n");
        printf("| NUMBER STATS |\n");
        printf("+--------------+\n");

        for (i = 0; i < data_position; i++)
            printf("Number %d: %5.2lf\n", i+1, data_array[i]);

        printf("\n");
    }

    for (i = 0; i < (sizeof calculators / sizeof(Calculator)); i++)
        printf("%20s: %5.2lf\n", calculators[i].calculation_name,
                                 calculators[i].calculate(data_array, array_size, data_position));

    return data_position;
}

void sort_array(float data_array[], size_t array_size, int data_position)
{
    int i = 0, j = 0;
    float temp = 0.0;

    for (i = 0; i < data_position-1; i++)
        for (j = i+1; j < data_position; j++)
            if (data_array[i] > data_array[j])
            {
                temp = data_array[i];
                data_array[i] = data_array[j];
                data_array[j] = temp;
            }
}

float calculate_high_number(float data_array[], size_t array_size, int data_position)
{
    return data_array[data_position-1];
}

float calculate_low_number(float data_array[], size_t array_size, int data_position)
{
    return data_array[0];
}

float calculate_mean(float data_array[], size_t array_size, int data_position)
{
    int i = 0;
    float sum = 0.0, mean = 0.0;

    for (i = 0; i < data_position; i++) sum += data_array[i];
    mean = sum / (data_position-1);

    return mean;
}

float calculate_median(float data_array[], size_t array_size, int data_position)
{
    return data_array[data_position/2];
}

float calculate_variance(float data_array[], size_t array_size, int data_position)
{
    return 50.0;
}

float calculate_mode(float data_array[], size_t array_size, int data_position)
{
    return 50.0;
}

float calculate_standard_deviation(float data_array[], size_t array_size, int data_position)
{
    return 50.0;
}
