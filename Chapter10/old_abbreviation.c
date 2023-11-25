/*
 * File: old_abbreviation.c
 * --------------------------
 *  This program reads in a word and convert
 *  it with old-style abbreviation.
 */

#include <ctype.h>
#include "genlib.h"
#include "simpio.h"
#include "strlib.h"

/* Function prototypes */

static string OldStyleAbbreviation(string word);
static bool IsVowel(char ch);

/* Main program */

int main(void)
{
    string word;

    printf("This program reads in a word and convert it with\n");
    printf("old-style abbrivation.\n");
    printf("INPUT: ");
    word = GetLine();
    printf("Converted: %s\n", OldStyleAbbreviation(word));
}

/*
 * Function: OldStyleAbbreviation
 * Usage: string s = OldStyleAbbreviation(word);
 * ---------------------------------------------
 *  This function converts an argument(string) to
 *  its old-style abbreviation string.
 *  Applied rules:
 *  1.  The initial consonana string, up to the first
 *      vowel. If the original string begins with a vowel,
 *      use that vowel instead
 *  2.  The last letter in the word.
 *  3.  A period.
 */

static string OldStyleAbbreviation(string word)
{
    int len = StringLength(word);
    int i;
    string result = CharToString(IthChar(word, 0));

    if(!IsVowel(IthChar(word, 0)))
    {
        for(i = 1; i < len; ++i)
        {
            if(IsVowel(IthChar(word, i)))
            {
                result = Concat(result, SubString(word, 1, i - 1));
                break;
            }
        }
    }
    result = Concat(result, CharToString(IthChar(word, len - 1)));
    
    return (Concat(result, "."));
}

/*
 * Function: IsVowel
 * Usage: if(IsVowel(ch))...
 * -------------------------
 *  IsVowel returns TRUE if ch is a vowel. This function
 *  recognizes vowels in either upper or lower case.
 */

static bool IsVowel(char ch)
{
    switch(tolower(ch))
    {
        case 'a': case 'e': case 'i': case 'o': case 'u':
            return (TRUE);
        default:
            return (FALSE);
    }
}
