/*
 * File: heart.c
 * -------------
 * This program draws a heart shape.
 */

#include <math.h>
#include "genlib.h"
#include "graphics.h"
#include "lucas.h"

/*
 * Constants
 * ---------
 * They are used for drawing a heart.
 */

#define SIZE 1.0

/* Main program */

main()
{
    double edge = SIZE / sqrt(2.0);
    InitGraphics();
    DrawLine(edge, edge);
    DrawArc(SIZE / 2, -45, 180);
    DrawArc(SIZE / 2, 45, 180);
    DrawLine(edge, -edge);
}

