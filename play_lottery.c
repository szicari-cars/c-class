#include <stdio.h>
#include <time.h>
#include <stdbool.h>

#define LOTTO_NUMBER_LENGTH 2

#define NO_PRIZE 0
#define GRAND_PRIZE 1
#define BIG_PRIZE 2
#define SMALL_PRIZE 3

int determine_prize(int, int);
int generate_lottery_number();
int play_lottery(int);
void print_lottery_results(int);
void show_greeting();
bool valid_lottery_number(int);
void split_number(int, int *, int *);

int main()
{
    int entered_number, lottery_number, prize;

    show_greeting();

    printf("Please enter a two-digit number: ");
    scanf("%d", &entered_number);

    if (valid_lottery_number(entered_number))
    {
        prize = play_lottery(entered_number);
        print_lottery_results(prize);
    }
    else
    {
        printf("%d is not a valid lottery number. You have three minutes to live.\n", entered_number);
    }
}

int play_lottery(int entered_number)
{
    int lottery_number = generate_lottery_number();
    printf("The lottery number is %d.\n", lottery_number);
    return determine_prize(entered_number, lottery_number);
}

bool valid_lottery_number(int entered_number)
{
    bool valid = true;
    int number_length = 0;

    while (entered_number > 0)
    {
        entered_number /= 10;
        number_length += 1;
    }

    return (number_length == LOTTO_NUMBER_LENGTH);
}

void show_greeting()
{
    printf("Welcome to the lottery!\n\n");
    printf("Enter a two-digit number to win big money.\n");
    printf("------\nPRIZES\n------\nExact match:\t\t$10,000\nMatch both digits:\t$ 3,000\nMatch one digit:\t$ 1,000\n\n");
}

/**
 * Generate a two digit lottery number between 10 and 100.
 */
int generate_lottery_number()
{
    srand(time(NULL));
    return (rand() % 100) + 10;
}

int determine_prize(int entered_number, int lottery_number)
{
    int guess1, guess2, lotto1, lotto2, prize = NO_PRIZE;

    split_number(entered_number, &guess1, &guess2);
    split_number(lottery_number, &lotto1, &lotto2);

    // They guessed both numbers in the right order
    if ((guess1 - lotto1 == 0) && (guess2 - lotto2 == 0))
        prize = GRAND_PRIZE;

    // They guessed both numbers in the opposite order
    else if ((guess1 - lotto2 == 0) && (guess2 - lotto1 == 0))
        prize = BIG_PRIZE;

    // They guessed at least one number in any order
    else if ((guess1 - lotto1 == 0) || (guess2 - lotto2 == 0) ||
             (guess1 - lotto2 == 0) || (guess2 - lotto1 == 0))
        prize = SMALL_PRIZE;

    return prize;
}

void split_number(int number, int *split1, int *split2)
{
    *split1 = number / 10;
    *split2 = number % 10;
}

void print_lottery_results(int prize)
{
    if (prize == GRAND_PRIZE) printf("Congratulations!! You won $10,000!\n");
    if (prize == BIG_PRIZE) printf("Really good! You won $3,000!\n");
    if (prize == SMALL_PRIZE) printf("Not bad! You won $1,000!\n");
    else if (prize == NO_PRIZE) printf("Wow, you suck. You won NOTHING.\n");
}

