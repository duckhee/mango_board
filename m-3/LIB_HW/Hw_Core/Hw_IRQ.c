#define HW_IRQ_LOCAL

#include "Hw_IRQ.h"


HW_IRQ_DEF void EXTI0_IRQHandler(void);
HW_IRQ_DEF void EXTI1_IRQHandler(void);
HW_IRQ_DEF void EXTI2_IRQHandler(void);
HW_IRQ_DEF void EXTI3_IRQHandler(void);
HW_IRQ_DEF void EXTI4_IRQHandler(void);
HW_IRQ_DEF void TIM2_IRQHandler(void);
HW_IRQ_DEF void TIM3_IRQHandler(void);
HW_IRQ_DEF void TIM4_IRQHandler(void);


HW_IRQ_DEF void EXTI0_IRQHandler(void)
{
    if(EXTI_GetITStatus(GPIO_EXTI_Line_KEY1) != RESET)
    {
        EXTI_ClearITPendingBit(GPIO_EXTI_Line_KEY1);
        printf("LEFT-WKUP Button Press!!\n");
    }

}

HW_IRQ_DEF void EXTI1_IRQHandler(void)
{
    if(EXTI_GetITStatus(GPIO_EXTI_Line_KEY2) != RESET)
    {
        EXTI_ClearITPendingBit(GPIO_EXTI_Line_KEY2);
        printf("RIGHT-WKUP Button Press!!\n");
    }

}

HW_IRQ_DEF void EXTI2_IRQHandler(void)
{

}

HW_IRQ_DEF void EXTI3_IRQHandler(void)
{

}

HW_IRQ_DEF void EXTI4_IRQHandler(void)
{
    
}


HW_IRQ_DEF void TIM2_IRQHandler(void)
{
    /* Clear TIM2 update interrupt */
    TIM_ClearITPendingBit(TIM2, TIM_IT_Update);

    LED_TOGGLE_RED();

}

HW_IRQ_DEF void TIM3_IRQHandler(void)
{
    /* Clear TIM3 update interrupt */
    TIM_ClearITPendingBit(TIM3, TIM_IT_Update);

    LED_TOGGLE_YELLOW();

}

HW_IRQ_DEF void TIM4_IRQHandler(void)
{
    /* Clear TIM4 update interrupt */
    TIM_ClearITPendingBit(TIM4, TIM_IT_Update);

    LED_TOGGLE_BLUE();

    
}
