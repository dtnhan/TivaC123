/*
 * delay.c
 *
 *  Created on: Sep 27, 2020
 *      Author: thanh
 */
#include <stdint.h>

void delay(uint32_t iter)
{
    int volatile counter = 0;
    while (counter < iter) //delay loop
    {
        counter++;
    }
}


