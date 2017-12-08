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
        HSIStatus = RCC->CR & RCC_CR_HSIRDY;
        StartUpCounter++;
    }while((HSIStatus == 0) && (StartUpCounter == 0x500));
    //flash access delay 24Mhz < SYSCLK <= 48Mhz
    FLASH->ACR |= FLASH_ACR_LATENCY_1;
    //PLL setting
    /* HCLK = SYSTICK */
    RCC->CFGR |= (uint32_t)SYSCLK_NOT_DIVIDED;
    /* PCLK2 = HCLK */
    RCC->CFGR |= (uint32_t)APB2_PCLK2_NOT_DIVIDED;
    /* PCLK1 = HCLK */
    RCC->CFGR |= (uint32_t)APB1_PCLK1_DIVIDED2;
    /* ADC = set div 4 */
    RCC->CFGR |= (uint32_t)ADCPRE_PLCK2_DIVIDED4;
    /* PLL ON */
    RCC->CR |= RCC_CR_PLLON;
    /* Wait till PLL is ready */
    while((RCC->CR & RCC_CR_PLLRDY) == 0)
    {
        ;
    }
    /* select PLL as system clock source */
    RCC->CFGR |= (uint32_t)SW_PLL_SYSCLOCK;
    /* Wailt til PLL is used as system clock source */
    while((RCC->CFGR & (uint32_t)SWS_MASK) != ((uint32_t)0x08))
    {
        ; //조건을 만족하면 여기 pll 준비가 안되어 있다는 것
    }
}


RCC_DEF void HSE_Init(void)
{
    __IO uint32_t HSEStatus = 0;
    RCC->CR |= ((uint32_t)RCC_CR_HSEON);
    do
    {
        HSEStatus = RCC->CR & RCC_CR_HSERDY;
        StartUpCounter++;
    }while((HSEStatus == 0) && (StartUpCounter == 0x500));
    //flash access delay 48MHz < SYSCLOCK <=72MHz
    FLASH->ACR |= FLASH_ACR_LATENCY_2;
     //PLL setting
    /* HCLK = SYSTICK */
    RCC->CFGR |= (uint32_t)SYSCLK_NOT_DIVIDED;
    /* PCLK2 = HCLK */
    RCC->CFGR |= (uint32_t)APB2_PCLK2_NOT_DIVIDED;
    /* PCLK1 = HCLK */
    RCC->CFGR |= (uint32_t)APB1_PCLK1_DIVIDED2;
    /* ADC = set div 6 */
    RCC->CFGR |= (uint32_t)ADCPRE_PLCK2_DIVIDED6;
    /* PLL configuration : PLLCLK = HSE * 6 = 72MHz */
    RCC->CFGR |= (uint32_t)(PLLSRC_HSE | PLL_INPUT_MULT6);
    /* PLL ON */
    RCC->CR |= RCC_CR_PLLON;
    /* Wait till PLL is ready */
    while((RCC->CR & RCC_CR_PLLRDY) == 0)
    {
        ;
    }
    /* select PLL as system clock source */
    RCC->CFGR |= (uint32_t)SW_PLL_SYSCLOCK;
    /* Wailt til PLL is used as system clock source */
    while((RCC->CFGR & (uint32_t)SWS_MASK) != ((uint32_t)0x08))
    {
        ; //조건을 만족하면 여기 pll 준비가 안되어 있다는 것
    }
}