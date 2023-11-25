/*
 * File: calendar.c
 * ----------------
 * This program is used to generate a calendar for a year
 * entered by the user.
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include "caltools.h"

/* Function prototypes */

void GiveInstructions(void);
int GetYearFromUser(void);
void PrintCalendar(int year);
void PrintCalendarMonth(monthT month, int year);
void IndentFirstLine(weekdayT weekday);

/* Main program */

main()
{
    int year;

    GiveInstructions();
    year = GetYearFromUser();
    PrintCalendar(year);
}

/*
 * Function: GiveInstructions
 * Usage: GiveInstructions();
 * --------------------------
 * This procedure prints out instructions to the user.
 */

void GiveInstructions(void)
{
    printf("This program displays a calendar for a full\n");
    printf("year.  The year must not be before 1900.\n");
}

/*
 * Function: GetYearFromUser
 * Usage: year = GetYearFromUser();
 * --------------------------------
 * This function reads in a year from the user and returns
 * that value.  If the user enters a year before 1900, the
 * function gives the user another choice.
 */

int GetYearFromUser(void)
{
    int year;

    printf("Which year? ");
    year = GetInteger();

    return year;
}

/*
 * Function: PrintCalendar
 * Usage: PrintCalendar(year);
 * ---------------------------
 * This procedure prints a calendar for an entire year.
 */

void PrintCalendar(int year)
{
    monthT month;
    
    for(month = January; month < MonthCount; ++month)
    {
        PrintCalendarMonth(month, year);
        printf("\n");
    }
}

/*
 * Function: PrintCalendarMonth
 * Usage: PrintCalendarMonth(month, year);
 * ---------------------------------------
 * This procedure prints a calendar for the given month
 * and year.
 */

void PrintCalendarMonth(monthT month, int year)
{
    int weekday, nDays, day;

    printf("    %s %d\n", MonthName(month), year);
    printf(" Su Mo Tu We Th Fr Sa\n");
    nDays = MonthDays(month, year);
    weekday = FirstDayOfMonth(month, year);
    IndentFirstLine(weekday);
    for(day = 1; day <= nDays; ++day)
    {
        printf(" %2d", day);
        if(weekday == Saturday) printf("\n");
        weekday = (weekday + 1) % 7;
    }
    if(weekday != Sunday) printf("\n");
}

/*
 * Function: IndentFirstLine
 * Usage: IndentFirstLine(weekday);
 * --------------------------------
 * This procedure indents the first line of the calendar
 * by printing enough blank spaces to get to the position
 * on the line corresponding to weekday.
 */

void IndentFirstLine(weekdayT weekday)
{
    weekdayT i;

    for(i = Sunday; i < weekday; ++i)
    {
        printf("   ");
    }
}
