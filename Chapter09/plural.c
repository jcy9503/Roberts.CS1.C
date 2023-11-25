/*
 * File: plural.c
 * --------------
 * This program reads a word and change
 * it into plural form.
 */

#include <ctype.h>
#include "genlib.h"
#include "strlib.h"
#include "simpio.h"

/* Function prototypes */

string RegularPluralForm(string word);
bool IsConsonant(char ch);

/* Main program */

int main(void)
{
    string word;

    printf("This program reads a word and change it into plural form.\n");
    printf("Word?: ");
    word = GetLine();
    printf("Converted: %s\n", RegularPluralForm(word));
}

/*
 * Function: RegularPluralForm
 * Usage: string str = RegularPluralForm(w);
 * -----------------------------------------
 * This program converts given string argument to
 * its plural form and returns it.
 */

string RegularPluralForm(string word)
{
    int len = StringLength(word);
    char last_one;
    string converted, last_two;

    converted = ConvertToLowerCase(word);
    last_one = converted[len - 1];
    last_two = SubString(converted, len - 2, len - 1);

    if(last_one == 's' || last_one == 'x' || last_one == 'z' ||
            StringEqual(last_two, "ch") || StringEqual(last_two, "sh"))
    {
        return (Concat(word, "es"));
    }
    if(last_one == 'y' && IsConsonant(last_two[0]))
    {
        return (Concat(SubString(word, 0, len - 2), "ies"));
    }
    return (Concat(word, "s"));
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
