#define GPIO_LOCAL

#include "Hw_Gpio.h"

GPIO_DEF void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct);
GPIO_DEF void GPIO_Configuratioin(void);

GPIO_DEF void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct)
{
    uint32_t currentmode = 0x00, currentpin = 0x00, pinpos = 0x00, pos = 0x00;
    uint32_t tmpreg = 0x00, pinmask = 0x00;
    /*--------------- GPIO Mode Configuration -----------------*/
    currentmode = ((uint32_t)GPIO_InitStruct->GPIO_Mode) & (uint32_t)0x0F;
}

GPIO_DEF void GPIO_Configuratioin(void)
{

}