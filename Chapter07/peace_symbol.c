/*
 * File: peace_symbol.c
 * --------------------
 * This program draws a peace symbol.
 */

#include <math.h>
#include "genlib.h"
#include "graphics.h"
#include "lucas.h"

/*
 * Constants
 * ---------
 * Constants for drawing a peace symbol.
 */

#define RADIUS 2.0

/* Function prototypes */

void DrawPeaceSymbol(double x, double y, double r);

/* Main program */

main()
{
    InitGraphics();
    DrawPeaceSymbol(0.0, 0.0, RADIUS);
}

/*
 * Function: DrawPeaceSymbol
 * Usage: DrawPeaceSymbol(x, y, r);
 * --------------------------------
 * This function draws a peace symbol.
 */

void DrawPeaceSymbol(double x, double y, double r)
{
    double edge = RADIUS / sqrt(2.0);
    MovePen(x, y);
    DrawCenteredCircle(x, y, r);
    AdjustPen(-edge, -edge);
    DrawLine(edge, edge);
    DrawLine(edge, -edge);
    AdjustPen(-edge, edge - RADIUS);
    DrawLine(0.0, RADIUS * 2);
}
