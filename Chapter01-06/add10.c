#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main()
{
    int i, n, value, total;

    printf("This program adds a list of numbers.\n");
    printf("How many numbers in the list? ");
    n = GetInteger();
    total = 0;
    for(i = 0; i < n; ++i)
    {
        printf(" ? ");
        value = GetInteger();
        total += value;
    }
    
    printf("The total is %d\n", total);
}
