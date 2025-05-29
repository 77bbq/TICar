#ifndef __JY61P_H
#define __JY61P_H

#include "uart_1.h"
#include "key.h"
#include "oled.h"


extern float speed_x,speed_y,speed_z;
extern float angle_x,angle_y,angle_z;
float fn(float YAW);
void jy_read(uint8_t rx_data);
			

#endif
