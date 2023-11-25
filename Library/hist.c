/*
 * File: hist.c
 * Version: 1.0
 * Last modified on Thu Nov 9 by Lucas
 * -----------------------------------
 *  This file implements histogram library package. See the
 *  interface description in hist.h for details.
 */

#include "genlib.h"

/* 
 * Private static value
 * --------------------
 *  range_size  -- Unit of histogram
 *  hist_min    -- Mimimum value of histogram
 *  hist_max    -- Maximum value of histogram
 */

static int range_size = 10;
static int hist_min = 0;
static int hist_max = 100;

/*
 * Function: HistPrint
 * Usage: HistPrint(arr, n);
 * -------------------------
 *  Prints out histogram.
 *  It first divide the given information to each section of histogram
 *  using display array.
 *  Print section starts with minimum value ~ minimum + range size.
 *  after first for loop of printing finished, it prints out last part
 *  of the histogram which includes maximum value of histogram.
 */

void HistPrint(int array[], int n)
{
    int num = (hist_max - hist_min) / range_size + 1;
    int* display = (int*)calloc(num, sizeof(int));
    int i, j;
    char buf[100];

    for(i = 0; i < n; ++i)
    {
        if(array[i] < hist_min || array[i] > hist_max)
        {
            Error("Input value is invalid.");
        }
        ++display[(array[i] - hist_min) / range_size];
    }

    printf("\n---- Histogram ----\n");
    for(i = 0; i < num - 1; ++i)
    {
        sprintf(buf, "%3d - %3d", hist_min + i * range_size, hist_min + (i + 1) * range_size - 1);
        printf("%-10s | ", buf);
        for(j = 0; j < display[i]; ++j) printf("*");
        printf("\n");
    }
    sprintf(buf, "%3d - %3d", hist_min + i * range_size, hist_max);
    printf("%-10s | ", buf);
    for(j = 0; j < display[num - 1]; ++j) printf("*");
    printf("\n");

    free(display);
}

/*
 * Function: HistSetRangeSize
 * Usage: HistSetRangeSize(n);
 * ---------------------------
 *  Error function occurs when input parameter is negative.
 */

void HistSetRangeSize(int size)
{
    if(size <= 0) Error("Histogram size value is illegal.");
    range_size = size;
}

/*
 * Function: HistSetMinimum
 * Usage: HistSetMinimum(min);
 * ---------------------------
 *  Error function occurs when input parameter is greater than
 *  maximum value.
 */

void HistSetMinimum(int min)
{
    if(min > hist_max) Error("Histogram min value is illegal.");
    hist_min = min;
}

/*
 * Function: HistSetMaximum
 * Usage: HistSetMaximum(max);
 * ---------------------------
 *  Error function occurs when input parameter is lesser than
 *  minimum value.
 */

void HistSetMaximum(int max)
{
    if(max < hist_min) Error("Histogram max value is illegal.");
    hist_max = max;
}
