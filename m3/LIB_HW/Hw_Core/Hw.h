#ifndef __HW_H__
#define __HW_H__

//include data type
#include <stdint.h>
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


#ifdef HW_LOCAL
#define HW_DEF
#else
#define HW_DEF                extern
#endif

HW_DEF void Hw_Init(void);


#endif