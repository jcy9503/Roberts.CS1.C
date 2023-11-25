/*
 * File: pascal_triangle.c
 * -----------------------
 * This program prints out pascal's triangle
 */

#include "genlib.h"
#include "simpio.h"

/*
 * Constants
 * ---------
 * HEIGHT is the height of the pascal's triangle.
 */

#define HEIGHT 8

/* Function prototypes */

int Combinations(int n, int k);
int Factorial(int n);
void Indentation(int n);

/* Main program */

main()
{
    int i, j;

    printf("This program prints out pascal's triangle.\n");
    printf("The height of the pascal's triangle is %d now.\n", HEIGHT);

    for(i = 0; i < HEIGHT; ++i)
    {
        Indentation(HEIGHT - i);
        for(j = 0; j <= i; ++j)
        {
            printf("%-2d  ", Combinations(i, j));
        }
        printf("\n");
    }
}

/*
 * Function: Combinations
 * Usage: ways = Combinations(n, k);
 * ---------------------------------
 * Implements the Combinations function, which returns the number
 * of distinct ways of choosing k objects from a set of n objects.
 * In mathematics, this function is often written as C(n, k), but a
 * function called C is not very self-descriptyive, particularly in
 * a language which has precisely the same name.
 */

int Combinations(int n, int k)
{
    return (Factorial(n) / (Factorial(k) * Factorial(n - k)));
}

/*
 * Function: Factorial
 * Usage: f = Factorial(n);
 * ------------------------
 * Returns the factorial of the argument n, where factorial
 * is defined as the product of all integers from 1 up to n.
 */

int Factorial(int n)
{
    int product, i;

    product = 1;
    for(i = 1; i <= n; ++i) product *= i;

    return product;
}

/*
 * Function: Indentation
 * Usage: Indentation(i);
 * ----------------------
 * Prints out start indentation of each line of the pascal's triangle.
 */

void Indentation(int n)
{
    int i;
    for(i = 0; i < n; ++i)
    {
        printf("  ");
    }
}
