/*
 * File: atom_decay.c
 * ------------------
 * This program simulates atoms of radioactive
 * material decaying by years.
 */

#include "genlib.h"
#include "random.h"

/*
 * Constants
 * ---------
 * N_ATOMS -- number of atoms.
 */

#define N_ATOMS 100000

/* Function prototypes */

bool IsDecaying(void);

/* Main program */

main()
{
    int i, year = 0, fresh = N_ATOMS;

    printf("This program simulates decaying process of atoms of radioactive.\n");
    printf("Year    Atoms left\n");
    printf("----    ----------\n");
    Randomize();
    printf("%3d       %6d\n", year, fresh);
    do
    {
        ++year;
        for(i = 0; i < fresh; ++i)
        {
            if(IsDecaying()) --fresh;
        }
        printf("%3d       %6d\n", year, fresh);
    } while(fresh);
}

/*
 * Function: IsDecaying
 * Usage: if(IsDecaying())...
 * --------------------------
 * Predicate function which randomly returns
 * TRUE of FALSE.
 * Writer: It seems that RandomInteger(0, 1) generates
 * 0 with approximately 1/3 ratio.
 */

bool IsDecaying(void)
{
    int r = RandomInteger(0, 99);
    return r < 50;
}
