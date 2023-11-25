/*
 * File: caltools.h
 * Version: 1.0
 * Last modified on Thu Nov 2 2023 by lucas
 * ----------------------------------------
 * This interface provides useful tools about
 * calendar.
 */

#ifndef _caltools_h
#define _caltools_h

#include "genlib.h"
#include "strlib.h"

/*
 * Constants:
 * ----------
 * Days of the week are represented by the integers 0-6.
 * Months of the year are identified by the integers 1-12;
 * because this numeric representation for months is in
 * common use, no special constants are defined.
 */

typedef enum
{
    Sunday, Monday, Tuesday, Wednesday, 
    Thursday, Friday, Saturday, DayCount
} weekdayT;

typedef enum
{
    January, February, March, April, May, June, July,
    August, September, October, November, December, MonthCount
} monthT;

/*
 * Function: MonthName
 * Usage: string name = MonthName(m);
 * ----------------------------------
 * This function converts a numeric month in the range 1-12
 * into the string name for that month.
 */

string MonthName(monthT month);

/*
 * Function: MonthDays
 * Usage: int day = MonthDays(m, y);
 * ---------------------------------
 * This function returns the number of days in the indicated
 * month and year. The year is required to handle leap years.
 */

int MonthDays(monthT month, int year);

/*
 * Function: FirstDayOfMonth
 * Usage: int day = FirstDayOfMonth(m, y);
 * ---------------------------------------
 * This function returns the day of the week on which the
 * indicated month begins. This program simply counts
 * forward from January 1, 1900, which was a Monday.
 */

weekdayT FirstDayOfMonth(monthT month, int year);

/*
 * Function: IsLeapYear
 * Usage: if(IsLeapYear(year))...
 * ------------------------------
 * This function returns TRUE if year is a leap year.
 */

bool IsLeapYear(int year);

#endif
