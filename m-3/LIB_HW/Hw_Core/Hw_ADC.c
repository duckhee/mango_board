#define HW_ADC_LOCAL

#include "Hw_ADC.h"


HW_ADC_DEF void ADC_Init(ADC_TypeDef* ADCx, ADC_InitTypeDef* ADC_InitStruct);
HW_ADC_DEF void ADC_RegularChannelConfig(ADC_TypeDef* ADCx, uint8_t ADC_Channel, uint8_t Rank, uint8_t ADC_SampleTime);
HW_ADC_DEF void ADC_DMA_Enable_Cmd(ADC_TypeDef* ADCx, FunctionalState NewState);
HW_ADC_DEF void ADC_Enable_Cmd(ADC_TypeDef* ADCx, FunctionalState NewState);
HW_ADC_DEF void ADC_ResetCalibration(ADC_TypeDef* ADCx);
HW_ADC_DEF FlagStatus ADC_GetResetCalibrationStatus(ADC_TypeDef* ADCx);
HW_ADC_DEF void ADC_StartCalibration(ADC_TypeDef* ADCx);
HW_ADC_DEF FlagStatus ADC_GetCalibrationStatus(ADC_TypeDef* ADCx);
HW_ADC_DEF void ADC_SoftwareStartConvCmd(ADC_TypeDef* ADCx, FunctionalState NewState);
HW_ADC_DEF void ADC_Configuration(void);


HW_ADC_DEF void ADC_Configuration(void)
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


HW_ADC_DEF void ADC_Init(ADC_TypeDef* ADCx, ADC_InitTypeDef* ADC_InitStruct)
{
    uint32_t tmpreg1 = 0;
    uint8_t tmpreg2 = 0;
    
    /*---------------------------- ADCx CR1 Configuration -----------------*/
    /* Get the ADCx CR1 value */
    tmpreg1 = ADCx->CR1;
    /* Clear DUALMOD and SCAN bits */
    tmpreg1 &= ADC_CR1_CLEAR_Mask;
    /* Configure ADCx: Dual mode and scan conversion mode */
    /* Set DUALMOD bits according to ADC_Mode value */
    /* Set SCAN bit according to ADC_ScanConvMode value */    
    tmpreg1 |= (uint32_t)(ADC_InitStruct->ADC_Mode | ((uint32_t)ADC_InitStruct->ADC_ScanConvMode << 8));
    /* Write to ADCx CR1 */
    ADCx->CR1 = tmpreg1;
    /*---------------------------- ADCx CR2 Configuration -----------------*/
    /* Get the ADCx CR2 value */
    tmpreg1 = ADCx->CR2;
    /* Clear CONT, ALIGN and EXTSEL bits */
    tmpreg1 &= ADC_CR2_CLEAR_Mask;
    /* Configure ADCx: external trigger event and continuous conversion mode */
    /* Set ALIGN bit according to ADC_DataAlign value */
    /* Set EXTSEL bits according to ADC_ExternalTrigConv value */
    /* Set CONT bit according to ADC_ContinuousConvMode value */
    tmpreg1 = (uint32_t)(ADC_InitStruct->ADC_DataAlign | ADC_InitStruct->ADC_ExternalTrigConv | 
    ((uint32_t)ADC_InitStruct->ADC_ContinuousConvMode << 1));
    /* Write to ADCx CR2 */
    ADCx->CR2 = tmpreg1;
    /*---------------------------- ADCx SQR1 Configuration -----------------*/
    /* Get the ADCx SQR1 value */
    tmpreg1 = ADCx->SQR1;
    /* Clear L bits */
    tmpreg1 &= ADC_SQR1_CLEAR_Mask;
    /* Configure ADCx: regular channel sequence length */
    /* Set L bits according to ADC_NbrOfChannel value */
    tmpreg2 |= (uint8_t)(ADC_InitStruct->ADC_NbrOfChannel - (uint8_t)1);
    tmpreg1 |= (uint32_t)tmpreg2 << 20;
    /* Write to ADCx SQR1 */
    ADCx->SQR1 = tmpreg1;

}

HW_ADC_DEF void ADC_RegularChannelConfig(ADC_TypeDef* ADCx, uint8_t ADC_Channel, uint8_t Rank, uint8_t ADC_SampleTime)
{
    uint32_t tmpreg1 = 0;
    uint32_t tmpreg2 = 0;
    /* if ADC_Channel_10 ... ADC_Channel_17 is selected */
    if(ADC_Channel > ADC_Channel_9)
    {
        /* Get the old register value */
        tmpreg1 = ADCx->SMPR1;
        /* Calculate the mask to clear */
        tmpreg2 = ADC_SMPR1_SMP_Set << (3 * (ADC_Channel - 10));
        /* Clear the old channel sample time */
        tmpreg1 &= ~tmpreg2;
        /* Calculate the mask to set */
        tmpreg2 = (uint32_t)ADC_SampleTime << (3 * (ADC_Channel - 10));
        /* Set the new channel sample time */
        tmpreg1 |= tmpreg2;
        /* Store the new register value */
        ADCx->SMPR1 = tmpreg1;
    }
    /* ADC_Channel include in ADC_Channel_[0..9] */
    else
    {
        /* Get the old register value */
        tmpreg1 = ADCx->SMPR2;
        /* Calculate the mask to clear */
        tmpreg2 = ADC_SMPR2_SMP_Set << (3 * ADC_Channel);
        /* Clear the old channel sample time */
        tmpreg1 &= ~tmpreg2;
        /* Calculate the mask to set */
        tmpreg2 = (uint32_t)ADC_SampleTime << (3 * ADC_Channel);
        /* Set the new channel sample time */
        tmpreg1 |= tmpreg2;
        /* Store the new register value */
        ADCx->SMPR2 = tmpreg1;
    }
    /* For Rank 1 to 6 */
    if(Rank < 7)
    {
        /* Get the old register value */
        tmpreg1 = ADCx->SQR3;
        /* Calculate the mask to clear */
        tmpreg2 = ADC_SQR3_SQ_Set << (5 * (Rank -1));
        /* Clear the old SQx bits for the selected rank */
        tmpreg1 &= ~tmpreg2;
        /* Calculate the mask to set */
        tmpreg2 = (uint32_t)ADC_Channel << (5 * (Rank - 1));
        /* Set the SQx bits for the selected rank */
        tmpreg1 |= tmpreg2;
        /* Store the new register value */
        ADCx->SQR3 = tmpreg1;
    }
    /* For Rank 7 to 12 */
  else if (Rank < 13)
  {
    /* Get the old register value */
    tmpreg1 = ADCx->SQR2;
    /* Calculate the mask to clear */
    tmpreg2 = ADC_SQR2_SQ_Set << (5 * (Rank - 7));
    /* Clear the old SQx bits for the selected rank */
    tmpreg1 &= ~tmpreg2;
    /* Calculate the mask to set */
    tmpreg2 = (uint32_t)ADC_Channel << (5 * (Rank - 7));
    /* Set the SQx bits for the selected rank */
    tmpreg1 |= tmpreg2;
    /* Store the new register value */
    ADCx->SQR2 = tmpreg1;
  }
  /* For Rank 13 to 16 */
  else
  {
    /* Get the old register value */
    tmpreg1 = ADCx->SQR1;
    /* Calculate the mask to clear */
    tmpreg2 = ADC_SQR1_SQ_Set << (5 * (Rank - 13));
    /* Clear the old SQx bits for the selected rank */
    tmpreg1 &= ~tmpreg2;
    /* Calculate the mask to set */
    tmpreg2 = (uint32_t)ADC_Channel << (5 * (Rank - 13));
    /* Set the SQx bits for the selected rank */
    tmpreg1 |= tmpreg2;
    /* Store the new register value */
    ADCx->SQR1 = tmpreg1;
  }

}

HW_ADC_DEF void ADC_DMA_Enable_Cmd(ADC_TypeDef* ADCx, FunctionalState NewState)
{
    if(NewState != DISABLE)
    {
        ADCx->CR2 |= ADC_CR2_DMA_Set;
    }
    else
    {
        ADCx->CR2 &= ADC_CR2_DMA_Reset;
    }
}

HW_ADC_DEF void ADC_Enable_Cmd(ADC_TypeDef* ADCx, FunctionalState NewState)
{
    if(NewState != DISABLE)
    {
        ADCx->CR2 |= ADC_CR2_ADON_Set;
    }
    else
    {
        ADCx->CR2 &= ADC_CR2_ADON_Reset;
    }
}

HW_ADC_DEF void ADC_ResetCalibration(ADC_TypeDef* ADCx)
{
    /* Resets the selected ADC calibartion registers */  
    ADCx->CR2 |= ADC_CR2_RSTCAL_Set;
}

HW_ADC_DEF FlagStatus ADC_GetResetCalibrationStatus(ADC_TypeDef* ADCx)
{
    FlagStatus bitstatus = RESET;

    if((ADCx->CR2 & ADC_CR2_RSTCAL_Set) != (uint32_t)RESET)
    {
        /* RSTCAL bit is set */
        bitstatus = SET;
    }
    else
    {
        /* RSTCAL bit is reset */
        bitstatus = RESET;
    }
    /* Return the RSTCAL bit status */
    return bitstatus;
}

HW_ADC_DEF void ADC_StartCalibration(ADC_TypeDef* ADCx)
{
    /* Enable the selected ADC calibration process */  
    ADCx->CR2 |= ADC_CR2_CAL_Set;
}

HW_ADC_DEF FlagStatus ADC_GetCalibrationStatus(ADC_TypeDef* ADCx)
{
    FlagStatus bitstatus = RESET;
    /* Check the status of CAL bit */
    if((ADCx->CR2 & ADC_CR2_CAL_Set) != (uint32_t)RESET)
    {
        /* CAL bit is set: calibration on going */
        bitstatus = SET;
    }
    else
    {
        /* CAL bit is reset: end of calibration */
        bitstatus = RESET;
    }
    /* Return the CAL bit status */
    return bitstatus;
}

HW_ADC_DEF void ADC_SoftwareStartConvCmd(ADC_TypeDef* ADCx, FunctionalState NewState)
{
    if(NewState != DISABLE)
    {
        /* Enable the selected ADC conversion on external event and start the selected
        ADC conversion */
        ADCx->CR2 |= ADC_CR2_EXTTRIG_SWSTART_Set;
    }
    else
    {
        /* Disable the selected ADC conversion on external event and stop the selected
       ADC conversion */
       ADCx->CR2 &= ADC_CR2_EXTTRIG_SWSTART_Reset;
    }
}