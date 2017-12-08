#define HW_LED_LOCAL

#include "Hw_Led.h"

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


HW_LED_DEF void LED_RED_On(void)
{
    GPIO_LED->BRR |= GPIO_LED1_PIN;
}
HW_LED_DEF void LED_RED_Off(void)
{
    GPIO_LED->BSRR |= GPIO_LED1_PIN;
}
HW_LED_DEF void LED_YELLOW_On(void)
{
    GPIO_LED->BRR |= GPIO_LED2_PIN;
}
HW_LED_DEF void LED_YELLOW_Off(void)
{
    GPIO_LED->BSRR |= GPIO_LED2_PIN;
}
HW_LED_DEF void LED_BLUE_On(void)
{
    GPIO_LED->BRR |= GPIO_LED3_PIN;
}
HW_LED_DEF void LED_BLUE_Off(void)
{
    GPIO_LED->BSRR |= GPIO_LED3_PIN;
}
HW_LED_DEF void LED_ALL_On(void)
{
    LED_RED_On();
    LED_YELLOW_On();
    LED_BLUE_On();
}
HW_LED_DEF void LED_ALL_Off(void)
{
    LED_RED_Off();
    LED_YELLOW_Off();
    LED_BLUE_Off();
}
HW_LED_DEF void LED_MULT_OnOff(uint32_t count)
{
    for(; count > 0; count --)
    {
        LED_RED_Off();
        LED_YELLOW_On();
        LED_BLUE_On();
        Hw_1_second();

        LED_RED_On();
        LED_YELLOW_Off();
        LED_BLUE_On();
        Hw_1_second();

        LED_RED_On();
        LED_YELLOW_On();
        LED_BLUE_Off();
        Hw_1_second();
    }
}
HW_LED_DEF void LED_TEST(void)
{
    #if 0
        LED_ALL_On();
        Hw_1_second();
        LED_ALL_Off();
        Hw_1_second();
        LED_ALL_On();
    #else
        LED_MULT_OnOff(30);
    #endif
}