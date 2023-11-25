/*
 * File: perfect_numbers.c
 * -----------------------
 * Thie program checks if there is a perfect number(s) range of
 * LOWER_LIMIT and UPPER_LIMIT and displays the number(s).
 */

#include "genlib.h"
#include "simpio.h"

/*
 * Constants
 * ---------
 * LOWER_LIMIT is the lower bound of checking numbers.
 * UPPER_LIMIT is the upper bound of checking numbers.
 */

#define LOWER_LIMIT 1
#define UPPER_LIMIT 9999

/* Function prototypes */

bool IsPerfect(int n);

/* Main program */

main()
{
    int i;

    printf("Searching perfect number(s) between %d and %d..\n", LOWER_LIMIT, UPPER_LIMIT);
    for(i = LOWER_LIMIT; i <= UPPER_LIMIT; ++i)
    {
        if(IsPerfect(i)) printf("%d\n", i);
    }
}

/*
 * Function: IsPerfect
 * Usage: if(IsPerfect(n))...
 * --------------------------
 * Checks if argument n is a perfect number or not.
 * Returns Boolean value (Predicate function)
 */

bool IsPerfect(int n)
{
    if(n == 1) return (FALSE);
    int i, product;
    product = 1;
    for(i = 2; i * i <= n; ++i)
    {
        if(n % i == 0)
        {
            product += i;
            if(i * i != n)
                product += n / i;
        }
    }

    if(product == n) return (TRUE);
    return (FALSE);
}
