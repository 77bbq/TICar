#include "uart_1.h"
#include "ti_msp_dl_config.h"
#include "key.h"
#include "JY61P.h"
int rxFrameFlag=0;
volatile uint8_t gEchoData_1 = 0;
static int8_t RxState_1 = 0;	
static int16_t RxCounter1=0;     
static int16_t RxBuffer1[3]={0};
int xx=0;
//TX PA8 RX PB5
void uart_1_init(void)
{
	NVIC_ClearPendingIRQ(UART_1_INST_INT_IRQN);
    NVIC_EnableIRQ(UART_1_INST_INT_IRQN);
}


void UART_1_INST_IRQHandler(void)
{
	
	switch (DL_UART_Main_getPendingInterrupt(UART_1_INST)) 
	{	
		case DL_UART_MAIN_IIDX_RX:
		{
            xx++;
			gEchoData_1 = DL_UART_Main_receiveData(UART_1_INST);
			jy_read(gEchoData_1);
			break;

		}
		default:
			break;
	}
}

void UART_1_SendPacket(uint8_t num1,uint8_t num2,uint8_t num3,uint8_t num4,uint8_t num5)
{
	DL_UART_Main_transmitDataBlocking(UART_1_INST,0x2C);
	DL_UART_Main_transmitDataBlocking(UART_1_INST,0x12);
	DL_UART_Main_transmitDataBlocking(UART_1_INST,num1);
	DL_UART_Main_transmitDataBlocking(UART_1_INST,num2);
	DL_UART_Main_transmitDataBlocking(UART_1_INST,num3);
	DL_UART_Main_transmitDataBlocking(UART_1_INST,num4);
	DL_UART_Main_transmitDataBlocking(UART_1_INST,num5);
	DL_UART_Main_transmitDataBlocking(UART_1_INST,0x5B);
}
void UART_1_SendData(uint8_t num1)
{
	DL_UART_Main_transmitData(UART_1_INST,num1);

}