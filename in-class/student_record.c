#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct xrec * prepend_to_list(struct xrec * first, struct xrec temp);
void print_student_names(struct xrec * records);
void compute_grade(struct xrec * student);
struct xrec * delete_from_list(struct xrec * list, char * ssn);

struct xrec
{
    char name[11];
    char ssn[12];
    char g;
    double h,q,m,f;
    char grade;
    struct xrec * next;
};

int main()
{
    struct xrec * first;
    struct xrec temp;
    FILE * infile = fopen("data.txt", "r");
    
    // Basic intialization to known values
    first = NULL;

    while (fscanf(infile, "%10s %11s %c %lf %lf %lf %lf", temp.name,
                                                          temp.ssn,
                                                          &temp.g,
                                                          &temp.h,
                                                          &temp.q,
                                                          &temp.m,
                                                          &temp.f) != EOF)
    {
        temp.name[10] = '\0';

        first = prepend_to_list(first, temp);
    }

    fclose(infile);

    compute_grade(first);
    print_student_names(first);

    return 0;
}

void compute_grade(struct xrec * student)
{
    double total = 0.0;

    while (student != NULL)
    {
        total = student->h * .40 + 10 + student->q * .15 + student->m;

        switch ((int)total/10)
        {
            case 9:
            case 10:
                student->grade = 'A';
                break;
            case 8:
                student->grade = 'B';
                break;
            case 7:
                student->grade = 'C';
                break;
            case 6:
                student->grade = 'D';
                break;
            default:
                student->grade = 'F';
        }

        student = student->next;
    }
}

void print_student_names(struct xrec * record)
{
    printf("\n");

    //sort_by_name(record, TODO: Finish integrating sort algorithm!!

    while (record != NULL)
    {
        printf("%8s  Value\n", "Field");
        printf("----------------------\n");

        printf("%8s: %s\n", "Name", record->name);
        printf("%8s: %s\n", "SSN", record->ssn);
        printf("%8s: %c\n", "Gender", record->g);
        printf("%8s: %5.2lf\n", "H", record->h);
        printf("%8s: %5.2lf\n", "Q", record->q);
        printf("%8s: %5.2lf\n", "M", record->m);
        printf("%8s: %5.2lf\n", "F", record->f);
        printf("%8s: %c\n", "Grade", record->grade);

        printf("----------------------\n\n");

        // Advance to the next record - crucial step!
        record = record->next;
    }
}

/**
 * prepend_to_list - Creates a linked list.
 *
 * Inserts the temp struct at the beginning of the list.
 */
struct xrec * prepend_to_list(struct xrec * list, struct xrec temp)
{
    struct xrec * new_node = malloc(sizeof(struct xrec));

    (*new_node) = temp;
    new_node->next = list;

    return new_node;
}

struct xrec * delete_from_list(struct xrec * list, char * ssn)
{
    struct xrec * current, * previous;

    for (previous = NULL, current = list; current != NULL && strcmp(current->ssn, ssn) != 0;
            previous = current, current = current->next);

    if (current != NULL)
    {
        if (previous == NULL)
        {
            // The ssn was found in the first element
            list = current->next;
        }
        else
        {
            // The ssn was found somewhere in the middle of the list
            previous->next = current->next;
        }

        free(current);
    }

    return list;
}

struct xrec * sort_by_name(struct xrec * list)
{
    int i = 0, j = 0;
    struct xrec * temp = NULL;

    for (i = 0; i < n-1; i++)
        for (j = i+1; j < n; j++)
            if (strcmp(a[i].name, a[j].name) > 0)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
}
