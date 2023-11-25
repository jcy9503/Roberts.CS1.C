/*
 * File: labelseq.h
 * Version: 1.0
 * Last modified on Wed Nov 07 2023 by Lucas
 * -----------------------------------------
 *  The label sequence package provides generating
 *  label sequence.
 */

#ifndef _labelseq_h
#define _labelseq_h

#include "strlib.h"

/*
 * Function: InitLabel
 * Usage: InitLabel();
 * -------------------
 *  Initializes label library.
 */

void InitLabel(void);

/*
 * Function: GetNextLabel
 * Usage: string str = GetNextLabel();
 * -----------------------------------
 *  Returns next label string.
 */

string GetNextLabel(void);

/*
 * Function: SetLabelPrefix
 * Usage: SetLabelPrefix("Some");
 * ------------------------------
 *  Setting label prefix.
 */

void SetLabelPrefix(string prefix);

/*
 * Function: SetLabelNumber
 * Usage: SetLabelNumber(0);
 * -------------------------
 *  Setting label number for next label.
 */

void SetLabelNumber(int next);

#endif
