/*
 * File: usa_phone.c
 * -----------------
 * This program generates USA-style phone number
 * using random.h.
 * Applied rules.
 * 1) The output contains a (-) between the third
 * and fourth digit, as in 555-1968.
 * 2) Neither of the first two digits is 0 or 1.
 */

#include "genlib.h"
#include "strlib.h"
#include "random.h"

/*
 * Constants
 * ---------
 * N_TRIALS -- number of trials.
 */

#define N_TRIALS    10

/* Function prototypes */

string RandomPhone(void);
string RandomIntegerNormal(void);
string RandomIntegerSpecial(void);

/* Main program */

main()
{
    int i;

    printf("This program generates USA-style phone number.\n");
    Randomize();
    for(i = 0; i < N_TRIALS; ++i)
    {
        printf("#%3d: %s\n", i + 1, RandomPhone());
    }
}

/*
 * Function: RandomPhone
 * Usage: string s = RandomPhone();
 * --------------------------------
 * Returns random phone number using applied rules.
 */

string RandomPhone(void)
{
    string result = "";
    int i;

    for(i = 0; i < 2; ++i)
    {
        result = Concat(result, RandomIntegerSpecial());
    }
    result = Concat(result, RandomIntegerNormal());
    result = Concat(result, "-");
    for(i = 0; i < 4; ++i)
    {
        result = Concat(result, RandomIntegerNormal());
    }

    return result;
}

/*
 * Function: RandomIntegerNormal
 * Usage: result = RandomIntegerNormal();
 * --------------------------------------
 * Returns random integer range between 0 ~ 9
 * converted to string.
 */

string RandomIntegerNormal(void)
{
    return (IntegerToString(RandomInteger(0, 9)));
}

/*
 * Function: RandomIntegerSpecial
 * Usage: result = RandomIntegerSpecial();
 * ---------------------------------------
 * Returns random integer range between 2 ~ 9
 * converted to string.
 */

string RandomIntegerSpecial(void)
{
    return (IntegerToString(RandomInteger(2, 9)));
}
