#define SYSTICK_LOCAL

#include "Hw_Systick.h"

SYSTICK_DEF uint32_t Systick_Config(uint32_t ticks)
{
    if(ticks > SYSTICK_MAXCOUNT)
    {
        /* Reload value impossible */
        return (1);
    }
    /* set reload register */
    SysTick->LOAD = (ticks & SYSTICK_MAXCOUNT) - 1;
    /* set Priority for Cortex-M0 System Interrupts */
    NVIC_SetPriority(SysTick_IRQn, (1<<__NVIC_PRIO_BITS) - 1);
    /* Load the SysTick Counter Value */
    SysTick->VAL = (0x00);
    /* Enable SysTick IRQ and SysTick Timer */
    SysTick->CTRL = (1 << SYSTICK_CLKSOURCE) | (1 << SYSTICK_ENABLE) | (1 << SYSTICK_TICKINT);
    /* Function successful */
    return (0);
}

SYSTICK_DEF void SysTick_Handler(void)
{
    
}