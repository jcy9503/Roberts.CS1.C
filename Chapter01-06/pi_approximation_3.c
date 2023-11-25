/*
 * File: pi_approximation_3.c
 * --------------------------
 * This program displays pi value calculated with approximation method 3.
 * The method is integration method which divides quater circle into
 * finite number of rectangles, and then calculate sum of the rectangles' area.
 * The circle's radius should be 2.0 so that calculated area of quarter circle
 * is exactly Pi.
 */

#include <math.h>
#include "genlib.h"
#include "simpio.h"

/*
 * Constants
 * ---------
 * NUM is the number of rectangles.
 * RADIUS is the radius of the circle.
 */

#define NUM     100000
#define RADIUS  2.0

/* Function prototypes */

double RectangleArea(int idx);

/* Main program */

main()
{
    int i;
    double result = 0.0;
    
    printf("This program displays Pi value calculated with approximation method 3.\n");
    for(i = 0; i < NUM; ++i)
    {
        result += RectangleArea(i);
    }

    printf("Pi: %.10f\n", result);
}

/*
 * Function: RectangleArea
 * Usage: result += RectangleArea(idx);
 * ------------------------------------
 * Returns the area of the i-th rectangle.
 */

double RectangleArea(int idx)
{
    double w = RADIUS / NUM;
    double h = sqrt(RADIUS * RADIUS - (idx * w) * (idx * w));

    return (w * h);
}
