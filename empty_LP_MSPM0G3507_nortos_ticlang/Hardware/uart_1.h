#ifndef _UART_1_H
#define _UART_1_H
#include "stdint.h"
#include "string.h"
#include "stdio.h"
void uart_1_init(void);
void UART_1_INST_IRQHandler(void);
extern int rxFrameFlag;

#endif
