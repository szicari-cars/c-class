#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int get_number_of_students();
void clear_input_buffer();
void get_student_data(int);

struct student {
    char *name;
    float test_grades[];
};

int main()
{
    int num_students = get_number_of_students();

    if (num_students > 0)
    {
        get_student_data(num_students);
    }

    return 0;
}

void get_student_data(int num_students)
{
    int i = 0;
    char name[300];

    for (i = 0; i < num_students; i++)
    {
        printf("Enter name of student %d: ", i+1);
        fgets(name, sizeof(name), stdin);
        printf("\nName is %s.\n", name);
    }
}

int get_number_of_students()
{
    int num_students = 0, attempt = 0, max_attempts = 5;

    while (num_students <= 0 && attempt < max_attempts)
    {
        printf("How many students are we tracking grades for? ");
        scanf("%d", &num_students);
        attempt += 1;
    }

    return num_students;
}

void clear_input_buffer()
{
    while (getchar() != '\n');
}

