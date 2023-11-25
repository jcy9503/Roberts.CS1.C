/*
 * File: countlet.c
 * ----------------
 *  This program counts the occurrences of individual letters
 *  that appear in text read in from the use. This program
 *  might be useful as a tool in solving cryptograms.
 */

#include <ctype.h>

#include "genlib.h"
#include "strlib.h"
#include "simpio.h"

/*
 * Constants
 * ---------
 *  MAX_LINES -- Maximum number of input lines
 *  N_LETTERS -- Number of letters
 */

#define MAX_LINES 100
#define N_LETTERS 26

/* Private function prototypes */

static void CountLetters(int letterCounts[]);
static void CountLettersInString(string str, int letterCounts[]);
static void RecordLetter(char ch, int letterCounts[]);
static void DisplayLetterCounts(const int letterCounts[]);
static int LetterIndex(char ch);
static void ClearIntegerArray(int array[], int n);

/* Main program */

int main(void)
{
    int letterCounts[N_LETTERS];

    printf("This program counts letter frequencies.\n");
    printf("Enter a blank line to signal end of input.\n");
    ClearIntegerArray(letterCounts, N_LETTERS);
    CountLetters(letterCounts);
    DisplayLetterCounts(letterCounts);
}

/*
 * Function: CountLetters
 * Usage: CountLetters(letterCounts);
 * ----------------------------------
 *  This function updates the values in the letterCounts array
 *  by scanning through a series of strings read in from the
 *  user. A blank line is used to signal the end of the input
 *  test.
 */

static void CountLetters(int letterCounts[])
{
    string line;

    while(TRUE)
    {
        line = GetLine();
        if(StringLength(line) == 0) break;
        CountLettersInString(line, letterCounts);
    }
}

/*
 * Function: CountLettersInString
 * Usage: CountLettersInString(str, letterCounts);
 * -----------------------------------------------
 *  This function updates the values in the letterCounts array for
 *  each character in the string str.
 */

static void CountLettersInString(string str, int letterCounts[])
{
    int i;

    for(i = 0; i < StringLength(str); ++i)
    {
        RecordLetter(IthChar(str, i), letterCounts);
    }
}

/*
 * Function: RecordLetter
 * Usage: RecordLetter(ch, letterCounts);
 * --------------------------------------
 *  This function records the fact that the character ch has
 *  been seen by incrementing the appropriate element in the
 *  letterCounts array. Non-letters are ignored.
 */

static void RecordLetter(char ch, int letterCounts[])
{
    int index;
    
    index = LetterIndex(ch);
    if(index != -1) ++letterCounts[index];
}

/*
 * Function: DisplayLetterCounts
 * Usage: DisplayLetterCounts(letterCounts);
 * -----------------------------------------
 *  This function displays the letter frequency table, leaving
 *  out any letters that did not occur.
 */

static void DisplayLetterCounts(const int letterCounts[])
{
    char ch;
    int num;

    for(ch = 'A'; ch <= 'Z'; ++ch)
    {
        num = letterCounts[LetterIndex(ch)];
        if(num != 0) printf("%c  %4d\n", ch, num);
    }
}

/*
 * Function: LetterIndex
 * Usage: Index = LetterIndex(ch);
 * -------------------------------
 *  This function converts a character into the appropriate index
 *  for use with the letterCounts array. In this implementation,
 *  LetterIndex converts characters in either case to an integer
 *  in the range 0 to 25. If ch is not a valid letter, LetterIndex
 *  returns -1. Clients should check for a -1 return value unless
 *  they are able to guarantee that the argument is a letter.
 */

int LetterIndex(char ch)
{
    if(isalpha(ch))
    {
        return (toupper(ch) - 'A');
    }
    return (-1);
}

/*
 * Function: ClearIntegerArray
 * Usage: ClearIntegerArray(array, n);
 * -----------------------------------
 *  This function sets the first n elements in the array to 0.
 */

static void ClearIntegerArray(int array[], int n)
{
    int i;

    for(i = 0; i < n; ++i) array[i] = 0;   
}
