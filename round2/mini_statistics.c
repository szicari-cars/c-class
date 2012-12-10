#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

typedef int (*Processor)(float *, size_t, int);
typedef float (*CalculatorFunction)(float *, size_t, int);

/**
 * Represents a calculation to be done on an array of numbers as well as the
 * name of the calculation being performed. Pointers everywhere!
 */
typedef struct
{
    CalculatorFunction calculate;
    char * calculation_name;
} Calculator;

typedef struct _mode_object
{
    float * value;
    int count;
    struct _mode_object * next;
} Mode_Object;

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

/**
 * Asks "the user" for a menu option and then dispatches out to a handler that
 * will respond to their input.
 */
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

/**
 * Shows the main menu to the user.
 */
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

/**
 * Function to get user input as safely as possible. Sets an upper limit on the
 * number of characters that can be entered, and protects against buffer over-
 * flows.
 */
char * get_input()
{
    int input_length = 100;
    char * unsanitized_input = (char *) malloc(input_length + 1);

    getline(&unsanitized_input, &input_length, stdin);

    return unsanitized_input;
}

/**
 * Asks for user input repeatedly until a valid number is entered.
 */
int get_user_choice()
{
    int user_choice = 0;

    do printf("Make your choice, knave! ");
    while (sscanf(get_input(), "%d", &user_choice) != 1);

    return user_choice;
}

/**
 * Uses function pointers to call handlers for the given input from the user.
 * By this point, the input has been sanitized and is within the range of valid
 * menu options available.
 */
int process_user_choice(int user_choice, float data_array[], size_t array_size, int data_position)
{
    int i = 0;
    Processor processors[] = {/* 0 */ NULL, // There is no menu option 0...YET!!!
                              /* 1 */ &collect_data,
                              /* 2 */ &print_statistics};

    return processors[user_choice](data_array, array_size, data_position);
}

/**
 * Collects user input into the data array until the array is full or the user
 * enters invalid input.
 *
 * This is slightly different from the assignment's requirement in that any
 * invalid input will exit out of the collection loop. I like this better be-
 * cause it means I can just press enter when I'm done entering numbers instead
 * of having to press some special key combination.
 */
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

/**
 * Prints out all entered numbers so far, and then prints out various statis-
 * tics about the numbers. The statistics are calculated by way of an array of
 * Calculator structures that include a pointer to a function to handle the
 * calculation as well as a short, descriptive title for the calculation.
 */
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

/**
 * Sorts a given array using a bubble sort algorithm.
 */
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

/**
 * Returns the highest number in the array.
 *
 * NOTE: This expects a sorted array!
 */
float calculate_high_number(float data_array[], size_t array_size, int data_position)
{
    return data_array[data_position-1];
}

/**
 * Returns the lowest number in the array.
 *
 * NOTE: This expects a sorted array!
 */
float calculate_low_number(float data_array[], size_t array_size, int data_position)
{
    return data_array[0];
}

/**
 * Returns the average of all the numbers in the given array.
 *
 * NOTE: This expects a sorted array!
 */
float calculate_mean(float data_array[], size_t array_size, int data_position)
{
    int i = 0;
    float sum = 0.0, mean = 0.0;

    for (i = 0; i < data_position; i++) sum += data_array[i];
    mean = sum / (data_position-1);

    return mean;
}

/**
 * Returns the middle number in the given array.
 *
 * NOTE: This expects a sorted array!
 */
float calculate_median(float data_array[], size_t array_size, int data_position)
{
    int middle_point = data_position / 2;

    if (array_size % 2 == 0)
    {
        return (data_array[middle_point-1] + data_array[middle_point]) / 2;
    }

    return data_array[middle_point];
}

/**
 * Returns the variance of the given array.
 *
 * NOTE: This expects a sorted array!
 */
float calculate_variance(float data_array[], size_t array_size, int data_position)
{
    float mean = calculate_mean(data_array, array_size, data_position), sum = 0.0;
    int i = 0;

    for (i = 0; i < data_position; i++)
        sum += pow(data_array[i]-mean, 2);

    return sum / (data_position-1);
}

/**
 * Returns the number that repeats the most in the given array.
 *
 * NOTE: This expects a sorted array!
 */
float calculate_mode(float data_array[], size_t array_size, int data_position)
{
    int winning_count = 0, current_count = 0, i = 0;
    Mode_Object mode_object, new_mode;
    float mode = 0.0, current_mode = 0.0;

    do
    {
        if (i == 0)
        {
            mode_object.value = &data_array[i];
            mode_object.count = 1;
        }
        else
        {
            if (data_array[i] == *mode_object.value)
                mode_object.count++;
            
            else
            {
                new_mode.value = &data_array[i];
                new_mode.counter = 1;
                mode_object.next = new_mode;
            }
        }

        //if (current_mode == data_array[i])
        //    current_count++;

        //else
        //{
        //    current_mode = data_array[i];
        //    current_count = 1;
        //}

        //if (current_count > winning_count)
        //{
        //    winning_count = current_count;
        //    mode = current_mode;
        //}

        i++;
    }
    while (i < data_position);
    
    return mode;
}

/**
 * Returns the standard deviation for the numbers in the given array.
 *
 * NOTE: This expects a sorted array!
 */
float calculate_standard_deviation(float data_array[], size_t array_size, int data_position)
{
    float variance = calculate_variance(data_array, array_size, data_position);

    return pow(variance, 0.5);
}
