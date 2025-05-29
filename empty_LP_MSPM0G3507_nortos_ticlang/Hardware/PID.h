#ifndef __PID_H
#define __PID_H

// extern float Bias,Integral_bias;
float p_pid_turn(int16_t now_position,int tar_position);
float p_pid_grey(float now_position_turn,float tar_position_turn);
float p_pid_JYgo(float now_position_JYgo,float tar_position_JYgo);
float pwm_control(float pwm);
float i_PID_R(int16_t speed,float tar);
int i_PID_L(int16_t speed,float tar);
void err_zero(void);

int16_t myabs(int a);
float pwm_control(float pwm);
#endif
