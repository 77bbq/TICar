#include "Timer_G0.h"
#include "ti_msp_dl_config.h"
int time=0;
int times=0;
void TIMG0_Init(void)
{
	NVIC_EnableIRQ(TIMER_G0_INST_INT_IRQN);
	DL_TimerG_startCounter(TIMER_G0_INST);
}

