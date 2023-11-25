/*
 * File: halloween.c
 * -----------------
 * This program draws Halloween pumpkin face.
 */

#include <math.h>
#include "genlib.h"
#include "graphics.h"
#include "lucas.h"

/*
 * Constants
 * ---------
 * These constants are used to draw pumpkin face.
 */

#define HEAD_RADIUS     1.0
#define STEM_WIDTH      0.1
#define STEM_HEIGHT     0.15
#define EYE_WIDTH       0.3
#define EYE_HEIGHT      0.2
#define NOSE_WIDTH      0.2
#define NOSE_HEIGHT     0.2
#define N_TEETH_PER_ROW 7
#define TOOTH_WIDTH     0.083333
#define TOOTH_HEIGHT    0.15

/* Function prototypes */

void DrawPumpkin(double x, double y);
void DrawStem(double x, double y);
void DrawEye(double x, double y);
void DrawNose(double x, double y);
void DrawTeeth(double x, double y);

/* Main program */

main()
{
    InitGraphics();
    DrawPumpkin(1.0, 1.0);
}

void PrintCurrentPen()
{
    printf("CurX: %g, CurY: %g\n", GetCurrentX(), GetCurrentY());
}

/*
 * Function: DrawPumpkin
 * Usage: DrawPumpkin(x, y);
 * -------------------------
 */

void DrawPumpkin(double x, double y)
{
    double edge = HEAD_RADIUS / 2.0 / sqrt(2.0);

    DrawCenteredCircle(x, y, HEAD_RADIUS);

    DrawStem(x, y + HEAD_RADIUS + STEM_HEIGHT / 2.0);

    DrawEye(x - edge - EYE_WIDTH / 2.0, y + edge + EYE_HEIGHT / 2.0);

    DrawEye(x + edge - EYE_WIDTH / 2.0, y + edge + EYE_HEIGHT / 2.0);
    
    DrawNose(x - NOSE_WIDTH / 2.0, y - NOSE_HEIGHT / 2.0);

    DrawTeeth(x - N_TEETH_PER_ROW * TOOTH_WIDTH / 2.0, y - HEAD_RADIUS / 2.0 - TOOTH_HEIGHT);
}

/*
 * Function: DrawStem
 * Usage: DrawStem(x, y);
 * ----------------------
 */

void DrawStem(double x, double y)
{
    DrawCenteredBox(x, y, STEM_WIDTH, STEM_HEIGHT);
}


/*
 * Function: DrawEye
 * Usage: DrawEye(x, y);
 * ---------------------
 */

void DrawEye(double x, double y)
{
    DrawTriangle(x, y, EYE_WIDTH, -EYE_HEIGHT);
}

/*
 * Function: DrawNose
 * Usage: DrawNose(x, y);
 * ----------------------
 */

void DrawNose(double x, double y)
{
    DrawTriangle(x, y, NOSE_WIDTH, NOSE_HEIGHT);
}

/*
 * Function: DrawTeeth
 * Usage: DrawTeeth(x, y);
 * -----------------------
 */

void DrawTeeth(double x, double y)
{
    DrawGrid(x, y, TOOTH_WIDTH, TOOTH_HEIGHT, N_TEETH_PER_ROW, 2);
}
