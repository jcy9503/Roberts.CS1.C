/*
 * File: perfectsquare.c
 * ---------------------
 * This program shows if input number is perfect square or not.
 */

#include <stdio.h>
#include <math.h>
#include "genlib.h"
#include "simpio.h"

/*
 * Constants
 * ---------
 * EPSILON is used for threshold when comparing real number.
 */

#define EPSILON 0.000001

/* Function prototypes */

bool IsPerfectSquare(double n);

/* Main program */

main()
{
    double n;

    printf("This program shows if input number is perfect square or not.\n");
    printf("n = ?: ");
    n = GetReal();

    if(IsPerfectSquare(n)) printf("TRUE!\n");
    else printf("FALSE!\n");
}

/*
 * Function: IsPerfectSquare
 * Usage: if(IsPerfectSquare(n)) ...
 * ---------------------------------
 * This predicate function returns TRUE if argument n is a perfect square number.
 */

bool IsPerfectSquare(double n)
{
    int resultI = sqrt(n) + 0.5;
    if(fabs(sqrt(n) - resultI) < EPSILON) return TRUE;
    return FALSE;
}
