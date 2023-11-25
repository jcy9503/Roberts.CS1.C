/*
 * File: pi_approximation_2.c
 * --------------------------
 * This program shows Pi value calculated with approximation method.
 * Version 2.
 */

#include <math.h>
#include "genlib.h"
#include "simpio.h"

/* Constants
 * ---------
 * TERMS is the number of terms in the series.
 * EPSILON used for floating-point number comparison of equality.
 */

#define TERMS 20
#define EPSILON 0.000000001

/* Function prototypes */

double ApproximationSeries(int idx);

/* Main program */

main()
{
    int i;
    double result = 0;
    printf("This program shows Pi value calculated with approximation method.\n");
    for(i = 0; i < TERMS; ++i)
    {
        result += ApproximationSeries(i);
        printf("Terms:%-5d= %12.10f\n", i + 1, result);
    }
    printf("Pi/6 = %.10f\n", result);
}

/*
 * Function: ApproximationSeries(int idx)
 * Usage: result += ApproximationSeries(idx);
 * ------------------------------------------
 * Returns the term of the series for corresponding index.
 */

double ApproximationSeries(int idx)
{
    int i;
    double a = 1.0, b = 1.0, c = 1.0;

    for(i = 0; i < idx; ++i)
    {
        a *= (i * 2.0 + 1.0) / (i * 2.0 + 2.0);
    }

    b = 1.0 / (idx * 2.0 + 1.0);

    c = pow(0.5, idx * 2.0 + 1.0);

    return (a * b * c);
}
