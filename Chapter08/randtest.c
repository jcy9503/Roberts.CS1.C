/*
 * File: randtest.c
 * ----------------
 * This program tests the ANSI rand function.
 */

#include <stdio.h>
#include <stdlib.h>
#include "genlib.h"

/*
 * Constants
 * ---------
 * N_TRIALS - Number of trials
 */

#define N_TRIALS 10

/* Main program */

main()
{
    int i, r;

    printf("On this computer, RAND_MAX = %d.\n", RAND_MAX);
    printf("Here are the results of %d calls to rand:\n", N_TRIALS);
    for(i = 0; i < N_TRIALS; ++i)
    {
        r = rand();
        printf("%10d\n", r);
    }
}
