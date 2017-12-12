#define HW_LOCAL

#include "Hw.h"


HW_DEF void Hw_Init(void);

HW_DEF void Hw_Init(void)
{
    HSE_Init();
    APB2Enable(AFIO_ENABLE, ENABLE);
    APB2Enable(IOPORT_A_ENABLE, ENABLE);
    APB2Enable(IOPORT_B_ENABLE, ENABLE);
    APB2Enable(IOPORT_C_ENABLE, ENABLE);
    APB2Enable(IOPORT_D_ENABLE, ENABLE);
    APB2Enable(USART1_ENABLE, ENABLE);
    APB1Enable(TIM2_ENABLE, ENABLE);
    APB1Enable(TIM3_ENABLE, ENABLE);
    APB1Enable(TIM4_ENABLE, ENABLE);
    APBEnable(DMA1_ENABLE, ENABLE);
    APB2Enable(ADC1_ENABLE, ENABLE);
    GPIO_Configuratioin();
    USART1_Init();
    
}