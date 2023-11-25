/*
 * File: morse.c
 * -------------
 *  This function reads in a line from user and translate
 *  it to Morse code. All of the punctuation marks will be
 *  ignored and blank will be newline character.
 */

#include <ctype.h>

#include "genlib.h"
#include "strlib.h"
#include "simpio.h"

/* morse[] -- morse code for corresponding character */
static string morse[] = 
{
    /* A */ "·-",
    /* B */ "-···",
    /* C */ "-·-·",
    /* D */ "-··",
    /* E */ "·",
    /* F */ "··-·",
    /* G */ "--·",
    /* H */ "····",
    /* I */ "··",
    /* J */ "·---",
    /* K */ "-·-",
    /* L */ "·-··",
    /* M */ "--",
    /* N */ "-·",
    /* O */ "---",
    /* P */ "·--·",
    /* Q */ "--·-",
    /* R */ "·-·",
    /* S */ "···",
    /* T */ "-",
    /* U */ "··-",
    /* V */ "···-",
    /* W */ "·--",
    /* X */ "-··-",
    /* Y */ "-·--",
    /* Z */ "--··",
};

/* Private Function prototypes */

static void Translate(string line);
static string TranslateChar(char ch);

/* Main program */

int main(void)
{
    string line;

    printf("This program translates a line into Morse code.\n");
    printf("Enter English text: ");
    line = GetLine();
    Translate(line);
}

/*
 * Function: Translate
 * Usage: Translate(line);
 * -----------------------
 *  This function translate string argument into Morse code.
 *  It prints out the result.
 */

static void Translate(string line)
{
    int i;
    
    for(i = 0; i < StringLength(line); ++i)
    {
        char ch = IthChar(line, i);
        if(ch == ' ') printf("\n");
        else if(isalpha(ch)) printf("%s ", TranslateChar(ch));
    }
    printf("\n");
}

/*
 * Function: TranslateChar
 * Usage: printf("%s ", TranslateChar(ch));
 * ----------------------------------------
 *  This function translate single character into Morse code.
 *  Returns string.
 */

static string TranslateChar(char ch)
{
    return (morse[tolower(ch) - 'a']);
}
