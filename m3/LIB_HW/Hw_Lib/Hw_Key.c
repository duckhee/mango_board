#define HW_KEY_LOCAL

#include "Hw_Key.h"


HW_KEY_DEF void KEY_TEST();

HW_KEY_DEF void KEY_TEST()
{
    uint32_t i = 0;
    LED_ALL_Off();

    while(1)
    {
        Hw_1_second();
        if((i++ & 0x1) == 0x0)
        {
            LED_BLUE_On();
        }
        else
        {
            LED_BLUE_Off();
        }

        if(GPIO_ReadInputDataBit(GPIO_KEY, GPIO_KEY1_PIN) == Bit_SET)
        {
            LED_RED_On();
        }
        else
        {
            LED_RED_Off();
        }

        if(GPIO_ReadInputDataBit(GPIO_KEY, GPIO_KEY2_PIN) == Bit_SET)
        {
            LED_YELLOW_On();
        }
        else
        {
            LED_YELLOW_Off();
        }
    }
}