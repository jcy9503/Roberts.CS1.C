/*
 * File: reverse_sentence.c
 * ------------------------
 *  This program reads in a sentence and prints
 *  it backward in word unit.
 */

#include <ctype.h>

#include "genlib.h"
#include "strlib.h"
#include "simpio.h"

/* Function prototypes */

static string ReverseLine(string line);
static string PolishWord(string word);

/* Main program */

int main(void)
{
    string line;

    printf("Enter a line: ");
    line = GetLine();
    printf("%s\n", ReverseLine(line));
}

/*
 * Function: ReverseLine
 * Usage: string str = ReverseLine(line);
 * --------------------------------------
 *  This function takes a string as argument and reverses
 *  it with word unit.
 *  It omits out all punctuation marks.
 */

static string ReverseLine(string line)
{
    string result = "";
    int i, len = StringLength(line);
    int start = len - 1;
    bool word = FALSE;

    for(i = len - 1; i >= 0; --i)
    {
        if(isspace(IthChar(line, i)) && word)
        {
            result = Concat(result, PolishWord(SubString(line, i + 1, start)));
            result = Concat(result, " ");
            start = i - 1;
            word = FALSE;
        }
        else if(isalnum(IthChar(line, i)))
        {
            word = TRUE;
        }
    }
    if(start >= 0)
        result = Concat(result, PolishWord(SubString(line, 0, start)));

    return result;
}

/*
 * Function: PolishWord
 * Usage: string str = PolishWord(word);
 * -------------------------------------
 *  This function takes a string as argument and
 *  polishes it. It omits all but alphanumeric letters.
 */

static string PolishWord(string word)
{
    string result = "";
    int i;

    for(i = 0; i < StringLength(word); ++i)
    {
        if(isalnum(IthChar(word, i)))
        {
            result = Concat(result, CharToString(IthChar(word, i)));
        }
    }

    return result;
}
