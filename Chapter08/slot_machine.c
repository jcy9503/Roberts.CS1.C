/*
 * File: slot_machine.c
 * --------------------
 * This program simulates slot machine.
 */

#include "genlib.h"
#include "random.h"
#include "simpio.h"
#include "strlib.h"

/*
 * Constants
 * ---------
 * INIT_MONEY -- initial money for user
 */

#define INIT_MONEY 50

/*
 * Global variables
 * ----------------
 * symbol[] -- array of string which indicates each symbol.
 * combinations[][] -- array of winning combinations.
 * pays[] -- array of integer of each combination's pays.
 */

string symbol[] = 
{
    "CHERRY", "LEMON", "ORANGE", "PLUM", "BELL", "BAR"
};
int combinations[][3] =
{
    {5, 5, 5},

    {4, 4, 5}, {4, 4, 4},

    {3, 3, 5}, {3, 3, 3},

    {2, 2, 5}, {2, 2, 2},

    {0, 0, 0},

    {0, 0, 2}, {0, 0, 3}, {0, 0, 4}, {0, 0, 5},

    {0, 2, 0}, {0, 2, 2}, {0, 2, 3}, {0, 2, 4}, {0, 2, 5},
    {0, 3, 0}, {0, 3, 2}, {0, 3, 3}, {0, 3, 4}, {0, 3, 5},
    {0, 4, 0}, {0, 4, 2}, {0, 4, 3}, {0, 4, 4}, {0, 4, 5},
    {0, 5, 0}, {0, 5, 2}, {0, 5, 3}, {0, 5, 4}, {0, 5, 5}
};
int pays[] =
{
    250,

    20, 20,

    14, 14,

    10, 10,

    7,

    5, 5, 5, 5,

    2, 2, 2, 2, 2,
    2, 2, 2, 2, 2,
    2, 2, 2, 2, 2,
    2, 2, 2, 2, 2
};

/* Function prototypes */

void ShowInstructions(void);
int DrawWheel(void);
int CalculateWheels(void);
bool GetYesOrNo(string prompt);

/* Main program */

int main(void)
{
    int cur = INIT_MONEY;
    Randomize();
    if(GetYesOrNo("Would you like instructions? ")) ShowInstructions();
    while(cur > 0)
    {
        printf("You have $%d. ", cur);
        if(GetYesOrNo("Would you like to play? "))
        {
            printf("\n");
            cur += CalculateWheels();
            printf("\n");
        }
        else
        {
            printf("Thank you for playing!\n");
            return (0);
        }
    }
    printf("You are out of money...\n");
    return (0);
}

/* 
 * Function: ShowInstructions
 * Usage: ShowInstructions();
 * --------------------------
 * Shows the rule of the slot machine.
 */

void ShowInstructions(void)
{
    int i;

    printf("\nLet's play slot machine and be broke!\n");
    printf("There are 6 symbols --\n");
    printf("CHERRY LEMON ORANGE PLUM BELL BAR\n");
    printf("At each game, you draws 3 wheels to get 3 symbols!\n");
    printf("When your combination contains LEMON, you lose.\n");
    printf("Otherwise, your combination will pay you with price!\n");
    printf("Combinations --\n");
    for(i = 0; i < 32; ++i)
    {
        printf("%-7s %-7s %-7s pays %5s\n", symbol[combinations[i][0]],
                symbol[combinations[i][1]], symbol[combinations[i][2]],
                Concat("$", IntegerToString(pays[i])));
    }
    printf("Your initial amount of money is $%d.\n\n", INIT_MONEY);
}

/*
 * Function: DrawWheel
 * Usage: result = DrawWheel();
 * ----------------------------
 * Draws wheel and returns the result.
 */

int DrawWheel(void)
{
    return (RandomInteger(0, 5));
}

/*
 * Function: CalculateWheels
 * Usage: result += CalculateWheels();
 * -----------------------------------
 * Draws 3 wheels and calculate the payoffs.
 */

int CalculateWheels(void)
{
    int x = DrawWheel();
    int y = DrawWheel();
    int z = DrawWheel();
    int i;

    printf("%-7s %-7s %-7s  -- ", symbol[x], symbol[y], symbol[z]);
    for(i = 0; i < 32; ++i)
    {
        if(x == combinations[i][0] && y == combinations[i][1] &&
                z == combinations[i][2])
        {
            printf("You win $%d\n", pays[i]);
            return (pays[i]);
        }
    }
    printf("You lose\n");
    return (-1);
}

/*
 * Function: GetYesOrNo
 * Usage: if(GetYesOrNo(str))...
 * -----------------------------
 * Repeat string until user input "yes" or "no".
 * It returns the input by Boolean value.
 */

bool GetYesOrNo(string prompt)
{
    string answer;
    
    while(TRUE)
    {
        printf("%s", prompt);
        answer = GetLine();
        if(StringEqual(answer, "yes")) return (TRUE);
        if(StringEqual(answer, "no")) return (FALSE);
    }
}
