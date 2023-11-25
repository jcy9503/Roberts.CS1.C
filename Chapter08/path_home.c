/*
 * File: path_home.c
 * -----------------
 * This program shows the path from upper right
 * corner of the grid to lower left corner of the
 * grid. The path is changing time to time but
 * maintains the shortest way.
 */

#include "genlib.h"
#include "graphics.h"
#include "lucas.h"
#include "random.h"

/*
 * Constants
 * ---------
 * N_ROWS -- number of rows of the grid.
 * N_COLUMNS -- number of columns of the grid.
 * WIDTH -- width of the path.
 */

#define N_ROWS      9
#define N_COLUMNS   15
#define GRID_SIZE   0.2
#define WIDTH       0.01

/* Function prototypes */

void DrawMap(double x, double y);
void DrawPath(double x, double y);

/* Main program */

main()
{
    printf("This program shows the path of the map.\n");

    InitGraphics();
    Randomize();
    DrawMap(0.0, 0.0);
    DrawPath(0.0, 0.0);
}

/*
 * Function: DrawGrid
 * Usage: DrawGrid();
 * ------------------
 * Draws grid of the map.
 */

void DrawMap(double x, double y)
{
    DrawGrid(x, y, GRID_SIZE, GRID_SIZE, N_COLUMNS, N_ROWS);
}

/*
 * Function: DrawPath
 * Usage: DrawPath();
 * ------------------
 * Draws the path on the grid.
 */

void DrawPath(double x, double y)
{
    int curX = N_COLUMNS;
    int curY = N_ROWS;
    int dir;
    int move[][2] = {{-1, 0}, {0, -1}};
    
    while(curX != 0 || curY != 0)
    {
        printf("curX: %2d, curY: %2d\n", curX, curY);
        if(curX == 0) 
        {
            dir = 1;
        }
        else if(curY == 0) 
        {
            dir = 0;
        }
        else 
        {
            dir = RandomInteger(0, 1);
        }

        if(dir == 0)
        {
            MovePen(x + curX * GRID_SIZE, y + curY * GRID_SIZE + WIDTH);
            DrawLine(move[dir][0] * GRID_SIZE - WIDTH, move[dir][1] * GRID_SIZE);
            MovePen(x + curX * GRID_SIZE, y + curY * GRID_SIZE - WIDTH);
            DrawLine(move[dir][0] * GRID_SIZE - WIDTH, move[dir][1] * GRID_SIZE);
        }
        else
        {
            MovePen(x + curX * GRID_SIZE + WIDTH, y + curY * GRID_SIZE);
            DrawLine(move[dir][0] * GRID_SIZE, move[dir][1] * GRID_SIZE - WIDTH);
            MovePen(x + curX * GRID_SIZE - WIDTH, y + curY * GRID_SIZE);
            DrawLine(move[dir][0] * GRID_SIZE, move[dir][1] * GRID_SIZE - WIDTH);
        }
        curX += move[dir][0];
        curY += move[dir][1];
    }
}
