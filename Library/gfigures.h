/*
 * File: gfigures.h
 * -------------
 * Using "graphics.h", there are several difficulties for using
 * functions within the library for clients. It contains convenient
 * functions using "graphics.h"
 */

#ifndef _gfigures_h
#define _gfigures_h

/*
 * Function: DrawBox
 * Usage: DrawBox(x, y, width, height);
 * ------------------------------------
 * This function draws a rectangle of the given width and
 * height with its lower left corner at (x, y).
 */

void DrawBox(double x, double y, double width, double height);

/*
 * Function: DrawCenteredBox
 * Usage: DrawCenteredBox(x, y, width, height);
 * --------------------------------------------
 * This function draws a rectangle of the given width and
 * height with its center at (x, y).
 */

void DrawCenteredBox(double x, double y, double width, double height);

/*
 * Function: DrawCenteredCircle
 * Usage: DrawCenteredCircle(x, y, r);
 * -----------------------------------
 * This function draws a circle of the given radius
 * with its center at (x, y).
 */

void DrawCenteredCircle(double x, double y, double r);

/*
 * Function: AdjustPen
 * Usage: AdjustPen(dx, dy);
 * -------------------------
 * This procedure adjusts the current point by moving it
 * dx inches from its current x coordinate and dy inches
 * from its current y coordinate. As with MovePen, no
 * line is actually drawn.
 */

void AdjustPen(double dx, double dy);

/*
 * Function: DrawLineTo
 * Usage: DrawLineTo(x, y);
 * ------------------------
 * This function is like DrawLine, except that it uses the
 * absolute coordinates of the endpoint rather than the relative
 * displacement from the current point.
 */

void DrawLineTo(double x, double y);

/*
 * Function: DrawGrid
 * Usage: DrawGird(x, y, width, height, columns, rows);
 * ----------------------------------------------------
 * DrawGrid draws rectangles arranged in a two-dimensional
 * grid. As always, (x, y) specifies the lower left corner
 * of the figure.
 */

void DrawGrid(double x, double y, double width, double height,
        int columns, int rows);

/*
 * Function: DrawTriangle
 * Usage: DrawTriangle(x, y, base, height);
 * ----------------------------------------
 * This function draws an isosceles triangle (i.e., one with
 * two equal sides) with a horizontal base. The coordinate of
 * the left endpoint of the base is (x, y), and the triangle
 * has the indicated base length and height. If height is
 * positive, the triangle points upward. If height is negative,
 * the triangle points downward.
 */

void DrawTriangle(double x, double y, double base, double height);

/*
 * Function: DrawCrossedBox
 * Usage: DrawCrossedBox(x, y, width, height);
 * -------------------------------------------
 * This function draws a crossed box other than have same effect
 * using DrawBox function.
 */

void DrawCrossedBox(double x, double y, double width, double height);

/*
 * Function: DrawRoundedBox
 * Usage: DrawRoundedBox(x, y, width, height, r);
 * ----------------------------------------------
 * This function draws a rounded box.
 * If user inputs r greater than width / 2.0 or height / 2.0,
 * it prints error message and stop.
 */

void DrawRoundedBox(double x, double y, double width, double height, double radius);

/*
 * Function: DrawCharacter
 * Usage: DrawCharacter(x, y, height, 'A');
 * ------------------------------------------
 * This function draws a character.
 * It draws Upper character only.
 * Draw character's width is always height / 2.0.
 */

void DrawCharacter(double x, double y, double height, char ch);

/*
 * Function: DrawString
 * Usage: DrawString(x, y, height, str);
 * -----------------------------
 * This function draws a string.
 */

void DrawString(double x, double y, double height, const char* str);

/*
 * Function: DrawShadedBox
 * Usage: DrawShadedBox(x, y, width, height, distance_line);
 * ---------------------------------------------------------
 * This function draws a shaded box whose interior is
 * shaded by closely spaced diagonal lines throughout
 * the entire figure. Fifth parameter indicates the
 * distance between each of the shading lines, measured
 * along the edges of the box rather than diagonally.
 * The shading seperation parameter should be an integer
 * measured in points, a unit of measure favored by printers
 * and typesetters that is equal to 1/72 of an inch.
 */

void DrawShadedBox(double x, double y, double width, double height, int point);

#endif
