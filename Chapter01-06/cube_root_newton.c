/*
 * File: cube_root_newton.c
 * ------------------------
 * This program tests the function that calculates
 * cube root of the number with Newton's approximation method.
 */

#include <math.h>
#include "genlib.h"
#include "simpio.h"

/*
 * Constants
 * ---------
 * EPSILON is for floating number equality test.
 */

#define EPSILON 0.000000001

/* Function prototypes */

bool ApproximatelyEqual(double x, double y);
double CubeRoot(double n);

/* Main program */

main()
{
    double n;

    printf("This program returns cube root value of the input number.\n");
    printf("n = ? ");
    n = GetReal();
    printf("The cube root of %g is %.10f\n", n, CubeRoot(n));
}

/* Function: ApproximatelyEqual
 * Usage: if(ApproximatelyEqual(x, y))...
 * --------------------------------------
 * Predicate function which compare two floating-point numbers
 * and check whether they are approximately equal or not.
 */

bool ApproximatelyEqual(double x, double y)
{
    return (fabs(x - y) < EPSILON);
}

/* Function: CubeRoot
 * Usage: result = CubeRoot(n);
 * ----------------------------
 * This function returns cube root value of the argument.
 */

double CubeRoot(double n)
{
    double g;
    if(n == 0) return (0);
    g = n;
    while(!ApproximatelyEqual(n, g * g * g))
    {
        g = (2 * g * g * g + n) / (3 * g * g);
    }

    return (g);
}
