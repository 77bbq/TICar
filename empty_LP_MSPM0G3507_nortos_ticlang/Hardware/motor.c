#include "MyInclude.h"

void right(float speed)
{
	if(speed>=0)
    {
        Set_Pwm(speed,1);
        Set_Pwm(speed,4); 
        DL_GPIO_setPins(GPIO_MOTOR_PORT,GPIO_MOTOR_PIN_motor2_PIN);
        DL_GPIO_setPins(GPIO_MOTOR_PORT,GPIO_MOTOR_PIN_motor7_PIN);
        DL_GPIO_clearPins(GPIO_MOTOR_PORT,GPIO_MOTOR_PIN_motor1_PIN);
        DL_GPIO_clearPins(GPIO_MOTOR_PORT,GPIO_MOTOR_PIN_motor8_PIN);
    }
    else
    {
        Set_Pwm(-speed,1);
        Set_Pwm(-speed,4); 
        DL_GPIO_setPins(GPIO_MOTOR_PORT,GPIO_MOTOR_PIN_motor1_PIN);
        DL_GPIO_setPins(GPIO_MOTOR_PORT,GPIO_MOTOR_PIN_motor8_PIN);
        DL_GPIO_clearPins(GPIO_MOTOR_PORT,GPIO_MOTOR_PIN_motor2_PIN);
        DL_GPIO_clearPins(GPIO_MOTOR_PORT,GPIO_MOTOR_PIN_motor7_PIN);
    }
}


void left(float speed)
{
   if(speed>=0)
    {
        Set_Pwm(speed,2);
        Set_Pwm(speed,3);  
        DL_GPIO_setPins(GPIO_MOTOR_PORT,GPIO_MOTOR_PIN_motor3_PIN);
        DL_GPIO_setPins(GPIO_MOTOR_PORT,GPIO_MOTOR_PIN_motor5_PIN);
        DL_GPIO_clearPins(GPIO_MOTOR_PORT,GPIO_MOTOR_PIN_motor4_PIN);
        DL_GPIO_clearPins(GPIO_MOTOR_PORT,GPIO_MOTOR_PIN_motor6_PIN);
    }
    else
    {
        Set_Pwm(-speed,2);
        Set_Pwm(-speed,3);         
        DL_GPIO_setPins(GPIO_MOTOR_PORT,GPIO_MOTOR_PIN_motor4_PIN);
        DL_GPIO_setPins(GPIO_MOTOR_PORT,GPIO_MOTOR_PIN_motor6_PIN);
        DL_GPIO_clearPins(GPIO_MOTOR_PORT,GPIO_MOTOR_PIN_motor3_PIN);
        DL_GPIO_clearPins(GPIO_MOTOR_PORT,GPIO_MOTOR_PIN_motor5_PIN);
    }
}
