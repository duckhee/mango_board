#define ADC_LOCAL

#include "Hw_ADC.h"


ADC_DEF void ADC_Init(ADC_TypeDef* ADCx, ADC_InitTypeDef* ADC_InitStruct);
ADC_DEF void ADC_Config(void);

ADC_DEF void ADC_Init(ADC_TypeDef* ADCx, ADC_InitTypeDef* ADC_InitStruct)
{
    uint32_t tmpreg1 = 0x00;
    uint32_t tmpreg2 = 0x00;
    /*---------------------------- ADCx CR1 Configuration -----------------*/
    /* Get the ADCx CR1 value */
    tmpreg1 = ADCx->CR1;
    tmpreg1 &= ADC_CR1_CLEAR_Mask;
    tmpreg1 |= (uint32_t)(ADC_InitStruct->ADC_Mode | ((uint32_t)ADC_InitStruct->ADC_ScanConvMode << 8));
}

ADC_DEF void ADC_Config(void)
{
    
}