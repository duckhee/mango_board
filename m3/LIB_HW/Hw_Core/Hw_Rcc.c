#define RCC_LOCAL


#include "Hw_Rcc.h"

__IO uint32_t StartUpCounter = 0;

//sysclock 36MHz
RCC_DEF void HSI_Init(void)
{
    __IO uint32_t HSIStatus = 0;
    RCC->CR |= ((uint32_t)RCC_CR_HSION);
    do
    {
        HSIStatus = RCC-CR & RCC_CR_HSIRDY;
        StartUpCounter++;
    }while((HSIStatus == 0) && (StartUpCounter == 0x500));
    //flash access delay 24Mhz < SYSCLK <= 48Mhz
    FLASH->ACR |= FLASH_ACR_LATENCY_1;
    //PLL setting
    /* HCLK = SYSTICK */
    RCC->CFGR |= RCC_CFGR_HPRE_DIV1;
     /* PCLK2 = HCLK */
    RCC->CFGR |= (uint32_t)RCC_CFGR_PPRE2_DIV1;
     /* PCLK1 = HCLK */
    RCC->CFGR |= (uint32_t)RCC_CFGR_PPRE1_DIV2;
}

RCC_DEF void HSE_Init(void)
{

}