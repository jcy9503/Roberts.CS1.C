/*
 * File: coin_toss.c
 * -----------------
 * This program plays game tossing a coin.
 * When 3 consecutive heads are tossed,
 * game is over and program will be teminated.
 */

#include "genlib.h"
#include "random.h"
#include "strlib.h"

/*
 * Global variables
 * ----------------
 * coin[] - array of string which indicates coin's status.
 */

string coin[] =
{
    "heads",
    "tails"
};

/* Main program */

main()
{
    int i = 0, flag = 0, result;

    printf("This program plays game tossing a coin.\n");
    printf("When 3 consecutive heads are tossed, game is over.\n");
    Randomize();
    while(TRUE)
    {
        ++i;
        result = RandomInteger(0, 1);
        if(result == 0) ++flag;
        else flag = 0;
        printf("%s\n", coin[result]);
        if(flag == 3)
        {
            printf("It took %d flips to get heads 3 consecutive times.\n", i);
            break;
        }
    }
}
