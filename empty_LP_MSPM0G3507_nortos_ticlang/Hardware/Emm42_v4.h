#ifndef _Emm42_v4_H
#define _Emm42_v4_H
#include <stdint.h>

void set_position();
void generate_cmd(uint8_t direction, uint16_t speed, uint8_t acceleration, uint32_t pulse_count);

#endif
