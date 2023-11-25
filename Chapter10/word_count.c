/*
 * File: word_count.c
 * ------------------
 *  This program reads in a paragraph and counts
 *  the number of words.
 */

#include <ctype.h>

#include "genlib.h"
#include "strlib.h"
#include "simpio.h"
#include "scanner.h"

/* Function prototypes */

static int CountWords(string line);
static bool IsWord(string word);

/* Main program */

int main(void)
{
    string line;
    int result = 0;

    printf("This program counts the number of words in a paragraph.\n");
    printf("End the paragraph with a blank line.\n");
    while(TRUE)
    {
        line = GetLine();
        if(StringEqual(line, "")) break;
        result += CountWords(line);
    }
    printf("Number of words: %d\n", result);
}

/*
 * Function: CountWords
 * Usage: int count = CountWords(line);
 * ------------------------------------
 *  This function counts number of words in a line
 *  and returns it.
 */

static int CountWords(string line)
{
    int result = 0;
    string token;

    InitScanner(line);
    while(!AtEndOfLine())
    {
        token = GetNextToken();
        if(IsWord(token)) ++result;
    }

    return (result);
}

/*
 * Function: IsWord
 * Usage: if(IsWord(word))...
 * --------------------------
 *  Predicate function that returns TRUE if an argument
 *  string contains at lease one letter.
 */

static bool IsWord(string word)
{
    int i;

    for(i = 0; i < StringLength(word); ++i)
    {
        if(isalnum(IthChar(word, i))) return (TRUE);
    }

    return (FALSE);
}
