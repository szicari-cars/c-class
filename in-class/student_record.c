#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct xrec * prepend_to_list(struct xrec * first, struct xrec temp);
void print_student_names(struct xrec * records);

struct xrec
{
    char name[11];
    char ssn[12];
    char g;
    double h,q,m,f;
    char grade;
    struct xrec * next;
};

void main()
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
        temp.grade = 'Z';

        first = prepend_to_list(first, temp);
    }

    fclose(infile);

    print_student_names(first);
}

void print_student_names(struct xrec * records)
{
    printf("\n");

    while (records != NULL)
    {
        printf("%8s  Value\n", "Field");
        printf("----------------------\n");

        printf("%8s: %s\n", "Name", records->name);
        printf("%8s: %s\n", "SSN", records->ssn);
        printf("%8s: %c\n", "Gender", records->g);
        printf("%8s: %5.2lf\n", "H", records->h);
        printf("%8s: %5.2lf\n", "Q", records->q);
        printf("%8s: %5.2lf\n", "M", records->m);
        printf("%8s: %5.2lf\n", "F", records->f);
        printf("%8s: %c\n", "Grade", records->grade);

        printf("----------------------\n\n");

        // Advance to the next record
        records = records->next;
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

