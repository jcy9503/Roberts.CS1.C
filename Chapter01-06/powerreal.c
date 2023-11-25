/*
 * File: powerreal.c
 * -----------------
 * This program displays the values N^k
 * between N^LOWER to N^UPPER in real number base.
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

/*
 * Constants
 * ---------
 * N is the base of the values.
 * LOWER is the start value of k
 * UPPER is the last value of k
 */

#define N       10
#define LOWER   -4
#define UPPER   4

/* Function prototypes */

double RaiseRealToPower(double n, double k);

/* Main program */

main()
{
    int i;

    printf("            k\n");
    printf(" k        10\n");
    printf("---------------\n");
    
    for(i = LOWER; i <= UPPER; ++i)
    {
        printf("%2d ", i);
        if(i < 0) 
        {
            printf("     %g\n", RaiseRealToPower(N, i));
        }
        else
        {
            printf("%8.1f\n", RaiseRealToPower(N, i));
        }
    }
}

/*
 * Function: RaiseRealToPower
 * Usage: result = RaiseRealToPower(n, k);
 * ---------------------------------------
 * This function returns n^k in real number.
 */

double RaiseRealToPower(double n, double k)
{
    int i;
    double result = 1;

    if(k < 0)
    {
        for(i = 0; i < -k; ++i) result /= n;           
    }
    else
    {
        for(i = 0; i < k; ++i) result *= n;
    }

    return result;
}
