/*
 * File: fill.c
 * ------------
 *  This file implements the fill margin print package.
 *  See the interface description in fill.h for details.
 */

#include <ctype.h>

#include "fill.h"
#include "strlib.h"
#include "scanner.h"

static int margin = 65;
static int cur = 0;

/*
 * Function: SetFillMargin
 * Usage: SetFillMargin(margin);
 * -----------------------------
 *  Setting margin to new value.
 */

void SetFillMargin(int value)
{
    margin = value;
}

/*
 * Function: PrintFilledString
 * Usage: PrintFilledString(str);
 * ------------------------------
 *  Prints out str with margin.
 *  Prints start at cur value.
 */

void PrintFilledString(string str)
{
    string token;
    int len;

    InitScanner(str);
    ReturnUppercaseTokens(FALSE);
    IgnoreSpace(FALSE);
    ReturnAlphaNumTokens(FALSE);

    while(!AtEndOfLine())
    {
        token = GetNextToken();
        len = StringLength(token);
        if(cur == 0 && len > margin)
        {
            printf("%s\n", token);
        }
        else if(cur == 0 && isspace(IthChar(token, 0)))
        {
        }
        else if(cur + len > margin)
        {
            if(isspace(IthChar(token, 0)))
            {
                printf("\n");
                cur = 0;
            }
            else
            {
                printf("\n%s", token);
                cur = len;
            }
        }
        else
        {
            printf("%s", token);
            cur += len;
        }
    }
}
