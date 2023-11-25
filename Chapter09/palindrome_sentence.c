/*
 * File: palindrome_sentence.c
 * ---------------------------
 * This program reads in strings and checks them
 * if they are palindrome or not.
 */

#include "genlib.h"
#include "strlib.h"
#include "simpio.h"

/* Function prototypes */

bool IsSentencePalindrome(string str);

/* Main program */

int main(void)
{
    string str;

    printf("This program checks for palindromes.\n");
    printf("Indicate the end of the input with a blank line.\n");

    while(TRUE)
    {
        printf("Enter a string: ");
        str = GetLine();
        if(str[0] == '\0') break;
        printf("That is ");
        if(!IsSentencePalindrome(str)) printf("not ");
        printf("a palindrome.\n");
    }
}

/*
 * Function: IsSentencePalindrome
 * Usage: if(IsSentencePalindrome(str))...
 * ---------------------------------------
 * Predicate function which checks for palindrome with
 * given string argument.
 */

bool IsSentencePalindrome(string str)
{
    string s1 = ConvertToLowerCase(str);
    string s2 = "";
    int i, n = StringLength(s1);

    for(i = 0; i < n; ++i)
    {
        if(s1[i] >= 'a' && s1[i] <= 'z')
        {
            s2 = Concat(s2, CharToString(s1[i]));
        }
    }

    n = StringLength(s2);
    for(i = 0; i < n / 2; ++i)
    {
        if(s2[i] != s2[n - 1 - i]) return (FALSE);
    }

    return (TRUE);
}
