#include <stdio.h>
#include <time.h>
#include <stdbool.h>

bool ask_math_questions();
bool validate_answer(int, int, int);
int generate_operand();
int pose_math_question(int, int);
void display_message(bool);
void generate_operands();
void show_instructions();

int main()
{
    char input;

    srand(time(NULL));

    show_instructions();

    while (true) ask_math_questions();

    return 0;
}


bool validate_answer(int answer, int operand1, int operand2)
{
    return (answer == (operand1 * operand2));
}

void generate_operands(int *operand1, int *operand2)
{
    *operand1 = generate_operand();
    *operand2 = generate_operand();
}

/**
 * Generates a random number between 0 and 9.
 */
int generate_operand()
{
    return (rand() % 10);
}

void show_instructions()
{
    printf("Greetings! We're going to practice multiplication.\n");
    printf("I'll ask you a series of multiplication questions. You will have ");
    printf("as many tries as you need to get them right.\n");
    printf("When you're ready to stop, press Ctrl-C.\n\n");
}

bool ask_math_questions()
{
    int user_answer = 0, operand1 = 0, operand2 = 0;
    bool valid_answer = true;

    generate_operands(&operand1, &operand2);

    do
    {
        user_answer = pose_math_question(operand1, operand2);
        valid_answer = validate_answer(user_answer, operand1, operand2);
        display_message(valid_answer);
    }
    while (false == valid_answer);
}

int pose_math_question(int operand1, int operand2)
{
    int answer = 0;

    printf("What is %d times %d? ", operand1, operand2);
    scanf("%d", &answer);

    return answer;
}

void display_message(bool valid_answer)
{
    int message_number = (rand() % 4) + 1;

    switch (message_number)
    {
        case 1:
            if (valid_answer) printf("Very good!\n");
            else printf("No. Please try again.\n");
            break;
        case 2:
            if (valid_answer) printf("Excellent!\n");
            else printf("Wrong. Try once more.\n");
            break;
        case 3:
            if (valid_answer) printf("Nice work!\n");
            else printf("Don't give up!\n");
            break;
        case 4:
            if (valid_answer) printf("Keep up the good work!\n");
            else printf("No. Keep trying.\n");
    }
}

