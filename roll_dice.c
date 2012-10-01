#include <stdio.h>

#define DIE_SIZE 6

void print_roll_results(int[], int);
void initialize_results_array(int *);
int get_array_size(int[]);

int main()
{
    int die_roll, i, bad_rolls = 0, results[DIE_SIZE];

    srand(time(NULL));

    // Initializes by reference, because you can't return an array from a
    // function in C.
    initialize_results_array(results);

    printf("Die is %d.\n", get_array_size(results));

    for (i = 0; i < 1000; i += 1)
    {
	die_roll = rand() % DIE_SIZE;

	if (die_roll < DIE_SIZE) results[die_roll] += 1;
	else bad_rolls += 1;
    }

    print_roll_results(results, bad_rolls);

    return 0;
}

void initialize_results_array(int results[])
{
    int i;

    for (i = 0; i < DIE_SIZE; i += 1) results[i] = 0;
    printf("Die is %d after initialization.\n", get_array_size(results));
}

int get_array_size(int results[])
{
  return sizeof(results)/sizeof*(results);
}

void print_roll_results(int results[], int bad_rolls)
{
    int i;

    printf("Array is %d.\n", get_array_size(results));

    for (i = 0; i < sizeof(results); i += 1)
    {
	printf("Number of %d's:\t%d\n", i+1, results[i]);
    }

    printf("Number of bad rolls:\t%d\n", bad_rolls);
}
