/*
 * File: line_graph.c
 * ------------------
 *  This program reads a set of coordinates(x, y) and
 *  prints out corresponding line graph.
 */

#include "genlib.h"
#include "strlib.h"
#include "scanner.h"
#include "simpio.h"
#include "graphics.h"
#include "gfigures.h"

/*
 * Constants
 * ---------
 *  N_POINTS -- Number of maximum points.
 */

#define N_POINTS 100

/* Private function prototypes */

static int ReadData(double x[], double y[]);
static void DrawLineGraph(double x[], double y[], int n);

/* Main program */

int main(void)
{
    int num;
    double x[N_POINTS];
    double y[N_POINTS];

    printf("This program prints line graph with input data.\n");
    printf("Input data(x, y): \n");
    num = ReadData(x, y);
    DrawLineGraph(x, y, num);
}

/*
 * Function: ReadData
 * Usage: num = ReadData(x, y);
 * ----------------------------
 *  This function reads data from user and fill in the
 *  two array which contains points' x and y coordinates.
 *  Blank line indicates the end of the data.
 *  Returns the number of the data.
 */

static int ReadData(double x[], double y[])
{
    string str;
    int i;
    
    for(i = 0; i < N_POINTS; ++i)
    {
        str = GetLine();
        if(StringLength(str) == 0) break;
        InitScanner(str);
        IgnoreSpace(TRUE);
        x[i] = StringToReal(GetNextToken());
        y[i] = StringToReal(GetNextToken());
    }

    return (i);
}

/*
 * Function: DrawLineGraph
 * Usage: DrawLineGraph(x, y, n);
 * ------------------------------
 *  Draws a line graph using graphics.h and gfigures.h
 */

static void DrawLineGraph(double x[], double y[], int n)
{
    int i;
    const double radius = 0.01;

    InitGraphics();
    for(i = 0; i < n; ++i)
    {
        DrawCenteredCircle(x[i], y[i], radius);
    }
    MovePen(x[0], y[0]);
    for(i = 1; i < n; ++i)
    {
        DrawLineTo(x[i], y[i]);
    }
}
