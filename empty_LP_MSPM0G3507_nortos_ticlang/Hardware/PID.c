#include "MyInclude.h"                



float add_control(float pwm);//80-400



float p_Err=0,p_last_err=0,Integral=0,p_p=0.1,p_d=0.02;
float p_pwm=0;
float p_pid_turn(int16_t now_position,int tar_position)
{
    p_Err=tar_position-now_position;
    p_pwm=p_p*p_Err+p_d*(p_Err-p_last_err);
    p_last_err=p_Err;
    return p_pwm;
}

//JY61P的转向环
float p_Err_turn=0,p_last_err_turn=0,Integral_turn=0,p_p_turn=2,p_d_turn= 7;
float p_pwm_turn=0;
float p_pid_grey(float now_position_turn,float tar_position_turn)
{
    p_Err_turn=tar_position_turn - now_position_turn;
    p_pwm_turn=p_p_turn * p_Err_turn +p_d_turn *(p_Err_turn-p_last_err_turn);
    p_last_err_turn=p_Err_turn;
    return p_pwm_turn;
}

//JY61P的直行
float p_Err_JYgo=0,p_last_err_JYgo=0,Integral_JYgo=0,p_p_JYgo=0.13,p_d_JYgo=4.2;
float p_pwm_JYgo=0;
float p_pid_JYgo(float now_position_JYgo,float tar_position_JYgo)
{
    p_Err_JYgo=tar_position_JYgo - now_position_JYgo;
    p_pwm_JYgo=p_p_JYgo * p_Err_JYgo +p_d_JYgo *(p_Err_JYgo-p_last_err_JYgo);
    p_last_err_JYgo=p_Err_JYgo;
    return p_pwm_JYgo;
}

/*******************************************************************/
float pid3_Err=0,pid3_add=0,pid3_pwm=0,pid3_next_erro=0,pid3_last_erro=0,pid3_p=46,pid3_i=9;
float i_PID_R(int16_t speed,float tar)
{
    pid3_Err=tar-speed;
    pid3_add=pid3_p*(pid3_Err-pid3_last_erro)+pid3_i*(pid3_Err);
    pid3_add = add_control(pid3_add);
    pid3_pwm+=pid3_add;
	pid3_pwm = pwm_control(pid3_pwm);
    pid3_next_erro=pid3_last_erro;
    pid3_last_erro=pid3_Err;
    return pid3_pwm;
}
//0.62  0.21
float pid4_Err=0,pid4_add=0,pid4_pwm=0,pid4_next_erro=0,pid4_last_erro=0,pid4_p=40,pid4_i=9;
int i_PID_L(int16_t speed,float tar)
{                       
  // speed=myabs(speed);
    pid4_Err=tar-speed;

    pid4_add=pid4_p*(pid4_Err-pid4_last_erro)+pid4_i*(pid4_Err);
     pid4_add = add_control(pid4_add);
    pid4_pwm+=pid4_add;
	pid4_pwm = pwm_control(pid4_pwm);
    pid4_last_erro=pid4_Err;
    return pid4_pwm;
}
/*******************************************************/
void err_zero(void)
{
	pid3_Err=0,pid3_add=0,pid3_last_erro=0,pid3_pwm=0;
	pid4_Err=0,pid4_add=0,pid4_last_erro=0,pid4_pwm=0;
}

int16_t myabs(int a)
{ 		   
	int temp=0;
	if(a<0)  temp=-a;  
	else temp=a;
	return temp;
}

float pwm_control(float pwm)//80-400
{
    if(pwm>99)
        pwm=99;
    else if(pwm<-99)
        pwm=-99;
	return pwm;
}

float add_control(float pwm)//80-400
{
    if(pwm>8)
        pwm=8;
    else if(pwm<-8)
        pwm=-8;
	return pwm;
}

