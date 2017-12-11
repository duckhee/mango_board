#define HW_TIM_LOCAL

#include "Hw_TIM.h"

HW_TIM_DEF void TIM_ClearITPendingBit(TIM_TypeDef* TIMx, uint16_t TIM_IT);
HW_TIM_DEF void TIM2_IRQHandler(void);
HW_TIM_DEF void TIM_TimeBaseInit(TIM_TypeDef* TIMx, TIM_TimeBaseInitTypeDef* TIM_TimeBaseInitStruct);
HW_TIM_DEF void TIM_Start_Cmd(TIM_TypeDef* TIMx, FunctionalState NewState);
HW_TIM_DEF void TIM_Configuration(void);