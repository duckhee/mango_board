#ifndef __HW_SEG_H__
#define __HW_SEG_H__

#include "Hw.h"

#define GPIO_7_SEG_POWER_PIN    GPIO_Pin_8
#define GPIO_7_SEG_A_PIN        GPIO_Pin_0
#define GPIO_7_SEG_B_PIN        GPIO_Pin_1
#define GPIO_7_SEG_C_PIN        GPIO_Pin_2
#define GPIO_7_SEG_D_PIN        GPIO_Pin_3
#define GPIO_7_SEG_E_PIN        GPIO_Pin_4
#define GPIO_7_SEG_F_PIN        GPIO_Pin_5
#define GPIO_7_SEG_G_PIN        GPIO_Pin_7
#define GPIO_7_SEG_DP_PIN       GPIO_Pin_6

#define GPIO_7_SEG              GPIOC

#ifdef HW_SEG_LOCAL
#define HW_SEG_DEF
#else 
#define HW_SEG_DEF              extern
#endif

HW_SEG_DEF void POWER_SEG_On(void);
HW_SEG_DEF void POWER_SEG_Off(void);
HW_SEG_DEF void SEG_OnePin_On(uint16_t pinNum);
HW_SEG_DEF void SEG_OnePin_Off(uint16_t pinNum);
HW_SEG_DEF void SEG_AllPin_On(void);
HW_SEG_DEF void SEG_AllPin_Off(void);
HW_SEG_DEF void SEG_Number_On(unsigned int num);
HW_SEG_DEF void SEG_TEST(void);

#endif