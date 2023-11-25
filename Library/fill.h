/*
 * File: fill.h
 * ------------
 *  This file is the interface to an abstraction that enables
 *  you to display filled output. To use the package, you first
 *  call SetFillMargin to set an output margin and then make
 *  calls to PrintFilledString to display the output. These
 *  functions are described in more detail below.
 */

#ifndef _fill_h
#define _fill_h

#include "genlib.h"

/*
 * Function: SetFillMargin
 * Usage: SetFillMargin(margin);
 * -----------------------------
 *  This function sets the fill margin to the value given by the
 *  margin parameter. When strings are displayed using the
 *  function PrintFilledString, the output will be broken up
 *  into seperate lines so that no lines extend past the margin.
 *  If no margin is set explicitly, the package uses 65 for the
 *  fill margin as a default.
 */

void SetFillMargin(int margin);

/*
 * Function: PrintFilledString
 * Usage: PrintFilledString(str);
 * ------------------------------
 *  The string str is displayed on the screen, starting from
 *  where the last string left off. Spaces and newline characters
 *  in the string are treated specially. If a space character
 *  appears in an argument, the function may choose to divide
 *  the string at that point by moving to the next line.
 *  Such division occurs when the next word would not fit
 *  within the margin established by SetFillMargin. A newline
 *  character in the string forces the cursor to advance to the
 *  beginning of the next line.
 */

void PrintFilledString(string str);

#endif
