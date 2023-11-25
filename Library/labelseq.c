/*
 * File: labelseq.c
 * Version: 1.0
 * Last modified on Wed Nov 2023 by Lucas
 * --------------------------------------
 *  This file implements the label sequence package.
 *  See the interface description in labelseq.h for details.
 */

#include "labelseq.h"

static string label = "Label";
static int num = 0;

/*
 * Function: InitLabel
 * Usage: InitLabel();
 * -------------------
 *  Initializes label to "Label" and num to 0.
 */

void InitLabel(void)
{
    label = "Label";
    num = 0;
}

/*
 * Function: GetNextLabel
 * Usage: string str = GetNextLabel();
 * -----------------------------------
 *  Returns next label string.
 *  Concatenating label and number.
 */

string GetNextLabel(void)
{
    return (Concat(Concat(label, " "), IntegerToString(num++)));
}

/*
 * Function: SetLabelPrefix
 * Usage: SetLabelPrefix("Some");
 * ------------------------------
 *  Setting label prefix.
 */

void SetLabelPrefix(string prefix)
{
    label = prefix;
}

/*
 * Function: SetLabelNumber
 * Usage: SetLabelNumber(0);
 * -------------------------
 *  Setting label number for next label.
 */

void SetLabelNumber(int next)
{
    num = next;
}
