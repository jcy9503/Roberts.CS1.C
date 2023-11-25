/*
 * File: lincoln_memorial.c
 * ------------------------
 * This program draws the Lincoln Memorial in
 * Washington, D.C.
 * Result picture will be written on graphics.ps file.
 */

#include "genlib.h"
#include "graphics.h"
#include "lucas.h"

/*
 * Constants
 * ---------
 * Constants used for drawing the LIncoln Memorial.
 */

#define MEMORIAL_WIDTH          5.0
#define PEDESTAL_HEIGHT         0.5

#define NUMBER_OF_COLUMNS       10
#define COLUMN_WIDTH            0.2
#define COLUMN_HEIGHT           0.8
#define COLUMN_CIRCLE_RADIUS    0.075

#define LOWER_ROOF_HEIGHT       0.3
#define UPPER_ROOF_WIDTH        3.5
#define UPPER_ROOF_HEIGHT       0.3

#define STATUE_WIDTH            0.2
#define STATUE_HEIGHT           0.4

/* Function prototypes */

void DrawPedestal(double x, double y);
void DrawColumn(double x, double y);
void DrawColumnCircle(double x, double y);
void DrawColumns(double x, double y);
void DrawLowerRoof(double x, double y);
void DrawUpperRoof(double x, double y);
void DrawStatue(double x, double y);

/* Main program */

main()
{
    printf("This program draws a picture of Lincoln Memorial in Washington, D.C.\n");

    InitGraphics();
    DrawPedestal(0.0, 0.0);
    DrawColumns(0.0, PEDESTAL_HEIGHT);
    DrawLowerRoof(0.0, PEDESTAL_HEIGHT + COLUMN_HEIGHT);
    DrawUpperRoof((MEMORIAL_WIDTH - UPPER_ROOF_WIDTH) / 2.0, PEDESTAL_HEIGHT + COLUMN_HEIGHT + LOWER_ROOF_HEIGHT);
    DrawStatue((MEMORIAL_WIDTH - STATUE_WIDTH) / 2.0, PEDESTAL_HEIGHT);
}

/*
 * Function: DrawPedestal
 * Usage: DrawPedestal(x, y);
 * --------------------------
 * Draws pedestal of the memorial.
 */

void DrawPedestal(double x, double y)
{
    DrawBox(x, y, MEMORIAL_WIDTH, PEDESTAL_HEIGHT);
}

/*
 * Function: DrawColumn
 * Usage: DrawColumn(x, y);
 * ------------------------
 * Draws a column.
 */

void DrawColumn(double x, double y)
{
    DrawBox(x, y, COLUMN_WIDTH, COLUMN_HEIGHT);
}

/*
 * Function: DrawColumnCircle
 * Usage: DrawColumnCircle(x, y);
 * ------------------------------
 * Draws a column circle with centered position (x, y).
 */

void DrawColumnCircle(double x, double y)
{
    DrawCenteredCircle(x, y, COLUMN_CIRCLE_RADIUS);
}

/*
 * Function: DrawColumns
 * Usage: DrawColumns(x, y);
 * -------------------------
 * Draws whole columns of the memorial.
 */

void DrawColumns(double x, double y)
{
    double space = (MEMORIAL_WIDTH - COLUMN_WIDTH * NUMBER_OF_COLUMNS) / 
        (NUMBER_OF_COLUMNS - 1) + COLUMN_WIDTH;
    int i;

    for(i = 0; i < NUMBER_OF_COLUMNS; ++i)
    {
        DrawColumn(x + i * space, y);
        DrawColumnCircle(x + i * space + COLUMN_WIDTH / 2.0, y + COLUMN_HEIGHT + LOWER_ROOF_HEIGHT / 2.0);
    }
}

/*
 * Function: DrawLowerRoof
 * Usage: DrawLowerRoof(x, y);
 * ---------------------------
 * Draws lower roof of the memorial.
 */

void DrawLowerRoof(double x, double y)
{
    DrawBox(x, y, MEMORIAL_WIDTH, LOWER_ROOF_HEIGHT);
}

/*
 * Function: DrawUpperRoof
 * Usage: DrawUpperRoof(x, y);
 * ---------------------------
 * Draws upper roof of the memorial.
 */

void DrawUpperRoof(double x, double y)
{
    DrawBox(x, y, UPPER_ROOF_WIDTH, UPPER_ROOF_HEIGHT);
}

/*
 * Function: DrawStatue
 * Usage: DrawStatue(x, y);
 * ------------------------
 * Draws a statue on the middle of the memorial.
 */

void DrawStatue(double x, double y)
{
    DrawBox(x, y, STATUE_WIDTH, STATUE_HEIGHT);
    DrawCenteredCircle(x + STATUE_WIDTH / 2.0, y + STATUE_HEIGHT + STATUE_WIDTH / 2.0,
            STATUE_WIDTH / 2.0);
}
