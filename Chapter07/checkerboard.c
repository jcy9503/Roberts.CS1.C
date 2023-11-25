/*
 * File: checkerboard.c
 * --------------------
 * This program draws a checkerboard with given constants.
 */

#include "genlib.h"
#include "graphics.h"
#include "lucas.h"

/*
 * Constants
 * ---------
 * Constants for drawing a checkerboard.
 */

#define NUM_OF_EDGE 8
#define SQUARE_SIZE 0.25
#define SHADED_SIZE 3

/* Function prototypes */

void DrawCheckerBoard(double x, double y);
void DrawFrame(double x, double y);
void DrawShaded(double x, double y);

/* Main program */

main()
{
    printf("This program draws a checkerboard with given constants.\n");
    
    InitGraphics();
    DrawCheckerBoard(1.0, 1.0);
}

void PrintCurPen(void)
{
    printf("CurX: %g, CurY: %g\n", GetCurrentX(), GetCurrentY());
}

/*
 * Function: DrawCheckerBoard
 * Usage: DrawCheckerBoard(x, y);
 * ------------------------------
 * Draws a whole checkerboard with given constants.
 */

void DrawCheckerBoard(double x, double y)
{
    int i, j;

    DrawFrame(x, y);
    for(i = 0; i < NUM_OF_EDGE; ++i)
    {
        MovePen(x, y + i * SQUARE_SIZE);
        for(j = 0; j < NUM_OF_EDGE; ++j)
        {
            if((i + j) % 2 == 0)
            {
                DrawShaded(GetCurrentX(), GetCurrentY());
            }
            AdjustPen(SQUARE_SIZE, 0.0);
        }
    }
}

/*
 * Function: DrawFrame
 * Usage: DrawFrame(x, y);
 * -----------------------
 * Draws the outline of the checkerboard.
 */

void DrawFrame(double x, double y)
{
    DrawBox(x, y, NUM_OF_EDGE * SQUARE_SIZE, NUM_OF_EDGE * SQUARE_SIZE);
}

/*
 * Function: DrawShaded
 * Usage: DrawShaded(x, y);
 * ------------------------
 * Draws a shaded square with given point.
 */

void DrawShaded(double x, double y)
{
    DrawShadedBox(x, y, SQUARE_SIZE, SQUARE_SIZE, SHADED_SIZE);
}
