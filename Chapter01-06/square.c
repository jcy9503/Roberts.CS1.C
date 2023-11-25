#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main()
{
    printf("Number  Square   Cube\n");
    for(int i = 1; i <= 10; ++i)
    {
        printf("%5d   %5d   %5d\n", i, i * i, i * i * i);
    }
}
