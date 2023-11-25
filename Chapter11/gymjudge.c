/*
 * File: gymjudge.c
 * ----------------
 *  This program averages a set of five gymnastic scores.
 */

#include "genlib.h"
#include "simpio.h"

/*
 * Constants
 * ---------
 *  N_JUDGES -- Number of judges
 */

#define N_JUDGES 5

/* Private function prototypes */

static double Mean(double array[], int n);

/* Main program */

int main(void)
{
    double gymnasticScores[N_JUDGES];
    int i;

    printf("Please enter a score for each judge.\n");
    for(i = 0; i < N_JUDGES; ++i)
    {
        printf("Score for judge #%d: ", i);
        gymnasticScores[i] = GetReal();
    }

    printf("The average score is %.2f\n", Mean(gymnasticScores, N_JUDGES));
}

/*
 * Function: Mean
 * Usage: mean = Mean(arr, n);
 * ---------------------------
 *  This function returns the mean of an array whose
 *  effective size is n.
 */

static double Mean(double array[], int n)
{
    int i;
    double sum = 0.0;

    for(i = 0; i < n; ++i) sum += array[i] / n;

    return sum;
}
