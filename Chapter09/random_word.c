/*
 * File: random_word.c
 * -------------------
 * This program generates random words.
 */

#include "genlib.h"
#include "random.h"

/*
 * Constants
 * ---------
 * N_TRIALS -- number of trials
 * MIN_LETTERS -- number of minimum amount of letters for each word
 * MAX_LETTERS -- number of maximum amount of letters for each word
 */

#define N_TRIALS    5
#define MIN_LETTERS 2
#define MAX_LETTERS 8

/* Function prototypes */

void PrintRandomWord(void);

/* Main program */

int main(void)
{
    int i;

    printf("This program generates %d random words.\n", N_TRIALS);
    Randomize();
    for(i = 0; i < N_TRIALS; ++i) PrintRandomWord();
}

/*
 * Function: PrintRandomWord
 * Usage: PrintRandomWord();
 * -------------------------
 * This function prints a random word with given constants.
 */

void PrintRandomWord(void)
{
    int n = RandomInteger(MIN_LETTERS, MAX_LETTERS), i;
    for(i = 0; i < n; ++i)
    {
        printf("%c", RandomInteger('A', 'Z'));
    }
    printf("\n");
}
