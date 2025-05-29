#include "MyInclude.h"
#include "PID.h"
#include <stdio.h>
#include <sys/_stdint.h>

#define time_task1   47
#define time_task2   35
#define time_task3  40
#define time_task3_C  41
#define slow_time 30
#define time_task2_D  35
#define time_huan    40   
#define HS_SPPPD 13
char str[30];
int task4_times=0;
int shan_flag=0;
int32_t juli=0;
float Tar_Angle = 0;//传入direction_turn,用于转弯
int Tar_Speed_MV = 0;
int Tar_Speed_l=0;
int Tar_Speed_r=0;

int Tar_Speed_JY = 0;
int Tar_Angle_JY = 0;
int enter = 0;
int Tar_Speed_Grey = 0;
float Tar_Grey = 0;

int led_time=0;
uint32_t Dist=0;
int flag=0;//定时中断里的标志位，用于切换不同的状态
int c1=0,c2=0,c3=0,c4=0;//四个编码器的值
int Openmv_Add=0;//openmv环算出来的
float JY61P_Add=0;	//陀螺仪环算出来的
float grey_add = 0;
int PWM_L = 0,PWM_R = 0;
void shan(void);
int choice=999;
void rage_engine(void);
void Rage_engine(void);
void conter_get(void);
void move_task4(void);
void move_task4_HS(void);
void direction_turn(float mpu_tar);
void turn(float angle);
void calculate(void);
void direction(int speed_l,int speed_r);
void direction_go_mv(int speed_tar);
void calculate_rage(void);
void direction_go_JY(int speed_tar,int angle_tar);

void direction_turn_grey(int speed_tar,float tar);

void move(int distance,int speed,int angle);
void move_task1(int speed,int angle);
void move_task2(void);
void move_task3(void);

void run(void);
void stop(void);
void JY61P_Init(void);	

void Key_GetNum(void);
 
//30-->10
int main(void)
{
    All_init();
    JY61P_Init();
    int key_num1=0;
    int key_num2=0;
    time=0;
    int key_cnt=0;

    // while(1)
    // {
    //     left(20);
    //     right(-20);
    //     printf("c1=%d   c2=%d\r\n",c1,c2);
    // }
        while(1)
        {  
            err_zero(); 
            sprintf(str, "z=%f", angle_z);
            OLED_ShowString(0, 0, (uint8_t*)str, 16);
            if(key_cnt==0)
            {        
                if (DL_GPIO_readPins(GPIO_KEY_PORT,GPIO_KEY_PIN_KEY1_PIN )==0)
                {
                    led_on();
                    key_cnt=1;
                    time=0;
                    delay_ms(20);
                    while(DL_GPIO_readPins(GPIO_KEY_PORT ,GPIO_KEY_PIN_KEY1_PIN)==0);
                    delay_ms(20);
                    key_num1++;
                    led_off();
                }

                if (DL_GPIO_readPins(GPIO_KEY_PORT,GPIO_KEY_PIN_KEY2_PIN)==0)
                {
                    led_on();
                    key_cnt=1;
                    time=0;
                    delay_ms(20);
                    while(DL_GPIO_readPins(GPIO_KEY_PORT,GPIO_KEY_PIN_KEY2_PIN)==0){};
                    delay_ms(20);
                    key_num2++;
                    led_off();
                }
            }
            else if(key_cnt==1)
            {
                if(key_num1 == 1)
                {
                    if(time<=40)
                    {

                        if (DL_GPIO_readPins(GPIO_KEY_PORT,GPIO_KEY_PIN_KEY1_PIN )==0)
                        {   
                        led_on();
                        delay_ms(20);
                        while(DL_GPIO_readPins(GPIO_KEY_PORT ,GPIO_KEY_PIN_KEY1_PIN)==0);
                        delay_ms(20);
                        key_num1++;
                        led_off();
                        }
                        
                    }
                    if(key_num1==2)
                    {
                        choice=2;
                        break;
                    }
                    if(time>40 && key_num1==1)
                    {
                        time=0;
                        choice = 1;
                        break;
                    }

                }
                if(key_num2 == 1)
                {
                    if(time<=40)
                    {
                        if (DL_GPIO_readPins(GPIO_KEY_PORT,GPIO_KEY_PIN_KEY2_PIN)==0)
                        {
                            led_on();
                            delay_ms(20);
                            while(DL_GPIO_readPins(GPIO_KEY_PORT,GPIO_KEY_PIN_KEY2_PIN)==0){};
                            delay_ms(20);
                            key_num2++;
                            led_off();
                        }
                        
                    }
                    if(key_num2==2)
                    {
                        choice=4;
                        break;
                    }
                    if(time>40 && key_num2==1)
                    {
                        time=0;
                        choice = 3;
                        break;
                    }


                }
            }
            // if (time>=40) 
            // {
            //     if(key_num1==1)
            //     {
            //         choice=1;
            //         break;
            //     }
            //     if(key_num1>=2)
            //     {
            //         choice=2;
            //         break;
            //     }
            //     if(key_num2==1)
            //     {
            //         choice=3;
            //         break;
            //     }
            //     if(key_num2>=2)
            //     {
            //         choice=4;
            //         break;
            //     }
            // }
            
            
        }                                             
    while (1)
	{
            // 第一行显示
        // sprintf(str, "z=%f", angle_z);
        // OLED_ShowString(0, 0, (uint8_t*)str, 16);
        // sprintf(str, "c1=%d c2=%d", c1, c2);
        // OLED_ShowString(2, 2, (uint8_t*)str, 16);
        // sprintf(str, "L=%d R=%d", PWM_L, PWM_R);
        // OLED_ShowString(2, 4, (uint8_t*)str, 16);
        // sprintf(str, "g= %d %d %d %d %d %d ",g1,g2,g3,g4,g5,g6);
        // OLED_ShowString(2, 6, (uint8_t*)str, 16);

        printf("choice=%d\r\n",choice);

        switch (choice)
        {
            case 0:
            {
               buzzer(4);
               led_on();
                printf("enter stop\r\n");
                while(1)
                {
                  flag = 0;
                      run();
                    stop();
                }

            }
            case 1://任务一
            {

                err_zero();//清除pid一直在计算的误差
                move_task1(8,0);//以8的速度，0的角度，走time_task1的时间
                choice = 0;
                break;
            }

            case 2:
            {
                err_zero();//清除pid一直在计算的误差
                move_task2();
                break;
            }

             case 3:
            {
                err_zero();//清除pid一直在计算的误差
                move_task3();
                break;
            }

            case 4:
            {
                err_zero();//清除pid一直在计算的误差
                move_task4();
                break;
            }
            default:
            {
                break;
            }
        
          }

      }

   
}

void TIMER_G0_INST_IRQHandler(void)
{
	switch(DL_TimerG_getPendingInterrupt(TIMER_G0_INST))
	{	
		case DL_TIMER_IIDX_ZERO:
		{
             times++;
             grey_GetNum();
             if(times>=10)
             {
                times=0;
                time++;
                led_time++;
             }
             if (shan_flag==1)
             {
                DL_GPIO_setPins(GPIO_BUZZER_PORT,GPIO_BUZZER_PIN_buzzer_PIN);
                led_toggle();
                if(led_time>=2)
                {
                    shan_flag=0;
                    DL_GPIO_clearPins(GPIO_BUZZER_PORT,GPIO_BUZZER_PIN_buzzer_PIN);
                    led_off();
                }
             }
             
		}
			break;
		default:
			break;
	}
}

void TIMER_G6_INST_IRQHandler(void)
{
	switch(DL_TimerG_getPendingInterrupt(TIMER_G6_INST))
	{	
		case DL_TIMER_IIDX_ZERO:
		{
            //conter_get();
          
            switch (flag)
            {
                case 0 :
                    {
                        stop();
                        break;
                    }
                case 1:
                    {
                     
                        break;
                    }
                case 2:
                    {
                        direction_turn(Tar_Angle);//转弯
                        break;
                    }
                case 3:
                    {
                        direction_go_JY(Tar_Speed_JY,Tar_Angle_JY);//直走
                        break;
                    }
                case 4:
                    {
                        calculate();
                        direction(Tar_Speed_l,Tar_Speed_r);//环岛
                        break;
                    }
                case 5:
                    {
                        Rage_engine();
                        direction(Tar_Speed_l,Tar_Speed_r);//环岛
                        break;
                    }
                case 6:
                        calculate_rage();
                        direction(Tar_Speed_l,Tar_Speed_r);//环岛
                        break;
                default:
			        break;
            }
		
			break;
		default:
			break;
	}
}
}

void stop(void)
{
     err_zero();
    conter_get();//获取编码器的值
    PWM_L=i_PID_L(c1,0);
    PWM_R=i_PID_R(c2,0);
    run();	

}

//陀螺仪转向，速度为0，传入角度
void direction_turn(float mpu_tar)
{
    conter_get();//获取编码器的值
	JY61P_Add=p_pid_turn(angle_z,mpu_tar);	
	PWM_L=i_PID_L(c1,-JY61P_Add);
    PWM_R=i_PID_R(c2,JY61P_Add);
    run();	
}

void turn(float angle)
{
    time = 0;
    Tar_Angle = angle;
    err_zero();
    int tt;
    if(time<45)
        tt=15;
    else
        tt=20;
    while(1)
    {
        if(time > tt)
        {
            flag = 0;
            break;
        }
        flag = 2;
    }
}



//用陀螺仪实现直走
void direction_go_JY(int speed_tar,int angle_tar)
{
    conter_get();
    JY61P_Add=p_pid_JYgo(angle_z,angle_tar);  
   	//JY61P_Add = 0;
    PWM_L = i_PID_L(c1,speed_tar -JY61P_Add );
	PWM_R = i_PID_R(c2,speed_tar + JY61P_Add);
    run();
}
void direction(int speed_l,int speed_r)
{
    conter_get();
    PWM_L = i_PID_L(c1,speed_l);
	PWM_R = i_PID_R(c2,speed_r);
    run();
}
//灰度走环岛
void direction_turn_grey(int speed_tar,float tar)
{
    conter_get();
    grey_add=p_pid_grey(tar,4.5);  
    PWM_L = i_PID_L(c1,speed_tar - grey_add );
	PWM_R = i_PID_R(c2,speed_tar + grey_add);
    printf("grey=%f\r\n",grey_add);
    run();
}

//用陀螺仪实现直走的函数
void move(int distance,int speed,int angle)
{
    time = 0;
    Tar_Speed_JY = speed;
    Tar_Angle_JY = angle;
    err_zero();
    while(1)
    {
       
        if(time >= distance)
        {
            flag = 0;
             break;
        }
        flag =3;
        // run();
    }

}

void move_task1(int speed,int angle)
{
    time = 0;
    Tar_Speed_JY = speed;
    Tar_Angle_JY = angle;
    err_zero();
    juli=0;
    while(1)
    {
        flag =3;
        // sprintf(str, "z=%f", angle_z);
        // OLED_ShowString(0, 0, (uint8_t*)str, 16);
        // sprintf(str, "c1=%d c2=%d", c1, c2);
        // OLED_ShowString(2, 2, (uint8_t*)str, 16);
        // sprintf(str, "L=%d R=%d", PWM_L, PWM_R);
        // OLED_ShowString(2, 4, (uint8_t*)str, 16);
        // sprintf(str, "g= %d %d %d %d %d %d ",g1,g2,g3,g4,g5,g6);
        // OLED_ShowString(2, 6, (uint8_t*)str, 16);
        
        if(((g1+g2+g3+g4+g5+g6+g7+g8)!=0)&&(juli>=1830))
        {
            flag = 0;
            choice = 0;
            shan();
            while(1)
            {
                flag=0;
                left(0);
                right(0);
                sprintf(str, "juli=%d", juli);
                OLED_ShowString(2, 4, (uint8_t*)str, 16);
                break;
                //1871 1873 1814 1877 1863 1871 1834 1837 1819 1919 1850
            }
            break;
        }
    }

}

void move_task2()
{
    time = 0;
    Tar_Speed_JY = 8;
    Tar_Angle = 0;
    enter = 1;
    switch (enter) 
    {
        case 1:
        {
            Tar_Speed_JY = 10;
            Tar_Angle_JY = 0;   
            juli=0;
            while(1)
            {
                enter = 1;
                flag =3;
                if((juli>= 1820)&& (g1+g2+g3+g4+g5+g6+g7+g8) != 0)// 到达b点
                {
                    enter = 2;
                    err_zero();
                    flag=4;
                    left_flag=0;
                    right_flag=1;
                    juli=0;
                    break;
                }
                // run();
            }
        }

        case 2:
        {
            shan();
            while(1)
            {
                if((juli>=2680)&& (g1+g2+g3+g4+g5+g6+g7+g8)== 0)//停
                {
                    shan();
                //2746 2806 2766 2734 2709 2750 2689 2726 2721  2860
                    enter = 3;  
                    turn(-180);
                   break;

                }

            }

        }

        case 3:
        {
            Tar_Speed_JY = 10;
            Tar_Angle_JY = -180;  
            time = 0; 
            juli=0;
        //    err_zero();
            while(1)
            {
                flag =3;
                if((juli>=1650)&& (g1+g2+g3+g4+g5+g6+g7+g8)!= 0)//到达D点
                {
                    enter = 4;
                    shan();
                    err_zero();
                    flag=4;
                    left_flag=0;
                    right_flag=1;
                    break;
                }
                // run();
            }

        }

        case 4:
        {
            juli=0;
            flag=4;
            while(1)
            {
                if((juli>=2690)&&((g1+g2+g3+g4+g5+g6+g7+g8) ==0))//停
                {
                    flag = 0;
                    choice = 0;
                    shan();
                    turn(0);
                    while(1)
                        {
                            flag=0;
                            left(0);
                            right(0);
                            sprintf(str, "juli=%d", juli);
                            OLED_ShowString(2, 4, (uint8_t*)str, 16);
                            //break;
                            //
                        }
                    break;
                }

            }   
        }
    }

}

void move_task3(void)
{
    enter = 0;
    switch(enter)
    {
        case 0:
        {
            err_zero();
            turn(-35.5);
            juli=0;
            Tar_Speed_JY = 10;
            Tar_Angle_JY = -35;
            while(1)
            {
                flag =3;
                if(juli>=2235) //到达C点
                {
                    turn(15);
                    //2202 2240 2220 2066 2113 2023 2223 2017
                    err_zero();
                    juli=0;
                    flag=4;
                    left_flag=1;
                    right_flag=0;
                    shan();
                    break;
                }
            }
        enter = 1;
        }
        case 1:
        {
            while(1)
            {
                if((juli>=1375)&&((g1+g2+g3+g4+g5+g6+g7+g8)==0))
                {
                    shan();//到达B点
                    break;
                }
            }
            err_zero();
            turn(-143);
            enter = 2;
        }

        case 2:
        {
            err_zero();
            Tar_Speed_JY = 10;
            Tar_Angle_JY = -143;
            flag =3;
            juli=0;
            while(1)
            {
                if(juli>=2135) // 到达D点
                {
                    shan();
                    flag = 0;
                    choice = 0;
                    break;
                }
    
            }
            turn(-190);
            flag=4;
            left_flag=0;
            right_flag=1;
            enter = 3;
        }

        case 3:
        {
            err_zero();
            juli=0;
            while(1)
            {
           
                if(juli>=2540)//停
                {
                    shan();
                    while(1)
                    {
                    flag = 0;
                    choice = 0;
                    turn(0);
                    }
                }

            }
        }
    }

 }

void move_task4(void)
{
    switch (task4_times) 
    {
        case 0:
        {
            enter = 0;
            switch(enter)
            {
                case 0:
                {
                    err_zero();
                    turn(-35.5);
                    juli=0;
                    Tar_Speed_JY = 13;
                    Tar_Angle_JY = -35;
                    while(1)
                    {
                        flag =3;
                        if(juli>=2235) //到达C点
                        {
                            turn(15);
                            //2202 2240 2220 2066 2113 2023 2223 2017
                            err_zero();
                            juli=0;
                            flag=4;
                            left_flag=1;
                            right_flag=0;
                            shan();
                            break;
                        }
                    }
                enter = 1;
                }
                case 1:
                {
                    while(1)
                    {
                        if((juli>=1375)&&((g1+g2+g3+g4+g5+g6+g7+g8)==0))
                        {
                            shan();//到达B点
                            break;
                        }
                    }
                    err_zero();
                    turn(-143);
                    enter = 2;
                }

                case 2:
                {
                    err_zero();
                    Tar_Speed_JY = 13;
                    Tar_Angle_JY = -143;
                    flag =3;
                    juli=0;
                    while(1)
                    {
                        if(juli>=2150) // 到达D点
                        {
                            shan();
                            flag = 0;
                            choice = 0;
                            break;
                        }
            
                    }
                    turn(-195);
                    flag=4;
                    left_flag=0;
                    right_flag=1;
                    enter = 3;
                }

                case 3:
                {
                    err_zero();
                    juli=0;
                    while(1)
                    {
                        if((juli>=2510)&&((g1+g2+g3+g4+g5+g6+g7+g8+g8)==0))//停
                        {
                            flag = 0;
                            choice = 0;
                            shan();
                            turn(0);
                            task4_times++;
                            break;
                        }

                    }
                }
            }
        }
        case 1: //第二圈
        {
            enter = 0;
            switch(enter)
            {
                case 0:
                {
                    err_zero();
                    turn(-36);
                    juli=0;
                    Tar_Speed_JY = 13;
                    Tar_Angle_JY = -36;
                    while(1)
                    {
                        flag =3;
                        if(juli>=2190) //到达C点
                        {
                            turn(15);
                            //2202 2240 2220 2066 2113 2023 2223 2017
                            err_zero();
                            juli=0;
                            flag=4;
                            left_flag=1;
                            right_flag=0;
                            shan();
                            break;
                        }
                    }
                enter = 1;
                }
                case 1:
                {
                    while(1)
                    {
                        if((juli>=1375)&&((g1+g2+g3+g4+g5+g6+g7+g8)==0))
                        {
                            shan();//到达B点
                            break;
                        }
                    }
                    err_zero();
                    turn(-142);
                    enter = 2;
                }

                case 2:
                {
                    err_zero();
                    Tar_Speed_JY = 13;
                    Tar_Angle_JY = -142;
                    flag =3;
                    juli=0;
                    while(1)
                    {
                        if(juli>=2130) // 到达D点
                        {
                            shan();
                            flag = 0;
                            choice = 0;
                            break;
                        }
            
                    }
                    turn(-195);
                    flag=4;
                    left_flag=0;
                    right_flag=1;
                    enter = 3;
                }

                case 3:
                {
                    err_zero();
                    juli=0;
                    while(1)
                    {
                        
                        if((juli>=2510)&&((g1+g2+g3+g4+g5+g6+g7+g8+g8)==0))//停
                        {
                            flag = 0;
                            choice = 0;
                            shan();
                            turn(0);
                            task4_times++;
                            break;
                        }

                    }
                }
            }
        }
        case 2://3
        {
            enter = 0;
            switch(enter)
            {
                case 0:
                {
                    err_zero();
                    turn(-35);
                    juli=0;
                    Tar_Speed_JY = 13;
                    Tar_Angle_JY = -35;
                    while(1)
                    {
                        flag =3;
                        if(juli>=2180) //到达C点
                        {
                            turn(15);
                            //2202 2240 2220 2066 2113 2023 2223 2017
                            err_zero();
                            juli=0;
                            flag=4;
                            left_flag=1;
                            right_flag=0;
                            shan();
                            break;
                        }
                    }
                enter = 1;
                }
                case 1:
                {
                    while(1)
                    {
                        if((juli>=1365)&&((g1+g2+g3+g4+g5+g6+g7+g8)==0))
                        {
                            shan();//到达B点
                            break;
                        }
                    }
                    err_zero();
                    turn(-141);
                    enter = 2;
                }

                case 2:
                {
                    err_zero();
                    Tar_Speed_JY = 13;
                    Tar_Angle_JY = -141;
                    flag =3;
                    juli=0;
                    while(1)
                    {
                        if(juli>=2130) // 到达D点 2210-20
                        {
                            shan();
                            flag = 0;
                            choice = 0;
                            break;
                        }
            
                    }
                    turn(-195);
                    flag=4;
                    left_flag=0;
                    right_flag=1;
                    enter = 3;
                }

                case 3:
                {
                    err_zero();
                    juli=0;
                    while(1)
                    {
                        if((juli>=2510)&&((g1+g2+g3+g4+g5+g6+g7+g8+g8)==0))//停
                        {
                            flag = 0;
                            choice = 0;
                            shan();
                            turn(0);
                            task4_times++;
                            break;
                        }

                    }
                }
            }
        }
        case 3: //4
        {
            enter = 0;
            switch(enter)
            {
                case 0:
                {
                    err_zero();
                    turn(-35);
                    juli=0;
                    Tar_Speed_JY = 10;
                    Tar_Angle_JY = -35;
                    while(1)
                    {
                        flag =3;
                        if(juli>=2210) //到达C点
                        {
                            turn(15);
                            //2202 2240 2220 2066 2113 2023 2223 2017
                            err_zero();
                            juli=0;
                            flag=4;
                            left_flag=1;
                            right_flag=0;
                            shan();
                            break;
                        }
                    }
                enter = 1;
                }
                case 1:
                {
                    while(1)
                    {
                        if((juli>=1375)&&((g1+g2+g3+g4+g5+g6+g7+g8)==0))
                        {
                            shan();//到达B点
                            break;
                        }
                    }
                    err_zero();
                    turn(-142);
                    enter = 2;
                }

                case 2:
                {
                    err_zero();
                    Tar_Speed_JY = 10;
                    Tar_Angle_JY = -142;
                    flag =3;
                    juli=0;
                    while(1)
                    {
                        if(juli>=2150) // 到达D点  //2210-20
                        {
                            shan();
                            flag = 0;
                            choice = 0;
                            break;
                        }
            
                    }
                    turn(-195);
                    flag=4;
                    left_flag=0;
                    right_flag=1;
                    enter = 3;
                }

                case 3:
                {
                    err_zero();
                    juli=0;
                    while(1)
                    {
                        if((juli>=2510)&&((g1+g2+g3+g4+g5+g6+g7+g8+g8)==0))//停
                        {
                            flag = 0;
                            choice = 0;
                            shan();
                            turn(0);
                            task4_times++;
                            break;
                        }

                    }
                }
            }
        }
    
    }
    
}

void move_task4_HS(void)
{
    switch (task4_times) 
    {
        case 0:
        {
            enter = 0;
            switch(enter)
            {
                case 0:
                {
                    err_zero();
                    //turn(-37);
                    Tar_Speed_JY = HS_SPPPD;
                    Tar_Angle_JY = -38;
                    time=0;
                    while(1)
                    {
                        flag =3;
                        juli=0;
                        while(1)
                        {
                            if(juli>=2370) //到达C点 //2250
                            {
                                turn(12);
                                //2202 2240 2220 2066 2113 2023 2223 2017
                                err_zero();
                                left_flag=1;
                                right_flag=0;
                                flag=4;
                                juli=0;
                                shan();
                                break;
                            }
                        }
                        break;
                    }
                enter = 1;
                time=0;
                }
                case 1:
                {
                    while(1)
                    {
                         if (time>=slow_time)
                        {
                            flag=5;
                        }
                        if((juli>=1530)&&((g1+g2+g3+g4+g5+g6+g7+g8)==0))
                        {
                            shan();//到达B点
                            break;
                        }
                    }
                    err_zero();
                    enter = 2;
                }

                case 2:
                {
                    err_zero();
                    Tar_Speed_JY = HS_SPPPD;
                    Tar_Angle_JY = -141;
                    flag =3;
                    juli=0;
                    while(1)
                    {
                        if(juli>=2250) // 到达D点 2090
                        {
                            shan();
                            flag = 0;
                            choice = 0;
                            break;
                        }
            
                    }
                    turn(-208);
                    flag=4;
                    juli=0;
                    left_flag=0;
                    right_flag=1;
                    time=0;
                    enter = 3;
                }

                case 3:
                {
                    err_zero();
                    while(1)
                    {
                        if (time>=slow_time)
                        {
                            flag=5;
                        }
                        if((juli>=2300)&&(g1+g2+g3+g4+g5+g6+g7+g8)==0)//停
                        {
                            flag = 0;
                            choice = 0;
                            shan();
                            turn(0);
                            task4_times++;
                            break;
                        }
                    }
                }
            }
        }
        case 1: //第二圈
        {
            enter = 0;
            switch(enter)
            {
                case 0:
                {
                    err_zero();
                    Tar_Speed_JY = HS_SPPPD;
                    Tar_Angle_JY = -40;
                    while(1)
                    {
                        flag =3;
                        juli=0;
                        while(1)
                        {
                            if(juli>=2290) //到达C点 2170
                            {
                                turn(15);
                                //2202 2240 2220 2066 2113 2023 2223 2017
                                err_zero();
                                left_flag=1;
                                right_flag=0;
                                shan();
                                break;
                            }
                        }
                        break;
                    }
                enter = 1;
                flag=4;
                juli=0;
                time=0;
                }
                case 1:
                {
                    while(1)
                    {
                        if (time>=slow_time)
                        {
                            flag=5;
                        }
                        if((juli>=1530)&&((g1+g2+g3+g4+g5+g6+g7+g8)==0))
                        {
                            shan();//到达B点
                            flag=0;
                            break;
                        }
                    }
                    err_zero();
                    enter = 2;
                }

                case 2:
                {
                    err_zero();
                    Tar_Speed_JY = HS_SPPPD;
                    Tar_Angle_JY = -139;
                    flag =3;
                    juli=0;
                    while(1)
                    {
                        if(juli>=2260) // 到达D点 2140
                        {
                            shan();
                            flag = 0;
                            choice = 0;
                            break;
                        }
            
                    }
                    turn(-200);
                    err_zero();
                    flag=4;
                    juli=0;
                    left_flag=0;
                    right_flag=1;
                    enter = 3;
                    time=0;
                }

                case 3:
                {
                    while(1)
                    {
                        if (time>=slow_time)
                            {
                                flag=5;
                            }
                        if((juli>=2480)&&((g1+g2+g3+g4+g5+g6+g7+g8)==0))//停
                        {
                            flag = 0;
                            choice = 0;
                            shan();
                            turn(0);
                            task4_times++;
                            break;
                        }

                    }
                }
            }
        }
        case 2://3
        {
            enter = 0;
            switch(enter)
            {
                case 0:
                {
                    err_zero();
                    Tar_Speed_JY = HS_SPPPD;
                    Tar_Angle_JY = -39;
                    while(1)
                    {
                        flag =3;
                        juli=0;
                        while(1)
                        {
                            if(juli>=2260) //到达C点
                            {
                                turn(12);
                                shan();
                                //2202 2240 2220 2066 2113 2023 2223 2017
                                err_zero();
                                left_flag=1;
                                right_flag=0;
                                flag=4;
                                juli=0;
                                time=0;
                                break;
                            }
                        }
                        break;
                    }
                enter = 1;
                }
                case 1:
                {
                    while(1)
                    {
                        if (time>=slow_time)
                        {
                            flag=5;
                        }
                        if((juli>=1570)&&((g1+g2+g3+g4+g5+g6+g7+g8)==0))
                        {
                            shan();//到达B点
                            flag=0;
                            break;
                        }
                    }
                    err_zero();
                    enter = 2;
                }

                case 2:
                {
                    err_zero();
                    Tar_Speed_JY = HS_SPPPD;
                    Tar_Angle_JY = -139;
                    flag =3;
                    juli=0;
                    while(1)
                    {
                        if(juli>=2210) // 到达D点 2210-20
                        {
                            shan();
                            flag = 0;
                            choice = 0;
                            break;
                        }
            
                    }
                    turn(-195);
                    err_zero();
                    flag=4;
                    juli=0;
                    left_flag=0;
                    right_flag=1;
                    enter = 3;
                    time=0;
                }

                case 3:
                {
                    while(1)
                    {
                        if (time>=slow_time)
                            {
                                flag=5;
                            }
                            
                        if((juli>=2480)&&((g1+g2+g3+g4+g5+g6+g7+g8)==0))//停
                        {
                            flag = 0;
                            choice = 0;
                            shan();
                            turn(0);
                            task4_times++;
                            break;
                        }

                    }
                }
            }
        }
        case 3: //4
        {
            enter = 0;
            switch(enter)
            {
                case 0:
                {
                    err_zero();
                    Tar_Speed_JY = HS_SPPPD;
                    Tar_Angle_JY = -39;
                    while(1)
                    {
                        flag =3;
                        juli=0;
                        while(1)
                        {
                            if(juli>=2220) //到达C点
                            {
                                turn(13);
                                //2202 2240 2220 2066 2113 2023 2223 2017
                                err_zero();
                                flag=4;
                                juli=0;
                                left_flag=1;
                                right_flag=0;
                                shan();
                                break;
                            }
                        }
                        break;
                    }
                enter = 1;
                time=0;
                }
                case 1:
                {
                    while(1)
                    {
                        if (time>=slow_time)
                            {
                                flag=5;
                            }
                        if((juli>=1530)&&((g1+g2+g3+g4+g5+g6+g7+g8)==0))
                        {
                            shan();//到达B点
                            flag=0;
                            break;
                        }
                    }
                    err_zero();
                    enter = 2;
                }

                case 2:
                {
                    err_zero();
                    Tar_Speed_JY = HS_SPPPD;
                    Tar_Angle_JY = -140;
                    flag =3;
                    juli=0;
                    while(1)
                    {
                        if(juli>=2210) // 到达D点  //2210-20
                        {
                            shan();
                            flag = 0;
                            choice = 0;
                            break;
                        }
            
                    }
                    turn(-195);
                    flag=4;
                    juli=0;
                    left_flag=0;
                    right_flag=1;
                    enter = 3;
                    time=0;
                }

                case 3:
                {
                    err_zero();
                    while(1)
                    {
                        if (time>=slow_time)
                            {
                                flag=5;
                            }
                        if((juli>=2460)&&((g1+g2+g3+g4+g5+g6+g7+g8)==0))//停
                        {
                            flag = 0;
                            choice = 0;
                            shan();
                            turn(0);
                            task4_times++;
                            break;
                        }

                    }
                }
            }
        }
    
    }
    

    
 }


void conter_get(void)//获取编码器的值
{
    c2 = conter1;
    c1 = conter2;
    juli+=c1;
    // c3 = conter3;
    // c4 = conter4;
    conter1 = 0;
    conter2 = 0;
    // conter3 = 0;
    // conter4 = 0;
}

void run(void)
{
    left(PWM_L);
    right(PWM_R);
}

void JY61P_Init(void)//JY61P初始化函数
{
	buzzer(4); //200ms 
	DL_UART_Main_transmitDataBlocking(UART_1_INST,0xFF);
	DL_UART_Main_transmitDataBlocking(UART_1_INST,0xAA);
	DL_UART_Main_transmitDataBlocking(UART_1_INST,0x69);
	DL_UART_Main_transmitDataBlocking(UART_1_INST,0x88);
	DL_UART_Main_transmitDataBlocking(UART_1_INST,0xB5);
	buzzer(4); //200ms 
    DL_UART_Main_transmitDataBlocking(UART_1_INST,0xFF);
	DL_UART_Main_transmitDataBlocking(UART_1_INST,0xAA);
	DL_UART_Main_transmitDataBlocking(UART_1_INST,0x01);
	DL_UART_Main_transmitDataBlocking(UART_1_INST,0x04);
	DL_UART_Main_transmitDataBlocking(UART_1_INST,0x00);
    time = 0;
    led_on();
    while(1)
    {   
        if(time>=60)
            break;
    }
    DL_UART_Main_transmitDataBlocking(UART_1_INST,0xFF);
	DL_UART_Main_transmitDataBlocking(UART_1_INST,0xAA);
	DL_UART_Main_transmitDataBlocking(UART_1_INST,0x00);
	DL_UART_Main_transmitDataBlocking(UART_1_INST,0x00);
	DL_UART_Main_transmitDataBlocking(UART_1_INST,0x00);
    led_off();
}

void Key_GetNum(void)
{



}
void shan(void)
{
    shan_flag=1;
    led_time=0;
}
void calculate(void)
{
   if(((g4+g5)!=0)&&((g1+g2+g3+g6+g7+g8)==0))
    {
       if(left_flag==1)
       {
            Tar_Speed_l=7;
            Tar_Speed_r=10;
       }
       else if(right_flag==1)
       {
            Tar_Speed_l=10;
            Tar_Speed_r=7;
       }
    }
    else if ((g4)!=0&&((g1+g2+g3+g5+g6+g7+g8)==0))
    {
       if(left_flag==1)
       {
            Tar_Speed_l=7;
            Tar_Speed_r=10;
       }
       else if(right_flag==1)
       {
            Tar_Speed_l=10;
            Tar_Speed_r=7;
       }
    }
    else if ((g5)!=0&&((g1+g2+g3+g4+g6+g7+g8)==0))
    {
       if(left_flag==1)
       {
            Tar_Speed_l=7;
            Tar_Speed_r=10;
       }
       else if(right_flag==1)
       {
            Tar_Speed_l=10;
            Tar_Speed_r=7;
       }
    }
    else if (((g3!=0)&&((g1+g2+g4+g5+g6+g7+g8)==0)))
    {
       Tar_Speed_l=4;
       Tar_Speed_r=9;
    }
    else if (((g2!=0)&&((g1+g3+g4+g5+g6+g7+g8)==0)))
    {
       Tar_Speed_l=2;
       Tar_Speed_r=9;
    }
    else if (((g1!=0)&&((g2+g3+g4+g5+g6+g7+g8)==0)))
    {
       Tar_Speed_l=-2;
       Tar_Speed_r=9;
    }
    else if (((g6!=0)&&((g1+g2+g4+g5+g3+g7+g8)==0)))
    {
       Tar_Speed_l=9;
       Tar_Speed_r=4;
    }
    else if (((g7!=0)&&((g1+g2+g4+g5+g3+g6+g8)==0)))
    {
       Tar_Speed_l=9;
       Tar_Speed_r=2;
    }
    else if (((g8!=0)&&((g1+g2+g4+g5+g3+g6+g8)==0)))
    {
       Tar_Speed_l=9;
       Tar_Speed_r=-2;
    }
    else if ((g4+g3)!=0&&((g1+g2+g5+g6+g7+g8)==0))
    {
       Tar_Speed_l=4;
       Tar_Speed_r=9;
    }
    else if (((g5+g6)!=0&&((g1+g2+g3+g4+g7+g8)==0)))
    {
       Tar_Speed_l=9;
       Tar_Speed_r=4;
    }
     else if ((g3+g2)!=0&&((g1+g5+g6+g4+g7+g8)==0))
    {
       Tar_Speed_l=2;
       Tar_Speed_r=9;
    }
     else if ((g6+g7)!=0&&((g1+g2+g3+g4+g5+g8)==0))
    {
       Tar_Speed_l=9;
       Tar_Speed_r=2;
    }
     else if ((g1+g2)!=0&&((g3+g4+g5+g6+g7+g8)==0))
    {
       Tar_Speed_l=-2;
       Tar_Speed_r=9;
    }
     else if ((g7+g8)!=0&&((g1+g2+g3+g4+g5+g6)==0))
    {
       Tar_Speed_l=9;
       Tar_Speed_r=-2;
    }
    else if (((g1+g2+g3)==0)&&((g4+g5)==0)&&((g6+g7+g8)!=0))
    {
       Tar_Speed_l=9;
       Tar_Speed_r=1;
    }
    else if (((g1+g2+g3)==0)&&((g4+g8)==0)&&((g6+g7+g5)!=0))
    {
       Tar_Speed_l=9;
       Tar_Speed_r=3;
    }
    else if (((g1+g2+g3)!=0)&&((g4+g5)==0)&&((g6+g7+g8)==0))
    {
       Tar_Speed_l=1;
       Tar_Speed_r=9;
    }
    else if (((g4+g2+g3)!=0)&&((g1+g5)==0)&&((g6+g7+g8)==0))
    {
       Tar_Speed_l=3;
       Tar_Speed_r=9;
    }
    else if (((g1+g2+g3+g4)!=0)&&((g5+g6+g7+g8)==0))
    {
       Tar_Speed_l=3;
       Tar_Speed_r=9;
    }
    else if (((g1+g2+g3+g4)==0)&&((g5+g6+g7+g8)!=0))
    {
       Tar_Speed_l=9;
       Tar_Speed_r=3;
    }
    else
    {
        if(left_flag==1)
       {
            Tar_Speed_l=6;
            Tar_Speed_r=10;
       }
       else if(right_flag==1)
       {
            Tar_Speed_l=10;
            Tar_Speed_r=6;
       }
    }
}
void calculate_rage(void)
{
   if(((g4+g5)!=0)&&((g1+g2+g3+g6+g7+g8)==0))
    {
       if(left_flag==1)
       {
            Tar_Speed_l=7;
            Tar_Speed_r=10;
       }
       else if(right_flag==1)
       {
            Tar_Speed_l=10;
            Tar_Speed_r=7;
       }
    }
    else if ((g4)!=0&&((g1+g2+g3+g5+g6+g7+g8)==0))
    {
       if(left_flag==1)
       {
            Tar_Speed_l=7;
            Tar_Speed_r=10;
       }
       else if(right_flag==1)
       {
            Tar_Speed_l=10;
            Tar_Speed_r=7;
       }
    }
    else if ((g5)!=0&&((g1+g2+g3+g4+g6+g7+g8)==0))
    {
       if(left_flag==1)
       {
            Tar_Speed_l=7;
            Tar_Speed_r=10;
       }
       else if(right_flag==1)
       {
            Tar_Speed_l=10;
            Tar_Speed_r=7;
       }
    }
    else if (((g3!=0)&&((g1+g2+g4+g5+g6+g7+g8)==0)))
    {
       Tar_Speed_l=3;
       Tar_Speed_r=6;
    }
    else if (((g2!=0)&&((g1+g3+g4+g5+g6+g7+g8)==0)))
    {
       Tar_Speed_l=3;
       Tar_Speed_r=7;
    }
    else if (((g1!=0)&&((g2+g3+g4+g5+g6+g7+g8)==0)))
    {
       Tar_Speed_l=3;
       Tar_Speed_r=7;
    }
    else if (((g6!=0)&&((g1+g2+g4+g5+g3+g7+g8)==0)))
    {
       Tar_Speed_l=6;
       Tar_Speed_r=3;
    }
    else if (((g7!=0)&&((g1+g2+g4+g5+g3+g6+g8)==0)))
    {
       Tar_Speed_l=7;
       Tar_Speed_r=3;
    }
    else if (((g8!=0)&&((g1+g2+g4+g5+g3+g6+g8)==0)))
    {
       Tar_Speed_l=7;
       Tar_Speed_r=3;
    }
    else if ((g4+g3)!=0&&((g1+g2+g5+g6+g7+g8)==0))
    {
       Tar_Speed_l=4;
       Tar_Speed_r=9;
    }
    else if (((g5+g6)!=0&&((g1+g2+g3+g4+g7+g8)==0)))
    {
       Tar_Speed_l=8;
       Tar_Speed_r=4;
    }
     else if ((g3+g2)!=0&&((g1+g5+g6+g4+g7+g8)==0))
    {
       Tar_Speed_l=4;
       Tar_Speed_r=7;
    }
     else if ((g6+g7)!=0&&((g1+g2+g3+g4+g5+g8)==0))
    {
       Tar_Speed_l=7;
       Tar_Speed_r=4;
    }
     else if ((g1+g2)!=0&&((g3+g4+g5+g6+g7+g8)==0))
    {
       Tar_Speed_l=3;
       Tar_Speed_r=7;
    }
     else if ((g7+g8)!=0&&((g1+g2+g3+g4+g5+g6)==0))
    {
       Tar_Speed_l=7;
       Tar_Speed_r=3;
    }
    else if (((g1+g2+g3)==0)&&((g4+g5)==0)&&((g6+g7+g8)!=0))
    {
       Tar_Speed_l=7;
       Tar_Speed_r=3;
    }
    else if (((g1+g2+g3)==0)&&((g4+g8)==0)&&((g6+g7+g5)!=0))
    {
       Tar_Speed_l=7;
       Tar_Speed_r=4;
    }
    else if (((g1+g2+g3)!=0)&&((g4+g5)==0)&&((g6+g7+g8)==0))
    {
       Tar_Speed_l=3;
       Tar_Speed_r=7;
    }
    else if (((g4+g2+g3)!=0)&&((g1+g5)==0)&&((g6+g7+g8)==0))
    {
       Tar_Speed_l=3;
       Tar_Speed_r=7;
    }
    else if (((g1+g2+g3+g4)!=0)&&((g5+g6+g7+g8)==0))
    {
       Tar_Speed_l=3;
       Tar_Speed_r=8;
    }
    else if (((g1+g2+g3+g4)==0)&&((g5+g6+g7+g8)!=0))
    {
       Tar_Speed_l=8;
       Tar_Speed_r=3;
    }
    else
    {
        if(left_flag==1)
       {
            Tar_Speed_l=6;
            Tar_Speed_r=10;
       }
       else if(right_flag==1)
       {
            Tar_Speed_l=10;
            Tar_Speed_r=6;
       }
    }
}
void Rage_engine(void)//狂暴引擎
{
     if(((g4+g5)!=0)&&((g1+g2+g3+g6+g7+g8)==0))
    {
       if(left_flag==1)
       {
            Tar_Speed_l=10;
            Tar_Speed_r=14;
       }
       else if(right_flag==1)
       {
            Tar_Speed_l=14;
            Tar_Speed_r=10;
       }
    }
    else if ((g4)!=0&&((g1+g2+g3+g5+g6+g7+g8)==0))
    {
       if(left_flag==1)
       {
            Tar_Speed_l=10;//10
            Tar_Speed_r=14;
       }
       else if(right_flag==1)
       {
            Tar_Speed_l=14;
            Tar_Speed_r=10;//10
       }
    }
    else if ((g5)!=0&&((g1+g2+g3+g4+g6+g7+g8)==0))
    {
       if(left_flag==1)
       {
            Tar_Speed_l=10;//10
            Tar_Speed_r=14;
       }
       else if(right_flag==1)
       {
            Tar_Speed_l=14;
            Tar_Speed_r=10;//10
       }
    }
    else if (((g3!=0)&&((g1+g2+g4+g5+g6+g7+g8)==0)))
    {
       Tar_Speed_l=9;//8
       Tar_Speed_r=14;
    }
    else if (((g2!=0)&&((g1+g3+g4+g5+g6+g7+g8)==0)))
    {
       Tar_Speed_l=8;//7
       Tar_Speed_r=14;
    }
    else if (((g1!=0)&&((g2+g3+g4+g5+g6+g7+g8)==0)))
    {
       Tar_Speed_l=6;//7
       Tar_Speed_r=12;
    }
    else if (((g6!=0)&&((g1+g2+g4+g5+g3+g7+g8)==0)))
    {
       Tar_Speed_l=14;
       Tar_Speed_r=9;//8
    }
    else if (((g7!=0)&&((g1+g2+g4+g5+g3+g6+g8)==0)))
    {
       Tar_Speed_l=14;
       Tar_Speed_r=8;//7
    }
    else if (((g8!=0)&&((g1+g2+g4+g5+g3+g6+g8)==0)))
    {
       Tar_Speed_l=12;
       Tar_Speed_r=6;//7
    }
    else if ((g4+g3)!=0&&((g1+g2+g5+g6+g7+g8)==0))
    {
       Tar_Speed_l=9;//7
       Tar_Speed_r=14;
    }
    else if (((g5+g6)!=0&&((g1+g2+g3+g4+g7+g8)==0)))
    {
       Tar_Speed_l=14;
       Tar_Speed_r=9;
    }
     else if ((g3+g2)!=0&&((g1+g5+g6+g4+g7+g8)==0))
    {
       Tar_Speed_l=6;//9
       Tar_Speed_r=12;
    }
     else if ((g6+g7)!=0&&((g1+g2+g3+g4+g5+g8)==0))
    {
       Tar_Speed_l=12;
       Tar_Speed_r=6;//8
    }
     else if ((g1+g2)!=0&&((g3+g4+g5+g6+g7+g8)==0))
    {
       Tar_Speed_l=6;
       Tar_Speed_r=14;
    }
     else if ((g7+g8)!=0&&((g1+g2+g3+g4+g5+g6)==0))
    {
       Tar_Speed_l=14;
       Tar_Speed_r=6;
    }
    else if (((g1+g2+g3)==0)&&((g4+g5)==0)&&((g6+g7+g8)!=0))
    {
       Tar_Speed_l=14;
       Tar_Speed_r=7;
    }
    else if (((g1+g2+g3)==0)&&((g4+g8)==0)&&((g6+g7+g5)!=0))
    {
       Tar_Speed_l=14;
       Tar_Speed_r=7;
    }
    else if (((g1+g2+g3)!=0)&&((g4+g5)==0)&&((g6+g7+g8)==0))
    {
       Tar_Speed_l=7;
       Tar_Speed_r=13;
    }
    else if (((g4+g2+g3)!=0)&&((g1+g5)==0)&&((g6+g7+g8)==0))
    {
       Tar_Speed_l=6;
       Tar_Speed_r=13;
    }
    else if (((g1+g2+g3+g4)!=0)&&((g5+g6+g7+g8)==0))
    {
       Tar_Speed_l=6;
       Tar_Speed_r=12;
    }
    else if (((g1+g2+g3+g4)==0)&&((g5+g6+g7+g8)!=0))
    {
       Tar_Speed_l=12;
       Tar_Speed_r=6;
    }
    else
    {
        if(left_flag==1)
       {
            Tar_Speed_l=8;
            Tar_Speed_r=14;
       }
       else if(right_flag==1)
       {
            Tar_Speed_l=14;
            Tar_Speed_r=8;
       }
    }
}

void rage_engine(void)

{
     if(((g4+g5)!=0)&&((g1+g2+g3+g6+g7+g8)==0))
    {
       if(left_flag==1)
       {
            Tar_Speed_l=10;
            Tar_Speed_r=14;
       }
       else if(right_flag==1)
       {
            Tar_Speed_l=14;
            Tar_Speed_r=10;
       }
    }
    else if ((g4)!=0&&((g1+g2+g3+g5+g6+g7+g8)==0))
    {
       if(left_flag==1)
       {
            Tar_Speed_l=10;//10
            Tar_Speed_r=14;
       }
       else if(right_flag==1)
       {
            Tar_Speed_l=14;
            Tar_Speed_r=10;//10
       }
    }
    else if ((g5)!=0&&((g1+g2+g3+g4+g6+g7+g8)==0))
    {
       if(left_flag==1)
       {
            Tar_Speed_l=10;//10
            Tar_Speed_r=14;
       }
       else if(right_flag==1)
       {
            Tar_Speed_l=14;
            Tar_Speed_r=10;//10
       }
    }
    else if (((g3!=0)&&((g1+g2+g4+g5+g6+g7+g8)==0)))
    {
       Tar_Speed_l=8;//8
       Tar_Speed_r=14;
    }
    else if (((g2!=0)&&((g1+g3+g4+g5+g6+g7+g8)==0)))
    {
       Tar_Speed_l=7;//7
       Tar_Speed_r=14;
    }
    else if (((g1!=0)&&((g2+g3+g4+g5+g6+g7+g8)==0)))
    {
       Tar_Speed_l=5;//7
       Tar_Speed_r=12;
    }
    else if (((g6!=0)&&((g1+g2+g4+g5+g3+g7+g8)==0)))
    {
       Tar_Speed_l=14;
       Tar_Speed_r=8;//8
    }
    else if (((g7!=0)&&((g1+g2+g4+g5+g3+g6+g8)==0)))
    {
       Tar_Speed_l=14;
       Tar_Speed_r=7;//7
    }
    else if (((g8!=0)&&((g1+g2+g4+g5+g3+g6+g8)==0)))
    {
       Tar_Speed_l=12;
       Tar_Speed_r=5;//7
    }
    else if ((g4+g3)!=0&&((g1+g2+g5+g6+g7+g8)==0))
    {
       Tar_Speed_l=8;//7
       Tar_Speed_r=14;
    }
    else if (((g5+g6)!=0&&((g1+g2+g3+g4+g7+g8)==0)))
    {
       Tar_Speed_l=14;
       Tar_Speed_r=8;
    }
     else if ((g3+g2)!=0&&((g1+g5+g6+g4+g7+g8)==0))
    {
       Tar_Speed_l=5;//9
       Tar_Speed_r=12;
    }
     else if ((g6+g7)!=0&&((g1+g2+g3+g4+g5+g8)==0))
    {
       Tar_Speed_l=12;
       Tar_Speed_r=5;//8
    }
     else if ((g1+g2)!=0&&((g3+g4+g5+g6+g7+g8)==0))
    {
       Tar_Speed_l=5;
       Tar_Speed_r=14;
    }
     else if ((g7+g8)!=0&&((g1+g2+g3+g4+g5+g6)==0))
    {
       Tar_Speed_l=14;
       Tar_Speed_r=5;
    }
    else if (((g1+g2+g3)==0)&&((g4+g5)==0)&&((g6+g7+g8)!=0))
    {
       Tar_Speed_l=14;
       Tar_Speed_r=6;
    }
    else if (((g1+g2+g3)==0)&&((g4+g8)==0)&&((g6+g7+g5)!=0))
    {
       Tar_Speed_l=13;
       Tar_Speed_r=7;
    }
    else if (((g1+g2+g3)!=0)&&((g4+g5)==0)&&((g6+g7+g8)==0))
    {
       Tar_Speed_l=6;
       Tar_Speed_r=13;
    }
    else if (((g4+g2+g3)!=0)&&((g1+g5)==0)&&((g6+g7+g8)==0))
    {
       Tar_Speed_l=6;
       Tar_Speed_r=13;
    }
    else if (((g1+g2+g3+g4)!=0)&&((g5+g6+g7+g8)==0))
    {
       Tar_Speed_l=6;
       Tar_Speed_r=12;
    }
    else if (((g1+g2+g3+g4)==0)&&((g5+g6+g7+g8)!=0))
    {
       Tar_Speed_l=12;
       Tar_Speed_r=6;
    }
    else
    {
        if(left_flag==1)
       {
            Tar_Speed_l=7;
            Tar_Speed_r=14;
       }
       else if(right_flag==1)
       {
            Tar_Speed_l=14;
            Tar_Speed_r=7;
       }
    }
}
