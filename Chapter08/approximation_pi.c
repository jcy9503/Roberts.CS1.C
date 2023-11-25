/*
 * File: approximation_pi.c
 * ------------------------
 * This program generates Pi / 4 value using
 * random-based approximation method. (Monte Carlo Integration)
 */

#include "genlib.h"
#include "random.h"

/*
 * Constants
 * ---------
 * N_TRIALS -- number of trials
 */

#define N_TRIALS 100000000

/* Function prototypes */

bool IsInCircle(void);

/* Main program */

main()
{
    int i = N_TRIALS, trues = 0, falses = 0;

    printf("This program generates Pi/4 value using Monte Carlo Integeration.\n");
    Randomize();
    while(i--)
    {
        if(IsInCircle()) ++trues;
        else ++falses;
    }
    printf("Result: %10f\n", (double)trues / (trues + falses));
}

/*
 * Function: IsInCircle
 * Usage: if(IsInCircle())...
 * --------------------------
 * Predicate function that random coordinate (x, y)
 * is in the circle (center is origin, r = 1) or not.
 * Range: -1 <= x <= 1, -1 <= y <= 1
 */

bool IsInCircle(void)
{
    double x = RandomReal(-1.0, 1.0);
    double y = RandomReal(-1.0, 1.0);

    return (x * x + y * y < 1.0);
}
