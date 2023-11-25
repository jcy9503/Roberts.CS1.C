#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main()
{
    int year;
    bool isLeapYear;

    printf("Program to determine whether a year is a leap year.\n");
    printf("What year? ");
    year = GetInteger();
    isLeapYear = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400) == 0;

    if(isLeapYear)
    {
        printf("%d is a leap year.\n", year);
    }
    else
    {
        printf("%d is not a leap year.\n", year);
    }

    return 0;
}
