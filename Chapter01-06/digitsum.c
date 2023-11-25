#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main()
{
    int n, dsum;

    printf("This program sums the digits in an integer.\n");
    printf("Enter a positive integer: ");
    n = GetInteger();
    dsum = 0;

    while(n)
    {
        dsum += n % 10;
        n /= 10;
    }

    printf("The sum of the digits is %d\n", dsum);
}
