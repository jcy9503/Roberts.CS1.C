/*
 * File: fibonacci.c
 * -----------------
 * This program displays fibonacci sequence from
 * 0 to UPPERLIMIT.
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

/*
 * Constants
 * ---------
 * UPPERLIMIT is the upper limit of displayed fibonacci sequence.
 */

#define UPPERLIMIT 20

/*
 * Type definition
 * ---------------
 * ULL is the short name of unsigned long long int type.
 */

typedef unsigned long long int ULL;

/* Function prototypes */

ULL Fibonacci(int n, ULL* a, ULL* b);
int Digit(int n);

/* Main program */

main()
{
    printf("This program lists the Fibonacci sequence.\n");

    int i, j;
    int digit = Digit(UPPERLIMIT);

    ULL a = 0, b = 1;

    for(i = 0; i <= UPPERLIMIT; ++i)
    {
        for(j = Digit(i); j < digit; ++j) printf(" ");
        printf("F(%d) = %15llu\n", i, Fibonacci(i, &a, &b));
    }
}

/*
 * Function: Fibonacci
 * Usage: result = Fibonacci(n, &a, &b);
 * -------------------------------------
 * This function returns n-th sequence of the fibonacci.
 * a and b should be last 2 preceding numbers of fibonacci.
 * The result of calculation will be saved to a and b variables.
 */

ULL Fibonacci(int n, ULL* a, ULL* b)
{
    if(n == 0) return *a;
    *b += *a;
    *a = *b - *a;
    return *b;
}

/*
 * Function: Digit
 * Usage: digit = Digit(n);
 * ------------------------
 * This function returns how many digits does n have.
 */

int Digit(int n)
{
    int digit = 1;
    while(n >= 10) 
    {
        ++digit;
        n /= 10;
    }

    return digit;
}
