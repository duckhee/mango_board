#define EXTI_LOCAL

#include "Hw_EXTI.h"

EXTI_DEF ITStatus EXTI_GetITStatus(uint32_t EXTI_Line);
EXTI_DEF void EXTI_ClearITPendingBit(uint32_t EXTI_Line);
EXTI_DEF void EXTI0_IRQHandler(void);
EXTI_DEF void EXTI1_IRQHandler(void);
EXTI_DEF void EXTI2_IRQHandler(void);
EXTI_DEF void EXTI3_IRQHandler(void);
EXTI_DEF void EXTI4_IRQHandler(void);
EXTI_DEF void EXTI5_IRQHandler(void);
EXTI_DEF void EXTI6_IRQHandler(void);
EXTI_DEF void EXTI7_IRQHandler(void);
EXTI_DEF void EXTI8_IRQHandler(void);
EXTI_DEF void EXTI9_IRQHandler(void);
EXTI_DEF void EXTI10_IRQHandler(void);
EXTI_DEF void EXTI11_IRQHandler(void);
EXTI_DEF void EXTI12_IRQHandler(void);
EXTI_DEF void EXTI13_IRQHandler(void);
EXTI_DEF void EXTI14_IRQHandler(void);
EXTI_DEF void EXTI15_IRQHandler(void);


EXTI_DEF ITStatus EXTI_GetITStatus(uint32_t EXTI_Line)
{
    ITStatus bitStatus = RESET;
    uint32_t enableStatus = 0;

    enableStatus = EXTI->IMR & EXTI_Line;
    if(((EXTI->PR & EXTI_Line) != (uint32_t)RESET) && (enableStatus != (uint32_t)RESET))
    {
        bitStatus = SET;
    }
    else
    {
        bitStatus = RESET;
    }
    return bitStatus;
}

EXTI_DEF void EXTI_ClearITPendingBit(uint32_t EXTI_Line)
{
    EXTI->PR = EXTI_Line;
}

EXTI_DEF void EXTI0_IRQHandler(void)
{
    if(EXTI_GetITStatus(GPIO_EXTI_Line_KEY1) != RESET)
    {
        EXTI_ClearITPendingBit(GPIO_EXTI_Line_KEY1);
        printf("LEFT-WKUP Button Press!!\n");
    }
}
EXTI_DEF void EXTI1_IRQHandler(void)
{
    if(EXTI_GetITStatus(GPIO_EXTI_Line_KEY2) != RESET)
    {
        EXTI_ClearITPendingBit(GPIO_EXTI_Line_KEY2);
        printf("RIGHT-WKUP Button Press!!\n");
    }
}

EXTI_DEF void EXTI2_IRQHandler(void){}

EXTI_DEF void EXTI3_IRQHandler(void){}

EXTI_DEF void EXTI4_IRQHandler(void){}

EXTI_DEF void EXTI5_IRQHandler(void){}

EXTI_DEF void EXTI6_IRQHandler(void){}

EXTI_DEF void EXTI7_IRQHandler(void){}

EXTI_DEF void EXTI8_IRQHandler(void){}

EXTI_DEF void EXTI9_IRQHandler(void){}

EXTI_DEF void EXTI10_IRQHandler(void){}

EXTI_DEF void EXTI11_IRQHandler(void){}

EXTI_DEF void EXTI12_IRQHandler(void){}

EXTI_DEF void EXTI13_IRQHandler(void){}

EXTI_DEF void EXTI14_IRQHandler(void){}

EXTI_DEF void EXTI15_IRQHandler(void){}

