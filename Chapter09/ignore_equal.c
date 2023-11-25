/*
 * File: ignore_equal.c
 * --------------------
 * This program tests function that reads 2 strings
 * and compares those.
 * Comparing should be implemented in ignoring
 * each character's case.
 */

#include "genlib.h"
#include "strlib.h"
#include "simpio.h"

/* Function prototypes */

bool EqualIgnoringCase(string str1, string str2);

/* Main program */

int main(void)
{
    string s1, s2;

    printf("This program compares 2 strings.\n");
    printf("INPUT #1: ");
    s1 = GetLine();
    printf("INPUT #2: ");
    s2 = GetLine();

    if(EqualIgnoringCase(s1, s2)) printf("TRUE\n");
    else printf("FALSE\n");
}

/*
 * Function: EqualIgnoringCase
 * Usage: if(EqualIgnoringCase(s1, s2))...
 * ---------------------------------------
 * Predicate function that returns result of comparing
 * two strings ignoring each charactere's case.
 */

bool EqualIgnoringCase(string str1, string str2)
{
    string s1 = ConvertToLowerCase(str1);
    string s2 = ConvertToLowerCase(str2);
    
    return (StringEqual(s1, s2));
}
