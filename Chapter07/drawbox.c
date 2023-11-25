/*
 * File: drawbox.c
 * ---------------
 * This program draws a box on the screen.
 */

#include "genlib.h"
#include "graphics.h"
#include "lucas.h"

/* Main program */

main()
{
    InitGraphics();
    DrawBox(0.5, 0.5, 1.0, 1.0);
}
