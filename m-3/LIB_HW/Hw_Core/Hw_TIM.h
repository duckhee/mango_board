#ifndef __HW_TIM_H__
#define __HW_TIM_H__

#include "Hw.h"

#define TIM_IT_Update                      ((uint16_t)0x0001)
#define TIM_IT_CC1                         ((uint16_t)0x0002)
#define TIM_IT_CC2                         ((uint16_t)0x0004)
#define TIM_IT_CC3                         ((uint16_t)0x0008)
#define TIM_IT_CC4                         ((uint16_t)0x0010)
#define TIM_IT_COM                         ((uint16_t)0x0020)
#define TIM_IT_Trigger                     ((uint16_t)0x0040)
#define TIM_IT_Break                       ((uint16_t)0x0080)

#ifdef HW_TIM_LOCAL
#define HW_TIM_DEF
#else
#define HW_TIM_DEF            extern
#endif

HW_TIM_DEF void TIM_ClearITPendingBit(TIM_TypeDef* TIMx, uint16_t TIM_IT);
HW_TIM_DEF void TIM2_IRQHandler(void);
HW_TIM_DEF void TIM_TimeBaseInit(TIM_TypeDef* TIMx, TIM_TimeBaseInitTypeDef* TIM_TimeBaseInitStruct);
HW_TIM_DEF void TIM_Start_Cmd(TIM_TypeDef* TIMx, FunctionalState NewState);
HW_TIM_DEF void TIM_Configuration(void);


#endif