/*
 * File: probability_board.c
 * -------------------------
 *  This program simulates probability board.
 *  Returned figure will be written in graphics.ps
 */

#include "genlib.h"
#include "graphics.h"
#include "gfigures.h"
#include "random.h"

/* 
 * Constants
 * ---------
 *  N_MARBLES -- Number of marbles.
 *  N_COLUMNS -- Number of columns.
 */

#define N_MARBLES 50
#define N_COLUMNS 10

/* Private function prototypes */

static void DropMarble(int col[]);
static void DrawBoard(int col[]);

/* Main program */

int main(void)
{
    int col[N_COLUMNS] = {0,};
    int i;

    printf("This program simulates probability board.\n");
    printf("Number of Marbles: %d\n", N_MARBLES);
    printf("Number of Columns: %d\n", N_COLUMNS);
    Randomize();
    for(i = 0; i < N_MARBLES; ++i)
    {
        DropMarble(col);
    }
    printf("Result: ");
    for(i = 0; i < N_COLUMNS; ++i)
    {
        printf("%d ", col[i]);
    }
    printf("\n");
    DrawBoard(col);
}

/*
 * Function: DropMarble
 * Usage: DropMarble(arr);
 * -----------------------
 *  Drop Marble in the hole at the top and store the
 *  result of the drop to column array.
 */

static void DropMarble(int col[])
{
    int cur = N_COLUMNS;
    int i;
    double r;

    for(i = 0; i < N_COLUMNS - 1; ++i)
    {
        r = RandomReal(-1.0, 1.0);
        if(r < 0) --cur;
        else ++cur;
    }

    ++col[cur / 2];
}

/*
 * Function: DrawBoard
 * Usage: DrawBoard(arr);
 * ----------------------
 *  Draws the result of dropping marbles with graphics.h
 */

static void DrawBoard(int col[])
{
    const double radius = 0.2;
    const double width = 0.5;
    double height, x, y;
    int max = 0;
    int i, j;

    for(i = 0; i < N_COLUMNS; ++i)
    {
        if(col[i] > max) max = col[i];
    }
    height = (max + 1) * radius * 2;
    
    InitGraphics();
    for(i = 0; i <= N_COLUMNS; ++i)
    {
        MovePen(i * width, 0.0);
        DrawLine(0.0, height);
    }
    for(i = 0; i < N_COLUMNS; ++i)
    {
        for(j = 0; j < col[i]; ++j)
        {
            x = width * i + width / 2.0;
            y = radius * j * 2.0 + radius;
            DrawCenteredCircle(x, y, radius);
        }
    }
}
