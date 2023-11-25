/*
 * File: quadratic.c
 * -----------------
 * This program evaluates solution of standard quadratic equation.
 * ax^2 + bx + c = 0
 */

#include <stdio.h>
#include <math.h>
#include "genlib.h"
#include "simpio.h"

/*
 * Constants:
 * ----------
 * THRESHOLD is used for comparing(==) double variables.
 */

#define THRESHOLD 0.00001

/* Function prototypes */

bool IsQuadratic(double a);
double SolveNonQuadratic(double b, double c);
double SolveQuadratic(double a, double b, double c);

/* Main program */

main()
{
    double a, b, c, result;
    bool quadratic;

    printf("Enter coefficients for the quadratic equation: \n");
    printf("a: "); a = GetReal();
    printf("b: "); b = GetReal();
    printf("c: "); c = GetReal();

    quadratic = IsQuadratic(a);

    if(!quadratic)
    {
        printf("Typed a = 0. The solution is %g\n", SolveNonQuadratic(b, c));
    }
    else
    {
        result = SolveQuadratic(a, b, c);
        if(IsQuadratic(result))
        {
            printf("The first solution is %g\n", (-b - result) / (2 * a));
            printf("The second solution is %g\n", (-b + result) / (2 * a));
        }
        else
        {
            printf("It has one solution. The solution is %g\n", (-b) / (2 * a));
        }
    }
}

/*
 * Function: IsQuadratic
 * Usage: quadratic - IsQuadratic(a);
 * ----------------------------------
 * This function reads in a value and returns TRUE if
 * a == 0, FALSE otherwise.
 */

bool IsQuadratic(double a)
{
    return (abs(a) > THRESHOLD);
}

/*
 * Function: SolveNonQuadratic(b, c)
 * Usage: result = SolveNonQuadratic(b, c);
 * ----------------------------------------
 * This function reads in linear equation bx + c = 0
 * and returns its solution.
 */

double SolveNonQuadratic(double b, double c)
{
    return (-c / b);
}

/*
 * Function: SolveQuadratic(a, b, c)
 * Usage: result = SolveQuadratic(a, b, c);
 * ----------------------------------------
 * This function reads in quadratic coefficients and returns
 * its sqrt(b^2 - 4 * a * c) value.
 */

double SolveQuadratic(double a, double b, double c)
{
    return (sqrt(b * b - 4 * a * c));
}
