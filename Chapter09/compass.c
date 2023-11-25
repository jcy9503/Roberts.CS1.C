/*
 * File: compass.c
 * ---------------
 * This program tests function that returns the compass
 * point that lies 90 degrees to the left.
 */

#include "genlib.h"
#include "strlib.h"

typedef enum
{
    North, East, South, West, Count
} directionT;

string name[] = 
{
    "North", "East", "South", "West"
};

/* Function prototypes */

directionT LeftFrom(directionT dir);

/* Main program */

int main(void)
{
    directionT i;

    printf("This program tests function returns the compass point\n");
    printf("that lies 90 degrees to the left.\n");

    for(i = North; i < Count; ++i)
    {
        printf("LeftFrom(%-5s) = %s\n", name[i], name[LeftFrom(i)]);    
    }
}

/*
 * Function: LeftFrom
 * Usage: dir = LeftFrom(dir);
 * ---------------------------
 * This function returns the compass point lying 90 degrees
 * to the left from the argument point.
 */

directionT LeftFrom(directionT dir)
{
    return ((dir + 3) % Count);
}
