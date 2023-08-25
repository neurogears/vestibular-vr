#include "hwbp_core.h"
#include "hwbp_core_regs.h"
#include "hwbp_core_types.h"

#include "app.h"
#include "app_funcs.h"
#include "app_ios_and_regs.h"

#define F_CPU 32000000
#include <util/delay.h>

#include "AD5048A.h"
#include "PAA5100JE.h"

/************************************************************************/
/* Declare application registers                                        */
/************************************************************************/
extern AppRegs app_regs;
extern uint8_t app_regs_type[];
extern uint16_t app_regs_n_elements[];
extern uint8_t *app_regs_pointer[];
extern void (*app_func_rd_pointer[])(void);
extern bool (*app_func_wr_pointer[])(void*);

/************************************************************************/
/* Initialize app                                                       */
/************************************************************************/
static const uint8_t default_device_name[] = "OutputExpander";

void hwbp_app_initialize(void)
{
    /* Define versions */
    uint8_t hwH = 1;
    uint8_t hwL = 0;
    uint8_t fwH = 2;
    uint8_t fwL = 2;
    uint8_t ass = 0;
    
   	/* Start core */
    core_func_start_core(
        1108,
        hwH, hwL,
        fwH, fwL,
        ass,
        (uint8_t*)(&app_regs),
        APP_NBYTES_OF_REG_BANK,
        APP_REGS_ADD_MAX - APP_REGS_ADD_MIN + 1,
        default_device_name
    );
}

/************************************************************************/
/* Handle if a catastrophic error occur                                 */
/************************************************************************/
void core_callback_catastrophic_error_detected(void)
{
	clr_LED_0; clr_LED_1; clr_LED_2; clr_LED_3; clr_LED_4;
	clr_LED_5; clr_LED_6; clr_LED_7; clr_LED_8; clr_LED_9;
	
	clr_OUT0; clr_OUT1; clr_OUT2; clr_OUT3; clr_OUT4;
	clr_OUT5; clr_OUT6; clr_OUT7; clr_OUT8; clr_OUT9;	
}

/************************************************************************/
/* User functions                                                       */
/************************************************************************/
/* Add your functions here or load external functions if needed */

/************************************************************************/
/* Initialization Callbacks                                             */
/************************************************************************/
#define T_STARTUP_ON  50
#define T_STARTUP_OFF 0

extern void update_reals_pwm0(void);
extern void update_reals_pwm1(void);
extern void update_reals_pwm2(void);

void core_callback_1st_config_hw_after_boot(void)
{
	/* Initialize IOs */
	/* Don't delete this function!!! */
	init_ios();
	
	/* Check if device is an harp output expander hardware */
	if (!read_IS_OUTPUT)
		core_func_catastrophic_error_detected();
	
	/* Initialize hardware */
	for (uint8_t i = 0; i < 2; i++)
	{
		set_LED_0;  _delay_ms(T_STARTUP_ON); clr_LED_0;  _delay_ms(T_STARTUP_OFF);
		set_LED_1;  _delay_ms(T_STARTUP_ON); clr_LED_1;  _delay_ms(T_STARTUP_OFF);
		set_LED_2;  _delay_ms(T_STARTUP_ON); clr_LED_2;  _delay_ms(T_STARTUP_OFF);
		set_LED_3;  _delay_ms(T_STARTUP_ON); clr_LED_3;  _delay_ms(T_STARTUP_OFF);
		set_LED_4;  _delay_ms(T_STARTUP_ON); clr_LED_4;  _delay_ms(T_STARTUP_OFF);
		set_LED_PWR;  _delay_ms(T_STARTUP_ON); clr_LED_PWR;  _delay_ms(T_STARTUP_OFF);
		set_LED_5;  _delay_ms(T_STARTUP_ON); clr_LED_5;  _delay_ms(T_STARTUP_OFF);
		set_LED_6;  _delay_ms(T_STARTUP_ON); clr_LED_6;  _delay_ms(T_STARTUP_OFF);
		set_LED_7;  _delay_ms(T_STARTUP_ON); clr_LED_7;  _delay_ms(T_STARTUP_OFF);
		set_LED_8;  _delay_ms(T_STARTUP_ON); clr_LED_8;  _delay_ms(T_STARTUP_OFF);
		set_LED_9;  _delay_ms(T_STARTUP_ON); clr_LED_9;  _delay_ms(T_STARTUP_OFF);
		set_LED_STATE;  _delay_ms(T_STARTUP_ON); clr_LED_STATE;  _delay_ms(T_STARTUP_OFF);
	}
	_delay_ms(T_STARTUP_ON*2);

	for (uint8_t i = 0; i < 2; i++)
	{
		set_LED_0; set_LED_1; set_LED_2; set_LED_3; set_LED_4; set_LED_PWR;
		set_LED_5; set_LED_6; set_LED_7; set_LED_8; set_LED_9; set_LED_STATE;
		_delay_ms(T_STARTUP_ON*2);
			
		clr_LED_0; clr_LED_1; clr_LED_2; clr_LED_3; clr_LED_4; clr_LED_PWR;
		clr_LED_5; clr_LED_6; clr_LED_7; clr_LED_8; clr_LED_9; clr_LED_STATE;
		_delay_ms(T_STARTUP_ON*2);
	}
		
	_delay_ms(500);
	set_LED_PWR;
	
	/* Initialize the optical tracking device */
	/* This functions still needs to be divided into a state machine */
	optical_tracking_initialize();
}

void core_callback_reset_registers(void)
{
	/* Initialize registers */	
	app_regs.REG_AUX_INPUTS_RISING_EDGE_ENABLE = B_AUX_IN0 | B_AUX_IN1;
	app_regs.REG_AUX_INPUTS_FALLING_EDGE_ENABLE = B_AUX_IN0 | B_AUX_IN1;
	
	app_regs.REG_PWM0_FREQ = 10;
	app_regs.REG_PWM0_DUTYCYCLE = 50;
	app_regs.REG_PWM0_COUNT = 10;
	app_regs.REG_PWM0_MODE = MSK_STIM_MODE_COUNT;
	app_regs.REG_PWM0_CONF_EVENT = MSK_PWM_RISE_EVENT_DIS;
	app_regs.REG_PWM0_TRIG = MSK_STIM_TRIG_SW;
	
	app_regs.REG_PWM1_FREQ = 10;
	app_regs.REG_PWM1_DUTYCYCLE = 50;
	app_regs.REG_PWM1_COUNT = 10;
	app_regs.REG_PWM1_MODE = MSK_STIM_MODE_COUNT;
	app_regs.REG_PWM1_CONF_EVENT = MSK_PWM_RISE_EVENT_DIS;
	app_regs.REG_PWM1_TRIG = MSK_STIM_TRIG_SW;
	
	app_regs.REG_PWM2_FREQ = 10;
	app_regs.REG_PWM2_DUTYCYCLE = 50;
	app_regs.REG_PWM2_COUNT = 10;
	app_regs.REG_PWM2_MODE = MSK_STIM_MODE_COUNT;
	app_regs.REG_PWM2_CONF_EVENT = MSK_PWM_RISE_EVENT_DIS;
	app_regs.REG_PWM2_TRIG = MSK_STIM_TRIG_SW;

	app_regs.REG_SERVO_PERIOD_US = 20000;	// 20 ms
	app_regs.REG_SERVO0_PULSE_US = 1500;	// 1.5 ms
	app_regs.REG_SERVO1_PULSE_US = 1500;	// 1.5 ms
	app_regs.REG_SERVO2_PULSE_US = 1500;	// 1.5 ms
	
	app_regs.REG_MAG_ENCODER_MODE = MSK_AT_100SPS;
}

void core_callback_registers_were_reinitialized(void)
{
	/* Update registers if needed */
	app_write_REG_OUTPUTS_WRITE(&app_regs.REG_OUTPUTS_WRITE);	

	update_reals_pwm0();
	update_reals_pwm1();
	update_reals_pwm2();
	
	app_write_REG_EXPANSION_OPTIONS(&app_regs.REG_EXPANSION_OPTIONS);
	
	app_write_REG_MAG_ENCODER_MODE(&app_regs.REG_MAG_ENCODER_MODE);
	
	app_write_REG_SERVO_PERIOD_US(&app_regs.REG_SERVO_PERIOD_US);
	app_write_REG_SERVO0_PULSE_US(&app_regs.REG_SERVO0_PULSE_US);
	app_write_REG_SERVO1_PULSE_US(&app_regs.REG_SERVO1_PULSE_US);
	app_write_REG_SERVO2_PULSE_US(&app_regs.REG_SERVO2_PULSE_US);
}

/************************************************************************/
/* Callbacks: Visualization                                             */
/************************************************************************/
void core_callback_visualen_to_on(void)
{
	/* Update visual indicators */
	 switch (app_regs.REG_EXPANSION_OPTIONS)
	 {
		 case MSK_BREAKOUT:
			if (read_OUT0) set_LED_0;
			if (read_OUT1) set_LED_1;
			if (read_OUT2) set_LED_2;
			if (read_OUT3) set_LED_3;
			if (read_OUT4) set_LED_4;
			if (read_OUT5) set_LED_5;
			if (read_OUT6) set_LED_6;
			if (read_OUT7) set_LED_7;
			if (read_OUT8) set_LED_8;
			if (read_OUT9) set_LED_9;
			break;
			
		case MSK_MAGNETIC_ENCODER:
			if (read_OUT0) set_LED_0;
			if (read_OUT1) set_LED_1;
			if (read_OUT2) set_LED_2;
			if (read_OUT3) set_LED_3;
			if (read_OUT4) set_LED_4;
			               set_LED_5;
			               set_LED_6;
			if (read_OUT7) set_LED_7;
			if (read_OUT8) set_LED_8;
			               set_LED_9;
			break;
			
		case MSK_SERVO_MOTOR_1:
			if (read_OUT0) set_LED_0;
			if (read_OUT1) set_LED_1;
			if (read_OUT2) set_LED_2;
			if (read_OUT3) set_LED_3;
			if (read_OUT4) set_LED_4;
			               set_LED_5;
			if (read_OUT6) set_LED_6;
			if (read_OUT7) set_LED_7;
			if (read_OUT8) set_LED_8;
			if (read_OUT9) set_LED_9;
			set_LED_9;
			break;
			
		case MSK_SERVO_MOTOR_2:
			if (read_OUT0) set_LED_0;
			if (read_OUT1) set_LED_1;
			if (read_OUT2) set_LED_2;
			if (read_OUT3) set_LED_3;
			if (read_OUT4) set_LED_4;
			               set_LED_5;
			               set_LED_6;
			if (read_OUT7) set_LED_7;
			if (read_OUT8) set_LED_8;
			if (read_OUT9) set_LED_9;
			set_LED_9;
			break;
			
		case MSK_SERVO_MOTOR_3:
			if (read_OUT0) set_LED_0;
			if (read_OUT1) set_LED_1;
			if (read_OUT2) set_LED_2;
			if (read_OUT3) set_LED_3;
			if (read_OUT4) set_LED_4;
			               set_LED_5;
			               set_LED_6;
			               set_LED_7;
			if (read_OUT8) set_LED_8;
			if (read_OUT9) set_LED_9;
			set_LED_9;
			break;
			
		case MSK_OPTICAL_TRACKING:
			if (read_OUT0) set_LED_0;
			if (read_OUT1) set_LED_1;
			if (read_OUT2) set_LED_2;
			if (read_OUT3) set_LED_3;
			if (read_OUT4) set_LED_4;
			               set_LED_5;
			               set_LED_6;
			if (read_OUT7) set_LED_7;
			if (read_OUT8) set_LED_8;
			               set_LED_9;
			set_LED_9;
			break;
	 }
	 
	 set_LED_PWR;
}

void core_callback_visualen_to_off(void)
{
	/* Clear all the enabled indicators */
	clr_LED_0; clr_LED_1; clr_LED_2; clr_LED_3; clr_LED_4;
	clr_LED_5; clr_LED_6; clr_LED_7; clr_LED_8; clr_LED_9;
	clr_LED_PWR;
}

/************************************************************************/
/* Callbacks: Change on the operation mode                              */
/************************************************************************/
extern uint16_t pwm_and_stim_enabled;

void core_callback_device_to_standby(void)
{
	if (pwm_and_stim_enabled & B_PWM0_EN_OUT1) { timer_type0_stop(&TCD0); clr_OUT1; clr_LED_1; }
	if (pwm_and_stim_enabled & B_PWM0_EN_OUT2) { timer_type0_stop(&TCD0); clr_OUT2; clr_LED_2; }
	if (pwm_and_stim_enabled & B_PWM0_EN_OUT3) { timer_type0_stop(&TCD0); clr_OUT3; clr_LED_3; }	
	if (pwm_and_stim_enabled & B_PWM1_EN_OUT6) { timer_type0_stop(&TCC0); clr_OUT6; clr_LED_6; }
	if (pwm_and_stim_enabled & B_PWM1_EN_OUT7) { timer_type0_stop(&TCC0); clr_OUT7; clr_LED_7; }
	if (pwm_and_stim_enabled & B_PWM1_EN_OUT8) { timer_type0_stop(&TCC0); clr_OUT8; clr_LED_8; }	
	if (pwm_and_stim_enabled & B_PWM2_EN_OUT9) { timer_type0_stop(&TCE0); clr_OUT9; clr_LED_9; }
	
}
void core_callback_device_to_active(void) {}
void core_callback_device_to_enchanced_active(void) {}
void core_callback_device_to_speed(void) {}

/************************************************************************/
/* Callbacks: 1 ms timer                                                */
/************************************************************************/
uint8_t magnetic_counter = 0;
uint8_t magnetic_counter_divider;
uint8_t optical_counter = 0;
uint8_t optical_counter_divider = 10;

Motion optical_motion;

void core_callback_t_before_exec(void) {}
void core_callback_t_after_exec(void) {}
void core_callback_t_new_second(void)
{
	magnetic_counter = magnetic_counter_divider-1;
	optical_counter = optical_counter_divider-1;
}
void core_callback_t_500us(void) {}
void core_callback_t_1ms(void)
{
	if (app_regs.REG_EXPANSION_OPTIONS == MSK_MAGNETIC_ENCODER)
	{
		if (++magnetic_counter == magnetic_counter_divider)
		{
			read_magnetic_encoder();
			core_func_send_event(ADD_REG_MAG_ENCODER_READ, true);
			magnetic_counter = 0;
		}
	}
	
	if (app_regs.REG_EXPANSION_OPTIONS == MSK_OPTICAL_TRACKING)
		{
			if (++optical_counter == optical_counter_divider)
			{				
				optical_tracking_read_motion(&optical_motion);
				
				memcpy(app_regs.REG_OPTICAL_TRACKING_READ, ((uint8_t*)(&optical_motion))+2,5);
				*(((uint8_t*)(&app_regs.REG_OPTICAL_TRACKING_READ[2]))+1) = 0;	// Clear high byte of [2]
				
				core_func_send_event(ADD_REG_OPTICAL_TRACKING_READ, true);
				optical_counter = 0;
			}
		}
}

/************************************************************************/
/* Callbacks: uart control                                              */
/************************************************************************/
void core_callback_uart_rx_before_exec(void) {}
void core_callback_uart_rx_after_exec(void) {}
void core_callback_uart_tx_before_exec(void) {}
void core_callback_uart_tx_after_exec(void) {}
void core_callback_uart_cts_before_exec(void) {}
void core_callback_uart_cts_after_exec(void) {}

/************************************************************************/
/* Callbacks: Read app register                                         */
/************************************************************************/
bool core_read_app_register(uint8_t add, uint8_t type)
{
	/* Check if it will not access forbidden memory */
	if (add < APP_REGS_ADD_MIN || add > APP_REGS_ADD_MAX)
		return false;
	
	/* Check if type matches */
	if (app_regs_type[add-APP_REGS_ADD_MIN] != type)
		return false;
	
	/* Receive data */
	(*app_func_rd_pointer[add-APP_REGS_ADD_MIN])();	

	/* Return success */
	return true;
}

/************************************************************************/
/* Callbacks: Write app register                                        */
/************************************************************************/
bool core_write_app_register(uint8_t add, uint8_t type, uint8_t * content, uint16_t n_elements)
{
	/* Check if it will not access forbidden memory */
	if (add < APP_REGS_ADD_MIN || add > APP_REGS_ADD_MAX)
		return false;
	
	/* Check if type matches */
	if (app_regs_type[add-APP_REGS_ADD_MIN] != type)
		return false;

	/* Check if the number of elements matches */
	if (app_regs_n_elements[add-APP_REGS_ADD_MIN] != n_elements)
		return false;

	/* Process data and return false if write is not allowed or contains errors */
	return (*app_func_wr_pointer[add-APP_REGS_ADD_MIN])(content);
}