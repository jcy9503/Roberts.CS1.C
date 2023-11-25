/*
 * File: caltools.c
 * Version: 1.0
 * Last modified on Thu Nov 2023 by Lucas
 * --------------------------------------
 * This file provides a fully standard implementation of the
 * caltools.h interface that helps calculating calendar.
 */

#include "caltools.h"

string weekdayN[] =
{
    "Sunday", "Monday", "Tuesday", "Wednesday",
    "Thursday", "Friday", "Saturday"
};

string monthN[] =
{
    "January", "February", "March", "April", "May", "June", "July",
    "August", "September", "October", "November", "December", "Illegal Month"
};

string MonthName(monthT month)
{
    if(month >= MonthCount) return monthN[MonthCount];
    return monthN[month];
}

int MonthDays(monthT month, int year)
{
    switch(month)
    {
        case February:
            if(IsLeapYear(year)) return (29);
            return (28);
        case April: case June: case September: case November:
            return (30);
        default:
            return (31);
    }
}

weekdayT FirstDayOfMonth(monthT month, int year)
{
    weekdayT weekday;
    int i;

    weekday = Monday;
    
    if(year >= 1900)
    {
        for(i = 1900; i < year; ++i)
        {
            weekday = (weekday + 1) % DayCount;
            if(IsLeapYear(i)) weekday = (weekday + 1) % DayCount;
        }
        for(i = January; i < month; ++i)
        {
            weekday = (weekday + MonthDays(i, year)) % DayCount;
        }
    }
    else
    {
        for(i = 1900; i > year; --i)
        {
            weekday = (weekday + DayCount - 1) % DayCount;
            if(IsLeapYear(i)) weekday = (weekday + DayCount - 1) % DayCount;
        }
        for(i = January; i < month; ++i)
        {
            weekday = (weekday + MonthDays(i, year)) % DayCount;
        }
    }

    return (weekday);
}

bool IsLeapYear(int year)
{
    return (((year % 4 == 0) && (year % 100 != 0))
            || (year % 400 == 0));
}
