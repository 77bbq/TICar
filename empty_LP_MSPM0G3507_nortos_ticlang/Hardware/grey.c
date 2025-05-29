#include "grey.h"
#include "ti/driverlib/dl_gpio.h"
#include "ti_msp_dl_config.h"
#include <ti/driverlib/m0p/dl_core.h>
int g1 = 0,g2 = 0,g3 = 0,g4 = 0,g5 = 0,g6 = 0,g7 = 0,g8 = 0;
int grey_times=0;
float grey_value=0.0;
int left_flag=0;
int right_flag=0;
void grey_GetNum(void)
{
    grey_times=0;
    if (DL_GPIO_readPins(GPIO_huidu_PIN_grey1_PORT,GPIO_huidu_PIN_grey1_PIN)==0)
    {
       g1 =1; 
       grey_times++;
    }
    else 
    {
        g1 =0;
    }

    if (DL_GPIO_readPins(GPIO_huidu_PIN_grey2_PORT,GPIO_huidu_PIN_grey2_PIN)==0)
    {
       g2 =2; 
       grey_times++;
    }
    else 
    {
        g2=0;
    }

    if (DL_GPIO_readPins(GPIO_huidu_PIN_grey3_PORT,GPIO_huidu_PIN_grey3_PIN)==0)
    {
       g3 =3; 
       grey_times++;
    }
    else
    {
        g3=0;
    }

    if (DL_GPIO_readPins(GPIO_huidu_PIN_grey4_PORT,GPIO_huidu_PIN_grey4_PIN)==0)
    {
       g4 =4; 
       grey_times++;
    }
    else
    {
        g4=0;
    }

    if (DL_GPIO_readPins(GPIO_huidu_PIN_grey5_PORT,GPIO_huidu_PIN_grey5_PIN)==0)
    {
        g5 =5; 
        grey_times++;
    }
    else 
    {
        g5=0;
    }

    if (DL_GPIO_readPins(GPIO_huidu_PIN_grey6_PORT,GPIO_huidu_PIN_grey6_PIN)==0)
    {
       g6 =6; 
       grey_times++;
    }
    else 
    {
        g6=0;
    }
    if (DL_GPIO_readPins(GPIO_huidu_PIN_grey7_PORT,GPIO_huidu_PIN_grey7_PIN)==0)
    {
       g7 =7; 
       grey_times++;
    }
    else 
    {
        g7=0;
    }
    if (DL_GPIO_readPins(GPIO_huidu_PIN_grey8_PORT,GPIO_huidu_PIN_grey8_PIN)==0)
    {
       g8 =8; 
       grey_times++;
    }
    else 
    {
        g8=0;
    }
    if (grey_times!=0)
    {
    grey_value=(float)(g1+g2+g3+g4+g5+g6+g7+g8)/(float)grey_times;
    }
    else 
    {
    grey_value=0.0;
    }


}