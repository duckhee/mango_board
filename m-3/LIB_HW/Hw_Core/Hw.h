#ifndef __HW_H__
#define __HW_H__


#include<stdint.h>
//register header
#include "Hw_Reg.h"
//rcc header
#include "Hw_Rcc.h"
//flash header
#include "Hw_Flash.h"
//gpio header
#include "Hw_Gpio.h"
//usart header
#include "Hw_Usart.h"
//nvic header
#include "Hw_NVIC.h"
//EXTI header
#include "Hw_EXTI.h"
//systick header
#include "Hw_SysTick.h"
//tim header
#include "Hw_TIM.h"
//dma header
#include "Hw_DMA.h"
//adc header
#include "Hw_ADC.h"
//hw lib header
#include "Hw_Led.h"
#include "Hw_Key.h"
#include "Hw_Seg.h"
//lib util
#include "Util.h"

#ifdef HW_LOCAL
#define HW_DEF
#else
#define HW_DEF                   extern
#endif

HW_DEF void Hw_Init(void);

#endif