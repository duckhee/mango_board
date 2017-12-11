#define HW_LOCAL

#include "Hw.h"


HW_DEF void Hw_Init(void);

HW_DEF void Hw_Init(void)
{
    HSE_Init();
    APB2Enable(AFIO_ENABLE, ENABLE);
    APB2Enable(IOPORT_A_ENABLE, ENABLE);
    APB2Enable(IOPORT_B_ENABLE, ENABLE);
    APB2Enable(USART1_ENABLE, ENABLE);
    GPIO_Configuratioin();
    USART1_Init();
    
}