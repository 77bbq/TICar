#include "uart_0.h"
#include "ti_msp_dl_config.h"
#include "key.h"
int Cq=0,Cw=0,Ce=0,Cr=0,Ct=0;
volatile uint8_t gEchoData_2 = 0;
static int8_t RxState_2 = 0;	
static int16_t RxCounter_2=0;       
static int16_t RxBuffer1_2[8]={0};
static int16_t Serial2_RxFlag =0;     
//TX PB17 RX PB18
void uart_2_init(void)
{
	NVIC_ClearPendingIRQ(UART_2_INST_INT_IRQN);
    NVIC_EnableIRQ(UART_2_INST_INT_IRQN);
}
void UART_2_INST_IRQHandler(void)
{
	
	int16_t i;         
	switch (DL_UART_Main_getPendingInterrupt(UART_2_INST)) 
	{	
		case DL_UART_MAIN_IIDX_RX:

			gEchoData_2 = DL_UART_Main_receiveData(UART_2_INST);
		
			if(RxState_2==0&&gEchoData_2==0x2C)  
			{
				RxState_2=1;
				
				RxBuffer1_2[RxCounter_2++]=gEchoData_2;
			}

			else if(RxState_2==1&&gEchoData_2==0x12)  
			{
				RxState_2=2;

				RxBuffer1_2[RxCounter_2++]=gEchoData_2;
			}

			else if(RxState_2==2)
			{
				RxBuffer1_2[RxCounter_2++]=gEchoData_2;

				if(RxCounter_2==8 && gEchoData_2 == 0x5B)
				{
					Cq=RxBuffer1_2[RxCounter_2-6];
					Cw=RxBuffer1_2[RxCounter_2-5];
					Ce=RxBuffer1_2[RxCounter_2-4];
					Cr=RxBuffer1_2[RxCounter_2-3];
					Ct=RxBuffer1_2[RxCounter_2-2];
					Serial2_RxFlag = 1;
					RxCounter_2 = 0;
					RxState_2 = 0;	
				}
				else if(RxCounter_2 > 8)
				{
					RxState_2 = 0;
					RxCounter_2=0;
					for(i=0;i<8;i++)
					{
							RxBuffer1_2[i]=0x00 ;
					}
				
				}
			}
			else 
			{	

					RxState_2 = 0;
					RxCounter_2=0;
					for(i=0;i<8;i++)
					{
							RxBuffer1_2[i]=0;   
					}
			}
			break;
		default:
			break;
	}
}

void UART_2_SendPacket(uint8_t num1,uint8_t num2,uint8_t num3,uint8_t num4,uint8_t num5)
{
	DL_UART_Main_transmitDataBlocking(UART_2_INST,0x2C);
	DL_UART_Main_transmitDataBlocking(UART_2_INST,0x12);
	DL_UART_Main_transmitDataBlocking(UART_2_INST,num1);
	DL_UART_Main_transmitDataBlocking(UART_2_INST,num2);
	DL_UART_Main_transmitDataBlocking(UART_2_INST,num3);
	DL_UART_Main_transmitDataBlocking(UART_2_INST,num4);
	DL_UART_Main_transmitDataBlocking(UART_2_INST,num5);
	DL_UART_Main_transmitDataBlocking(UART_2_INST,0x5B);
}
void UART_2_SendData(uint8_t num1)
{
	DL_UART_Main_transmitData(UART_2_INST,num1);

}