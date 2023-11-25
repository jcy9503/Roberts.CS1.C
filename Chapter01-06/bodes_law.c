/*
 * File: bodes_law.c
 * -----------------
 * This program displays each of the planets in solar system's
 * distance from the sun calculated by Bode's law.
 */

#include "genlib.h"
#include "simpio.h"

/* Function prototypes */

double BodesLaw(int n);

/* Main program */

main()
{
    int i;
    string planets[] = {"Mercury", "Venus", "Earth", "Mars", "?", "Jupiter", "Saturn", "Uranus"};

    printf("This program displays planets' distances from the sun.\n");
    
    for(i = 0; i < 8; ++i)
    {
        printf("%-10s%4.1f AU\n", planets[i], BodesLaw(i));
    }
}

/*
 * Function: BodesLaw
 * Usage: result = BodesLaw(n);
 * ----------------------------
 * Returns distance of index n in Bode's Law sequence.
 */

double BodesLaw(int n)
{
    int sequence = 3, i;
    switch(n)
    {
        case 0: sequence = 1; break;
        case 1: sequence = 3; break;
        default:
                for(i = n; i > 1; --i) sequence *= 2;
                break;
    }

    return ((4.0 + sequence) / 10.0);
}
