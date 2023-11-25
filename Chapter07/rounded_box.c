/*
 * File: rounded_box.c
 * -------------------
 * This program tests DrawRoundedBox function in lucas.h
 */

#include "genlib.h"
#include "graphics.h"
#include "lucas.h"

/*
 * Constants
 * ---------
 * Constants that are used drawing rounded box.
 */

#define CORNER_RADIUS   0.5
#define WIDTH           2.0
#define HEIGHT          1.0

/* Main program */

main()
{
    InitGraphics();
    DrawRoundedBox(0.0, 0.0, WIDTH, HEIGHT, CORNER_RADIUS);
}
