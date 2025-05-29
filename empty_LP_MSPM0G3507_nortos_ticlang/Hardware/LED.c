#include "buzzer.h"
#include "ti/driverlib/dl_gpio.h"
#include <ti/driverlib/m0p/dl_core.h>
#include "ti_msp_dl_config.h"
void led_on(void)
{
	DL_GPIO_setPins(GPIO_LED_PORT,GPIO_LED_PIN_LED_PIN);
}
void led_off(void)
{
	DL_GPIO_clearPins(GPIO_LED_PORT,GPIO_LED_PIN_LED_PIN);
}
void led_toggle(void)
{	
	DL_GPIO_togglePins(GPIO_LED_PORT,GPIO_LED_PIN_LED_PIN);
}
