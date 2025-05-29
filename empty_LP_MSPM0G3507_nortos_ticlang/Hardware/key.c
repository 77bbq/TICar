#include "key.h"
#include "ti/driverlib/dl_gpio.h"
#include <ti/driverlib/m0p/dl_core.h>
#include "oled.h"
#include "ti_msp_dl_config.h"
int KeyNum = 0 ;
void delay_us(uint32_t us)
{
	while(us--)
	{
		delay_cycles(32);
	}
}



