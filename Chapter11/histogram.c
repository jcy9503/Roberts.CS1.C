/*
 * File: histogram.c
 * -----------------
 *  This program reads in a set of integers and draws
 *  histogram for data analysis.
 */

#include "genlib.h"
#include "strlib.h"
#include "simpio.h"
#include "hist.h"

/*
 * Constants
 * ---------
 *  SIZE_N -- allocated size for an array.
 */

#define SIZE_N 10000

/* Private function prototypes */

static int ReadInput(int arr[]);
static void DrawHistogram(int arr[], int n);

/* Main program */

int main(void)
{
    int arr[SIZE_N];
    int n;

    printf("This program draws histogram for a set of integers.\n");
    printf("Please input values. Signal of the end is blank line.\n");
    n = ReadInput(arr);
    DrawHistogram(arr, n);
}

/*
 * Function: ReadInput
 * Usage: n = ReadInput(arr);
 * --------------------------
 *  This function reads in a set of integers.
 *  Input ends when user input blank line.
 *  Returns effective size of the array.
 */

static int ReadInput(int arr[])
{
    int i;
    string str;

    for(i = 0; i < SIZE_N; ++i)
    {
        str = GetLine();
        if(StringLength(str) == 0) break;
        arr[i] = StringToInteger(str);
    }

    return (i);
}

/*
 * Function: DrawHistogram
 * Usage: DrawHistogram(arr, n);
 * -----------------------------
 *  Draws histogram using array of integer.
 */

static void DrawHistogram(int arr[], int n)
{
    HistSetRangeSize(5);
    HistSetMinimum(-10);
    HistSetMaximum(150);
    HistPrint(arr, n);
}
