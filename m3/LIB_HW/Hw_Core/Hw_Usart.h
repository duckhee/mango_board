#ifndef __HW_USART_H__
#define __HW_USART_H__

#include "Hw.h"


#define GPIO_USART1            GPIOA
#define GPIO_USART1_Rx_Pin     GPIO_Pin_10
#define GPIO_USART1_Tx_Pin     GPIO_Pin_9


#ifdef USART_LOCAL
#define USART_DEF
#else
#define USART_DEF            extern
#endif




#endif