#ifndef __HW_SYSTICK_H__
#define __HW_SYSTICK_H__

#include "Hw.h"

/* Config-Bit to start or stop the SysTick Timer                         */
#define SYSTICK_ENABLE              0
/* Config-Bit to enable or disable the SysTick interrupt                 */
#define SYSTICK_TICKINT             1
/* Clocksource has the offset 2 in SysTick Control and Status Register   */
#define SYSTICK_CLKSOURCE           2
/* SysTick MaxCount                                                      */
#define SYSTICK_MAXCOUNT       ((1<<24) -1)

#ifdef SYSTICK_LOCAL
#define SYSTICK_DEF
#else
#define SYSTICK_DEF         extern
#endif

SYSTICK_DEF uint32_t Systick_Config(uint32_t ticks);
SYSTICK_DEF void SysTick_Handler(void);




#endif
