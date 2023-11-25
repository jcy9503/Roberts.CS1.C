/*
 * File: cyclic_cipher.c
 * ---------------------
 * This program runs cyclic cipher operation with
 * given string and number.
 */

#include "genlib.h"
#include "strlib.h"
#include "simpio.h"

/* Function prototypes */

string EncodeString(string str, int key);

/* Main program */

int main(void)
{
    int n;
    string str;

    printf("This program encodes a message using a cyclic cipher.\n");
    printf("Enter the numberic key: ");
    n = GetInteger();
    printf("Enter a message: ");
    str = GetLine();
    printf("Encoded message: %s\n", EncodeString(str, n));
}

/*
 * Function: EncodeString
 * Usage: string str = EncodeString(s, n);
 * ---------------------------------------
 * Encodes string with cyclic cipher method.
 */

string EncodeString(string str, int key)
{
    string result = "";
    const int v = 'z' - 'a' + 1;
    int i;

    for(i = 0; str[i]; ++i)
    {
        if(str[i] >= 'a' && str[i] <= 'z')
        {
            if(str[i] + key < 'a' || str[i] + key > 'z')
            {
                result = Concat(result, CharToString(str[i] + key - v));
            }
            else
            {
                result = Concat(result, CharToString(str[i] + key));
            }
        }
        else if(str[i] >= 'A' && str[i] <= 'Z')
        {
            if(str[i] + key < 'A' || str[i] + key > 'Z')
            {
                result = Concat(result, CharToString(str[i] + key - v));
            }
            else
            {
                result = Concat(result, CharToString(str[i] + key));
            }
        }
        else
        {
            result = Concat(result, CharToString(str[i]));
        }
    }
    return result;
}
