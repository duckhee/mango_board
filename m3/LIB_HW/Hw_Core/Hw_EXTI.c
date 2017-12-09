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

EXTI_DEF void EXTI2_IRQHandler(void)
{
    if(EXTI_GetITStatus(EXTI_LINE2) != RESET)
    {
        EXTI_ClearITPendingBit(EXTI_LINE2);
    }
}

EXTI_DEF void EXTI3_IRQHandler(void)
{
    if(EXTI_GetITStatus(EXTI_LINE3) != RESET)
    {
        EXTI_ClearITPendingBit(EXTI_LINE3);
    }
}

EXTI_DEF void EXTI4_IRQHandler(void)
{
    if(EXTI_GetITStatus(EXTI_LINE4) != RESET)
    {
        EXTI_ClearITPendingBit(EXTI_LINE4);
    }
}

EXTI_DEF void EXTI5_IRQHandler(void)
{
    if(EXTI_GetITStatus(EXTI_LINE5) != RESET)
    {
        EXTI_ClearITPendingBit(EXTI_LINE5);
    }
}

EXTI_DEF void EXTI6_IRQHandler(void)
{
    if(EXTI_GetITStatus(EXTI_LINE6) != RESET)
    {
        EXTI_ClearITPendingBit(EXTI_LINE6);
    }
}

EXTI_DEF void EXTI7_IRQHandler(void)
{
    if(EXTI_GetITStatus(EXTI_LINE7) != RESET)
    {
        EXTI_ClearITPendingBit(EXTI_LINE7);
    }
}

EXTI_DEF void EXTI8_IRQHandler(void)
{
    if(EXTI_GetITStatus(EXTI_LINE8) != RESET)
    {
        EXTI_ClearITPendingBit(EXTI_LINE8);
    }
}

EXTI_DEF void EXTI9_IRQHandler(void)
{
    if(EXTI_GetITStatus(EXTI_LINE9) != RESET)
    {
        EXTI_ClearITPendingBit(EXTI_LINE9);
    }
}

EXTI_DEF void EXTI10_IRQHandler(void)
{
    if(EXTI_GetITStatus(EXTI_LINE10) != RESET)
    {
        EXTI_ClearITPendingBit(EXTI_LINE10);
    }
}

EXTI_DEF void EXTI11_IRQHandler(void)
{
    if(EXTI_GetITStatus(EXTI_LINE11) != RESET)
    {
        EXTI_ClearITPendingBit(EXTI_LINE11);
    }
}

EXTI_DEF void EXTI12_IRQHandler(void)
{
    if(EXTI_GetITStatus(EXTI_LINE12) != RESET)
    {
        EXTI_ClearITPendingBit(EXTI_LINE12);
    }
}

EXTI_DEF void EXTI13_IRQHandler(void)
{
    if(EXTI_GetITStatus(EXTI_LINE13) != RESET)
    {
        EXTI_ClearITPendingBit(EXTI_LINE13);
    }
}

EXTI_DEF void EXTI14_IRQHandler(void)
{
    if(EXTI_GetITStatus(EXTI_LINE14) != RESET)
    {
        EXTI_ClearITPendingBit(EXTI_LINE14);
    }
}

EXTI_DEF void EXTI15_IRQHandler(void){}

