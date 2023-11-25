#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

void swap(int* a, int* b)
{
    int tp = *a;
    *a = *b;
    *b = tp;
}

main()
{
    int a, b, total;
    printf("This program returns total sum of numbers between 2 numbers and themselves in Gauss way.\n");
    printf("Type two integers: ");
    a = GetInteger();
    b = GetInteger();
    if(a > b) swap(&a, &b);

    total = (b - a + 1) / 2.0 * (a + b);

    printf("The sum of total: %d\n", total);
}
