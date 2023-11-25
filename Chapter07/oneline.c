/*
 * File: oneline.c
 * ---------------
 * This program draws a single straight line.
 */

#include "genlib.h"
#include "graphics.h"

main()
{
    InitGraphics();
    MovePen(0.5, 0.5);
    DrawLine(0.0, 1.0);
}
