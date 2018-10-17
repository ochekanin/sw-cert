#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>


void generateRandomNumbers(uint32_t *out, uint32_t numbers, uint32_t upperLimit)
{
    srand(time(NULL));

    for (uint32_t i = 0; i < numbers; ++i)
    {
        out[i] = (uint32_t)rand() % upperLimit;
    }
}