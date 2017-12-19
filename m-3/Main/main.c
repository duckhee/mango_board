#include "main.h"

__IO uint16_t ADCConvertedValue;

void DMA_Configuration(void)
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
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
    DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
    DMA_InitStructure.DMA_Priority = DMA_Priority_High;
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
    DMA_Init(DMA1_Channel1, &DMA_InitStructure);

    /* Enable DMA1 Channel1 */
    DMA_Start_Cmd(DMA1_Channel1, ENABLE);
}

void ADC_Configuration(void)
{
    ADC_InitTypeDef ADC_InitStructure;
    /* ADC1 Configuration */
    ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
    ADC_InitStructure.ADC_ScanConvMode = DISABLE;
    ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
    ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
    ADC_InitStructure.ADC_NbrOfChannel = 1;
    ADC_Init(ADC1, &ADC_InitStructure);
    
    /* ADC1 regular channel14 configuration */ 
    ADC_RegularChannelConfig(ADC1, ADC_Channel_14, 1, ADC_SampleTime_55Cycles5);

    /* Enable ADC1 DMA */
    ADC_DMA_Enable_Cmd(ADC1, ENABLE);

    /* Enable ADC1 */
    ADC_Enable_Cmd(ADC1, ENABLE);

    /* Enable ADC1 reset calibaration register */   
    ADC_ResetCalibration(ADC1);
    /* Check the end of ADC1 reset calibration register */
    while(ADC_GetResetCalibrationStatus(ADC1));

    /* Start ADC1 calibaration */
    ADC_StartCalibration(ADC1);
    /* Check the end of ADC1 calibration */
    while(ADC_GetCalibrationStatus(ADC1));

    /* Start ADC1 Software Conversion */ 
    ADC_SoftwareStartConvCmd(ADC1, ENABLE);
}

RCC_ClocksTypeDef  rcc_clocks;
int AD_value;
int timeout = 7200000;
float test_value;
int main()
{
    float volt = 0.0;
    Hw_Init();
    RCC_GetClocksFreq(&rcc_clocks);
    NVIC_Configuration();
    EXTI_Configuration();
    //TIM_Configuration();
    System_Information();
    DMA_Configuration();
    ADC_Configuration();
    printf("testing!\n");
    float test = 3.14;
    while (1)
    {
        Delay(1000);
        volt = (float) ADCConvertedValue * 3.3 / (float) 4095;
        
        printf("ADCConvertedValue: %d\n", ADCConvertedValue);
        printf("%f\n", test);
        printf("volt :%f V\n", volt);
        AD_value = ADC_GetConversionValue(ADC1);
        
    }
}