/*
 * File: resistor.c
 * ----------------
 *  This file reads three color from user which indicate
 *  specific registor. The program calculates and returns
 *  its resistance value.
 */

#include "genlib.h"
#include "simpio.h"
#include "strlib.h"

/*
 * Static variables
 * ----------------
 *  color_name: string array which contains color codes.
 */

static string color_name[] = 
{
	"black", "brown", "red", "orange", "yellow",
	"green", "blue", "violet", "gray", "white",
};

/* Static function prototypes */

static int ColorValue(string name);
static int PowerTen(int exp);

/* Main program */

int main(void)
{
	string color;
	int result = 0;

	printf("This program interprets the resistor color code:\n");
	printf("Color of first band: ");
	color = GetLine();
	result += 10 * ColorValue(color);
	printf("Color of second band: ");
	color = GetLine();
	result += ColorValue(color);
	printf("Color of third band: ");
	color = GetLine();
	result *= PowerTen(ColorValue(color));

	printf("Resistance = %d ohms.\n", result);

	return 0;
}

/*
 * Function: ColorValue
 * Usage: result = ColorValue(color);
 * ----------------------------------
 *  This function interprets color string and returns
 *  corresponding integer.
 */

static int ColorValue(string name)
{
	int i;

	for(i = 0; i < 10; ++i)
	{
		if(StringEqual(ConvertToLowerCase(name), color_name[i])) return i;
	}

	Error("Invalid color code.");
	return -1;
}

/*
 * Function: PowerTen
 * Usage: result *= PowerTen(exp);
 * -------------------------------
 *  This function returns 10 to the exp-th.
 */

static int PowerTen(int exp)
{
	int result = 1, i;
	for(i = 0; i < exp; ++i) result *= 10;

	return result;
}
