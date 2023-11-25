/*
 * File: draw_string.c
 * -------------------
 * This program tests DrawString in lucas.h
 */

#include "genlib.h"
#include "graphics.h"
#include "lucas.h"

/*
 * Constants
 * ---------
 * Character constant
 */

#define HEIGHT 0.5

/* Main program */

main()
{
    InitGraphics();
    MovePen(0, HEIGHT * 3.0 / 2.0 * 3);
    DrawString(GetCurrentX(), GetCurrentY(), HEIGHT, "abcdefghi");
    AdjustPen(0, -HEIGHT * 3.0 / 2.0);
    DrawString(GetCurrentX(), GetCurrentY(), HEIGHT, "JKLMNOPQR");
    AdjustPen(0, -HEIGHT * 3.0 / 2.0);
    DrawString(GetCurrentX(), GetCurrentY(), HEIGHT, "stuvwxyz");
    AdjustPen(0, -HEIGHT * 3.0 / 2.0);
    DrawString(GetCurrentX(), GetCurrentY(), HEIGHT, "lucasjeong");
}
