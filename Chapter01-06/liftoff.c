/*
 * File: liftoff.c
 * ---------------
 * Simulates a countdown for a rocket launch.
 */

#include <stdio.h>
#include "genlib.h"

/*
 * Constant: StartingCount
 * -----------------------
 * Change this constant to use a different starting value
 * for the countdown.
 */

#define StartingCount 10

/* Main program */

main()
{
    int t = StartingCount + 1;

    while(t--)
    {
        printf("%2d\n", t);
    }

    printf("Liftoff!\n");
}
