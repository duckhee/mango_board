#ifndef __HW_LED_H__
#define __HW_LED_H__

#include "Hw.h"

#define GPIO_LED             GPIOB

#define GPIO_LED1_PIN        GPIO_Pin_9 /* RED */
#define GPIO_LED2_PIN        GPIO_Pin_5 /* YELLOW */ 
#define GPIO_LED3_PIN        GPIO_Pin_8 /* BLUE */

#ifdef HW_LED_LOCAL
#define HW_LED_DEF
#else
#define HW_LED_DEF           extern
#endif

HW_LED_DEF void LED_RED_On(void);
HW_LED_DEF void LED_RED_Off(void);
HW_LED_DEF void LED_YELLOW_On(void);
HW_LED_DEF void LED_YELLOW_Off(void);
HW_LED_DEF void LED_BLUE_On(void);
HW_LED_DEF void LED_BLUE_Off(void);
HW_LED_DEF void LED_ALL_On(void);
HW_LED_DEF void LED_ALL_Off(void);
HW_LED_DEF void LED_MULT_OnOff(uint32_t count);
HW_LED_DEF void LED_TEST(void);


#endif