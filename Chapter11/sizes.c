/*
 * File: sizes.c
 * -------------
 *  This program shows the number of bytes required to
 *  store various type of values.
 */

#include "genlib.h"
#include "strlib.h"

/* 
 * Private static variables
 * ------------------------
 *  typename[] -- array of string which holds the name of types.
 *  typesize[] -- array of integer which holds the size of types.
 */

static string typename[] = {"char", "int", "short", "long", "float", "double"};
static int typesize[] = {sizeof(char), sizeof(int), sizeof(short), sizeof(long),
sizeof(float), sizeof(double)};

/* Main program */

int main(void)
{
    int i;
    
    for(i = 0; i < sizeof(typesize) / sizeof(typesize[0]); ++i)
    {
        printf("Values of type %s require %d byte(s).\n", typename[i], typesize[i]);
    }
}
