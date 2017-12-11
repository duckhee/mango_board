#define HW_SEG_LOCAL

#include "Hw_Seg.h"

HW_SEG_DEF void POWER_SEG_On(void);
HW_SEG_DEF void POWER_SEG_Off(void);
HW_SEG_DEF void SEG_OnePin_On(uint16_t pinNum);
HW_SEG_DEF void SEG_OnePin_Off(uint16_t pinNum);
HW_SEG_DEF void SEG_AllPin_On(void);
HW_SEG_DEF void SEG_AllPin_Off(void);
HW_SEG_DEF void SEG_Number_On(unsigned int num);
HW_SEG_DEF void SEG_TEST(void);

HW_SEG_DEF void POWER_SEG_On(void)
{
    GPIO_7_SEG->BRR |= GPIO_7_SEG_POWER_PIN;
}

HW_SEG_DEF void POWER_SEG_Off(void)
{
    GPIO_7_SEG->BSRR |= GPIO_7_SEG_POWER_PIN;
}

HW_SEG_DEF void SEG_OnePin_On(uint16_t pinNum)
{
    GPIO_7_SEG->BRR |= pinNum;
}

HW_SEG_DEF void SEG_OnePin_Off(uint16_t pinNum)
{
    GPIO_7_SEG->BSRR |= pinNum;
}

HW_SEG_DEF void SEG_AllPin_On(void)
{
    SEG_OnePin_On(GPIO_7_SEG_A_PIN | GPIO_7_SEG_B_PIN | GPIO_7_SEG_C_PIN
         | GPIO_7_SEG_D_PIN | GPIO_7_SEG_E_PIN | GPIO_7_SEG_F_PIN
         | GPIO_7_SEG_G_PIN | GPIO_7_SEG_DP_PIN);
}

HW_SEG_DEF void SEG_AllPin_Off(void)
{
    SEG_OnePin_Off(GPIO_7_SEG_A_PIN | GPIO_7_SEG_B_PIN | GPIO_7_SEG_C_PIN
         | GPIO_7_SEG_D_PIN | GPIO_7_SEG_E_PIN | GPIO_7_SEG_F_PIN
         | GPIO_7_SEG_G_PIN | GPIO_7_SEG_DP_PIN);
}

HW_SEG_DEF void SEG_Number_On(unsigned int num)
{
    SEG_AllPin_Off();

    switch(num)
    {
        case 0 :
            SEG_OnePin_On(GPIO_7_SEG_A_PIN | GPIO_7_SEG_B_PIN | GPIO_7_SEG_C_PIN | GPIO_7_SEG_D_PIN | GPIO_7_SEG_E_PIN | GPIO_7_SEG_F_PIN);
        break;

        case 1 :
                SEG_OnePin_On(GPIO_7_SEG_B_PIN | GPIO_7_SEG_C_PIN);
        break;
        
        case 2 :
                SEG_OnePin_On(GPIO_7_SEG_A_PIN | GPIO_7_SEG_B_PIN | GPIO_7_SEG_D_PIN | GPIO_7_SEG_E_PIN | GPIO_7_SEG_G_PIN);
        break;
                    
        case 3 :
                SEG_OnePin_On(GPIO_7_SEG_A_PIN | GPIO_7_SEG_B_PIN | GPIO_7_SEG_C_PIN | GPIO_7_SEG_D_PIN | GPIO_7_SEG_G_PIN);
        break;
                
        case 4 :
                SEG_OnePin_On(GPIO_7_SEG_B_PIN | GPIO_7_SEG_C_PIN | GPIO_7_SEG_F_PIN | GPIO_7_SEG_G_PIN);
        break;

        case 5 :
                SEG_OnePin_On(GPIO_7_SEG_A_PIN | GPIO_7_SEG_C_PIN | GPIO_7_SEG_D_PIN | GPIO_7_SEG_F_PIN | GPIO_7_SEG_G_PIN);
        break;

        case 6 :
                SEG_OnePin_On(GPIO_7_SEG_A_PIN | GPIO_7_SEG_C_PIN | GPIO_7_SEG_D_PIN | GPIO_7_SEG_E_PIN | GPIO_7_SEG_F_PIN | GPIO_7_SEG_G_PIN);
        break;

        case 7 :
                SEG_OnePin_On(GPIO_7_SEG_A_PIN | GPIO_7_SEG_B_PIN | GPIO_7_SEG_C_PIN | GPIO_7_SEG_F_PIN);
        break;

        case 8 :
                SEG_OnePin_On(GPIO_7_SEG_A_PIN | GPIO_7_SEG_B_PIN | GPIO_7_SEG_C_PIN | GPIO_7_SEG_D_PIN | GPIO_7_SEG_E_PIN | GPIO_7_SEG_F_PIN | GPIO_7_SEG_G_PIN);
        break;
        
        case 9 : 
                SEG_OnePin_On(GPIO_7_SEG_A_PIN | GPIO_7_SEG_B_PIN | GPIO_7_SEG_C_PIN | GPIO_7_SEG_D_PIN | GPIO_7_SEG_F_PIN | GPIO_7_SEG_G_PIN);
        break;
    }
}

HW_SEG_DEF void SEG_TEST(void)
{
    int i;

    SEG_OnePin_On(GPIO_7_SEG_A_PIN);
    Hw_1_second();
    SEG_OnePin_On(GPIO_7_SEG_B_PIN);
    Hw_1_second();
    SEG_OnePin_On(GPIO_7_SEG_C_PIN);
    Hw_1_second();
    SEG_OnePin_On(GPIO_7_SEG_D_PIN);
    Hw_1_second();
    SEG_OnePin_On(GPIO_7_SEG_E_PIN);
    Hw_1_second();
    SEG_OnePin_On(GPIO_7_SEG_F_PIN);
    Hw_1_second();
    SEG_OnePin_On(GPIO_7_SEG_G_PIN);
    Hw_1_second();
    SEG_OnePin_On(GPIO_7_SEG_DP_PIN);
    Hw_1_second();

    for(i = 0; i < 10; i++)
    {
        SEG_Number_On(i);
        Hw_1_second();
    }
}
