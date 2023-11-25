/*
 * File: pi_approximation.c
 * ------------------------
 * This program displays Pi value with approximation series.
 */

#include "genlib.h"
#include "simpio.h"

/*
 * Constants
 * ---------
 * TERMS is the number of terms of the series.
 */

#define TERMS 10000

/* Main program */

main()
{
    int i;
    double result = 0;

    printf("Pi Approximation: ");
    for(i = 1; i <= 10000; ++i)
    {
        result += (1.0) / (i * 2.0 - 1) * (i % 2 == 0 ? -1.0 : 1.0);
    }
    printf("Pi/4 = %.10f\n", result);
}
