/*
 * File: shaded_box.c
 * ------------------
 * This program test DrawShadedBox function in "lucas.h".
 */

#include "genlib.h"
#include "graphics.h"
#include "lucas.h"

/* Main program */

main()
{
    InitGraphics();
    DrawShadedBox(1.0, 1.0, 0.5, 3.0, 7);
}
