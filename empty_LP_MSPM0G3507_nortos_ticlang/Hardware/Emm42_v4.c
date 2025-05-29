#include "uart_1.h"
#include "ti_msp_dl_config.h"
#include "Emm42_v4.h"
#include "key.h"

//void set_zero(void)
//{
//	
//}


////��ַ + 0xFD + ������ٶȣ�2 �ֽڣ� + ���ٶ� + ��������3 �ֽڣ� + У���ֽ�
////
void set_position()
{
	uint8_t cmd[10];
	uint16_t i = 0;

	cmd[0] = 0x01;	/* ��ַ */
	cmd[1] = 0xFD;	/* ������ */
	
	
	cmd[2] = 0x14;	/* ������ֽ� + �ٶȸ߰��ֽ� */
	cmd[3] = 0xFF;	/* �ٶ��ֽ�,( (uint16_t)(cmd[2] & 0x0F) << 8 | (uint16_t)cmd[3] )����ٶ� */
	cmd[4] = 0x00;	/* ���ٶ� */
	cmd[5] = 0x00;	/* ���������ֽ� */
	cmd[6] = 0x0C;	/* ���������ֽ� */
	cmd[7] = 0x80;	/* ���������ֽ� */
	
	
	cmd[8] = 0x6B;;	/* �̶�У���ֽ� */
	
	for(i = 0; i < 9 ;i++)
	{
		DL_UART_Main_transmitDataBlocking(UART_1_INST,cmd[i]);
	}
	
}

void generate_cmd(uint8_t direction, uint16_t speed, uint8_t acceleration, uint32_t pulse_count) 
{
	uint8_t cmd[10];
	uint16_t i = 0;
	
	cmd[0] = 0x01;	/* ��ַ */
	cmd[1] = 0xFD;	/* ������ */
    // �����ٶȸ߰��ֽ�
    cmd[2] = (direction << 4) | ((speed >> 8) & 0x0F);
    // �ٶȵ��ֽ�
    cmd[3] = speed & 0xFF;
    // ���ٶ�
    cmd[4] = acceleration;
    // ���������ֽ�
    cmd[5] = (pulse_count >> 16) & 0xFF;
    // ���������ֽ�
    cmd[6] = (pulse_count >> 8) & 0xFF;
    // ���������ֽ�
    cmd[7] = pulse_count & 0xFF;
	
		
	cmd[8] = 0x6B;;	/* �̶�У���ֽ� */
	
	for(i = 0; i < 9 ;i++)
	{
		DL_UART_Main_transmitDataBlocking(UART_1_INST,cmd[i]);
	}
	
	while(1)
	{
		//delay_us(10);
		if(rxFrameFlag==1)
			break;
	}
	
	rxFrameFlag = 0;
}


