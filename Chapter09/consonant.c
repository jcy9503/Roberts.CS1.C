/*
 * File: consonant.c
 * -----------------
 * This program prints English consonants.
 */

#include <ctype.h>
#include "genlib.h"

/* Funtion prototypes */

bool IsConsonant(char ch);

/* Main program */

int main(void)
{
    char i;

    printf("The English consonants are:\n");
    for(i = 'A'; i <= 'Z'; ++i)
    {
        if(IsConsonant(i)) printf(" %c", i);
    }
    printf("\n");
}

/*
 * Function: IsConsonant
 * Usage: if(IsConsonant(ch))...
 * -----------------------------
 * Predicate function returning TRUE if argument
 * is consonant and FALSE otherwise.
 */

bool IsConsonant(char ch)
{
    switch(tolower(ch))
    {
        case 'a': case 'e': case 'i': case 'o': case 'u':
            return (FALSE);
        default: return (TRUE);
    }
}
