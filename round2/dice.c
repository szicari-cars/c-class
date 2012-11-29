#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define WINS_INDEX      0
#define LOSSES_INDEX    1
#define WINS_WP         2
#define LOSSES_WP       3

#define NUM_ROLLS       100

int roll_die();
int roll_dice();
bool keep_score(int roll_sum, int * scores, int * roll_counter);
void print_game_stats(int * scores);

void main()
{
    int i = 0, roll_counter = 0, scores[] = {/*        WINS        */ 0,
                                             /*       LOSSES       */ 0,
                                             /*  WINS WITH POINTS  */ 0,
                                             /* LOSSES WITH POINTS */ 0};
    bool roll_again = false;

    srand(time(NULL));

    for (i = 0; i < NUM_ROLLS; i++)
    {
        do
        {
            roll_again = keep_score(roll_dice(), scores, &roll_counter);
            if (!roll_again) roll_counter = 0;
        }
        while (roll_again);
    }

    print_game_stats(scores);
}

void print_game_stats(int * scores)
{
    printf("Final Results:\n");
    printf("--------------\n");
    printf("%20s: %d\n", "Wins", scores[WINS_INDEX]);
    printf("%20s: %d\n", "Losses", scores[LOSSES_INDEX]);
    printf("%20s: %d\n", "Wins with points", scores[WINS_WP]);
    printf("%20s: %d\n", "Losses with points", scores[LOSSES_WP]);
    printf("---------------\n");
}

bool keep_score(int roll_sum, int * scores, int * roll_counter)
{
    bool roll_again = false;

    if (roll_sum == 7 || roll_sum == 11)
        (*roll_counter > 0) ? scores[WINS_WP]++ : scores[WINS_INDEX]++;

    else if (roll_sum == 2 || roll_sum == 3 || roll_sum == 12)
        (*roll_counter > 0) ? scores[LOSSES_WP]++ : scores[LOSSES_INDEX]++;

    else
    {
        *roll_counter++;
        roll_again = true;
    }

    return roll_again;
}

int roll_die()
{
    return rand() % 6 + 1;
}

int roll_dice()
{
    int i = 0, sum = 0;

    for (i = 0; i < 2; i++) sum += roll_die();

    return sum;
}
