#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct student {
    char name[50];
    int num_test_grades;
    float *test_grades;
};

int get_number_of_students();
void clear_buffer(FILE *buffer);
void print_buffer(FILE *buffer);
void remove_line_ending(char *str);
void get_student_data(int num_students, struct student *students);
void get_student_name(struct student *a_student, int student_num);
int get_student_grades(struct student *a_student, int student_num);

int main()
{
    int num_students = get_number_of_students();
    struct student *students;

    if (num_students > 0) get_student_data(num_students, students);

    return 0;
}

void get_student_data(int num_students, struct student *students)
{
    int i = 0, j = 0;

    students = (struct student *)malloc(num_students * sizeof(struct student));

    for (i = 0; i < num_students; i++)
    {
        get_student_name(&students[i], i+1);
        students[i].num_test_grades = get_student_grades(&students[i], i+1);
    }
}

void get_student_name(struct student *a_student, int student_num)
{
    char name[50];

    do printf("Enter name of student %d: ", student_num);
    while (fgets(name, sizeof(name), stdin) == NULL);

    remove_line_ending(name);
    strcpy(a_student->name, name);
}

int get_student_grades(struct student *a_student, int student_num)
{
    int num_grades = 0, i = 0;
    double grade = 0.0;

    do
    {
        printf("Enter number of tests %s has taken: ", a_student->name);
    }
    while (scanf("%d", &num_grades) != 1);

    // Allocate enough memory for the array of floats
    a_student->test_grades = (float *)malloc(num_grades * sizeof(float));

    for (i = 0; i < num_grades; i++)
    {
        do
        {
            printf("Enter grade for test %d: ", i+1);
        }
        while (scanf("%lf", &grade) != 1);

        a_student->test_grades[i] = grade;
    }
    
    return num_grades;
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

    clear_buffer(stdin);

    return num_students;
}

void clear_buffer(FILE *buffer)
{
    while (fgetc(buffer) != '\n');
}

void print_buffer(FILE *buffer)
{
    printf("\nCurrent buffer contents:\n------------------------\n");
    printf("%d\n", fgetc(buffer));
    printf("------------------------\n\n");
}

void remove_line_ending(char *str)
{
    char *line_ending = strchr(str, '\n');

    if (line_ending != NULL) *line_ending = '\0';
}

