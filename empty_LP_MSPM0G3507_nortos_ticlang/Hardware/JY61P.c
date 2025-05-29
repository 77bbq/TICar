#include "JY61P.h"
#include "buzzer.h"
#include "oled.h"
int start_flag=0;
int num=0;
uint8_t sum=0;
uint8_t revice[11];
float speed_x,speed_y,speed_z;
float angle_x,angle_y,angle_z;
int mm=0;

void jy_read(uint8_t rx_data)
{
	if(start_flag==0 && rx_data==0x55)
	{
        num=0;
		start_flag=1;
		revice[num]=rx_data;
	}
    else if(start_flag==1 && rx_data==0x53)
	{
		start_flag=2;
        num++;
		revice[num]=rx_data;
	}
	else if(num<=10)
	{
		num++;
		revice[num]=rx_data;
		if(num==10)
		{
			for(int i=0;i<=9;i++)
			{
				sum+=revice[i];
			}
		}
		if(num==10 && sum==revice[10])
		{

            angle_x=(float)((short)((short)revice[3]<<8|revice[2]))/32768*180;
            angle_y=(float)((short)((short)revice[5]<<8|revice[4]))/32768*180;
            angle_z=(float)((short)((short)revice[7]<<8|revice[6]))/32768*180;
            angle_z=fn(angle_z);
		}
		if(num==10)
		{
            start_flag=0;
            num=0;
            sum=0;
            for(int i=0;i<=10;i++)
            revice[i]=0;
		}
	}
}

float fn(float YAW)
{
	float Yaw;
	if(YAW <= 90 && YAW >= 0)
		Yaw = 1.0 * YAW;
	else if(YAW <= 180 && YAW >=90)
		Yaw = YAW-360;
	else 
		Yaw = YAW;
	
	return Yaw;
}

