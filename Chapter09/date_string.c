/*
 * File: date_string.c
 * -------------------
 * This program makes date string with 3 given
 * integers(day, month, year).
 */

#include "genlib.h"
#include "strlib.h"
#include "simpio.h"

/* Function prototypes */

string DateString(int day, int month, int year);

/* Main program */

int main(void)
{
    int day, month, year;

    printf("This program makes date string with 3 given integers.\n");
    printf("Day: ");
    day = GetInteger();
    printf("Month: ");
    month = GetInteger();
    printf("Year: ");
    year = GetInteger();

    printf("Converted string: %s\n", DateString(day, month, year));
}

/*
 * Function: DateString
 * Usage: string s = DateString(d, m, y);
 * --------------------------------------
 * This function returns date string with 3
 * given argument integers.
 */

string DateString(int day, int month, int year)
{
    string mon[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug",
    "Sep", "Oct", "Nov", "Dec"};
    string result = IntegerToString(day);
    result = Concat(Concat(Concat(Concat(result, "-"), mon[month - 1]), "-"), IntegerToString(year % 100));

    return (result);
}
