/*
 * File: longest_word.c
 * --------------------
 *  This program reads in a line and returns
 *  the longest word within the line.
 */

#include <ctype.h>

#include "genlib.h"
#include "strlib.h"
#include "simpio.h"
#include "scanner.h"

/* Function prototypes */

static string LongestWord(string line);
static bool IsWord(string word);
static string WordFilter(string word);

/* Main program */

int main(void)
{
    string line;

    printf("This program reads in a line and returns\n");
    printf("the longest word within the line.\n");
    printf("Enter a line:\n");
    line = GetLine();
    printf("The longest word is \"%s\".\n", LongestWord(line));
}

/*
 * Function: LongestWord
 * Usage: string str = LongestWord(line);
 * --------------------------------------
 *  Returns the longest word from argument string.
 */

static string LongestWord(string line)
{
    string longest, token;
    int max_len = -1, len;

    InitScanner(line);
    while(!AtEndOfLine())
    {
        token = GetNextToken();
        if(IsWord(token))
        {
            token = WordFilter(token);
            len = StringLength(token);
            if(len > max_len)
            {
                max_len = len;
                longest = token;
            }
        }
    }

    return longest;
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

/*
 * Function: WordFilter
 * Usage: string token = WordFilter(word);
 * ---------------------------------------
 *  Returns true word form of argument string.
 *  It doesn't count any punctuation mark in sides.
 */

static string WordFilter(string word)
{
    string result = "";
    int i, end = 0;
    bool start = FALSE;

    for(i = StringLength(word) - 1; i >= 0; --i)
    {
        if(isalnum(IthChar(word, i)))
        {
            end = i;
            break;
        }
    }

    for(i = 0; i <= end; ++i)
    {
        if(isalnum(IthChar(word, i)))
        {
            if(!start) start = TRUE;
            result = Concat(result, CharToString(IthChar(word, i)));
        }
        else if(start)
        {
            result = Concat(result, CharToString(IthChar(word, i)));
        }
    }

    return result;
}
