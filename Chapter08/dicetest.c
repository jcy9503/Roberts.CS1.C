/*
 * File: dicetest.c
 * ----------------
 * This program simulates rolling a die.
 */

#include <stdio.h>
#include "genlib.h"
#include "random.h"

/*
 * Constants
 * ---------
 * N_TRIALS -- Number of trials
 */

#define N_TRIALS 10

/* Function prototypes */

int RollDie(void);

/* Main program */

main()
{
    int i;
    Randomize();
    for(i = 0; i < N_TRIALS; ++i)
    {
        printf("%d\n", RollDie());
    }
}

/*
 * Function: RollDie
 * Usage: die = RollDie();
 * -----------------------
 * This function generates and returns a random integer in the
 * range 1 to 6, representing the roll of a six-sided die.
 */

int RollDie(void)
{
    return (RandomInteger(-5, 5));
}
