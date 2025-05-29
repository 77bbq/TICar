/*
 * Copyright (c) 2023, Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ============ ti_msp_dl_config.h =============
 *  Configured MSPM0 DriverLib module declarations
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */
#ifndef ti_msp_dl_config_h
#define ti_msp_dl_config_h

#define CONFIG_MSPM0G350X

#if defined(__ti_version__) || defined(__TI_COMPILER_VERSION__)
#define SYSCONFIG_WEAK __attribute__((weak))
#elif defined(__IAR_SYSTEMS_ICC__)
#define SYSCONFIG_WEAK __weak
#elif defined(__GNUC__)
#define SYSCONFIG_WEAK __attribute__((weak))
#endif

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform all required MSP DL initialization
 *
 *  This function should be called once at a point before any use of
 *  MSP DL.
 */


/* clang-format off */

#define POWER_STARTUP_DELAY                                                (16)



#define CPUCLK_FREQ                                                     80000000



/* Defines for PWM_A0 */
#define PWM_A0_INST                                                        TIMA0
#define PWM_A0_INST_IRQHandler                                  TIMA0_IRQHandler
#define PWM_A0_INST_INT_IRQN                                    (TIMA0_INT_IRQn)
#define PWM_A0_INST_CLK_FREQ                                              100000
/* GPIO defines for channel 0 */
#define GPIO_PWM_A0_C0_PORT                                                GPIOB
#define GPIO_PWM_A0_C0_PIN                                         DL_GPIO_PIN_8
#define GPIO_PWM_A0_C0_IOMUX                                     (IOMUX_PINCM25)
#define GPIO_PWM_A0_C0_IOMUX_FUNC                    IOMUX_PINCM25_PF_TIMA0_CCP0
#define GPIO_PWM_A0_C0_IDX                                   DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_PWM_A0_C1_PORT                                                GPIOB
#define GPIO_PWM_A0_C1_PIN                                         DL_GPIO_PIN_9
#define GPIO_PWM_A0_C1_IOMUX                                     (IOMUX_PINCM26)
#define GPIO_PWM_A0_C1_IOMUX_FUNC                    IOMUX_PINCM26_PF_TIMA0_CCP1
#define GPIO_PWM_A0_C1_IDX                                   DL_TIMER_CC_1_INDEX
/* GPIO defines for channel 2 */
#define GPIO_PWM_A0_C2_PORT                                                GPIOB
#define GPIO_PWM_A0_C2_PIN                                         DL_GPIO_PIN_4
#define GPIO_PWM_A0_C2_IOMUX                                     (IOMUX_PINCM17)
#define GPIO_PWM_A0_C2_IOMUX_FUNC                    IOMUX_PINCM17_PF_TIMA0_CCP2
#define GPIO_PWM_A0_C2_IDX                                   DL_TIMER_CC_2_INDEX
/* GPIO defines for channel 3 */
#define GPIO_PWM_A0_C3_PORT                                                GPIOB
#define GPIO_PWM_A0_C3_PIN                                         DL_GPIO_PIN_2
#define GPIO_PWM_A0_C3_IOMUX                                     (IOMUX_PINCM15)
#define GPIO_PWM_A0_C3_IOMUX_FUNC                    IOMUX_PINCM15_PF_TIMA0_CCP3
#define GPIO_PWM_A0_C3_IDX                                   DL_TIMER_CC_3_INDEX



/* Defines for TIMER_G0 */
#define TIMER_G0_INST                                                    (TIMG0)
#define TIMER_G0_INST_IRQHandler                                TIMG0_IRQHandler
#define TIMER_G0_INST_INT_IRQN                                  (TIMG0_INT_IRQn)
#define TIMER_G0_INST_LOAD_VALUE                                         (1999U)
/* Defines for TIMER_G6 */
#define TIMER_G6_INST                                                    (TIMG6)
#define TIMER_G6_INST_IRQHandler                                TIMG6_IRQHandler
#define TIMER_G6_INST_INT_IRQN                                  (TIMG6_INT_IRQn)
#define TIMER_G6_INST_LOAD_VALUE                                         (3999U)



/* Defines for UART_0 */
#define UART_0_INST                                                        UART0
#define UART_0_INST_IRQHandler                                  UART0_IRQHandler
#define UART_0_INST_INT_IRQN                                      UART0_INT_IRQn
#define GPIO_UART_0_RX_PORT                                                GPIOA
#define GPIO_UART_0_TX_PORT                                                GPIOA
#define GPIO_UART_0_RX_PIN                                        DL_GPIO_PIN_11
#define GPIO_UART_0_TX_PIN                                        DL_GPIO_PIN_10
#define GPIO_UART_0_IOMUX_RX                                     (IOMUX_PINCM22)
#define GPIO_UART_0_IOMUX_TX                                     (IOMUX_PINCM21)
#define GPIO_UART_0_IOMUX_RX_FUNC                      IOMUX_PINCM22_PF_UART0_RX
#define GPIO_UART_0_IOMUX_TX_FUNC                      IOMUX_PINCM21_PF_UART0_TX
#define UART_0_BAUD_RATE                                                (115200)
#define UART_0_IBRD_40_MHZ_115200_BAUD                                      (21)
#define UART_0_FBRD_40_MHZ_115200_BAUD                                      (45)
/* Defines for UART_1 */
#define UART_1_INST                                                        UART1
#define UART_1_INST_IRQHandler                                  UART1_IRQHandler
#define UART_1_INST_INT_IRQN                                      UART1_INT_IRQn
#define GPIO_UART_1_RX_PORT                                                GPIOA
#define GPIO_UART_1_TX_PORT                                                GPIOA
#define GPIO_UART_1_RX_PIN                                         DL_GPIO_PIN_9
#define GPIO_UART_1_TX_PIN                                         DL_GPIO_PIN_8
#define GPIO_UART_1_IOMUX_RX                                     (IOMUX_PINCM20)
#define GPIO_UART_1_IOMUX_TX                                     (IOMUX_PINCM19)
#define GPIO_UART_1_IOMUX_RX_FUNC                      IOMUX_PINCM20_PF_UART1_RX
#define GPIO_UART_1_IOMUX_TX_FUNC                      IOMUX_PINCM19_PF_UART1_TX
#define UART_1_BAUD_RATE                                                  (9600)
#define UART_1_IBRD_40_MHZ_9600_BAUD                                       (260)
#define UART_1_FBRD_40_MHZ_9600_BAUD                                        (27)
/* Defines for UART_2 */
#define UART_2_INST                                                        UART2
#define UART_2_INST_IRQHandler                                  UART2_IRQHandler
#define UART_2_INST_INT_IRQN                                      UART2_INT_IRQn
#define GPIO_UART_2_RX_PORT                                                GPIOB
#define GPIO_UART_2_TX_PORT                                                GPIOB
#define GPIO_UART_2_RX_PIN                                        DL_GPIO_PIN_18
#define GPIO_UART_2_TX_PIN                                        DL_GPIO_PIN_17
#define GPIO_UART_2_IOMUX_RX                                     (IOMUX_PINCM44)
#define GPIO_UART_2_IOMUX_TX                                     (IOMUX_PINCM43)
#define GPIO_UART_2_IOMUX_RX_FUNC                      IOMUX_PINCM44_PF_UART2_RX
#define GPIO_UART_2_IOMUX_TX_FUNC                      IOMUX_PINCM43_PF_UART2_TX
#define UART_2_BAUD_RATE                                                (115200)
#define UART_2_IBRD_40_MHZ_115200_BAUD                                      (21)
#define UART_2_FBRD_40_MHZ_115200_BAUD                                      (45)





/* Port definition for Pin Group GPIO_LED */
#define GPIO_LED_PORT                                                    (GPIOB)

/* Defines for PIN_LED: GPIOB.13 with pinCMx 30 on package pin 1 */
#define GPIO_LED_PIN_LED_PIN                                    (DL_GPIO_PIN_13)
#define GPIO_LED_PIN_LED_IOMUX                                   (IOMUX_PINCM30)
/* Port definition for Pin Group GPIO_BUZZER */
#define GPIO_BUZZER_PORT                                                 (GPIOB)

/* Defines for PIN_buzzer: GPIOB.0 with pinCMx 12 on package pin 47 */
#define GPIO_BUZZER_PIN_buzzer_PIN                               (DL_GPIO_PIN_0)
#define GPIO_BUZZER_PIN_buzzer_IOMUX                             (IOMUX_PINCM12)
/* Port definition for Pin Group GPIO_MOTOR */
#define GPIO_MOTOR_PORT                                                  (GPIOA)

/* Defines for PIN_motor1: GPIOA.1 with pinCMx 2 on package pin 34 */
#define GPIO_MOTOR_PIN_motor1_PIN                                (DL_GPIO_PIN_1)
#define GPIO_MOTOR_PIN_motor1_IOMUX                               (IOMUX_PINCM2)
/* Defines for PIN_motor2: GPIOA.7 with pinCMx 14 on package pin 49 */
#define GPIO_MOTOR_PIN_motor2_PIN                                (DL_GPIO_PIN_7)
#define GPIO_MOTOR_PIN_motor2_IOMUX                              (IOMUX_PINCM14)
/* Defines for PIN_motor3: GPIOA.12 with pinCMx 34 on package pin 5 */
#define GPIO_MOTOR_PIN_motor3_PIN                               (DL_GPIO_PIN_12)
#define GPIO_MOTOR_PIN_motor3_IOMUX                              (IOMUX_PINCM34)
/* Defines for PIN_motor4: GPIOA.13 with pinCMx 35 on package pin 6 */
#define GPIO_MOTOR_PIN_motor4_PIN                               (DL_GPIO_PIN_13)
#define GPIO_MOTOR_PIN_motor4_IOMUX                              (IOMUX_PINCM35)
/* Defines for PIN_motor5: GPIOA.14 with pinCMx 36 on package pin 7 */
#define GPIO_MOTOR_PIN_motor5_PIN                               (DL_GPIO_PIN_14)
#define GPIO_MOTOR_PIN_motor5_IOMUX                              (IOMUX_PINCM36)
/* Defines for PIN_motor6: GPIOA.15 with pinCMx 37 on package pin 8 */
#define GPIO_MOTOR_PIN_motor6_PIN                               (DL_GPIO_PIN_15)
#define GPIO_MOTOR_PIN_motor6_IOMUX                              (IOMUX_PINCM37)
/* Defines for PIN_motor7: GPIOA.16 with pinCMx 38 on package pin 9 */
#define GPIO_MOTOR_PIN_motor7_PIN                               (DL_GPIO_PIN_16)
#define GPIO_MOTOR_PIN_motor7_IOMUX                              (IOMUX_PINCM38)
/* Defines for PIN_motor8: GPIOA.17 with pinCMx 39 on package pin 10 */
#define GPIO_MOTOR_PIN_motor8_PIN                               (DL_GPIO_PIN_17)
#define GPIO_MOTOR_PIN_motor8_IOMUX                              (IOMUX_PINCM39)
/* Port definition for Pin Group GPIO_OLED */
#define GPIO_OLED_PORT                                                   (GPIOA)

/* Defines for PIN_SCL: GPIOA.28 with pinCMx 3 on package pin 35 */
#define GPIO_OLED_PIN_SCL_PIN                                   (DL_GPIO_PIN_28)
#define GPIO_OLED_PIN_SCL_IOMUX                                   (IOMUX_PINCM3)
/* Defines for PIN_SDA: GPIOA.31 with pinCMx 6 on package pin 39 */
#define GPIO_OLED_PIN_SDA_PIN                                   (DL_GPIO_PIN_31)
#define GPIO_OLED_PIN_SDA_IOMUX                                   (IOMUX_PINCM6)
/* Port definition for Pin Group GPIO_ENCONDER */
#define GPIO_ENCONDER_PORT                                               (GPIOB)

/* Defines for PIN_ECO1A: GPIOB.10 with pinCMx 27 on package pin 62 */
// pins affected by this interrupt request:["PIN_ECO1A","PIN_ECO2A"]
#define GPIO_ENCONDER_INT_IRQN                                  (GPIOB_INT_IRQn)
#define GPIO_ENCONDER_INT_IIDX                  (DL_INTERRUPT_GROUP1_IIDX_GPIOB)
#define GPIO_ENCONDER_PIN_ECO1A_IIDX                        (DL_GPIO_IIDX_DIO10)
#define GPIO_ENCONDER_PIN_ECO1A_PIN                             (DL_GPIO_PIN_10)
#define GPIO_ENCONDER_PIN_ECO1A_IOMUX                            (IOMUX_PINCM27)
/* Defines for PIN_ECO1B: GPIOB.11 with pinCMx 28 on package pin 63 */
#define GPIO_ENCONDER_PIN_ECO1B_PIN                             (DL_GPIO_PIN_11)
#define GPIO_ENCONDER_PIN_ECO1B_IOMUX                            (IOMUX_PINCM28)
/* Defines for PIN_ECO2A: GPIOB.19 with pinCMx 45 on package pin 16 */
#define GPIO_ENCONDER_PIN_ECO2A_IIDX                        (DL_GPIO_IIDX_DIO19)
#define GPIO_ENCONDER_PIN_ECO2A_PIN                             (DL_GPIO_PIN_19)
#define GPIO_ENCONDER_PIN_ECO2A_IOMUX                            (IOMUX_PINCM45)
/* Defines for PIN_ECO2B: GPIOB.20 with pinCMx 48 on package pin 19 */
#define GPIO_ENCONDER_PIN_ECO2B_PIN                             (DL_GPIO_PIN_20)
#define GPIO_ENCONDER_PIN_ECO2B_IOMUX                            (IOMUX_PINCM48)
/* Defines for PIN_grey1: GPIOA.25 with pinCMx 55 on package pin 26 */
#define GPIO_huidu_PIN_grey1_PORT                                        (GPIOA)
#define GPIO_huidu_PIN_grey1_PIN                                (DL_GPIO_PIN_25)
#define GPIO_huidu_PIN_grey1_IOMUX                               (IOMUX_PINCM55)
/* Defines for PIN_grey2: GPIOA.22 with pinCMx 47 on package pin 18 */
#define GPIO_huidu_PIN_grey2_PORT                                        (GPIOA)
#define GPIO_huidu_PIN_grey2_PIN                                (DL_GPIO_PIN_22)
#define GPIO_huidu_PIN_grey2_IOMUX                               (IOMUX_PINCM47)
/* Defines for PIN_grey3: GPIOA.26 with pinCMx 59 on package pin 30 */
#define GPIO_huidu_PIN_grey3_PORT                                        (GPIOA)
#define GPIO_huidu_PIN_grey3_PIN                                (DL_GPIO_PIN_26)
#define GPIO_huidu_PIN_grey3_IOMUX                               (IOMUX_PINCM59)
/* Defines for PIN_grey4: GPIOB.24 with pinCMx 52 on package pin 23 */
#define GPIO_huidu_PIN_grey4_PORT                                        (GPIOB)
#define GPIO_huidu_PIN_grey4_PIN                                (DL_GPIO_PIN_24)
#define GPIO_huidu_PIN_grey4_IOMUX                               (IOMUX_PINCM52)
/* Defines for PIN_grey5: GPIOA.27 with pinCMx 60 on package pin 31 */
#define GPIO_huidu_PIN_grey5_PORT                                        (GPIOA)
#define GPIO_huidu_PIN_grey5_PIN                                (DL_GPIO_PIN_27)
#define GPIO_huidu_PIN_grey5_IOMUX                               (IOMUX_PINCM60)
/* Defines for PIN_grey6: GPIOB.3 with pinCMx 16 on package pin 51 */
#define GPIO_huidu_PIN_grey6_PORT                                        (GPIOB)
#define GPIO_huidu_PIN_grey6_PIN                                 (DL_GPIO_PIN_3)
#define GPIO_huidu_PIN_grey6_IOMUX                               (IOMUX_PINCM16)
/* Defines for PIN_grey7: GPIOB.25 with pinCMx 56 on package pin 27 */
#define GPIO_huidu_PIN_grey7_PORT                                        (GPIOB)
#define GPIO_huidu_PIN_grey7_PIN                                (DL_GPIO_PIN_25)
#define GPIO_huidu_PIN_grey7_IOMUX                               (IOMUX_PINCM56)
/* Defines for PIN_grey8: GPIOB.23 with pinCMx 51 on package pin 22 */
#define GPIO_huidu_PIN_grey8_PORT                                        (GPIOB)
#define GPIO_huidu_PIN_grey8_PIN                                (DL_GPIO_PIN_23)
#define GPIO_huidu_PIN_grey8_IOMUX                               (IOMUX_PINCM51)
/* Port definition for Pin Group GPIO_KEY */
#define GPIO_KEY_PORT                                                    (GPIOB)

/* Defines for PIN_KEY1: GPIOB.26 with pinCMx 57 on package pin 28 */
#define GPIO_KEY_PIN_KEY1_PIN                                   (DL_GPIO_PIN_26)
#define GPIO_KEY_PIN_KEY1_IOMUX                                  (IOMUX_PINCM57)
/* Defines for PIN_KEY2: GPIOB.27 with pinCMx 58 on package pin 29 */
#define GPIO_KEY_PIN_KEY2_PIN                                   (DL_GPIO_PIN_27)
#define GPIO_KEY_PIN_KEY2_IOMUX                                  (IOMUX_PINCM58)

/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_PWM_A0_init(void);
void SYSCFG_DL_TIMER_G0_init(void);
void SYSCFG_DL_TIMER_G6_init(void);
void SYSCFG_DL_UART_0_init(void);
void SYSCFG_DL_UART_1_init(void);
void SYSCFG_DL_UART_2_init(void);


bool SYSCFG_DL_saveConfiguration(void);
bool SYSCFG_DL_restoreConfiguration(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */
