/*
 * File: find_string.c
 * -------------------
 * This program demonstrates searching string
 * in the string feature.
 */

#include "genlib.h"
#include "strlib.h"
#include "simpio.h"

/* Function prototypes */

int MyFindString(string str, string text, int start);

/* Main program */

int main(void)
{
    string str, text;
    int start, idx;

    printf("This program demonstrates searching string in the string feature.\n");
    printf("Whole string: ");
    str = GetLine();
    printf("Searching: ");
    text = GetLine();
    printf("Start from?: ");
    start = GetInteger();
    switch(idx = MyFindString(str, text, start))
    {
        case -1: printf("Can't find value.\n"); break;
        default: printf("Index: %d\n", idx);
    }
}

/*
 * Function: MyFindString
 * Usage: int idx = MyFindString(str, txt, stt);
 * ---------------------------------------------
 * This function search given string in the string
 * and returns the start index of the result.
 * If there isn't any string, it returns -1.
 */

int MyFindString(string str, string text, int start)
{
    int str_len = StringLength(str);
    int txt_len = StringLength(text);
    int i, j;

    if(start < 0) start = 0;
    else if(start >= str_len) start = str_len - 1;
    if(str_len < txt_len + start) return (-1);

    for(i = start; i <= str_len - txt_len; ++i)
    {
        for(j = i; j < i + txt_len; ++j)
        {
            if(str[j] != text[j - i]) break;
        }
        if(j == i + txt_len) return (i);
    }
    return (-1);
}
