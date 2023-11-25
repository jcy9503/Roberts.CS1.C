/*
 * File: pyramid.c
 * ---------------
 * This is a program that draws a pyramid with given levels.
 */

#include "genlib.h"
#include "graphics.h"
#include "lucas.h"

/*
 * Constants
 * ---------
 * They are used for drawing a pyramid.
 */

#define BRICK_WIDTH     0.3
#define BRICK_HEIGHT    0.1
#define PYRAMID_LEVEL   16

/* Main program */

main()
{
    int i, j;

    InitGraphics();
    for(i = 0; i < PYRAMID_LEVEL; ++i)
    { 
        for(j = 0; j < PYRAMID_LEVEL - i; ++j)
        {
            DrawBox(i * BRICK_WIDTH * 0.5 + j * BRICK_WIDTH, i * BRICK_HEIGHT, BRICK_WIDTH, BRICK_HEIGHT);
        }
    }
}
