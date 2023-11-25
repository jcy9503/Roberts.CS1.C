/*
 * File: hist.h
 * Version: 1.0
 * Last modified on Thu Nov 9 by Lucas
 * -----------------------------------
 *  This file is the interface for drawing histogram through
 *  console.
 */

#ifndef _hist_h
#define _hist_h

/*
 * Function: HistPrint
 * Usage: HistPrint(arr, n);
 * -------------------------
 *  Prints out histogram with given information and array.
 */

void HistPrint(int array[], int n);

/*
 * Function: HistSetRangeSize
 * Usage: HistSetRangeSize(n);
 * ---------------------------
 *  Sets histogram range size with n
 */

void HistSetRangeSize(int size);

/*
 * Function: HistSetMinimum
 * Usage: HistSetMinimum(min);
 * ---------------------------
 *  Sets histogram minimum value with min.
 */

void HistSetMinimum(int min);

/*
 * Function: HistSetMaximum
 * Usage: HistSetMaximum(max);
 * ---------------------------
 *  Sets histogram maximum value with max.
 */

void HistSetMaximum(int max);

#endif
