/*
 * File: gfigures.c
 * -------------
 * This file contains useful functions using "graphics.h" library.
 * Please check descriptions of the functions in "gfigures.h" file.
 */

#include "gfigures.h"
#include "genlib.h"
#include "graphics.h"

#ifndef max
#define max(a, b) (((a) > (b)) ? (a) : (b))
#endif

#ifndef min
#define min(a, b) (((a) < (b)) ? (a) : (b))
#endif

void DrawBox(double x, double y, double width, double height)
{
    double prevX = GetCurrentX();
    double prevY = GetCurrentY();

    MovePen(x, y);
    DrawLine(0, height);
    DrawLine(width, 0);
    DrawLine(0, -height);
    DrawLine(-width, 0);
    MovePen(prevX, prevY);
}

void DrawCenteredBox(double x, double y, double width, double height)
{
    DrawBox(x - width / 2, y - height / 2, width, height);
}

void DrawCenteredCircle(double x, double y, double r)
{
    double prevX = GetCurrentX();
    double prevY = GetCurrentY();

    MovePen(x + r, y);
    DrawArc(r, 0.0, 360.0);
    MovePen(prevX, prevY);
}

void AdjustPen(double dx, double dy)
{
    MovePen(GetCurrentX() + dx, GetCurrentY() + dy);
}

void DrawLineTo(double x, double y)
{
    DrawLine(x - GetCurrentX(), y - GetCurrentY());
}

void DrawGrid(double x, double y, double width, double height,
        int columns, int rows)
{
    int i, j;

    for(i = 0; i < columns; ++i)
    {
        for(j = 0; j < rows; ++j)
            DrawBox(x + i * width, y + j * height,
                    width, height);
    }
}

void DrawTriangle(double x, double y, double base, double height)
{
    double prevX = GetCurrentX();
    double prevY = GetCurrentY();

    MovePen(x, y);
    DrawLine(base, 0);
    DrawLine(-base / 2, height);
    DrawLine(-base / 2, -height);
    MovePen(prevX, prevY);
}

void DrawCrossedBox(double x, double y, double width, double height)
{
    double prevX = GetCurrentX();
    double prevY = GetCurrentY();

    MovePen(x, y);
    DrawLine(width, 0);
    DrawLine(0, height);
    DrawLine(-width, 0);
    DrawLine(0, -height);
    DrawLine(width, height);
    AdjustPen(-width, 0);
    DrawLine(width, -height);
    MovePen(prevX, prevY);
}

void DrawRoundedBox(double x, double y, double width, double height, double radius)
{
    double prevX = GetCurrentX();
    double prevY = GetCurrentY();
    double adjustedWidth = width - 2.0 * radius;
    double adjustedHeight = height - 2.0 * radius;

    if(adjustedWidth < 0.0 || adjustedHeight < 0.0)
    {
        Error("DrawRoundedBox: Corner radius value error. Terminating program.\n");
    }

    MovePen(x, y + radius);
    DrawArc(radius, 180, 90);
    DrawLine(adjustedWidth, 0.0);
    DrawArc(radius, 270, 90);
    DrawLine(0.0, adjustedHeight);
    DrawArc(radius, 0, 90);
    DrawLine(-adjustedWidth, 0.0);
    DrawArc(radius, 90, 90);
    DrawLine(0.0, -adjustedHeight);
    MovePen(prevX, prevY);
}

void DrawCharacter(double x, double y, double height, char ch)
{
    double prevX = GetCurrentX();
    double prevY = GetCurrentY();

    double width = height / 2.0;

    MovePen(x, y);
    switch(ch)
    {
        case 'a':
        case 'A':
            DrawLine(width / 2.0, height);
            DrawLine(width / 2.0, -height);
            AdjustPen(-width / 4.0, height / 2.0);
            DrawLine(-width / 2.0, 0.0);
            break;

        case 'b':
        case 'B':
            DrawLine(0.0, height);
            DrawLine(width - height / 4.0, 0.0);
            DrawArc(height / 4.0, 90, -180);
            DrawLine(-width + height / 4.0, 0.0);
            AdjustPen(width - height / 4.0, 0.0);
            DrawArc(height / 4.0, 90, -180);
            DrawLine(-width + height / 4.0, 0.0);
            break;

        case 'c':
        case 'C':
            AdjustPen(width, height);
            DrawArc(height / 2.0, 90, 90);
            DrawArc(height / 2.0, 180, 90);
            break;

        case 'd':
        case 'D':
            DrawLine(0.0, height);
            DrawArc(height / 2.0, 90, -90);
            DrawArc(height / 2.0, 0, -90);
            break;

        case 'e':
        case 'E':
            DrawLine(0.0, height);
            DrawLine(width, 0.0);
            AdjustPen(-width, -height / 2.0);
            DrawLine(width * 2.0 / 3.0, 0.0);
            MovePen(x, y);
            DrawLine(width, 0.0);
            break;

        case 'f':
        case 'F':
            DrawLine(0.0, height);
            DrawLine(width, 0.0);
            AdjustPen(-width, -height / 2.0);
            DrawLine(width, 0.0);
            break;

        case 'g':
        case 'G':
            AdjustPen(width, height);
            DrawArc(height / 2.0, 90, 90);
            DrawArc(height / 2.0, 180, 90);
            DrawLine(0.0, height / 2.0);
            DrawLine(-width / 2.0, 0.0);
            break;

        case 'h':
        case 'H':
            DrawLine(0.0, height);
            AdjustPen(0.0, -height / 2.0);
            DrawLine(width, 0.0);
            AdjustPen(0.0, height / 2.0);
            DrawLine(0.0, -height);
            break;

        case 'i':
        case 'I':
            DrawLine(width, 0.0);
            AdjustPen(-width / 2.0, 0.0);
            DrawLine(0.0, height);
            AdjustPen(-width / 2.0, 0.0);
            DrawLine(width, 0.0);
            break;

        case 'j':
        case 'J':
            AdjustPen(0.0, height);
            DrawLine(width, 0.0);
            AdjustPen(-width / 2.0, 0.0);
            DrawLine(0.0, -height * 3.0 / 4.0);
            DrawArc(height / 4.0, 0, -90);
            break;

        case 'k':
        case 'K':
            DrawLine(0.0, height);
            AdjustPen(0.0, -height / 2.0);
            DrawLine(width, height / 2.0);
            AdjustPen(-width, -height / 2.0);
            DrawLine(width, -height / 2.0);
            break;

        case 'l':
        case 'L':
            DrawLine(0.0, height);
            AdjustPen(0.0, -height);
            DrawLine(width, 0.0);
            break;

        case 'm':
        case 'M':
            DrawLine(0.0, height);
            DrawLine(width / 2.0, -height);
            DrawLine(width / 2.0, height);
            DrawLine(0.0, -height);
            break;

        case 'n':
        case 'N':
            DrawLine(0.0, height);
            DrawLine(width, -height);
            DrawLine(0.0, height);
            break;

        case 'o':
        case 'O':
            AdjustPen(0.0, height / 4.0);
            DrawLine(0.0, height / 2.0);
            DrawArc(height / 4.0, 180, -180);
            DrawLine(0.0, -height / 2.0);
            DrawArc(height / 4.0, 0, -180);
            break;

        case 'p':
        case 'P':
            DrawLine(0.0, height);
            DrawLine(width / 2.0, 0.0);
            DrawArc(height / 4.0, 90, -180);
            DrawLine(-width / 2.0, 0.0);
            break;

        case 'q':
        case 'Q':
            AdjustPen(0.0, height / 4.0);
            DrawLine(0.0, height / 2.0);
            DrawArc(height / 4.0, 180, -180);
            DrawLine(0.0, -height / 2.0);
            DrawArc(height / 4.0, 0, -180);
            MovePen(x, y);
            AdjustPen(width / 2.0, height / 2.0);
            DrawLine(width / 2.0, -height / 2.0);
            break;

        case 'r':
        case 'R':
            DrawLine(0.0, height);
            DrawLine(width / 2.0, 0.0);
            DrawArc(height / 4.0, 90, -180);
            DrawLine(-width / 2.0, 0.0);
            AdjustPen(width / 2.0, 0.0);
            DrawLine(width / 2.0, -height / 2.0);
            break;

        case 's':
        case 'S':
            AdjustPen(0.0, height / 4.0);
            DrawArc(height / 4.0, 180, 270);
            DrawArc(height / 4.0, 270, -270);
            break;

        case 't':
        case 'T':
            AdjustPen(0.0, height);
            DrawLine(width, 0.0);
            AdjustPen(-width / 2.0, 0.0);
            DrawLine(0.0, -height);
            break;

        case 'u':
        case 'U':
            AdjustPen(0.0, height);
            DrawLine(0.0, -height * 3.0 / 4.0);
            DrawArc(height / 4.0, 180, 180);
            DrawLine(0.0, height * 3.0 / 4.0);
            break;

        case 'v':
        case 'V':
            AdjustPen(0.0, height);
            DrawLine(width / 2.0, -height);
            DrawLine(width / 2.0, height);
            break;

        case 'w':
        case 'W':
            AdjustPen(0.0, height);
            DrawLine(width / 4.0, -height);
            DrawLine(width / 4.0, height * 3.0 / 4.0);
            DrawLine(width / 4.0, -height * 3.0 / 4.0);
            DrawLine(width / 4.0, height);
            break;

        case 'x':
        case 'X':
            DrawLine(width, height);
            AdjustPen(0.0, -height);
            DrawLine(-width, height);
            break;

        case 'y':
        case 'Y':
            AdjustPen(0.0, height);
            DrawLine(width / 2.0, -height / 2.0);
            DrawLine(width / 2.0, height / 2.0);
            AdjustPen(-width / 2.0, -height / 2.0);
            DrawLine(0.0, -height / 2.0);
            break;

        case 'z':
        case 'Z':
            AdjustPen(0.0, height);
            DrawLine(width, 0.0);
            DrawLine(-width, -height);
            DrawLine(width, 0.0);
            break;

        default:
            Error("DrawCharacter: You should input alphabet only.\n");
    }
    MovePen(prevX, prevY);
}

void DrawString(double x, double y, double height, const char* str)
{
    double prevX = GetCurrentX();
    double prevY = GetCurrentY();
    double curX, curY;
    double space = height * 3.0 / 4.0;
    int i;

    MovePen(x, y);
    for(i = 0; str[i]; ++i)
    {
        curX = GetCurrentX();
        curY = GetCurrentY();
        DrawCharacter(curX, curY, height, str[i]);
        AdjustPen(space, 0.0);
    }
    MovePen(prevX, prevY);
}

void DrawShadedBox(double x, double y, double width, double height, int points)
{
    double prevX = GetCurrentX();
    double prevY = GetCurrentY();
    double unit = points / 72.0;
    double tp;
    int i = 0;
    bool flag = width >= height ? TRUE : FALSE;

    DrawBox(x, y, width, height);

    if(flag)
    {
        while(++i)
        {
            MovePen(x - height + unit * i, y);
            if(GetCurrentX() > x + width) break;
            if(GetCurrentX() < x)
            {
                MovePen(x, y + height - unit * i);
                DrawLine(unit * i, unit * i);
            }
            else if(GetCurrentX() > x + width - height)
            {
                tp = width - (GetCurrentX() - x);
                DrawLine(tp, tp);
            }
            else
            {
                DrawLine(height, height);
            }
        }
    }
    else
    {
        while(++i)
        {
            MovePen(x, y - width + unit * i);
            if(GetCurrentY() > y + height) break;
            if(GetCurrentY() < y)
            {
                MovePen(x + width - unit * i, y);
                DrawLine(unit * i, unit * i);
            }
            else if(GetCurrentY() > y + height - width)
            {
                tp = height - (GetCurrentY() - y);
                DrawLine(tp, tp);
            }
            else
            {
                DrawLine(width, width);
            }
        }
    }
    MovePen(prevX, prevY);
}
