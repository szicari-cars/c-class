#include <stdio.h>

#define DIE_SIZE 6

void print_roll_results(int *, int);
void initialize_results_array(int *);
int get_array_size(int *);

int main()
{
    int die_roll, i, bad_rolls = 0, results[DIE_SIZE];

    srand(time(NULL));

    initialize_results_array(results);

    for (i = 0; i < 1000; i += 1)
    {
        die_roll = rand() % DIE_SIZE;

        // Remember each number that was rolled by incrementing that value in
        // an array. This takes the place of having to do multiple IF state-
        // ments, one for each possible value of the die.
        if (die_roll < DIE_SIZE) results[die_roll] += 1;
        else bad_rolls += 1;
    }

    print_roll_results(results, bad_rolls);

    return 0;
}

void initialize_results_array(int * results)
{
    int i;

    for (i = 0; i < DIE_SIZE; i += 1) results[i] = 0;
}

void print_roll_results(int *results, int bad_rolls)
{
    int i;

    for (i = 0; i < DIE_SIZE; i += 1)
    {
        printf("Number of %d's:\t%d\n", i+1, results[i]);
    }

    printf("Number of bad rolls:\t%d\n", bad_rolls);
}
