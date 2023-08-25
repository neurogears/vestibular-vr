#include <avr/io.h>
#include "hwbp_core_types.h"
#include "app_ios_and_regs.h"

/************************************************************************/
/* Configure and initialize IOs                                         */
/************************************************************************/
void init_ios(void)
{	
		/* Configure input pins */
		io_pin2in(&PORTB, 0, PULL_IO_TRISTATE, SENSE_IO_EDGES_BOTH);         // EMERGENCY_INPUT
		io_pin2in(&PORTC, 2, PULL_IO_TRISTATE, SENSE_IO_EDGES_BOTH);         // CLOCK_INPUT
		io_pin2in(&PORTC, 4, PULL_IO_TRISTATE, SENSE_IO_EDGES_BOTH);         // ENCODER_A_PHASE
		io_pin2in(&PORTC, 5, PULL_IO_TRISTATE, SENSE_IO_EDGES_BOTH);         // ENCODER_B_PHASE

		/* Configure input Analog pins */
		//io_pin2in(&PORTA, 0, PULL_IO_TRISTATE, SENSE_IO_EDGES_BOTH);         // ANALOG_VREF
		//io_pin2in(&PORTA, 1, PULL_IO_TRISTATE, SENSE_IO_EDGES_BOTH);         // HALL_EFFECT_SENSOR
		



		/* Configure output pins */
		io_pin2out(&PORTR, 0, OUT_IO_DIGITAL, IN_EN_IO_EN);                  // LED_STATE
		io_pin2out(&PORTC, 0, OUT_IO_DIGITAL, IN_EN_IO_EN);                  // STEP_MOTOR_ENABLE
		io_pin2out(&PORTC, 3, OUT_IO_DIGITAL, IN_EN_IO_EN);                  // STEP_MOTOR_PULSE
		io_pin2out(&PORTC, 6, OUT_IO_DIGITAL, IN_EN_IO_EN);                  // STEP_MOTOR_DIRECTION

		/* Initialize output pins */
		set_LED_STATE;
		 
		clr_STEP_MOTOR_ENABLE;
		//set_STEP_MOTOR_DIRECTION; 
		clr_STEP_MOTOR_DIRECTION;
		
}

/************************************************************************/
/* Registers' stuff                                                     */
/************************************************************************/
AppRegs app_regs;

uint8_t app_regs_type[] = {
	TYPE_U8,
	TYPE_U8,
	TYPE_U16,
	TYPE_U16,
	TYPE_U16,
	TYPE_U16,
	TYPE_U8,
	TYPE_U8,
	TYPE_U8,
	TYPE_U8,
	TYPE_U8,
	TYPE_U8,
	TYPE_U8,
	TYPE_U8,
	TYPE_I16
};

uint16_t app_regs_n_elements[] = {
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	6
};

uint8_t *app_regs_pointer[] = {
	//(uint8_t*)(&app_regs.REG_CAM0_EVENT),
	//(uint8_t*)(&app_regs.REG_CAM1_EVENT),
	//(uint8_t*)(&app_regs.REG_CAM0_TRIGGER_FREQUENCY),
	//(uint8_t*)(&app_regs.REG_CAM0_TRIGGER_DURATION_US),
	//(uint8_t*)(&app_regs.REG_CAM1_TRIGGER_FREQUENCY),
	//(uint8_t*)(&app_regs.REG_CAM1_TRIGGER_DURATION_US),
	//(uint8_t*)(&app_regs.REG_START_AND_STOP),
	//(uint8_t*)(&app_regs.REG_IN_STATE),
	//(uint8_t*)(&app_regs.REG_VALVE0_PULSE),
	//(uint8_t*)(&app_regs.REG_VALVE1_PULSE),
	(uint8_t*)(&app_regs.REG_OUT_SET),
	(uint8_t*)(&app_regs.REG_OUT_CLEAR),
	(uint8_t*)(&app_regs.REG_OUT_TOGGLE),
	(uint8_t*)(&app_regs.REG_OUT_WRITE),
	//(uint8_t*)(app_regs.REG_REG_OPTICAL_TRACKING_READ)
};