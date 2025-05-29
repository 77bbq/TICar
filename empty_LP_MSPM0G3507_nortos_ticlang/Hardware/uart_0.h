#ifndef _UART_0_H
#define _UART_0_H
#include "stdint.h"
#include "string.h"
#include "stdio.h"
void uart_0_init(void);
void UART_0_SendData(uint8_t num1);
void UART_0_INST_IRQHandler(void);
extern int Cx,Cy,Cz,Cm,Cn;	
int puts(const char *_ptr);
int fputs(const char* restrict s, FILE* restrict stream);
int fputc(int c,FILE* stream);
#endif
