#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void fill_array_with_ints(int * array, size_t array_size);
void print_array_with_ints(int * array, size_t array_size);

int main()
{
    int array[50];
    size_t array_size = sizeof array / sizeof(array[0]);

    srand(time(NULL));

    fill_array_with_ints(array, array_size);
    print_array_with_ints(array, array_size);
}

void fill_array_with_ints(int * array, size_t array_size)
{
    int i = 0;
    int * array_pointer = array;

    for (i = 0; i < array_size; i++)
        array_pointer[i] = rand() % 10;
}

void print_array_with_ints(int * array, size_t array_size)
{
    int i = 0;
    int * array_pointer = array;

    for (i = 0; i < array_size; i++)
        printf("Item %d: %d\n", i+1, array_pointer[i]);
}
