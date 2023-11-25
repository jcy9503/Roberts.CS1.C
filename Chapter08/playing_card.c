/*
 * File: playing_card.c
 * --------------------
 * This program generates random card
 * of the deck.
 */

#include "genlib.h"
#include "strlib.h"
#include "random.h"

/*
 * Constants
 * ---------
 * N_TRIALS -- number of trials.
 */

#define N_TRIALS    10

/* 
 * Global variables
 * ----------------
 * number[] -- array of string which holds the name of number.
 * suit[] -- array of string which holds the name of suit.
 */

string number[] = 
{
    "Ace",
    "2", "3", "4", "5", "6", "7", "8", "9", "10",
    "Jack", "Queen", "King"
};
string suit[] = 
{
    "Clubs", "Diamonds", "Hearts", "Spades"
};

/* Function prototypes */

string RandomCardSuit(void);
string RandomCardNumber(void);

/* Main program */

main()
{
    int i;

    printf("This program generates random card.\n");
    Randomize();
    for(i = 0; i < N_TRIALS; ++i)
    {
        printf("#%3d: %s of %s\n", i + 1, RandomCardNumber(), RandomCardSuit());
    }
}

/*
 * Function: RandomCardSuit
 * Usage: string s = RandomCardSuit();
 * -----------------------------------
 * Returns random card suit name by string.
 */

string RandomCardSuit(void)
{
    return (suit[RandomInteger(0, 3)]);
}

/*
 * Function: RandomCardNumber
 * Usage: string s = RandomCardNumber();
 * -------------------------------------
 * Returns random card number name by string.
 */

string RandomCardNumber(void)
{
    return (number[RandomInteger(0, 12)]);
}
