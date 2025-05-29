#include "buzzer.h"
#include "ti/driverlib/dl_gpio.h"
#include <ti/driverlib/m0p/dl_core.h>
#include "Timer_G0.h"
#include "ti_msp_dl_config.h"
void buzzer(int t)
{
	time=0;
    while(1)
    {
        if (time<=t)
        {	
            DL_GPIO_setPins(GPIO_BUZZER_PORT,GPIO_BUZZER_PIN_buzzer_PIN);
        }
        else
        {	
            DL_GPIO_clearPins(GPIO_BUZZER_PORT,GPIO_BUZZER_PIN_buzzer_PIN);
            break;
        }
    }
}