/*
 * File: real_equal.c
 * ------------------
 * This program shows the comparison of two real numbers
 * for equality using epsilon.
 */

#include <stdio.h>
#include <math.h>
#include "genlib.h"
#include "simpio.h"

/*
 * Constants
 * ---------
 * EPSILON is used for comparison between the two real numbers.
 */

#define EPSILON 0.000001

/* Function prototypes */

bool ApproximatelyEqual(double x, double y);

/* Main program */

main()
{
    double x;

    for(x = 1.0; x <= 2.0 || ApproximatelyEqual(x, 2.0); x += 0.1)
    {
        printf("%.1f\n", x);
    }
}

/*
 * Function: ApproximatelyEqual
 * Usage: if(ApproximatelyEqual(x, y)) ...
 * ---------------------------------------
 * This predicate function returns true if real number x and y
 * are close enough to say they are in equal.
 */

bool ApproximatelyEqual(double x, double y)
{
    return (fabs(x - y) < EPSILON);
}
