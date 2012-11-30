#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef void (*Processor)(float *);

void display_menu();
void process_user_choice(int user_choice, float data_array[]);
void collect_data(float data_array[]);
void print_statistics(float data_array[]);
void clear_buffer();

void main()
{
    int user_choice = false;
    float data_array[200];

    do
    {
        display_menu();
        user_choice = get_user_choice();
        if (user_choice < 3) process_user_choice(user_choice, data_array);
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

int get_user_choice()
{
    int user_choice = false;

    printf("Make your choice, knave! ");

    do
    {
        scanf("%d", &user_choice);
    }
    while (user_choice == false);
}

void clear_buffer()
{
    while (getchar() != '\n');
}

void process_user_choice(int user_choice, float data_array[])
{
    Processor processors[] = {/* 0 */ NULL, // There is no menu option 0
                              /* 1 */ &collect_data,
                              /* 2 */ &print_statistics};

    processors[user_choice](data_array);
}

void collect_data(float data_array[])
{
    printf("Hey, collecting data!\n");
}

void print_statistics(float data_array[])
{
    printf("Hey, printing statistics!\n");
}
