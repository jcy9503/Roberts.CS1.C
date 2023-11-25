/*
 * File: round.c
 * -------------
 * This program shows round function for real numbers.
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

/* Function prototypes */

int Round(double x);

/* Main program */

main()
{
    double n;

    printf("This program shows round function for real number.\n");
    printf("n = ?: ");
    n = GetReal();
    printf("The rounded integer of %g is %d\n", n, Round(n));
}

/*
 * Function: Round
 * Usage: result = Round(x);
 * -------------------------
 * This function returns round value of real number x
 */

int Round(double x)
{
    return x < 0 ? x - 0.5 : x + 0.5;
}
