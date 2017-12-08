#ifndef __HW_NVIC_H__
#define __HW_NVIC_H__

#include "Hw.h"

#define NVIC_VectTab_RAM             ((uint32_t)0x20000000)
#define NVIC_VectTab_FLASH           ((uint32_t)0x08000000)

#ifdef HW_NVIC_LOCAL
#define HW_NVIC_DEF
#else
#define HW_NVIC_DEF                extern
#endif


HW_NVIC_DEF void NVIC_PriorityGroupConfig(uint32_t NVIC_PriorityGroup);
HW_NVIC_DEF void NVIC_SetVectorTable(uint32_t NVIC_VectTab, uint32_t Offset);
HW_NVIC_DEF void NVIC_Configuration(void);
HW_NVIC_DEF void NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority);
HW_NVIC_DEF void NVIC_PriorityGroupConfig(uint32_t NVIC_PriorityGroup);
HW_NVIC_DEF void NVIC_Init(NVIC_InitTypeDef* NVIC_InitStruct);


#endif