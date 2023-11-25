/*
 * File: prime_factorization.c
 * ---------------------------
 * This program reads in a positive integer and displays
 * prime factorization of the integer.
 */

#include <stdio.h>
#include <math.h>
#include "genlib.h"
#include "simpio.h"

/* Function prototypes */

bool IsPrime(int n);

/* Main program */

main()
{
    int n, d;

    printf("Enter number to be factored: ");
    n = GetInteger();

    while(n > 1)
    {
        for(d = 2;;++d)
        {
            if(IsPrime(d) && n % d == 0)
            {
                n /= d;
                printf("%d", d);
                break;
            }
        }
        if(n != 1) printf(" * ");
    }
    printf("\n");
}

/*
 * Function: IsPrime
 * Usage: if(IsPrime(n)) ...
 * -------------------------
 * The predicate function which determine whether
 * the integer n is prime number or not.
 */

bool IsPrime(int n)
{
    int i, limit;

    if(n <= 1) return (FALSE);
    if(n == 2) return (TRUE);
    if(n % 2 == 0) return (FALSE);
    limit = sqrt(n) + 1;
    for(i = 3; i <= limit; i += 2)
    {
        if(n % i == 0) return (FALSE);
    }
    return (TRUE);
}
