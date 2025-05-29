#ifndef _UART_2_H
#define _UART_2_H
#include <stdint.h>
void uart_2_init(void);
void UART_2_SendData(uint8_t num1);
void UART_2_INST_IRQHandler(void);
extern int Cq,Cw,Ce,Cr,Ct;	
#endif
