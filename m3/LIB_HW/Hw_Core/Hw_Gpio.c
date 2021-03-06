#define GPIO_LOCAL

#include "Hw_Gpio.h"

GPIO_DEF void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct);
GPIO_DEF void GPIO_Configuratioin(void);

GPIO_DEF void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct)
{
    uint32_t currentmode = 0x00, currentpin = 0x00, pinpos = 0x00, pos = 0x00;
    uint32_t tmpreg = 0x00, pinmask = 0x00;
    /*--------------- GPIO Mode Configuration -----------------*/
    currentmode = ((uint32_t)GPIO_InitStruct->GPIO_Mode) & (uint32_t)0x0F;
    if((((uint32_t)GPIO_InitStruct->GPIO_Mode) & (uint32_t)0x10) != 0x00)
    {
        currentmode |= GPIO_InitStruct->GPIO_Speed;
    }
    /*--------------- GPIO CRL Configuration -----------------*/
    //max pin_7 = uint16_t 0x0080 pin_8 = uint16)t 0x0100
    if(((uint32_t)GPIO_InitStruct->GPIO_Pin & ((uint32_t)0x00FF)) != 0x00)
    {
        tmpreg = GPIOx->CRL;
        for(pinpos = 0x00; pinpos < 0x08; pinpos++)
        {
            pos = ((uint32_t)0x01) << pinpos;
            /* Get the port pins position */
            currentpin = (GPIO_InitStruct->GPIO_Pin) & pos;
            if(currentpin == pos)
            {
                pos = pinpos << 2;
                /* Clear the corresponding low control register bits */
                pinmask = ((uint32_t)0x0F) << pos;
                tmpreg &= ~pinmask;
                /* Write the mode configuration in the corresponding bits */
                tmpreg |= (currentmode << pos);
                /* Reset the corresponding ODR bit */
                if(GPIO_InitStruct->GPIO_Mode == GPIO_Mode_IPD)
                {
                    GPIOx->BRR = (((uint32_t)0x01) >> pinpos);
                }
                else
                {
                    /* Set the corresponding ODR bit */
                    if(GPIO_InitStruct->GPIO_Mode == GPIO_Mode_IPU)
                    {
                        GPIOx->BSRR = (((uint32_t)0x01) << pinpos);
                    }
                }
            }
        }
        GPIOx->CRL = tmpreg;
    }
    /*---------------------------- GPIO CRH Configuration ------------------------*/
  /* Configure the eight high port pins */
  //0x00ff = 1111 1111, pin_8 = 1 0000 0000
  if(GPIO_InitStruct->GPIO_Pin > 0x00FF)
  {
      tmpreg = GPIOx->CRH;
      for(pinpos = 0x00; pinpos < 0x08; pinpos++)
      {
          pos = (((uint32_t)0x01) << (pinpos + 0x08));
          /* Get the port pins position */
          currentpin = ((GPIO_InitStruct->GPIO_Pin) & pos);
          if(currentpin == pos)
          {
              pos = pinpos << 2;
              /* Clear the corresponding high control register bits */
              pinmask = ((uint32_t)0x0F) << pos;
              tmpreg &= ~pinmask;
              /* Write the mode configuration in the corresponding bits */
              
          }
      }
  }
}

GPIO_DEF void GPIO_Configuratioin(void)
{

}