#include "app_funcs.h"
#include "app_ios_and_regs.h"
#include "hwbp_core.h"


/************************************************************************/
/* Create pointers to functions                                         */
/************************************************************************/
extern AppRegs app_regs;

void (*app_func_rd_pointer[])(void) = {
	&app_read_ANALOG_VREF,
	&app_read_HALL_EFFECT_SENSOR,
	&app_read_CLOCK_INPUT,
	&app_read_EMERGENCY_INPUT,
	&app_read_ENCODER_A_PHASE,
	&app_read_ENCODER_B_PHASE,
	&app_read_REG_IN_STATE,
	&app_read_REG_OUT_SET,
	&app_read_REG_OUT_CLEAR,
	&app_read_REG_OUT_TOGGLE,
	&app_read_REG_OUT_WRITE,
};

bool (*app_func_wr_pointer[])(void*) = {
	&app_write_ANALOG_VREF,
	&app_write_HALL_EFFECT_SENSOR,
	&app_write_CLOCK_INPUT,
	&app_write_EMERGENCY_INPUT,
	&app_write_ENCODER_A_PHASE,
	&app_write_ENCODER_B_PHASE,
	&app_write_REG_IN_STATE,
	&app_write_REG_OUT_SET,
	&app_write_REG_OUT_CLEAR,
	&app_write_REG_OUT_TOGGLE,
	&app_write_REG_OUT_WRITE,
};


/************************************************************************/
/* ANALOG_VREF                                                       */
/************************************************************************/
void app_read_ANALOG_VREF(void) {}
bool app_write_ANALOG_VREF(void *a)
{
	return false;
}


/************************************************************************/
/* HALL_EFFECT_SENSOR                                                       */
/************************************************************************/
void app_read_HALL_EFFECT_SENSOR(void) {}
bool app_write_HALL_EFFECT_SENSOR(void *a)
{
	return false;
}


/************************************************************************/
/* CLOCK_INPUT                                                       */
/************************************************************************/
void app_read_CLOCK_INPUT(void) {}
bool app_write_CLOCK_INPUT(void *a)
{
	return false;
}

/************************************************************************/
/* EMERGENCY_INPUT                                                       */
/************************************************************************/
void app_read_EMERGENCY_INPUT(void) {}
bool app_write_EMERGENCY_INPUT(void *a)
{
	return true;
}

/************************************************************************/
/* ENCODER_A_PHASE                                                       */
/************************************************************************/
void app_read_ENCODER_A_PHASE(void) {}
bool app_write_ENCODER_A_PHASE(void *a)
{
	return false;
}

/************************************************************************/
/* ENCODER_B_PHASE                                                       */
/************************************************************************/
void app_read_ENCODER_B_PHASE(void) {}
bool app_write_ENCODER_B_PHASE(void *a)
{
	return false;
}









/************************************************************************/
/* REG_IN_STATE                                                         */
/************************************************************************/
void app_read_REG_IN_STATE(void)
{
	app_regs.REG_IN_STATE  = (read_EMERGENCY_INPUT) ? B_EMERGENCY_INPUT : 0;
	app_regs.REG_IN_STATE |= (read_ENCODER_A_PHASE) ? B_ENCODER_A_PHASE : 0;
	app_regs.REG_IN_STATE |= (read_ENCODER_B_PHASE) ? B_ENCODER_B_PHASE : 0;

}

bool app_write_REG_IN_STATE(void *a)
{
	return false;
}

/************************************************************************/
/* REG_OUT_SET                                                          */
/************************************************************************/
extern uint8_t pulse_countdown_valve0;
extern uint8_t pulse_countdown_valve1;

void app_read_REG_OUT_SET(void) {}
bool app_write_REG_OUT_SET(void *a)
{
	uint8_t reg = *((uint8_t*)a);
	
	if (reg & B_STEP_MOTOR_PULSE) { set_STEP_MOTOR_PULSE; }
	if (reg & B_STEP_MOTOR_ENABLE) { set_STEP_MOTOR_ENABLE; }
	if (reg & B_STEP_MOTOR_DIRECTION) { set_STEP_MOTOR_DIRECTION; }

	
	app_regs.REG_OUT_SET = reg;
	return true;
}


/************************************************************************/
/* REG_OUT_CLEAR                                                        */
/************************************************************************/
void app_read_REG_OUT_CLEAR(void) {}
bool app_write_REG_OUT_CLEAR(void *a)
{
	uint8_t reg = *((uint8_t*)a);
	
	if (reg & B_STEP_MOTOR_PULSE) { clr_STEP_MOTOR_PULSE; }
	if (reg & B_STEP_MOTOR_ENABLE) { clr_STEP_MOTOR_ENABLE; }
	if (reg & B_STEP_MOTOR_DIRECTION) { clr_STEP_MOTOR_DIRECTION; }


	app_regs.REG_OUT_CLEAR = reg;
	return true;
}


/************************************************************************/
/* REG_OUT_TOGGLE                                                       */
/************************************************************************/
void app_read_REG_OUT_TOGGLE(void) {}
bool app_write_REG_OUT_TOGGLE(void *a)
{
	uint8_t reg = *((uint8_t*)a);

	if (reg & B_STEP_MOTOR_PULSE) { clr_STEP_MOTOR_PULSE; }	
	if (reg & B_STEP_MOTOR_ENABLE) { clr_STEP_MOTOR_ENABLE; }
	if (reg & B_STEP_MOTOR_DIRECTION) { clr_STEP_MOTOR_DIRECTION; }
	
	
	app_regs.REG_OUT_TOGGLE = reg;
	return true;
}


/************************************************************************/
/* REG_OUT_WRITE                                                        */
/************************************************************************/
void app_read_REG_OUT_WRITE(void)
{
		app_regs.REG_OUT_WRITE  = (read_EMERGENCY_INPUT) ? B_EMERGENCY_INPUT : 0;
		app_regs.REG_OUT_WRITE |= (read_ENCODER_A_PHASE) ? B_ENCODER_A_PHASE : 0;
		app_regs.REG_OUT_WRITE |= (read_ENCODER_B_PHASE) ? B_STEP_MOTOR_DIRECTION : 0;
}

bool app_write_REG_OUT_WRITE(void *a)
{
	uint8_t reg = *((uint8_t*)a);
	
	if (reg & B_STEP_MOTOR_ENABLE) { set_STEP_MOTOR_ENABLE; } else { clr_STEP_MOTOR_ENABLE; }
	if (reg & B_STEP_MOTOR_DIRECTION) { set_STEP_MOTOR_DIRECTION; } else { clr_STEP_MOTOR_DIRECTION; }
	if (reg & B_STEP_MOTOR_PULSE) { set_STEP_MOTOR_PULSE; } else { clr_STEP_MOTOR_PULSE; }

	app_regs.REG_OUT_WRITE = reg;
	return true;
}

