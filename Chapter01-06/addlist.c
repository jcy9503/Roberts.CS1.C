#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

main()
{
    int value, total;

    printf("This program adds a list of numbers.\n");
    printf("Signal end of list with a 0.\n");
    total = 0;
    while(TRUE)
    {
        printf(" ? ");
        value = GetInteger();
        if(value == 0) break;
        total += value;
    }

    printf("The total is %d\n", total);
}
