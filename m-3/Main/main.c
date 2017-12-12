#include "main.h"

__IO uint16_t ADCConvertedValue;

int main()
{
    float volt = 0;
    Hw_Init();
    NVIC_Configuration();
    EXTI_Configuration();
    TIM_Configuration();
    System_Information();
    DMA_Configuration();
    ADC_Configuration();
    printf("testing!\n");
    Hw_1_second();
    volt = (float) ADCConvertedValue * 3.3 / (float) 4095;
    printf("ADCConvertedValue: 0x%0X, %d, Volt: %f V\n",
               ADCConvertedValue, ADCConvertedValue, volt);
    Hw_1_second();
}