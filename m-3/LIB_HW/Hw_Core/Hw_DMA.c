#define HW_DMA_LOCAL

#include "Hw_DMA.h"

__IO uint16_t ADCConvertedValue;

HW_DMA_DEF void DMA_Start_Cmd(DMA_Channel_TypeDef* DMAy_Channelx, FunctionalState NewState);
HW_DMA_DEF void DMA_Init(DMA_Channel_TypeDef* DMAy_Channelx, DMA_InitTypeDef* DMA_InitStruct);
HW_DMA_DEF void DMA_DeInit(DMA_Channel_TypeDef* DMAy_Channelx);
HW_DMA_DEF void DMA_Configuration(void);

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

HW_DMA_DEF void DMA_Start_Cmd(DMA_Channel_TypeDef* DMAy_Channelx, FunctionalState NewState)
{
    if(NewState != DISABLE)
    {
        /* Enable the selected DMAy Channelx */
        DMAy_Channelx->CCR |= DMA_CCR1_EN;
    }
    else
    {
        /* Disable the selected DMAy Channelx */
        DMAy_Channelx->CCR &= (uint16_t)(~DMA_CCR1_EN);
    }
}

HW_DMA_DEF void DMA_Init(DMA_Channel_TypeDef* DMAy_Channelx, DMA_InitTypeDef* DMA_InitStruct)
{
    uint32_t tmpreg = 0;
    /*--------------------------- DMAy Channelx CCR Configuration -----------------*/
    /* Get the DMAy_Channelx CCR value */
    tmpreg = DMAy_Channelx->CCR;
    /* Clear MEM2MEM, PL, MSIZE, PSIZE, MINC, PINC, CIRC and DIR bits */
    tmpreg &= DMA_CCR_CLEAR_Mask;
    /* Configure DMAy Channelx: data transfer, data size, priority level and mode */
    /* Set DIR bit according to DMA_DIR value */
    /* Set CIRC bit according to DMA_Mode value */
    /* Set PINC bit according to DMA_PeripheralInc value */
    /* Set MINC bit according to DMA_MemoryInc value */
    /* Set PSIZE bits according to DMA_PeripheralDataSize value */
    /* Set MSIZE bits according to DMA_MemoryDataSize value */
    /* Set PL bits according to DMA_Priority value */
    /* Set the MEM2MEM bit according to DMA_M2M value */
    tmpreg |= DMA_InitStruct->DMA_DIR | DMA_InitStruct->DMA_Mode |
     DMA_InitStruct->DMA_PeripheralInc | DMA_InitStruct->DMA_MemoryInc |
     DMA_InitStruct->DMA_PeripheralDataSize | DMA_InitStruct->DMA_MemoryDataSize |
     DMA_InitStruct->DMA_Priority | DMA_InitStruct->DMA_M2M ;

    /* Write to DMAy Channelx CCR */
    DMAy_Channelx->CCR = tmpreg;
    /*--------------------------- DMAy Channelx CNDTR Configuration ---------------*/
    /* Write to DMAy Channelx CNDTR */
    DMAy_Channelx->CNDTR = DMA_InitStruct->DMA_BufferSize;
    /*--------------------------- DMAy Channelx CPAR Configuration ----------------*/
    /* Write to DMAy Channelx CPAR */
    DMAy_Channelx->CPAR = DMA_InitStruct->DMA_PeripheralBaseAddr;
    /*--------------------------- DMAy Channelx CMAR Configuration ----------------*/
    /* Write to DMAy Channelx CMAR */
    DMAy_Channelx->CMAR = DMA_InitStruct->DMA_MemoryBaseAddr;

}

HW_DMA_DEF void DMA_DeInit(DMA_Channel_TypeDef* DMAy_Channelx)
{
/* Disable the selected DMAy Channelx */
  DMAy_Channelx->CCR &= DMA_CCR_ENABLE_Reset;
  /* Reset DMAy Channelx control register */
  DMAy_Channelx->CCR  = 0;
  
  /* Reset DMAy Channelx remaining bytes register */
  DMAy_Channelx->CNDTR = 0;
  
  /* Reset DMAy Channelx peripheral address register */
  DMAy_Channelx->CPAR  = 0;
  
  /* Reset DMAy Channelx memory address register */
  DMAy_Channelx->CMAR = 0;
  
  if (DMAy_Channelx == DMA1_Channel1)
  {
    /* Reset interrupt pending bits for DMA1 Channel1 */
    DMA1->IFCR |= DMA1_Channel1_IT_Mask;
  }
  else if (DMAy_Channelx == DMA1_Channel2)
  {
    /* Reset interrupt pending bits for DMA1 Channel2 */
    DMA1->IFCR |= DMA1_Channel2_IT_Mask;
  }
  else if (DMAy_Channelx == DMA1_Channel3)
  {
    /* Reset interrupt pending bits for DMA1 Channel3 */
    DMA1->IFCR |= DMA1_Channel3_IT_Mask;
  }
  else if (DMAy_Channelx == DMA1_Channel4)
  {
    /* Reset interrupt pending bits for DMA1 Channel4 */
    DMA1->IFCR |= DMA1_Channel4_IT_Mask;
  }
  else if (DMAy_Channelx == DMA1_Channel5)
  {
    /* Reset interrupt pending bits for DMA1 Channel5 */
    DMA1->IFCR |= DMA1_Channel5_IT_Mask;
  }
  else if (DMAy_Channelx == DMA1_Channel6)
  {
    /* Reset interrupt pending bits for DMA1 Channel6 */
    DMA1->IFCR |= DMA1_Channel6_IT_Mask;
  }
  else if (DMAy_Channelx == DMA1_Channel7)
  {
    /* Reset interrupt pending bits for DMA1 Channel7 */
    DMA1->IFCR |= DMA1_Channel7_IT_Mask;
  }
  else if (DMAy_Channelx == DMA2_Channel1)
  {
    /* Reset interrupt pending bits for DMA2 Channel1 */
    DMA2->IFCR |= DMA2_Channel1_IT_Mask;
  }
  else if (DMAy_Channelx == DMA2_Channel2)
  {
    /* Reset interrupt pending bits for DMA2 Channel2 */
    DMA2->IFCR |= DMA2_Channel2_IT_Mask;
  }
  else if (DMAy_Channelx == DMA2_Channel3)
  {
    /* Reset interrupt pending bits for DMA2 Channel3 */
    DMA2->IFCR |= DMA2_Channel3_IT_Mask;
  }
  else if (DMAy_Channelx == DMA2_Channel4)
  {
    /* Reset interrupt pending bits for DMA2 Channel4 */
    DMA2->IFCR |= DMA2_Channel4_IT_Mask;
  }
  else
  { 
    if (DMAy_Channelx == DMA2_Channel5)
    {
      /* Reset interrupt pending bits for DMA2 Channel5 */
      DMA2->IFCR |= DMA2_Channel5_IT_Mask;
    }
  }
}