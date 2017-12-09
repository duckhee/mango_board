#ifndef __HW_ADC_H__
#define __HW_ADC_H__

#include "Hw.h"

#define ADC_CR1_CLEAR_Mask              ((uint32_t)0xFFF0FEFF)

#ifdef ADC_LOCAL
#define ADC_DEF
#else
#define ADC_DEF              extern
#endif

ADC_DEF void ADC_Init(ADC_TypeDef* ADCx, ADC_InitTypeDef* ADC_InitStruct);
ADC_DEF void ADC_Config(void);



#endif