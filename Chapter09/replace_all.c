/*
 * File: replace_all.c
 * -------------------
 * This program replaces all chunks of certain string
 * to given string and displays the result.
 */

#include "genlib.h"
#include "strlib.h"
#include "simpio.h"

/* Function prototypes */

string ReplaceAll(string str, string text, string rep);

/* Main program */

int main(void)
{
    string str, text, rep;

    printf("This program replaces all chunks of certain string\n");
    printf("to given string and displays the result.\n");
    printf("Base string: ");
    str = GetLine();
    printf("Search string: ");
    text = GetLine();
    printf("Replacement string: ");
    rep = GetLine();
    printf("Result: %s\n", ReplaceAll(str, text, rep));
}

/*
 * Function: ReplaceAll
 * Usage: string str = ReplaceAll(s, t, r);
 * ----------------------------------------
 * This function searches string chunks in base string
 * and replace them to given argument(3rd).
 */

string ReplaceAll(string str, string text, string rep)
{
    int str_len = StringLength(str);
    int txt_len = StringLength(text);
    int i, j;
    string result = "";

    for(i = 0; i < str_len;)
    {
        if(i > str_len - txt_len)
        {
            for(j = i; j < str_len; ++j)
            {
                result = Concat(result, CharToString(str[i]));
            }
            break;
        }

        if(str[i] != text[0])
        {
            result = Concat(result, CharToString(str[i++]));
            continue;
        }

        for(j = i; j < i + txt_len; ++j)
        {
            if(str[j] != text[j - i]) break;
        }
        if(j == i + txt_len)
        {
            result = Concat(result, rep);
            i += txt_len;
            continue;
        }
        result = Concat(result, CharToString(str[i++]));
    }

    return (result);
}
