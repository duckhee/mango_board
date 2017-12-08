#ifndef __HW_RCC_H__
#define __HW_RCC_H__

#include "Hw.h"

/********************  Bit definition for RCC_CR register  ********************/
#define  RCC_CR_HSION                        ((uint32_t)0x00000001)        /*!< Internal High Speed clock enable */
#define  RCC_CR_HSIRDY                       ((uint32_t)0x00000002)        /*!< Internal High Speed clock ready flag */
#define  RCC_CR_HSITRIM                      ((uint32_t)0x000000F8)        /*!< Internal High Speed clock trimming */
#define  RCC_CR_HSICAL                       ((uint32_t)0x0000FF00)        /*!< Internal High Speed clock Calibration */
#define  RCC_CR_HSEON                        ((uint32_t)0x00010000)        /*!< External High Speed clock enable */
#define  RCC_CR_HSERDY                       ((uint32_t)0x00020000)        /*!< External High Speed clock ready flag */
#define  RCC_CR_HSEBYP                       ((uint32_t)0x00040000)        /*!< External High Speed clock Bypass */
#define  RCC_CR_CSSON                        ((uint32_t)0x00080000)        /*!< Clock Security System enable */
#define  RCC_CR_PLLON                        ((uint32_t)0x01000000)        /*!< PLL enable */
#define  RCC_CR_PLLRDY                       ((uint32_t)0x02000000)        /*!< PLL clock ready flag */

//System clock switch
#define SW_HSI_SYSCLOCK                      ((uint32_t)0x00000000)
#define SW_HSE_SYSCLOCK                      ((uint32_t)0x00000001)
#define SW_PLL_SYSCLOCK                      ((uint32_t)0x00000002)
#define SW_NOT_ALLOWED                       ((uint32_t)0x00000003)
//System clock mask
#define SWS_MASK                             ((uint32_t)0x0000000C)
//ADC PREscaler
#define ADCPRE_PLCK2_DIVIDED2                ((uint32_t)0x00000000)
#define ADCPRE_PLCK2_DIVIDED4                ((uint32_t)0x00004000)
#define ADCPRE_PLCK2_DIVIDED6                ((uint32_t)0x00006000)
#define ADCPRE_PLCK2_DIVIDED8                ((uint32_t)0x0000C000)
//APB2 PREscaler
#define APB2_PCLK2_NOT_DIVIDED               ((uint32_t)0x00000000)
#define APB2_PCLK2_DIVIDED2                  ((uint32_t)0x00002000)
#define APB2_PCLK2_DIVIDED4                  ((uint32_t)0x00002800)
#define APB2_PCLK2_DIVIDED8                  ((uint32_t)0x00003000)
#define APB2_PCLK2_DIVIDED16                 ((uint32_t)0x00003800)
//APB1 PREscaler
#define APB1_PCLK1_NOT_DIVIDED               ((uint32_t)0x00000000)
#define APB1_PCLK1_DIVIDED2                  ((uint32_t)0x00000400)
#define APB1_PCLK1_DIVIDED4                  ((uint32_t)0x00000500)
#define APB1_PCLK1_DIVIDED8                  ((uint32_t)0x00000600)
#define APB1_PCLK1_DIVIDED16                 ((uint32_t)0x00000700)
//AHB PREsacler
#define SYSCLK_NOT_DIVIDED                   ((uint32_t)0x00000000)
#define SYSCLK_DIVIDED2                      ((uint32_t)0x00000080)
#define SYSCLK_DIVIDED4                      ((uint32_t)0x00000090)
#define SYSCLK_DIVIDED8                      ((uint32_t)0x000000A0)
#define SYSCLK_DIVIDED16                     ((uint32_t)0x000000B0)
#define SYSCLK_DIVIDED64                     ((uint32_t)0x000000C0)
#define SYSCLK_DIVIDED128                    ((uint32_t)0x000000D0)
#define SYSCLK_DIVIDED256                    ((uint32_t)0x000000E0)
#define SYSCLK_DIVIDED512                    ((uint32_t)0x000000F0)
//pll use hse or hsi
#define PLLSRC_HSI                           ((uint32_t)0x00000000)
#define PLLSRC_HSE                           ((uint32_t)0x00010000)        /*!< HSE clock selected as PLL entry clock source */
//pll mult
#define PLL_INPUT_MULT2                      ((uint32_t)0x00000000)
#define PLL_INPUT_MULT3                      ((uint32_t)0x00040000)
#define PLL_INPUT_MULT4                      ((uint32_t)0x00080000)
#define PLL_INPUT_MULT5                      ((uint32_t)0x000C0000)
#define PLL_INPUT_MULT6                      ((uint32_t)0x00100000)
#define PLL_INPUT_MULT7                      ((uint32_t)0x00140000)
#define PLL_INPUT_MULT8                      ((uint32_t)0x00180000)
#define PLL_INPUT_MULT9                      ((uint32_t)0x001C0000)
#define PLL_INPUT_MULT10                     ((uint32_t)0x00200000)
#define PLL_INPUT_MULT11                     ((uint32_t)0x00240000)
#define PLL_INPUT_MULT12                     ((uint32_t)0x00280000)
#define PLL_INPUT_MULT13                     ((uint32_t)0x002C0000)
#define PLL_INPUT_MULT14                     ((uint32_t)0x00300000)
#define PLL_INPUT_MULT15                     ((uint32_t)0x00340000)
#define PLL_INPUT_MULT16                     ((uint32_t)0x00380000)
#define PLL_INPUT_MULT2_16                     ((uint32_t)0x003C0000)






#ifdef RCC_LOCAL
#define RCC_DEF
#else
#define RCC_DEF              extern
#endif

RCC_DEF void HSI_Init(void);
RCC_DEF void HSE_Init(void);


#endif