/*
 * Copyright (c) 2023, Texas Instruments Incorporated
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
 *  ============ ti_msp_dl_config.c =============
 *  Configured MSPM0 DriverLib module definitions
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */

#include "ti_msp_dl_config.h"

DL_TimerA_backupConfig gPWM_A0Backup;
DL_TimerG_backupConfig gTIMER_G6Backup;

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform any initialization needed before using any board APIs
 */
SYSCONFIG_WEAK void SYSCFG_DL_init(void)
{
    SYSCFG_DL_initPower();
    SYSCFG_DL_GPIO_init();
    /* Module-Specific Initializations*/
    SYSCFG_DL_SYSCTL_init();
    SYSCFG_DL_PWM_A0_init();
    SYSCFG_DL_TIMER_G0_init();
    SYSCFG_DL_TIMER_G6_init();
    SYSCFG_DL_UART_0_init();
    SYSCFG_DL_UART_1_init();
    SYSCFG_DL_UART_2_init();
    /* Ensure backup structures have no valid state */
	gPWM_A0Backup.backupRdy 	= false;
	gTIMER_G6Backup.backupRdy 	= false;


}
/*
 * User should take care to save and restore register configuration in application.
 * See Retention Configuration section for more details.
 */
SYSCONFIG_WEAK bool SYSCFG_DL_saveConfiguration(void)
{
    bool retStatus = true;

	retStatus &= DL_TimerA_saveConfiguration(PWM_A0_INST, &gPWM_A0Backup);
	retStatus &= DL_TimerG_saveConfiguration(TIMER_G6_INST, &gTIMER_G6Backup);

    return retStatus;
}


SYSCONFIG_WEAK bool SYSCFG_DL_restoreConfiguration(void)
{
    bool retStatus = true;

	retStatus &= DL_TimerA_restoreConfiguration(PWM_A0_INST, &gPWM_A0Backup, false);
	retStatus &= DL_TimerG_restoreConfiguration(TIMER_G6_INST, &gTIMER_G6Backup, false);

    return retStatus;
}

SYSCONFIG_WEAK void SYSCFG_DL_initPower(void)
{
    DL_GPIO_reset(GPIOA);
    DL_GPIO_reset(GPIOB);
    DL_TimerA_reset(PWM_A0_INST);
    DL_TimerG_reset(TIMER_G0_INST);
    DL_TimerG_reset(TIMER_G6_INST);
    DL_UART_Main_reset(UART_0_INST);
    DL_UART_Main_reset(UART_1_INST);
    DL_UART_Main_reset(UART_2_INST);

    DL_GPIO_enablePower(GPIOA);
    DL_GPIO_enablePower(GPIOB);
    DL_TimerA_enablePower(PWM_A0_INST);
    DL_TimerG_enablePower(TIMER_G0_INST);
    DL_TimerG_enablePower(TIMER_G6_INST);
    DL_UART_Main_enablePower(UART_0_INST);
    DL_UART_Main_enablePower(UART_1_INST);
    DL_UART_Main_enablePower(UART_2_INST);
    delay_cycles(POWER_STARTUP_DELAY);
}

SYSCONFIG_WEAK void SYSCFG_DL_GPIO_init(void)
{

    DL_GPIO_initPeripheralOutputFunction(GPIO_PWM_A0_C0_IOMUX,GPIO_PWM_A0_C0_IOMUX_FUNC);
    DL_GPIO_enableOutput(GPIO_PWM_A0_C0_PORT, GPIO_PWM_A0_C0_PIN);
    DL_GPIO_initPeripheralOutputFunction(GPIO_PWM_A0_C1_IOMUX,GPIO_PWM_A0_C1_IOMUX_FUNC);
    DL_GPIO_enableOutput(GPIO_PWM_A0_C1_PORT, GPIO_PWM_A0_C1_PIN);
    DL_GPIO_initPeripheralOutputFunction(GPIO_PWM_A0_C2_IOMUX,GPIO_PWM_A0_C2_IOMUX_FUNC);
    DL_GPIO_enableOutput(GPIO_PWM_A0_C2_PORT, GPIO_PWM_A0_C2_PIN);
    DL_GPIO_initPeripheralOutputFunction(GPIO_PWM_A0_C3_IOMUX,GPIO_PWM_A0_C3_IOMUX_FUNC);
    DL_GPIO_enableOutput(GPIO_PWM_A0_C3_PORT, GPIO_PWM_A0_C3_PIN);

    DL_GPIO_initPeripheralOutputFunction(
        GPIO_UART_0_IOMUX_TX, GPIO_UART_0_IOMUX_TX_FUNC);
    DL_GPIO_initPeripheralInputFunction(
        GPIO_UART_0_IOMUX_RX, GPIO_UART_0_IOMUX_RX_FUNC);
    DL_GPIO_initPeripheralOutputFunction(
        GPIO_UART_1_IOMUX_TX, GPIO_UART_1_IOMUX_TX_FUNC);
    DL_GPIO_initPeripheralInputFunction(
        GPIO_UART_1_IOMUX_RX, GPIO_UART_1_IOMUX_RX_FUNC);
    DL_GPIO_initPeripheralOutputFunction(
        GPIO_UART_2_IOMUX_TX, GPIO_UART_2_IOMUX_TX_FUNC);
    DL_GPIO_initPeripheralInputFunction(
        GPIO_UART_2_IOMUX_RX, GPIO_UART_2_IOMUX_RX_FUNC);

    DL_GPIO_initDigitalOutput(GPIO_LED_PIN_LED_IOMUX);

    DL_GPIO_initDigitalOutput(GPIO_BUZZER_PIN_buzzer_IOMUX);

    DL_GPIO_initDigitalOutput(GPIO_MOTOR_PIN_motor1_IOMUX);

    DL_GPIO_initDigitalOutput(GPIO_MOTOR_PIN_motor2_IOMUX);

    DL_GPIO_initDigitalOutput(GPIO_MOTOR_PIN_motor3_IOMUX);

    DL_GPIO_initDigitalOutput(GPIO_MOTOR_PIN_motor4_IOMUX);

    DL_GPIO_initDigitalOutput(GPIO_MOTOR_PIN_motor5_IOMUX);

    DL_GPIO_initDigitalOutput(GPIO_MOTOR_PIN_motor6_IOMUX);

    DL_GPIO_initDigitalOutput(GPIO_MOTOR_PIN_motor7_IOMUX);

    DL_GPIO_initDigitalOutput(GPIO_MOTOR_PIN_motor8_IOMUX);

    DL_GPIO_initDigitalOutput(GPIO_OLED_PIN_SCL_IOMUX);

    DL_GPIO_initDigitalOutput(GPIO_OLED_PIN_SDA_IOMUX);

    DL_GPIO_initDigitalInput(GPIO_ENCONDER_PIN_ECO1A_IOMUX);

    DL_GPIO_initDigitalInput(GPIO_ENCONDER_PIN_ECO1B_IOMUX);

    DL_GPIO_initDigitalInput(GPIO_ENCONDER_PIN_ECO2A_IOMUX);

    DL_GPIO_initDigitalInput(GPIO_ENCONDER_PIN_ECO2B_IOMUX);

    DL_GPIO_initDigitalInput(GPIO_huidu_PIN_grey1_IOMUX);

    DL_GPIO_initDigitalInput(GPIO_huidu_PIN_grey2_IOMUX);

    DL_GPIO_initDigitalInput(GPIO_huidu_PIN_grey3_IOMUX);

    DL_GPIO_initDigitalInput(GPIO_huidu_PIN_grey4_IOMUX);

    DL_GPIO_initDigitalInput(GPIO_huidu_PIN_grey5_IOMUX);

    DL_GPIO_initDigitalInput(GPIO_huidu_PIN_grey6_IOMUX);

    DL_GPIO_initDigitalInput(GPIO_huidu_PIN_grey7_IOMUX);

    DL_GPIO_initDigitalInput(GPIO_huidu_PIN_grey8_IOMUX);

    DL_GPIO_initDigitalInputFeatures(GPIO_KEY_PIN_KEY1_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(GPIO_KEY_PIN_KEY2_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_clearPins(GPIOA, GPIO_MOTOR_PIN_motor1_PIN |
		GPIO_MOTOR_PIN_motor2_PIN |
		GPIO_MOTOR_PIN_motor3_PIN |
		GPIO_MOTOR_PIN_motor4_PIN |
		GPIO_MOTOR_PIN_motor5_PIN |
		GPIO_MOTOR_PIN_motor6_PIN |
		GPIO_MOTOR_PIN_motor7_PIN |
		GPIO_MOTOR_PIN_motor8_PIN |
		GPIO_OLED_PIN_SCL_PIN |
		GPIO_OLED_PIN_SDA_PIN);
    DL_GPIO_enableOutput(GPIOA, GPIO_MOTOR_PIN_motor1_PIN |
		GPIO_MOTOR_PIN_motor2_PIN |
		GPIO_MOTOR_PIN_motor3_PIN |
		GPIO_MOTOR_PIN_motor4_PIN |
		GPIO_MOTOR_PIN_motor5_PIN |
		GPIO_MOTOR_PIN_motor6_PIN |
		GPIO_MOTOR_PIN_motor7_PIN |
		GPIO_MOTOR_PIN_motor8_PIN |
		GPIO_OLED_PIN_SCL_PIN |
		GPIO_OLED_PIN_SDA_PIN);
    DL_GPIO_clearPins(GPIOB, GPIO_LED_PIN_LED_PIN |
		GPIO_BUZZER_PIN_buzzer_PIN);
    DL_GPIO_enableOutput(GPIOB, GPIO_LED_PIN_LED_PIN |
		GPIO_BUZZER_PIN_buzzer_PIN);
    DL_GPIO_setLowerPinsPolarity(GPIOB, DL_GPIO_PIN_10_EDGE_RISE);
    DL_GPIO_setUpperPinsPolarity(GPIOB, DL_GPIO_PIN_19_EDGE_RISE);
    DL_GPIO_clearInterruptStatus(GPIOB, GPIO_ENCONDER_PIN_ECO1A_PIN |
		GPIO_ENCONDER_PIN_ECO2A_PIN);
    DL_GPIO_enableInterrupt(GPIOB, GPIO_ENCONDER_PIN_ECO1A_PIN |
		GPIO_ENCONDER_PIN_ECO2A_PIN);

}


static const DL_SYSCTL_SYSPLLConfig gSYSPLLConfig = {
    .inputFreq              = DL_SYSCTL_SYSPLL_INPUT_FREQ_16_32_MHZ,
	.rDivClk2x              = 3,
	.rDivClk1               = 0,
	.rDivClk0               = 0,
	.enableCLK2x            = DL_SYSCTL_SYSPLL_CLK2X_ENABLE,
	.enableCLK1             = DL_SYSCTL_SYSPLL_CLK1_DISABLE,
	.enableCLK0             = DL_SYSCTL_SYSPLL_CLK0_DISABLE,
	.sysPLLMCLK             = DL_SYSCTL_SYSPLL_MCLK_CLK2X,
	.sysPLLRef              = DL_SYSCTL_SYSPLL_REF_SYSOSC,
	.qDiv                   = 9,
	.pDiv                   = DL_SYSCTL_SYSPLL_PDIV_2
};
SYSCONFIG_WEAK void SYSCFG_DL_SYSCTL_init(void)
{

	//Low Power Mode is configured to be SLEEP0
    DL_SYSCTL_setBORThreshold(DL_SYSCTL_BOR_THRESHOLD_LEVEL_0);
    DL_SYSCTL_setFlashWaitState(DL_SYSCTL_FLASH_WAIT_STATE_2);

    
	DL_SYSCTL_setSYSOSCFreq(DL_SYSCTL_SYSOSC_FREQ_BASE);
	/* Set default configuration */
	DL_SYSCTL_disableHFXT();
	DL_SYSCTL_disableSYSPLL();
    DL_SYSCTL_configSYSPLL((DL_SYSCTL_SYSPLLConfig *) &gSYSPLLConfig);
    DL_SYSCTL_setULPCLKDivider(DL_SYSCTL_ULPCLK_DIV_2);
    DL_SYSCTL_setMCLKSource(SYSOSC, HSCLK, DL_SYSCTL_HSCLK_SOURCE_SYSPLL);

}


/*
 * Timer clock configuration to be sourced by  / 8 (10000000 Hz)
 * timerClkFreq = (timerClkSrc / (timerClkDivRatio * (timerClkPrescale + 1)))
 *   100000 Hz = 10000000 Hz / (8 * (99 + 1))
 */
static const DL_TimerA_ClockConfig gPWM_A0ClockConfig = {
    .clockSel = DL_TIMER_CLOCK_BUSCLK,
    .divideRatio = DL_TIMER_CLOCK_DIVIDE_8,
    .prescale = 99U
};

static const DL_TimerA_PWMConfig gPWM_A0Config = {
    .pwmMode = DL_TIMER_PWM_MODE_EDGE_ALIGN,
    .period = 100,
    .isTimerWithFourCC = true,
    .startTimer = DL_TIMER_STOP,
};

SYSCONFIG_WEAK void SYSCFG_DL_PWM_A0_init(void) {

    DL_TimerA_setClockConfig(
        PWM_A0_INST, (DL_TimerA_ClockConfig *) &gPWM_A0ClockConfig);

    DL_TimerA_initPWMMode(
        PWM_A0_INST, (DL_TimerA_PWMConfig *) &gPWM_A0Config);

    DL_TimerA_setCaptureCompareOutCtl(PWM_A0_INST, DL_TIMER_CC_OCTL_INIT_VAL_LOW,
		DL_TIMER_CC_OCTL_INV_OUT_DISABLED, DL_TIMER_CC_OCTL_SRC_FUNCVAL,
		DL_TIMERA_CAPTURE_COMPARE_0_INDEX);

    DL_TimerA_setCaptCompUpdateMethod(PWM_A0_INST, DL_TIMER_CC_UPDATE_METHOD_IMMEDIATE, DL_TIMERA_CAPTURE_COMPARE_0_INDEX);
    DL_TimerA_setCaptureCompareValue(PWM_A0_INST, 50, DL_TIMER_CC_0_INDEX);

    DL_TimerA_setCaptureCompareOutCtl(PWM_A0_INST, DL_TIMER_CC_OCTL_INIT_VAL_LOW,
		DL_TIMER_CC_OCTL_INV_OUT_DISABLED, DL_TIMER_CC_OCTL_SRC_FUNCVAL,
		DL_TIMERA_CAPTURE_COMPARE_1_INDEX);

    DL_TimerA_setCaptCompUpdateMethod(PWM_A0_INST, DL_TIMER_CC_UPDATE_METHOD_IMMEDIATE, DL_TIMERA_CAPTURE_COMPARE_1_INDEX);
    DL_TimerA_setCaptureCompareValue(PWM_A0_INST, 50, DL_TIMER_CC_1_INDEX);

    DL_TimerA_setCaptureCompareOutCtl(PWM_A0_INST, DL_TIMER_CC_OCTL_INIT_VAL_LOW,
		DL_TIMER_CC_OCTL_INV_OUT_DISABLED, DL_TIMER_CC_OCTL_SRC_FUNCVAL,
		DL_TIMERA_CAPTURE_COMPARE_2_INDEX);

    DL_TimerA_setCaptCompUpdateMethod(PWM_A0_INST, DL_TIMER_CC_UPDATE_METHOD_IMMEDIATE, DL_TIMERA_CAPTURE_COMPARE_2_INDEX);
    DL_TimerA_setCaptureCompareValue(PWM_A0_INST, 50, DL_TIMER_CC_2_INDEX);

    DL_TimerA_setCaptureCompareOutCtl(PWM_A0_INST, DL_TIMER_CC_OCTL_INIT_VAL_LOW,
		DL_TIMER_CC_OCTL_INV_OUT_DISABLED, DL_TIMER_CC_OCTL_SRC_FUNCVAL,
		DL_TIMERA_CAPTURE_COMPARE_3_INDEX);

    DL_TimerA_setCaptCompUpdateMethod(PWM_A0_INST, DL_TIMER_CC_UPDATE_METHOD_IMMEDIATE, DL_TIMERA_CAPTURE_COMPARE_3_INDEX);
    DL_TimerA_setCaptureCompareValue(PWM_A0_INST, 50, DL_TIMER_CC_3_INDEX);

    DL_TimerA_enableClock(PWM_A0_INST);


    
    DL_TimerA_setCCPDirection(PWM_A0_INST , DL_TIMER_CC0_OUTPUT | DL_TIMER_CC1_OUTPUT | DL_TIMER_CC2_OUTPUT | DL_TIMER_CC3_OUTPUT );


}



/*
 * Timer clock configuration to be sourced by BUSCLK /  (40000000 Hz)
 * timerClkFreq = (timerClkSrc / (timerClkDivRatio * (timerClkPrescale + 1)))
 *   400000 Hz = 40000000 Hz / (1 * (99 + 1))
 */
static const DL_TimerG_ClockConfig gTIMER_G0ClockConfig = {
    .clockSel    = DL_TIMER_CLOCK_BUSCLK,
    .divideRatio = DL_TIMER_CLOCK_DIVIDE_1,
    .prescale    = 99U,
};

/*
 * Timer load value (where the counter starts from) is calculated as (timerPeriod * timerClockFreq) - 1
 * TIMER_G0_INST_LOAD_VALUE = (5ms * 400000 Hz) - 1
 */
static const DL_TimerG_TimerConfig gTIMER_G0TimerConfig = {
    .period     = TIMER_G0_INST_LOAD_VALUE,
    .timerMode  = DL_TIMER_TIMER_MODE_PERIODIC,
    .startTimer = DL_TIMER_START,
};

SYSCONFIG_WEAK void SYSCFG_DL_TIMER_G0_init(void) {

    DL_TimerG_setClockConfig(TIMER_G0_INST,
        (DL_TimerG_ClockConfig *) &gTIMER_G0ClockConfig);

    DL_TimerG_initTimerMode(TIMER_G0_INST,
        (DL_TimerG_TimerConfig *) &gTIMER_G0TimerConfig);
    DL_TimerG_enableInterrupt(TIMER_G0_INST , DL_TIMERG_INTERRUPT_ZERO_EVENT);
    DL_TimerG_enableClock(TIMER_G0_INST);





}

/*
 * Timer clock configuration to be sourced by BUSCLK /  (80000000 Hz)
 * timerClkFreq = (timerClkSrc / (timerClkDivRatio * (timerClkPrescale + 1)))
 *   400000 Hz = 80000000 Hz / (1 * (199 + 1))
 */
static const DL_TimerG_ClockConfig gTIMER_G6ClockConfig = {
    .clockSel    = DL_TIMER_CLOCK_BUSCLK,
    .divideRatio = DL_TIMER_CLOCK_DIVIDE_1,
    .prescale    = 199U,
};

/*
 * Timer load value (where the counter starts from) is calculated as (timerPeriod * timerClockFreq) - 1
 * TIMER_G6_INST_LOAD_VALUE = (10ms * 400000 Hz) - 1
 */
static const DL_TimerG_TimerConfig gTIMER_G6TimerConfig = {
    .period     = TIMER_G6_INST_LOAD_VALUE,
    .timerMode  = DL_TIMER_TIMER_MODE_PERIODIC,
    .startTimer = DL_TIMER_STOP,
};

SYSCONFIG_WEAK void SYSCFG_DL_TIMER_G6_init(void) {

    DL_TimerG_setClockConfig(TIMER_G6_INST,
        (DL_TimerG_ClockConfig *) &gTIMER_G6ClockConfig);

    DL_TimerG_initTimerMode(TIMER_G6_INST,
        (DL_TimerG_TimerConfig *) &gTIMER_G6TimerConfig);
    DL_TimerG_enableInterrupt(TIMER_G6_INST , DL_TIMERG_INTERRUPT_ZERO_EVENT);
    DL_TimerG_enableClock(TIMER_G6_INST);





}



static const DL_UART_Main_ClockConfig gUART_0ClockConfig = {
    .clockSel    = DL_UART_MAIN_CLOCK_BUSCLK,
    .divideRatio = DL_UART_MAIN_CLOCK_DIVIDE_RATIO_1
};

static const DL_UART_Main_Config gUART_0Config = {
    .mode        = DL_UART_MAIN_MODE_NORMAL,
    .direction   = DL_UART_MAIN_DIRECTION_TX_RX,
    .flowControl = DL_UART_MAIN_FLOW_CONTROL_NONE,
    .parity      = DL_UART_MAIN_PARITY_NONE,
    .wordLength  = DL_UART_MAIN_WORD_LENGTH_8_BITS,
    .stopBits    = DL_UART_MAIN_STOP_BITS_ONE
};

SYSCONFIG_WEAK void SYSCFG_DL_UART_0_init(void)
{
    DL_UART_Main_setClockConfig(UART_0_INST, (DL_UART_Main_ClockConfig *) &gUART_0ClockConfig);

    DL_UART_Main_init(UART_0_INST, (DL_UART_Main_Config *) &gUART_0Config);
    /*
     * Configure baud rate by setting oversampling and baud rate divisors.
     *  Target baud rate: 115200
     *  Actual baud rate: 115190.78
     */
    DL_UART_Main_setOversampling(UART_0_INST, DL_UART_OVERSAMPLING_RATE_16X);
    DL_UART_Main_setBaudRateDivisor(UART_0_INST, UART_0_IBRD_40_MHZ_115200_BAUD, UART_0_FBRD_40_MHZ_115200_BAUD);


    /* Configure Interrupts */
    DL_UART_Main_enableInterrupt(UART_0_INST,
                                 DL_UART_MAIN_INTERRUPT_RX);


    DL_UART_Main_enable(UART_0_INST);
}

static const DL_UART_Main_ClockConfig gUART_1ClockConfig = {
    .clockSel    = DL_UART_MAIN_CLOCK_BUSCLK,
    .divideRatio = DL_UART_MAIN_CLOCK_DIVIDE_RATIO_1
};

static const DL_UART_Main_Config gUART_1Config = {
    .mode        = DL_UART_MAIN_MODE_NORMAL,
    .direction   = DL_UART_MAIN_DIRECTION_TX_RX,
    .flowControl = DL_UART_MAIN_FLOW_CONTROL_NONE,
    .parity      = DL_UART_MAIN_PARITY_NONE,
    .wordLength  = DL_UART_MAIN_WORD_LENGTH_8_BITS,
    .stopBits    = DL_UART_MAIN_STOP_BITS_ONE
};

SYSCONFIG_WEAK void SYSCFG_DL_UART_1_init(void)
{
    DL_UART_Main_setClockConfig(UART_1_INST, (DL_UART_Main_ClockConfig *) &gUART_1ClockConfig);

    DL_UART_Main_init(UART_1_INST, (DL_UART_Main_Config *) &gUART_1Config);
    /*
     * Configure baud rate by setting oversampling and baud rate divisors.
     *  Target baud rate: 9600
     *  Actual baud rate: 9599.81
     */
    DL_UART_Main_setOversampling(UART_1_INST, DL_UART_OVERSAMPLING_RATE_16X);
    DL_UART_Main_setBaudRateDivisor(UART_1_INST, UART_1_IBRD_40_MHZ_9600_BAUD, UART_1_FBRD_40_MHZ_9600_BAUD);


    /* Configure Interrupts */
    DL_UART_Main_enableInterrupt(UART_1_INST,
                                 DL_UART_MAIN_INTERRUPT_RX);


    DL_UART_Main_enable(UART_1_INST);
}

static const DL_UART_Main_ClockConfig gUART_2ClockConfig = {
    .clockSel    = DL_UART_MAIN_CLOCK_BUSCLK,
    .divideRatio = DL_UART_MAIN_CLOCK_DIVIDE_RATIO_1
};

static const DL_UART_Main_Config gUART_2Config = {
    .mode        = DL_UART_MAIN_MODE_NORMAL,
    .direction   = DL_UART_MAIN_DIRECTION_TX_RX,
    .flowControl = DL_UART_MAIN_FLOW_CONTROL_NONE,
    .parity      = DL_UART_MAIN_PARITY_NONE,
    .wordLength  = DL_UART_MAIN_WORD_LENGTH_8_BITS,
    .stopBits    = DL_UART_MAIN_STOP_BITS_ONE
};

SYSCONFIG_WEAK void SYSCFG_DL_UART_2_init(void)
{
    DL_UART_Main_setClockConfig(UART_2_INST, (DL_UART_Main_ClockConfig *) &gUART_2ClockConfig);

    DL_UART_Main_init(UART_2_INST, (DL_UART_Main_Config *) &gUART_2Config);
    /*
     * Configure baud rate by setting oversampling and baud rate divisors.
     *  Target baud rate: 115200
     *  Actual baud rate: 115190.78
     */
    DL_UART_Main_setOversampling(UART_2_INST, DL_UART_OVERSAMPLING_RATE_16X);
    DL_UART_Main_setBaudRateDivisor(UART_2_INST, UART_2_IBRD_40_MHZ_115200_BAUD, UART_2_FBRD_40_MHZ_115200_BAUD);


    /* Configure Interrupts */
    DL_UART_Main_enableInterrupt(UART_2_INST,
                                 DL_UART_MAIN_INTERRUPT_RX);


    DL_UART_Main_enable(UART_2_INST);
}

