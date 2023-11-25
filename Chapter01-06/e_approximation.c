/*
 * File: e_approximation.c
 * -----------------------
 * This program displays e value calculated with approximation series.
 */

#include <math.h>
#include "genlib.h"
#include "simpio.h"

/*
 * Constants
 * ---------
 * EPSILON is the limit of floating-point precision.
 */

#define EPSILON 0.00000000001

/* Function prototypes */

bool ApproximatelyEqual(double x, double y);
double InverseFactorial(int n);

/* Main program */

main()
{
    int n = 0;
    double result = 1.0, prev = 1.0;

    printf("This program displays e value calculated with approximation series.\n");
    do
    {
        ++n;
        prev = result ;
        result = prev + InverseFactorial(n);
    } while(!ApproximatelyEqual(result, prev));

    printf("e: %.10f\nIteration: %d\n", result, n);
}

/*
 * Function: ApproximatelyEqual
 * Usage: if(ApproximatelyEqual(x, y))...
 * --------------------------------------
 * Predicate function which compare two arguments' equality.
 */

bool ApproximatelyEqual(double x, double y)
{
    return (fabs(x - y) < EPSILON);
}

/*
 * Function: InverseFactorial
 * Usage: result = InverseFactorial(n)
 * -----------------------------------
 * Returns 1 / n!
 */

double InverseFactorial(int n)
{
    static double fact = 1.0;
    
    fact *= n;
    return (1.0 / fact);
}
