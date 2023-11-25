/*
 * File: scrabble_score.c
 * ----------------------
 * This program reads a word from user and prints
 * corresponding score for the word.
 */

#include "genlib.h"
#include "strlib.h"
#include "simpio.h"

/*
 * Global variables
 * ----------------
 * score[] -- an array of integers indicating score of each uppercase value.
 */

int score[] =
{
    1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10
};
//  A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P,  Q, R, S, T, U, V, W, X, Y,  Z

/* Function prototypes */

int ScrabbleScore(string word);

/* Main program */

int main(void)
{
    string word = "";

    printf("This program tests the ScrabbleScore function.\n");
    printf("Enter words, ending with a blank line.\n");
    while(TRUE)
    {
        printf("Word: ");
        word = GetLine();
        if(StringEqual(word, "")) break;
        printf("The basic score for '%s' is %d.\n", word, ScrabbleScore(word));
    }
}

/*
 * Function: ScrabbleScore
 * Usage: int score = ScrabbleScore(word);
 * ---------------------------------------
 * This function calculates scrabble score from given word and returns it.
 */

int ScrabbleScore(string word)
{
    int i, result = 0;

    for(i = 0; word[i]; ++i)
    {
        if(word[i] < 'A' || word[i] > 'Z') continue;
        result += score[word[i] - 'A'];
    }

    return result;
}
