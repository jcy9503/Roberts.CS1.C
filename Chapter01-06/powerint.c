/*
 * File: power.c
 * -------------
 * This program displays the values from N^LOWER to N^UPPER
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

/*
 * Constants
 * ---------
 * N is the base. N^k
 * LOWER is the first k
 * UPPER is the last k
 */

#define N       2
#define LOWER   0
#define UPPER   10

/* Function prototypes */

int RaiseIntToPower(int n, int k);

/* Main program */

main()
{
    int i;

    printf("This program displays the values from %d^%d to %d^%d\n", N, LOWER, N, UPPER);

    for(i = LOWER; i <= UPPER; ++i)
    {
        printf("%2d^%2d = %5d\n", N, i, RaiseIntToPower(N, i));
    }
}

/*
 * Function: RaiseIntToPower
 * Usage: result = RaiseIntToPower(n, k);
 * --------------------------------------
 * This function returns the value of n^k
 */

int RaiseIntToPower(int n, int k)
{
    int i, result = 1;

    for(i = 0; i < k; ++i) result *= n;

    return result;
}
