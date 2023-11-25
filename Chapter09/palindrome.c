/*
 * File: palindrome.c
 * ------------------
 * This program tests a predicate function which
 * checks string is a palindrome or not.
 */

#include "genlib.h"
#include "strlib.h"
#include "simpio.h"

/* Function prototypes */

bool IsPalindrome(string str);

/* Main program */

int main(void)
{
    string str;

    printf("This program tests palindrome function.\n");
    printf("INPUT: ");
    str = GetLine();
    if(IsPalindrome(str)) printf("TRUE\n");
    else printf("FALSE\n");
}

/*
 * Function: IsPalindrome
 * Usage: if(IsPalindrome(str))...
 * -------------------------------
 * Predicate function which checks whether argument
 * string is palindrome or not.
 */

bool IsPalindrome(string str)
{
    int n = StringLength(str);
    int i;

    for(i = 0; i < n / 2; ++i)
    {
        if(str[i] != str[n - 1 - i]) return (FALSE);
    }

    return (TRUE);
}
