#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct student {
    char name[50];
    int num_test_grades;
    float *test_grades;
};

char get_letter_grade(double test_average);
double compute_test_averages(struct student a_student);
int get_number_of_students();
void clear_buffer(FILE *buffer);
void print_buffer(FILE *buffer);
void print_student_statistics(int num_students, struct student *students);
void remove_line_ending(char *str);
struct student * get_student_data(int num_students);
void get_student_name(struct student *a_student, int student_num);
int get_student_grades(struct student *a_student, int student_num);

int main()
{
    int num_students = get_number_of_students();
    struct student *students;

    if (num_students > 0)
    {
        students = get_student_data(num_students);
        print_student_statistics(num_students, students);
    }

    return 0;
}

struct student * get_student_data(int num_students)
{
    int i = 0, j = 0;
    struct student *students = (struct student *)malloc(num_students * sizeof(struct student));

    for (i = 0; i < num_students; i++)
    {
        get_student_name(&students[i], i+1);
        students[i].num_test_grades = get_student_grades(&students[i], i+1);
        clear_buffer(stdin);
    }

    return students;
}

void print_student_statistics(int num_students, struct student *students)
{
    int i = 0;
    double test_average = 0.0;

    for (i = 0; i < num_students; i++)
    {
        test_average = compute_test_averages(students[i]);

        printf("\n");
        printf("%18s: %s\n", "Name", students[i].name);
        printf("%18s: %d\n", "Number of tests", students[i].num_test_grades);
        printf("%18s: %5.2lf\n", "Test Average", test_average);
        printf("%18s: %c", "Letter Grade", get_letter_grade(test_average));
        printf("\n");
    }
}

double compute_test_averages(struct student a_student)
{
    int i = 0;
    double sum_tests = 0.0;

    for (i = 0; i < a_student.num_test_grades; i++)
    {
        sum_tests += a_student.test_grades[i];
    }

    return sum_tests / a_student.num_test_grades;
}

char get_letter_grade(double test_average)
{
    char letter_grade = 'F';

    if (test_average >= 90.0) letter_grade = 'A';
    if (test_average >= 80.0) letter_grade = 'B';
    if (test_average >= 70.0) letter_grade = 'C';
    if (test_average >= 65.0) letter_grade = 'D';

    return letter_grade;
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

