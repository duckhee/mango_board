#define HW_TIM_LOCAL

#include "Hw_TIM.h"

HW_TIM_DEF void TIM_ClearITPendingBit(TIM_TypeDef* TIMx, uint16_t TIM_IT);
HW_TIM_DEF void TIM2_IRQHandler(void);
HW_TIM_DEF void TIM_TimeBaseInit(TIM_TypeDef* TIMx, TIM_TimeBaseInitTypeDef* TIM_TimeBaseInitStruct);
HW_TIM_DEF void TIM_Start_Cmd(TIM_TypeDef* TIMx, FunctionalState NewState);
HW_TIM_DEF void TIM_Configuration(void);
HW_TIM_DEF void TIM_PrescalerConfig(TIM_TypeDef* TIMx, uint16_t prescaler, uint16_t TIM_PscReloadMode);
HW_TIM_DEF void TIM_ClearFlag(TIM_TypeDef* TIMx, uint16_t TIM_FLAG);


HW_TIM_DEF void TIM_Configuration(void)
{

}

HW_TIM_DEF void TIM2_IRQHandler(void)
{

}

HW_TIM_DEF void TIM_ClearITPendingBit(TIM_TypeDef* TIMx, uint16_t TIM_IT)
{
    /* Clear the IT pending Bit */
    TIMx->SR = (uint16_t)~TIM_IT;
}

HW_TIM_DEF void TIM_TimeBaseInit(TIM_TypeDef* TIMx, TIM_TimeBaseInitTypeDef* TIM_TimeBaseInitStruct)
{
    TIMx->CR1 &= TIM_CR1_CKD_Mask & TIM_CR1_CounterMode_Mask;
    TIMx->CR1 |= (uint32_t)TIM_TimeBaseInitStruct->TIM_ClockDivision | TIM_TimeBaseInitStruct->TIM_CounterMode;
    /* Set the Autoreload value */
    TIMx->ARR = TIM_TimeBaseInitStruct->TIM_Period;
    /* Set the Prescaler value */
    TIMx->PSC = TIM_TimeBaseInitStruct->TIM_Prescaler;
    if ((((uint32_t) TIMx) == TIM1_BASE) || (((uint32_t) TIMx) == TIM8_BASE))
    {
        /* Set the Repetition Counter value */
        TIMx->RCR = TIM_TimeBaseInitStruct->TIM_RepetitionCounter;
    }
    /* Generate an update event to reload the Prescaler value immediatly */
    TIMx->EGR = TIM_PSCReloadMode_Immediate;          

}

HW_TIM_DEF void TIM_Start_Cmd(TIM_TypeDef* TIMx, FunctionalState NewState)
{
    if (NewState != DISABLE)
    {
        /* Enable the TIM Counter */
        TIMx->CR1 |= TIM_CR1_CEN_Set;
    }
    else
    {
        /* Disable the TIM Counter */
        TIMx->CR1 &= TIM_CR1_CEN_Reset;
    }
}

HW_TIM_DEF void TIM_PrescalerConfig(TIM_TypeDef* TIMx, uint16_t prescaler, uint16_t TIM_PscReloadMode)
{
    /* Set the Prescaler value */
    TIMx->PSC = prescaler;
    /* Set or reset the UG Bit */
    TIMx->EGR = TIM_PscReloadMode;
}

HW_TIM_DEF void TIM_ClearFlag(TIM_TypeDef* TIMx, uint16_t TIM_FLAG)
{
    /* Clear the flags */
    TIMx->SR = (uint16_t)~TIM_FLAG;
}