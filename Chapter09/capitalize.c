/*
 * File: capitalize.c
 * ------------------
 * This program reads in a line and convert it in a normal way.
 */

#include <ctype.h>
#include "genlib.h"
#include "strlib.h"
#include "simpio.h"

/* Function prototypes */

string Capitalize(string str);

/* Main program */

int main(void)
{
    string str;

    printf("This program reads in a line and convert in a normal way.\n");
    printf("INPUT: ");
    str = GetLine();
    printf("Converted: %s\n", Capitalize(str));
}

/*
 * Function: Capitalize
 * Usage: string str = Capitalize(s);
 * ----------------------------------
 * This function converts argument(string) to 
 * capitalized normal form.
 */

string Capitalize(string str)
{
    int i;
    string result = "";

    result = Concat(result, CharToString(toupper(str[0])));
    for(i = 1; str[i]; ++i)
    {
        result = Concat(result, CharToString(tolower(str[i])));
    }

    return result;
}
