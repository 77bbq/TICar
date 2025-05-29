#include "ti_msp_dl_config.h"
#include "enconder.h"

volatile int32_t conter1 =0 ;
volatile int32_t conter2 =0 ;
volatile int32_t conter3 =0 ;
volatile int32_t conter4 =0 ;
// 1A PB10 1B PB11
// 2A PB19 2B PB15
// 3A PB24 3B PB6
// 4A PB7  4B PB16
void enconder_init(void)
{	
    NVIC_EnableIRQ(GPIO_ENCONDER_INT_IRQN);//ʹ���ⲿ�ж�
}
void GROUP1_IRQHandler(void)
{
	uint32_t GPIO_A= DL_GPIO_getEnabledInterruptStatus(GPIOB,GPIO_ENCONDER_PIN_ECO1A_PIN|
	GPIO_ENCONDER_PIN_ECO2A_PIN);
	if(GPIO_A&GPIO_ENCONDER_PIN_ECO1A_PIN)
		{	
			if(DL_GPIO_readPins(GPIO_ENCONDER_PORT,GPIO_ENCONDER_PIN_ECO1B_PIN))
			{
				conter1--;
			}
			else
			{
				conter1++;
			}
            DL_GPIO_clearInterruptStatus(GPIO_ENCONDER_PORT, GPIO_ENCONDER_PIN_ECO1A_PIN);
		}
	if(GPIO_A&GPIO_ENCONDER_PIN_ECO2A_PIN)
		{	
			if(DL_GPIO_readPins(GPIO_ENCONDER_PORT,GPIO_ENCONDER_PIN_ECO2B_PIN))
			{
				conter2++;
			}
			else
			{
				conter2--;
			}
            DL_GPIO_clearInterruptStatus(GPIO_ENCONDER_PORT, GPIO_ENCONDER_PIN_ECO2A_PIN);
		}
}

