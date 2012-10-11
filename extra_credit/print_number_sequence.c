#include <stdio.h>
#include "c-classlib.h"

int main() 
{
    int num = 0, input_number = 2002;
    printf("Welcome, sucka.\n");

    while (num = get_digit(&input_number))
    {
        printf("The next digit is %d.\n", num);
    }

    printf("No more numbers!\n");

    return 0;
}

