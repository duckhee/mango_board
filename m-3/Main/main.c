#include "main.h"

int main()
{
    Hw_Init();
    NVIC_Configuration();
    EXTI_Configuration();
    TIM_Configuration();
    System_Information();
    printf("testing!\n");
    command_main();
    
}