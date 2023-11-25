/*
 * File: house.c
 * -------------
 * This program draws a simple frame house.
 */

#include "genlib.h"
#include "graphics.h"
#include "lucas.h"

/*
 * Constants
 * ---------
 * The following constants control the sizes of the
 * various elements in the display.
 */

#define HOUSE_HEIGHT            2.0
#define HOUSE_WIDTH             3.0
#define ATTIC_HEIGHT            0.7

#define DOOR_WIDTH              0.4
#define DOOR_HEIGHT             0.7
#define DOORKNOB_RADIUS         0.03
#define DOORKNOB_INSET          0.07

#define PANE_HEIGHT             0.25
#define PANE_WIDTH              0.2

#define FIRST_FLOOR_WINDOWS     0.3
#define SECOND_FLOOR_WINDOWS    1.25

/* Function prototypes */

void DrawHouse(double x, double y);
void DrawOutline(double x, double y);
void DrawWindows(double x, double y);
void DrawDoor(double x, double y);

/* Main program */

main()
{
    double cx, cy;

    InitGraphics();
    cx = GetWindowWidth() / 2;
    cy = GetWindowHeight() / 2;
    printf("cx: %g, cy: %g\n", cx, cy);
    DrawHouse(cx - HOUSE_WIDTH / 2, 
            cy - (HOUSE_HEIGHT + ATTIC_HEIGHT) / 2);
}

/*
 * Function: DrawHouse
 * Usage: DrawHouse(x, y);
 * -----------------------
 * This function draws a house diagram width the lower left corner
 * at (x, y). This level of the function merely divides up the work.
 */

void DrawHouse(double x, double y)
{
    DrawOutline(x, y);
    DrawDoor(x + (HOUSE_WIDTH - DOOR_WIDTH) / 2, y);
    DrawWindows(x, y);
}

/*
 * Function: DrawOutline
 * Usage: DrawOutline(x, y);
 * -------------------------
 * This function draws the outline for the house, using (x, y)
 * as the origin. The outline consists of a box with a triangle
 * on top.
 */

void DrawOutline(double x, double y)
{
    DrawBox(x, y, HOUSE_WIDTH, HOUSE_HEIGHT);
    DrawTriangle(x, y + HOUSE_HEIGHT, HOUSE_WIDTH, ATTIC_HEIGHT);
}

/*
 * Function: DrawDoor
 * Usage: DrawDoor(x, y);
 * ----------------------
 * This function draws a door, with its doorknob. As usual,
 * (x, y) specifies the lower left corner of the door.
 */

void DrawDoor(double x, double y)
{
    DrawBox(x, y, DOOR_WIDTH, DOOR_HEIGHT);
    DrawCenteredCircle(x + DOOR_WIDTH - DOORKNOB_INSET,
            y + DOOR_HEIGHT / 2, DOORKNOB_RADIUS);
}

/*
 * Function: DrawWindows
 * Usage: DrawWindows(x, y);
 * -------------------------
 * This function draws all the windows for the house,
 * taking advantage of the fact that the windows are all
 * arranged in two-dimensional grids of equal-sized panes.
 * By calling the function DrawGrid, this implementation
 * can create all of the window structures using a single
 * tool.
 */

void DrawWindows(double x, double y)
{
    double xleft, xright;
    
    xleft = x + HOUSE_WIDTH * 0.25;
    xright = x + HOUSE_WIDTH * 0.75;

    DrawGrid(xleft - PANE_WIDTH * 1.5, y + FIRST_FLOOR_WINDOWS,
            PANE_WIDTH, PANE_HEIGHT, 3, 2);
    DrawGrid(xright - PANE_WIDTH * 1.5, y + FIRST_FLOOR_WINDOWS,
            PANE_WIDTH, PANE_HEIGHT, 3, 2);
    DrawGrid(xleft - PANE_WIDTH, y + SECOND_FLOOR_WINDOWS,
            PANE_WIDTH, PANE_HEIGHT, 2, 2);
    DrawGrid(xright - PANE_WIDTH, y + SECOND_FLOOR_WINDOWS,
            PANE_WIDTH, PANE_HEIGHT, 2, 2);
}
