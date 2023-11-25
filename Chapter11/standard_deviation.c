/*
 * File: standrad_deviation.c
 * --------------------------
 *  This file contains a function of calculating
 *  standard deviation from the array.
 */

#include <math.h>

#include "genlib.h"

/* Private function prototypes */

double Mean(double array[], int n);
double StandardDeviation(double array[], int n);

/*
 * Function: Mean
 * Usage: mean = Mean(arr, n);
 * ---------------------------
 *  This function returns the mean of an array whose
 *  effective size is n.
 */

double Mean(double array[], int n)
{
    int i;
    double sum = 0.0;

    for(i = 0; i < n; ++i) sum += array[i] / n;

    return sum;
}

/*
 * Function: StandardDeviation
 * Usage: result = StandardDeviation(arr, n);
 * ------------------------------------------
 *  Returns standard deviation of an array.
 */

double StandardDeviation(double array[], int n)
{
    double mean = Mean(array, n);
    double result = 0.0;
    int i;

    for(i = 0; i < n; ++i)
    {
        result += (mean - array[i]) * (mean - array[i]) / n;
    }
    result = sqrt(result);

    return (result);
}

