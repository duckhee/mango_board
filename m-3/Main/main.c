#include "main.h"

__IO uint16_t ADCConvertedValue;

HW_DMA_DEF void DMA_Configuration(void)
{
    DMA_InitTypeDef DMA_InitStructure;

    /* DMA1 channel1 configuration */
    DMA_DeInit(DMA1_Channel1);
    DMA_InitStructure.DMA_PeripheralBaseAddr = ADC1_DR_Address;
    DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)&ADCConvertedValue;
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
    DMA_InitStructure.DMA_BufferSize = 1;
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Disable;
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_MemoryDataSize_HalfWord;
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
    DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
    DMA_InitStructure.DMA_Priority = DMA_Priority_High;
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
    DMA_Init(DMA1_Channel1, &DMA_InitStructure);

    /* Enable DMA1 Channel1 */
    DMA_Start_Cmd(DMA1_Channel1, ENABLE);
}


int main()
{
    float volt = 0;
    Hw_Init();
    NVIC_Configuration();
    EXTI_Configuration();
    //TIM_Configuration();
    System_Information();
    DMA_Configuration();
    ADC_Configuration();
    printf("testing!\n");
    while (1)
    {
        Delay(1000);

        volt = (float) ADCConvertedValue * 3.3 / (float) 4095;
        printf("ADCConvertedValue: 0x%0X, %d, Volt: %f V\n", ADCConvertedValue, ADCConvertedValue, volt);
        Hw_1_second();
    }
}