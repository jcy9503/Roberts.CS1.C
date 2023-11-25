/*
 * File: sieve_of_eratosthenes.c
 * -----------------------------
 *  This program displays all prime numbers between
 *  two given constants using sieve of Eratosthenes.
 */

#include "genlib.h"

/*
 * Constants
 * ---------
 *  UPPER_LIMIT -- Upper bound of range.
 */

#define UPPER_LIMIT 10000

/* Private function prototypes */

static void PrintPrimeNumbers(int n);
static void Initialization(bool arr[], int n, bool value);
static void FindPrimeNumbers(bool arr[], int n);

/* Main program */

int main(void)
{
    printf("This program displays all prime numbers between\n");
    printf("1 and %d(inclusive) using sieve of Eratosthenes.\n", UPPER_LIMIT);
    PrintPrimeNumbers(UPPER_LIMIT);
}

/*
 * Function: PrintPrimeNumbers
 * Usage: PrintPrimeNumbers(n);
 * ----------------------------
 *  This function prints out all prime numbers lesser or
 *  equal to n.
 */

static void PrintPrimeNumbers(int n)
{
    bool sieve[n + 1];
    int i, num = 1;

    Initialization(sieve, n + 1, TRUE);
    sieve[0] = sieve[1] = FALSE;
    FindPrimeNumbers(sieve, n + 1);
    printf("Prime numbers:\n");
    for(i = 0; i < n + 1; ++i)
    {
        if(sieve[i]) printf("#%4d: %5d\n", num++, i);
    }
}

/*
 * Function: Initialization
 * Usage: Initialization(arr, n, TRUE);
 * ------------------------------------
 *  This function initialize a boolean array of effective size
 *  n with given argument.
 */

static void Initialization(bool arr[], int n, bool value)
{
    int i;
    
    for(i = 0; i < n; ++i) arr[i] = value;
}

/*
 * Function: FindPrimeNumbers
 * Usage: FindPrimeNumbers(arr, n);
 * --------------------------------
 *  This function finds prime numbers in array with Eratosthenes
 *  method.
 */

static void FindPrimeNumbers(bool arr[], int n)
{
    int i, j;

    for(i = 2; i < n; ++i)
    {
        if(arr[i])
        {
            for(j = i * i; j < n; j += i) arr[j] = FALSE;
        }
    }
}
