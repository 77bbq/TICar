#include "Timer_G6.h"
#include "ti_msp_dl_config.h"
void TIMG6_Init(void)
{
	NVIC_EnableIRQ(TIMER_G6_INST_INT_IRQN);
	DL_TimerG_startCounter(TIMER_G6_INST);
}

