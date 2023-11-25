/*
 * File: c2ftable.c
 * ----------------
 * This program illustrates the use of functions by generating
 * a table of Celsius to Fahrenheit conversions or opposite.
 */

#include <stdio.h>
#include "genlib.h"

/*
 * Constants
 * ---------
 * LowerLimit -- Starting value for temperature table
 * UpperLimit -- Final value for temperature table
 * StepSize   -- Step size between table entries
 */

#define LowerLimit  32
#define UpperLimit  100
#define StepSize    2

/* Function prototypes */

double CelsiusToFahrenheit(double c);
double FahrenheitToCelsius(double f);

/* Main program */

main()
{
    int f;

    printf("Fahrenheit to Celsius table.\n");
    printf("  F    C\n");
    for(f = LowerLimit; f <= UpperLimit; f += StepSize)
    {
        printf("%3d  %3.1f\n", f, FahrenheitToCelsius(f));
    }
}

/*
 * Function: CelsiusToFahrenheit
 * Usage: f = CelsiusToFahrenheit(c);
 * ----------------------------------
 * This function returns the Fahrenheit equivalent of the Celsius
 * temperature c.
 */

double CelsiusToFahrenheit(double c)
{
    return (9.0 / 5.0 * c + 32);
}

/*
 * Function: FahrenheitToCelsius
 * Usage: c = FahrenheitToCelsius(f);
 * ----------------------------------
 * This function returns the Celsius equivalent of the Fahrenheit
 * temperature f.
 */

double FahrenheitToCelsius(double f)
{
    return ((f - 32.0) * 5.0 / 9.0);
}
