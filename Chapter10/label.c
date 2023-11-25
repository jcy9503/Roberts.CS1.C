/*
 * File: label.c
 * -------------
 *  This program tests labelseq.h interface.
 */

#include "genlib.h"
#include "strlib.h"
#include "simpio.h"
#include "labelseq.h"

/* Main program */

int main(void)
{
    string prefix;
    int start;
    int i;

    printf("This program tests the labelseq abstraction.\n");
    printf("Prefix to use for labels: ");
    prefix = GetLine();
    SetLabelPrefix(prefix);
    printf("Starting number: ");
    start = GetInteger();
    SetLabelNumber(start);
    for(i = 0; i < 5; ++i)
    {
        printf("%s\n", GetNextLabel());
    }
}
