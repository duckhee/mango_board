#ifndef __HW_EXTI_H__
#define __HW_EXTI_H__

#include "Hw.h"

#define EXTI_Line0       ((uint32_t)0x00001)  /*!< External interrupt line 0 */
#define EXTI_Line1       ((uint32_t)0x00002)  /*!< External interrupt line 1 */
#define EXTI_Line2       ((uint32_t)0x00004)  /*!< External interrupt line 2 */
#define EXTI_Line3       ((uint32_t)0x00008)  /*!< External interrupt line 3 */
#define EXTI_Line4       ((uint32_t)0x00010)  /*!< External interrupt line 4 */
#define EXTI_Line5       ((uint32_t)0x00020)  /*!< External interrupt line 5 */
#define EXTI_Line6       ((uint32_t)0x00040)  /*!< External interrupt line 6 */
#define EXTI_Line7       ((uint32_t)0x00080)  /*!< External interrupt line 7 */
#define EXTI_Line8       ((uint32_t)0x00100)  /*!< External interrupt line 8 */
#define EXTI_Line9       ((uint32_t)0x00200)  /*!< External interrupt line 9 */
#define EXTI_Line10      ((uint32_t)0x00400)  /*!< External interrupt line 10 */
#define EXTI_Line11      ((uint32_t)0x00800)  /*!< External interrupt line 11 */
#define EXTI_Line12      ((uint32_t)0x01000)  /*!< External interrupt line 12 */
#define EXTI_Line13      ((uint32_t)0x02000)  /*!< External interrupt line 13 */
#define EXTI_Line14      ((uint32_t)0x04000)  /*!< External interrupt line 14 */
#define EXTI_Line15      ((uint32_t)0x08000)  /*!< External interrupt line 15 */
#define EXTI_Line16      ((uint32_t)0x10000)  /*!< External interrupt line 16 Connected to the PVD Output */
#define EXTI_Line17      ((uint32_t)0x20000)  /*!< External interrupt line 17 Connected to the RTC Alarm event */
#define EXTI_Line18      ((uint32_t)0x40000)  /*!< External interrupt line 18 Connected to the USB Device/USB OTG FS
                                                   Wakeup from suspend event */
#define EXTI_Line19      ((uint32_t)0x80000)  /*!< External interrupt line 19 Connected to the Ethernet Wakeup event */ 

#define GPIO_EXTI_Line_KEY1        EXTI_Line0
#define GPIO_EXTI_Line_KEY2        EXTI_Line1

#ifdef EXTI_LOCAL
#define EXTI_DEF
#else
#define EXTI_DEF          extern
#endif

EXTI_DEF ITStatus EXTI_GetITStatus(uint32_t EXTI_Line);
EXTI_DEF void EXTI_ClearITPendingBit(uint32_t EXTI_Line);
EXTI_DEF void EXTI0_IRQHandler(void);
EXTI_DEF void EXTI1_IRQHandler(void);
EXTI_DEF void EXTI2_IRQHandler(void);
EXTI_DEF void EXTI3_IRQHandler(void);
EXTI_DEF void EXTI4_IRQHandler(void);
EXTI_DEF void EXTI5_IRQHandler(void);
EXTI_DEF void EXTI6_IRQHandler(void);
EXTI_DEF void EXTI7_IRQHandler(void);
EXTI_DEF void EXTI8_IRQHandler(void);
EXTI_DEF void EXTI9_IRQHandler(void);
EXTI_DEF void EXTI10_IRQHandler(void);
EXTI_DEF void EXTI11_IRQHandler(void);
EXTI_DEF void EXTI12_IRQHandler(void);
EXTI_DEF void EXTI13_IRQHandler(void);
EXTI_DEF void EXTI14_IRQHandler(void);
EXTI_DEF void EXTI15_IRQHandler(void);



#endif