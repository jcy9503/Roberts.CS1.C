/*
 * File: math_edu.c
 * ----------------
 * This program generates math questions
 * for first or second grade students.
 * Applied rules.
 * 1) Each question should consist of a single
 * addition or subtraction problem.
 * 2) none of the numbers involved, including the
 * answer, should be less than 1 or greater than 20.
 * 3) Program should give the student three chances
 * to answer. If the student doesn't get the answer
 * in three tries, program should give the answer
 * and go on to another problem.
 */

#include "genlib.h"
#include "random.h"
#include "simpio.h"
#include "strlib.h"

/*
 * Constants
 * ---------
 * N_TRIALS -- number of trials
 */

#define N_TRIALS 5

/* Function prototypes */

string GenerateQuestion(int* answer);

/* Main program */

main()
{
    int t = N_TRIALS, tries, answer, input, msg;
    string correct[] = {
        "You got it. The answer is ",
        "That's the answer!",
        "Splendid!",
        "Correct!",
        "Awesome!"
    };

    printf("Welcome to Math Quiz!\n");
    Randomize();
    while(t--)
    {
        tries = 1;
        printf("What is %s? ", GenerateQuestion(&answer));
        while(TRUE)
        {
            input = GetInteger();
            if(input == answer) break;
            if(tries == 3) break;
            printf("That's incorrect. Try a different answer: ");
            ++tries;
        }
        if(tries == 3) printf("No, the answer is %d\n.", answer);
        else 
        {
            msg = RandomInteger(0, 4);
            printf("%s", correct[msg]);
            if(msg == 0) printf("%d.", answer);
            printf("\n");
        }
    }
}

/*
 * Function: GenerateQuestion
 * Usage: string s = GenerateQuestion(&answer);
 * --------------------------------------------
 * Returns simple math question and store the answer
 * to pointer parameter.
 */

string GenerateQuestion(int* answer)
{
    string question = "";
    string operator[] = {" + ", " - "};
    int operation = RandomInteger(0, 1);
    int a, b;

    while(TRUE)
    {
        a = RandomInteger(1, 20);
        b = RandomInteger(1, 20);
        if(operation) 
        {
            if(a - b > 0 && a - b <= 20) break;
            continue;
        }
        else
        {
            if(a + b > 0 && a + b <= 20) break;
            continue;
        }
    }
    *answer = operation ? a - b : a + b;
    question = Concat(IntegerToString(a), operator[operation]);
    question = Concat(question, IntegerToString(b));

    return (question);
}
