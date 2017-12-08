#define SYSTICK_LOCAL

#include "Hw_Systick.h"

SYSTICK_DEF uint32_t Systick_Config(uint32_t ticks)
{
    if(ticks > SYSTICK_MAXCOUNT)
    {
        return (1);
    }

    SysTick->LOAD = (ticks & SYSTICK_MAXCOUNT) - 1;
}