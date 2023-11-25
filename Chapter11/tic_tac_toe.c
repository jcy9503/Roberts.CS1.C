/*
 * File: tic_tac_toe.c
 * -------------------
 *  This program prints who has won the tic-tac-toe game
 *  in current state of the board.
 */

#include "genlib.h"
#include "strlib.h"
#include "simpio.h"

/* Private function prototypes */

static bool IsWinningPosition(char board[3][3], char player);

/* Main program */

int main(void)
{
    char board[3][3];
    string line;
    int i, j;
    char ch;

    printf("This program tests the IsWinningPosition function.\n");
    printf("Enter the state of the board, row by row.\n\n");
    for(i = 0; i < 3; ++i)
    {
        line = GetLine();
        if(StringLength(line) != 3) Error("Input is invalid.");
        for(j = 0; j < 3; ++j)
        {
            ch = IthChar(line, j);
            if(ch != 'O' && ch != 'X' && ch != '-')
            {
                Error("Input is invalid.");
            }
            board[i][j] = ch;
        }
    }
    
    printf("\n");
    if(IsWinningPosition(board, 'X')) printf("X");
    else printf("O");
    printf(" has won\n");
}

/*
 * Function: IsWinningPosition
 * Usage: if(IsWinningPosition(board, 0))...
 * -----------------------------------------
 *  Returns whether the player(input) has won the game
 *  or not.
 */

static bool IsWinningPosition(char board[3][3], char player)
{
    int i, j;
    bool flag;

    if(player != 'O' && player != 'X') Error("Invalid player info.");

    // Check rows
    for(i = 0; i < 3; ++i)
    {
        flag = TRUE;
        for(j = 0; j < 3; ++j)
        {
            if(board[i][j] != player) flag = FALSE;
        }
        if(flag) return (TRUE);
    }

    // Check columns
    for(j = 0; j < 3; ++j)
    {
        flag = TRUE;
        for(i = 0; i < 3; ++i)
        {
            if(board[i][j] != player) flag = FALSE;
        }
        if(flag) return (TRUE);
    }

    // Check diagonals
    for(i = 0, j = 0; i < 3; ++i, ++j)
    {
        flag = TRUE;
        if(board[i][j] != player) flag = FALSE;
    }
    if(flag) return (TRUE);
    for(i = 0, j = 2; i < 3; ++i, --j)
    {
        flag = TRUE;
        if(board[i][j] != player) flag = FALSE;
    }
    if(flag) return (TRUE);

    return (FALSE);
}
