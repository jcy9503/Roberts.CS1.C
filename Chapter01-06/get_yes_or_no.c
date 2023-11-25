/*
 * File: get_yes_or_no.c
 * ---------------------
 * This program reads string from user and judge the input
 * is legal or not.
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include "strlib.h"

/* Function prototypes */

void PlayOneGame(void);
bool GetYesOrNo(string s);

/* Main program */

main()
{
    while(TRUE)
    {
        PlayOneGame();
        if(!GetYesOrNo("Would you like to play again? ")) break;
    }
}

/*
 * Function: PlayOneGame
 * Usage: PlayOneGame();
 * ---------------------
 * This function is empty.
 */

void PlayOneGame(void)
{    
    printf(". . . play the game . . .\n");
}

/*
 * Function: GetYesOrNo
 * Usage: if(GetYesOrNo("Type Yes?")) ...
 * --------------------------------------
 * This function judges if the user typed legal value
 * "yes" or "no".
 */

bool GetYesOrNo(string s)
{
    string input;

    while(TRUE)
    {
        printf("%s", s);
        input = GetLine();
        if(StringEqual(input, "yes")) return TRUE;
        else if(StringEqual(input, "no")) return FALSE;
        else printf("Please answer yes or no.\n");
    }
}
