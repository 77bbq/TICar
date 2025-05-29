#include "uart_0.h"
#include "ti_msp_dl_config.h"
#include "stdio.h"
#include "key.h"
int Cx=0,Cy=0,Cz=0,Cm=0,Cn=0;//Cx,Cy���꣬Cz������
uint8_t Serial3_TxPacket[5],Serial0_RxFlag=0;				//12 2C 01 02 03 04 05 5B
volatile uint8_t gEchoData = 0;
static int8_t RxState = 0;	
static int16_t RxCounter1=0;       
static int16_t RxBuffer1[8]={0};
uint8_t count=0;
//TX PB0 RX PB1
void uart_0_init(void)
{
	NVIC_ClearPendingIRQ(UART_0_INST_INT_IRQN);
    NVIC_EnableIRQ(UART_0_INST_INT_IRQN);
}
void UART_0_INST_IRQHandler(void)
{

	int16_t i; 
	switch (DL_UART_Main_getPendingInterrupt(UART_0_INST)) 
	{
		case DL_UART_MAIN_IIDX_RX:
			gEchoData = DL_UART_Main_receiveData(UART_0_INST);
			if(RxState==0&&gEchoData==0x2C)  
			{
				RxState=1;
				RxBuffer1[RxCounter1++]=gEchoData;
			}

			else if(RxState==1&&gEchoData==0x12)  
			{
				RxState=2;
				RxBuffer1[RxCounter1++]=gEchoData;
			}

			else if(RxState==2)
			{
				RxBuffer1[RxCounter1++]=gEchoData;
				if(RxCounter1==8 && gEchoData == 0x5B)
				{
					Cx=RxBuffer1[RxCounter1-6];
					Cy=RxBuffer1[RxCounter1-5];
					Cz=RxBuffer1[RxCounter1-4];
					Cm=RxBuffer1[RxCounter1-3];
					Cn=RxBuffer1[RxCounter1-2];
					Serial0_RxFlag = 1;
					RxCounter1 = 0;
					RxState = 0;	
				}
				else if(RxCounter1 > 8)
				{
					RxState = 0;
					RxCounter1=0;
					for(i=0;i<8;i++)
					{
							RxBuffer1[i]=0x00 ;
					}
				
				}
			}
			else 
			{	

					RxState = 0;
					RxCounter1=0;
					for(i=0;i<8;i++)
					{
							RxBuffer1[i]=0;   
					}
			}
			break;
		default:
			break;
	}
}
void UART_0_SendPacket(uint8_t num1,uint8_t num2,uint8_t num3,uint8_t num4,uint8_t num5)
{
	DL_UART_Main_transmitDataBlocking(UART_0_INST,0x2C);
	DL_UART_Main_transmitDataBlocking(UART_0_INST,0x12);
	DL_UART_Main_transmitDataBlocking(UART_0_INST,num1);
	DL_UART_Main_transmitDataBlocking(UART_0_INST,num2);
	DL_UART_Main_transmitDataBlocking(UART_0_INST,num3);
	DL_UART_Main_transmitDataBlocking(UART_0_INST,num4);
	DL_UART_Main_transmitDataBlocking(UART_0_INST,num5);
	DL_UART_Main_transmitDataBlocking(UART_0_INST,0x5B);
}
void UART_0_SendData(uint8_t num1)
{
	DL_UART_Main_transmitData(UART_0_INST,num1);

}
int fputc(int c,FILE* stream)
{
	DL_UART_Main_transmitDataBlocking(UART0,c);
	return c;
}

int fputs(const char* restrict s, FILE* restrict stream)
{
    uint16_t i,len;
    len = strlen(s);
    for(i=0;i<len;i++)
    {
        DL_UART_Main_transmitDataBlocking(UART_0_INST,s[i]);
    }
    return len;
}
int puts(const char *_ptr)
{
    int count = fputs(_ptr,stdout);
    count+=fputs("\n",stdout);
    return count;
}