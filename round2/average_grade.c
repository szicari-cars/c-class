#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int get_number_of_students();
void clear_input_buffer();
void initialize_student_data_arrays(char *, float *, int);
void get_student_data(int, char *, float *);

int main()
{
	int num_students = get_number_of_students();
	char * student_names;
	float * student_grades;

	if (num_students > 0)
	{
		initialize_student_data_arrays(student_names, student_grades, num_students);
		get_student_data(num_students, student_names, student_grades);
	}

	return 0;
}

void get_student_data(int num_students, char * student_names, float * student_grades)
{
	int i = 0;

	for (i = 0; i < num_students; i++)
	{
		printf("Enter name of student %d: ", i);
		gets(student_names[i]);
	}
}

void initialize_student_data_arrays(char * student_names, float * student_grades, int num_students)
{
	student_names = (char *) malloc(num_students * sizeof(char));
	student_grades = (float *) malloc(num_students * sizeof(float));
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

