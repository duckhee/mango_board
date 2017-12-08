#define USART_LOCAL

#include "Hw_Usart.h"

USART_DEF void USART1_Init(void);
USART_DEF void USART_Init(USART_TypeDef* USARTx, USART_InitTypeDef* USART_InitStruct);


USART_DEF void USART1_Init(void)
{
    USART_InitTypeDef USART_InitStructure;
    /* USARTx configuration */
    /* USARTx configured as follow : 
    - BaudRate = 115200 baud
    - Word Length = 8bits
    - One Stop Bit
    - No parity
    - Hardware flow control disabled (RTS and CTS signals)
    - Receive and transmit enabled
    */
    USART_InitStructure.USART_BaudRate = 115200;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

    USART_Init(USART1, &USART_InitStructure);

    USART1->CR1 |= USART_ENABLE;
}
USART_DEF void USART_Init(USART_TypeDef* USARTx, USART_InitTypeDef* USART_InitStruct)
{
    uint32_t tmpreg = 0x00, apbclock = 0x00;
    uint32_t integerdivider = 0x00;
    uint32_t fractionaldivider = 0x00;
    uint32_t usartxbase = 0;
    //RCC Clock을 얻기 위해서 구조체 선언
    RCC_ClocksTypeDef RCC_CLocksStatus;
    /* The hardware flow control is available only for USART1, USART2 and USART3 */
    if(USART_InitStruct->USART_HardwareFlowControl != USART_HardwareFlowControl_None)
    {
        //확인을 하기위한 디버그 코드가 여기 들어간다.
    }
    usartxbase = (uint32_t)USARTx;
    /*---------------------------- USART CR2 Configuration -----------------------*/
    tmpreg = USARTx->CR2;
    /* Clear STOP[13:12] bits */
    tmpreg &= USART_STOP_BIT_CLEAR_MASK;
    /* Configure the USART Stop Bits, Clock, CPOL, CPHA and LastBit ------------*/
    /* Set STOP[13:12] bits according to USART_StopBits value */
    tmpreg |= (uint32_t)USART_InitStruct->USART_StopBits;
    /* Write to USART CR2 */
    USARTx->CR2 = (uint16_t)tmpreg;
    /*---------------------------- USART CR1 Configuration -----------------------*/
    tmpreg = USARTx->CR1;
    /* Clear M, PCE, PS, TE and RE bits */
    tmpreg &= ~USART_CR1_CLEAR_MASK;
    /* Configure the USART Word Length, Parity and mode ----------------------- */
    /* Set the M bits according to USART_WordLength value */
    /* Set PCE and PS bits according to USART_Parity value */
    /* Set TE and RE bits according to USART_Mode value */
    tmpreg |= (uint32_t)USART_InitStruct->USART_WordLength | USART_InitStruct->USART_Parity | USART_InitStruct->USART_Mode;
    /* Write to USART CR1 */
    USARTx->CR1 = (uint16_t)tmpreg;
    /*---------------------------- USART CR3 Configuration -----------------------*/
    tmpreg = USARTx->CR3;
    /* Clear CTSE and RTSE bits */
    tmpreg &= USART_CR3_CLEAR_MASK;
    /* Configure the USART HFC -------------------------------------------------*/
    /* Set CTSE and RTSE bits according to USART_HardwareFlowControl value */
    tmpreg |= (uint32_t)USART_InitStruct->USART_HardwareFlowControl; 
    /* Write to USART CR3 */
    USARTx->CR3 = (uint16_t)tmpreg;
    /*---------------------------- USART BRR Configuration -----------------------*/
    /* Configure the USART Baud Rate -------------------------------------------*/
    /* Determine the integer part */
    RCC_GetClocksFreq(&RCC_CLocksStatus);
    if(usartxbase == USART1_BASE)
    {
        apbclock = RCC_CLocksStatus.PCLK2_Frequency;
    }
    else
    {
        apbclock = RCC_CLocksStatus.PCLK1_Frequency;
    }
    /* Determine the integer part */
    integerdivider = ((0x19 * apbclock) / (0x04 * (USART_InitStruct->USART_BaudRate)));
    tmpreg = (integerdivider / 0x64) << 0x04;
    /* Determine the fractional part */
    fractionaldivider = integerdivider - (0x64 * (tmpreg >> 0x04));
    tmpreg |= ((((fractionaldivider * 0x10) + 0x32) / 0x64)) & ((uint8_t)0x0F);
    USARTx->BRR = (uint16_t)tmpreg;
    
}