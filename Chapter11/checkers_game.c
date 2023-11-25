/*
 * File: checkers_game.c
 * ---------------------
 *  This program initializes checkerboard and displays it.
 */

#include "genlib.h"

/* Private function prototypes */

static void InitCheckerboard(char board[8][8]);
static void DisplayCheckerboard(char board[8][8]);

/* Main program */

int main(void)
{
    char board[8][8];

    InitCheckerboard(board);
    DisplayCheckerboard(board);
}

/*
 * Function: InitCheckerboard
 * Usage: InitCheckerboard(board);
 * -------------------------------
 *  This function initializes checkerboard with character value.
 */

static void InitCheckerboard(char board[8][8])
{
    int i, j;

    for(i = 0; i < 8; ++i)
    {
        for(j = 0; j < 8; ++j)
        {
            if((i + j) % 2 == 0)
            {
                board[i][j] = ' ';
            }
            else
            {
                if(i < 3) board[i][j] = 'b';
                else if(i < 5) board[i][j] = '-';
                else board[i][j] = 'r';
            }
        }
    }
}

/*
 * Function: DisplayCheckerboard
 * Usage: DisplayCheckerboard(board);
 * ----------------------------------
 *  This function displays current state of the checkerboard.
 */

static void DisplayCheckerboard(char board[8][8])
{
    int i, j;

    for(i = 0; i < 8; ++i)
    {
        for(j = 0; j < 8; ++j)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
