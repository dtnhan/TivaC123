#include <stdint.h>
#include "tm4c123g_cmsis.h"
#include "delay.h"

#define LED_RED   (1U << 1)
#define LED_BLUE  (1U << 2)
#define LED_GREEN (1U << 3)

typedef struct {
    uint16_t x;
    uint8_t y;
} point;

point p1, p2;

typedef struct {
    point top_left;
    point bottom_right;
} window;

typedef struct {
    point corners[3];
} triangle;

window w, w2;
triangle t;

int main(void)
{
    point *pp;
    window *wp;

    p1.x = sizeof(point);
    p1.y = p1.x - 3U;

    w.top_left.x = 1U;
    w.bottom_right.y = 2U;

    t.corners[0].x = 1U;
    t.corners[2].y = 2U;

    p2 = p1;
    w2 = w;

    pp = &p1;
    wp = &w2;

    (*pp).x = 1U;
    (*wp).top_left = *pp;

    pp->x = 1U;
    wp->top_left = *pp;

    SYSCTL->RCGC2    |= (1U << 5); //enable clock for GPIOF
    SYSCTL->GPIOHBCTL   |= (1 << 5);
    GPIOF_AHB->DIR |= (LED_RED | LED_GREEN | LED_BLUE); // set pins 1, 2, and 3 as output
    GPIOF_AHB->DEN |= (LED_RED | LED_GREEN | LED_BLUE);

    GPIOF_AHB->DATA_Bits[LED_BLUE] = LED_BLUE;

    while (1)
    {
        GPIOF_AHB->DATA_Bits[LED_RED] ^= LED_RED;
        delay(1000000);

    }


}

