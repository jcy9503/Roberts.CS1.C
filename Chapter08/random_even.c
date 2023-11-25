/*
 * File: random_even.c
 * -------------------
 * This program produces random even number between
 * given constants numbers.
 */

#include "genlib.h"
#include "random.h"

/*
 * Constants
 * ---------
 * LOWER_BOUND -- lower bound of the range inclusive.
 * UPPER_BOUND -- upper bound of the range inclusive.
 * N_TRIALS -- number of trials
 */

#define LOWER_BOUND     2
#define UPPER_BOUND     100
#define N_TRIALS        10

/* Function prototypes */

int RandomEvenNumber(int low, int high);

/* Main program */

main()
{
    int i;

    if(LOWER_BOUND % 2 || UPPER_BOUND % 2) Error("random_even.c: You must set upper and lower bound to even number.\n");
    printf("This program produces random even number between %d and %d (inclusive)\n", LOWER_BOUND, UPPER_BOUND);

    Randomize();
    for(i = 0; i < N_TRIALS; ++i)
    {
        printf("%d\n", RandomEvenNumber(LOWER_BOUND, UPPER_BOUND));
    }
}

/*
 * Function: RandomEvenNumber
 * Usage: result = RandomEvenNumber(x, y);
 * ---------------------------------------
 * This function returns random even number between x and y inclusive.
 */

int RandomEvenNumber(int low, int high)
{
    double d = (double) rand() / ((double)RAND_MAX + 1);
    int k = (int)(d * (high - low + 2));
    if(k % 2) --k;
    return (k + low);
}
