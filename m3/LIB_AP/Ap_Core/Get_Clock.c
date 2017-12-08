#define GET_CLOCK_LOCAL

#include "Get_Clock.h"



GET_CLOCK_DEF void System_Information(void);

extern __IO uint32_t StartUpCouter;

GET_CLOCK_DEF void System_Information(void)
{
    RCC_ClocksTypeDef rcc_clock;
    printf("StartupCounter : %d\n", StartUpCouter);
    Rcc_GetClocksFreq(&rcc_clock);
    printf("System clock frequency = %d\n", rcc_clock.SYSCLK_Frequency);
    printf("HCLK_Freqeuncy : %d\n", rcc_clock.HCLK_Frequency);
    printf("PCLK1_Frequency : %d\n", rcc_clock.PCLK1_Frequency);
    printf("PCLK2_Frequency : %d\n", rcc_clock.PCLK2_Frequency);
    printf("ADCCLK_Frequency : %d\n", rcc_clock.ADCCLK_Frequency);

}