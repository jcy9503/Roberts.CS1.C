/*
 * File: cointest.c
 * ----------------
 * This program simulates flippint a coin.
 */

#include <stdio.h>
#include <stdlib.h>
#include "genlib.h"

/*
 * Constants
 * ---------
 * N_TRIALS -- Number of trials
 */

#define N_TRIALS 10

/* Main program */

main()
{
    int i;

    for(i = 0; i < N_TRIALS; ++i)
    {
        if(rand() <= RAND_MAX / 2) printf("Heads\n");
        else printf("Tails\n");
    }
}
