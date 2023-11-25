/*
 * File: guessnum.c
 * ----------------
 *  This program plays a number-guessing game with its user.
 *  The number user inputs must be in range 1~100.
 */

#include <stdarg.h>

#include "genlib.h"
#include "simpio.h"
#include "strlib.h"

/* Static function prototypes */

static bool GetYesOrNo(string msg, ...);

/* Main program */

int main(void)
{
	int guess = 50, cur = 50;

	printf("Think of a number between 1 and 100 and I'll\nguess it.\n");
	while(!GetYesOrNo("Is it %d? ", cur))
	{
		guess /= 2;
		if(GetYesOrNo("Is it less than %d? ", cur))
		{
			cur -= guess;
		}
		else
		{
			cur += guess;
		}
	}
	printf("I guessed the number!\n");
}

/*
 * Function: GetYesOrNo
 * Usage: if(GetYesOrNo(str))...
 * -----------------------------
 *  Predicate function that returns user's answer with Boolean value.
 *  Only Yes/yes or No/no are valid input.
 */

static bool GetYesOrNo(string msg, ...)
{
	va_list args;
	char question[100];
	string answer;
	
	va_start(args, msg);
	vsprintf(question, msg, args);
	va_end(args);

	do
	{
		printf("%s", question);
		answer = GetLine();
		if(StringEqual("yes", ConvertToLowerCase(answer))) return (TRUE);
		if(StringEqual("no", ConvertToLowerCase(answer))) return (FALSE);
		printf("Please answer with yes/no.\nTry again.\n");
	} while(TRUE);

	return (FALSE);
}
