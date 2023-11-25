/*
 * File: random_circle.c
 * ---------------------
 * This program generates random circles with
 * "graphics.h" library and store the data to
 * graphics.ps.
 * Applied Rules:
 * 1) Each circle should have a randomly chosen
 * radius between 0.05 and 0.5 inches.
 * 2) Each circle should be positioned at a
 * random location in the drawing window.
 */

#include "genlib.h"
#include "graphics.h"
#include "lucas.h"
#include "random.h"

/*
 * Constants
 * ---------
 * N_CIRCLES -- number of circles
 */

#define N_CIRCLES 10

/* Function prototypes */

void DrawCircle(void);

/* Main program */

main()
{
    int t = N_CIRCLES;

    printf("This program generates random %d circles.\n", N_CIRCLES);
    Randomize();
    InitGraphics();
    while(t--)
    {
        DrawCircle();
    }
}

/*
 * Function: DrawCircle
 * Usage: DrawCircle();
 * --------------------
 * This program draws a circle within graphics
 * window boundary.
 */

void DrawCircle(void)
{
    double x, y, r;
    double wx = GetWindowWidth();
    double wy = GetWindowHeight();

    r = RandomReal(0.05, 0.5);
    x = RandomReal(r, wx - r);
    y = RandomReal(r, wy - r);

    DrawCenteredCircle(x, y, r);
}
