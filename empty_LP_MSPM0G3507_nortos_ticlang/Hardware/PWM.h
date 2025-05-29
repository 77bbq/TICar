#ifndef _PWM_H
#define _PWM_H
#include <stdint.h>

void PWM_init(void);
void Set_Pwm(float duty,uint8_t channel);
#endif
