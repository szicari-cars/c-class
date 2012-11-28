#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct xrec * prepend_to_list(struct xrec * first, struct xrec temp);
struct xrec * get_line(FILE * input_stream);
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

    while (fscanf(infile, "%10s,%11s,%c,%lf,%lf,%lf,%lf", temp.name,
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
}

/**
 * Gets a single line from the given input stream.
 */
struct xrec * get_line(FILE * input_stream)
{
}

void print_student_names(struct xrec * records)
{
    while (records != NULL)
    {
        printf("%15s: %s\n", "Name", records->name);
        printf("%15s: %s\n", "SSN", records->ssn);
        printf("%15s: %c\n", "Gender", records->g);
        printf("%15s: %lf\n", "H", records->h);
        printf("%15s: %lf\n", "Q", records->q);
        printf("%15s: %lf\n", "Q", records->q);

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
