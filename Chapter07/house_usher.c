/*
 * File: house_usher.c
 * -------------------
 * This program draws House of Usher, which
 * Edgar Allen Poe describes on his book.
 * Result will be written on graphics.ps file.
 */

#include "genlib.h"
#include "graphics.h"
#include "lucas.h"

/*
 * Constants
 * ---------
 * Constants used for drawing House of Usher
 */

#define HOUSE_WIDTH     1.5
#define HOUSE_HEIGHT    2.0
#define HOUSE_ARCH      1.0

#define TOWER_WIDTH     0.4
#define TOWER_HEIGHT    2.3
#define TOWER_ARCH      0.6

#define DOOR_WIDTH      0.3
#define DOOR_HEIGHT     0.5
#define DOOR_ARCH       0.25

#define WINDOW_LEVEL    1.4
#define WINDOW_SIZE     0.3

/* Function prototypes */

void DrawTower(double x, double y);
void DrawHouseFrame(double x, double y);
void DrawDoor(double x, double y);
void DrawWindow(double x, double y);

/* Main Program */

main()
{
    double windowEdge = (HOUSE_WIDTH / 2.0 - WINDOW_SIZE) / 2.0;
    printf("This program draws a diagram of House of Usher.\n");

    InitGraphics();
    DrawTower(0.0, 0.0);
    DrawHouseFrame(TOWER_WIDTH, 0.0);
    DrawTower(TOWER_WIDTH + HOUSE_WIDTH, 0.0);
    DrawDoor(TOWER_WIDTH + (HOUSE_WIDTH - DOOR_WIDTH) / 2.0, 0.0);
    DrawWindow(TOWER_WIDTH + windowEdge, WINDOW_LEVEL);
    DrawWindow(TOWER_WIDTH + HOUSE_WIDTH - windowEdge - WINDOW_SIZE, WINDOW_LEVEL);
}

/*
 * Function: DrawTower
 * Usage: DrawTower(x, y);
 * -----------------------
 * Draws tower shape.
 */

void DrawTower(double x, double y)
{
    DrawBox(x, y, TOWER_WIDTH, TOWER_HEIGHT);
    DrawTriangle(x, y + TOWER_HEIGHT, TOWER_WIDTH, TOWER_ARCH);
}

/*
 * Function: DrawHouseFrame
 * Usage: DrawHouseFrame(x, y);
 * ----------------------------
 * Draws frame of the house.
 */

void DrawHouseFrame(double x, double y)
{
    DrawBox(x, y, HOUSE_WIDTH, HOUSE_HEIGHT);
    DrawTriangle(x, y + HOUSE_HEIGHT, HOUSE_WIDTH, HOUSE_ARCH);
}

/*
 * Function: DrawDoor
 * Usage: DrawDoor(x, y);
 * ----------------------
 * Draws the door of the house.
 */

void DrawDoor(double x, double y)
{
    DrawBox(x, y, DOOR_WIDTH, DOOR_HEIGHT);
    DrawTriangle(x, y + DOOR_HEIGHT, DOOR_WIDTH, DOOR_ARCH);
}

/*
 * Function: DrawWindow
 * Usage: DrawWindow(x, y);
 * ------------------------
 * Draws a square shaped window.
 */

void DrawWindow(double x, double y)
{
    DrawBox(x, y, WINDOW_SIZE, WINDOW_SIZE);
}
