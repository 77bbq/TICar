#include "All_Init.h"

void All_init(void)
{
    SYSCFG_DL_init(); //芯片资源初始化,由SysConfig配置软件自动生成
	TIMG0_Init();
    TIMG6_Init();
	uart_0_init();
	PWM_init();
	uart_1_init();        
	uart_2_init();
	enconder_init();
    OLED_Init();
}