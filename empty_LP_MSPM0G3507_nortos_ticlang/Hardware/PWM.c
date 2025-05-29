#include "PWM.h"
#include "ti/driverlib/dl_gpio.h"
#include "ti_msp_dl_config.h"

void PWM_init(void)
{	
	DL_TimerA_startCounter(PWM_A0_INST);
}
void Set_Pwm(float duty,uint8_t channel)
{
	uint32_t CompareValue;
	duty=duty/100;
	CompareValue =99-100*duty;
	switch(channel)
	{	
		case 1:
			DL_TimerA_setCaptureCompareValue(PWM_A0_INST ,CompareValue,DL_TIMER_CC_0_INDEX);
			break;
		case 2:
			DL_TimerA_setCaptureCompareValue(PWM_A0_INST ,CompareValue,DL_TIMER_CC_1_INDEX);
			break;
		case 3:
			DL_TimerA_setCaptureCompareValue(PWM_A0_INST ,CompareValue,DL_TIMER_CC_2_INDEX);
			break;
		case 4:
			DL_TimerA_setCaptureCompareValue(PWM_A0_INST ,CompareValue,DL_TIMER_CC_3_INDEX);
			break;
		default:
			break;
	}
	
}