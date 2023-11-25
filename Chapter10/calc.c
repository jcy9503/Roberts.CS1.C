/*
 * File: calc.c
 * ------------
 *  This program reads in lines of calculating problems
 *  and returns their answers.
 *  The precedence of calculation will be ignored.
 *  All operators have same precedence.
 */

#include "genlib.h"
#include "strlib.h"
#include "simpio.h"
#include "scanner.h"

/* Function prototypes */

static int Calculate(string line);

/* Main program */

int main(void)
{
    string line;

    printf("This program implements a simple calculator.\n");
    printf("When the > prompt appers, enter an expression\n");
    printf("consisting of integer constants and the operators\n");
    printf("+, -, *, /, and %%. To stop, enter a blank line.\n");
    IgnoreSpace(TRUE);
    ReturnAlphaNumTokens(TRUE);
    while(TRUE)
    {
        printf("> ");
        line = GetLine();
        if(StringEqual(line, "")) break;
        printf("%d\n", Calculate(line));
    }
}

/*
 * Function: Calculate
 * Usage: int result = Calculate(str);
 * -----------------------------------
 *  This function returns the correct answer of the expression
 *  line.
 */

static int Calculate(string line)
{
    string token;
    char operator;
    int result = 0, tp = 0;

    InitScanner(line);

    result = StringToInteger(GetNextToken());
    while(!AtEndOfLine())
    {
        token = GetNextToken();
        if(StringLength(token) > 1) Error("Invalid expression.\n");

        operator = IthChar(token, 0);
        token = GetNextToken();
        tp = StringToInteger(token);
        switch(operator)
        {
            case '+': result += tp; break;
            case '-': result -= tp; break;
            case '*': result *= tp; break;
            case '/': result /= tp; break;
            case '%': result %= tp; break;
            default: Error("Invalid operator %c.\n", operator);
        }
    }

    return result;
}
