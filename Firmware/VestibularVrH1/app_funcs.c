#include "app_funcs.h"
#include "app_ios_and_regs.h"
#include "hwbp_core.h"


/************************************************************************/
/* Create pointers to functions                                         */
/************************************************************************/
extern AppRegs app_regs;

void (*app_func_rd_pointer[])(void) = {
	&app_read_REG_CAM0_EVENT,
	&app_read_REG_CAM1_EVENT,
	&app_read_REG_CAM0_TRIGGER_FREQUENCY,
	&app_read_REG_CAM0_TRIGGER_DURATION_US,
	&app_read_REG_CAM1_TRIGGER_FREQUENCY,
	&app_read_REG_CAM1_TRIGGER_DURATION_US,
	&app_read_REG_START_AND_STOP,
	&app_read_REG_IN_STATE,
	&app_read_REG_VALVE0_PULSE,
	&app_read_REG_VALVE1_PULSE,
	&app_read_REG_OUT_SET,
	&app_read_REG_OUT_CLEAR,
	&app_read_REG_OUT_TOGGLE,
	&app_read_REG_OUT_WRITE,
	&app_read_REG_REG_OPTICAL_TRACKING_READ
};

bool (*app_func_wr_pointer[])(void*) = {
	&app_write_REG_CAM0_EVENT,
	&app_write_REG_CAM1_EVENT,
	&app_write_REG_CAM0_TRIGGER_FREQUENCY,
	&app_write_REG_CAM0_TRIGGER_DURATION_US,
	&app_write_REG_CAM1_TRIGGER_FREQUENCY,
	&app_write_REG_CAM1_TRIGGER_DURATION_US,
	&app_write_REG_START_AND_STOP,
	&app_write_REG_IN_STATE,
	&app_write_REG_VALVE0_PULSE,
	&app_write_REG_VALVE1_PULSE,
	&app_write_REG_OUT_SET,
	&app_write_REG_OUT_CLEAR,
	&app_write_REG_OUT_TOGGLE,
	&app_write_REG_OUT_WRITE,
	&app_write_REG_REG_OPTICAL_TRACKING_READ
};


/************************************************************************/
/* REG_CAM0_EVENT                                                       */
/************************************************************************/
void app_read_REG_CAM0_EVENT(void)
{
	//app_regs.REG_CAM0_EVENT = 0;

}

bool app_write_REG_CAM0_EVENT(void *a)
{
	uint8_t reg = *((uint8_t*)a);

	app_regs.REG_CAM0_EVENT = reg;
	return true;
}


/************************************************************************/
/* REG_CAM1_EVENT                                                       */
/************************************************************************/
void app_read_REG_CAM1_EVENT(void)
{
	//app_regs.REG_CAM1_EVENT = 0;

}

bool app_write_REG_CAM1_EVENT(void *a)
{
	uint8_t reg = *((uint8_t*)a);

	app_regs.REG_CAM1_EVENT = reg;
	return true;
}


/************************************************************************/
/* REG_CAM0_TRIGGER_FREQUENCY                                           */
/************************************************************************/
void app_read_REG_CAM0_TRIGGER_FREQUENCY(void)
{
	//app_regs.REG_CAM0_TRIGGER_FREQUENCY = 0;

}

bool app_write_REG_CAM0_TRIGGER_FREQUENCY(void *a)
{
	uint16_t reg = *((uint16_t*)a);

	app_regs.REG_CAM0_TRIGGER_FREQUENCY = reg;
	return true;
}


/************************************************************************/
/* REG_CAM0_TRIGGER_DURATION_US                                         */
/************************************************************************/
void app_read_REG_CAM0_TRIGGER_DURATION_US(void)
{
	//app_regs.REG_CAM0_TRIGGER_DURATION_US = 0;

}

bool app_write_REG_CAM0_TRIGGER_DURATION_US(void *a)
{
	uint16_t reg = *((uint16_t*)a);

	app_regs.REG_CAM0_TRIGGER_DURATION_US = reg;
	return true;
}


/************************************************************************/
/* REG_CAM1_TRIGGER_FREQUENCY                                           */
/************************************************************************/
void app_read_REG_CAM1_TRIGGER_FREQUENCY(void)
{
	//app_regs.REG_CAM1_TRIGGER_FREQUENCY = 0;

}

bool app_write_REG_CAM1_TRIGGER_FREQUENCY(void *a)
{
	uint16_t reg = *((uint16_t*)a);

	app_regs.REG_CAM1_TRIGGER_FREQUENCY = reg;
	return true;
}


/************************************************************************/
/* REG_CAM1_TRIGGER_DURATION_US                                         */
/************************************************************************/
void app_read_REG_CAM1_TRIGGER_DURATION_US(void)
{
	//app_regs.REG_CAM1_TRIGGER_DURATION_US = 0;

}

bool app_write_REG_CAM1_TRIGGER_DURATION_US(void *a)
{
	uint16_t reg = *((uint16_t*)a);

	app_regs.REG_CAM1_TRIGGER_DURATION_US = reg;
	return true;
}


/************************************************************************/
/* REG_START_AND_STOP                                                   */
/************************************************************************/
void app_read_REG_START_AND_STOP(void)
{
	//app_regs.REG_START_AND_STOP = 0;

}

bool app_write_REG_START_AND_STOP(void *a)
{
	uint8_t reg = *((uint8_t*)a);

	app_regs.REG_START_AND_STOP = reg;
	return true;
}


/************************************************************************/
/* REG_IN_STATE                                                         */
/************************************************************************/
void app_read_REG_IN_STATE(void)
{
	app_regs.REG_IN_STATE  = (read_LICK0) ? B_LICK0 : 0;
	app_regs.REG_IN_STATE |= (read_LICK1) ? B_LICK1 : 0;
}

bool app_write_REG_IN_STATE(void *a)
{
	return false;
}


/************************************************************************/
/* REG_VALVE0_PULSE                                                     */
/************************************************************************/
void app_read_REG_VALVE0_PULSE(void) {}
bool app_write_REG_VALVE0_PULSE(void *a)
{
	uint8_t reg = *((uint8_t*)a);
	
	if (reg < 1)   return false;
	if (reg > 250) return false;

	app_regs.REG_VALVE0_PULSE = reg;
	return true;
}


/************************************************************************/
/* REG_VALVE1_PULSE                                                     */
/************************************************************************/
void app_read_REG_VALVE1_PULSE(void) {}
bool app_write_REG_VALVE1_PULSE(void *a)
{
	uint8_t reg = *((uint8_t*)a);
	
	if (reg < 1)   return false;
	if (reg > 250) return false;

	app_regs.REG_VALVE1_PULSE = reg;
	return true;
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
	
	if (reg & B_TRIGGER_CAM0) { set_CAM0_TRIGGER; }
	if (reg & B_TRIGGER_CAM1) { set_CAM1_TRIGGER; }
	if (reg & B_VALVE0)       { set_VALVE0; }
	if (reg & B_VALVE1)       { set_VALVE1; }
	if (reg & B_PULSE_VALVE0) { set_VALVE0; pulse_countdown_valve0 = app_regs.REG_VALVE0_PULSE + 1; }
	if (reg & B_PULSE_VALVE1) { set_VALVE1; pulse_countdown_valve1 = app_regs.REG_VALVE1_PULSE + 1; }
	
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
	
	if (reg & B_TRIGGER_CAM0) { clr_CAM0_TRIGGER; }
	if (reg & B_TRIGGER_CAM1) { clr_CAM1_TRIGGER; }
	if (reg & B_VALVE0)       { clr_VALVE0; pulse_countdown_valve0 = 0; }
	if (reg & B_VALVE1)       { clr_VALVE1; pulse_countdown_valve1 = 0; }
	if (reg & B_PULSE_VALVE0) { clr_VALVE0; pulse_countdown_valve0 = 0; }
	if (reg & B_PULSE_VALVE1) { clr_VALVE1; pulse_countdown_valve1 = 0; }

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
	
	if (reg & B_TRIGGER_CAM0) { tgl_CAM0_TRIGGER; }
	if (reg & B_TRIGGER_CAM1) { tgl_CAM1_TRIGGER; }
	if (reg & B_VALVE0)       { tgl_VALVE0; pulse_countdown_valve0 = 0; }
	if (reg & B_VALVE1)       { tgl_VALVE1; pulse_countdown_valve1 = 0; }
	
	if (reg & B_PULSE_VALVE0)
	{
		if (read_VALVE0)
		{
			clr_VALVE0;
			pulse_countdown_valve0 = 0;
		}
		else
		{
			set_VALVE0;
			pulse_countdown_valve0 = app_regs.REG_VALVE0_PULSE + 1;
		}
	}
	
	if (reg & B_PULSE_VALVE1)
	{
		if (read_VALVE1)
		{
			clr_VALVE1;
			pulse_countdown_valve1 = 0;
		}
		else
		{
			set_VALVE1;
			pulse_countdown_valve1 = app_regs.REG_VALVE1_PULSE + 1;
		}
	}

	app_regs.REG_OUT_TOGGLE = reg;
	return true;
}


/************************************************************************/
/* REG_OUT_WRITE                                                        */
/************************************************************************/
void app_read_REG_OUT_WRITE(void)
{
		app_regs.REG_OUT_WRITE  = (read_LICK0) ? B_LICK0 : 0;
		app_regs.REG_OUT_WRITE |= (read_LICK1) ? B_LICK1 : 0;
		app_regs.REG_OUT_WRITE |= (read_VALVE0) ? B_VALVE0 : 0;
		app_regs.REG_OUT_WRITE |= (read_VALVE1) ? B_VALVE1 : 0;
		app_regs.REG_OUT_WRITE |= (read_VALVE0 && pulse_countdown_valve0) ? B_PULSE_VALVE0 : 0;
		app_regs.REG_OUT_WRITE |= (read_VALVE1 && pulse_countdown_valve1) ? B_PULSE_VALVE1 : 0;
}

bool app_write_REG_OUT_WRITE(void *a)
{
	uint8_t reg = *((uint8_t*)a);
	
	if (reg & B_TRIGGER_CAM0) { set_CAM0_TRIGGER; } else { clr_CAM0_TRIGGER; }
	if (reg & B_TRIGGER_CAM1) { set_CAM1_TRIGGER; } else { clr_CAM1_TRIGGER; }
	if (reg & B_VALVE0)       { set_VALVE0; } else { clr_VALVE0; pulse_countdown_valve0 = 0; }
	if (reg & B_VALVE1)       { set_VALVE1; } else { clr_VALVE1; pulse_countdown_valve1 = 0; }
	if (reg & B_PULSE_VALVE0) { set_VALVE0; pulse_countdown_valve0 = app_regs.REG_VALVE0_PULSE + 1; } else { clr_VALVE0; pulse_countdown_valve0 = 0; }
	if (reg & B_PULSE_VALVE1) { set_VALVE1; pulse_countdown_valve1 = app_regs.REG_VALVE1_PULSE + 1; } else { clr_VALVE1; pulse_countdown_valve1 = 0; }

	app_regs.REG_OUT_WRITE = reg;
	return true;
}


/************************************************************************/
/* REG_REG_OPTICAL_TRACKING_READ                                        */
/************************************************************************/
// This register is an array with 6 positions
void app_read_REG_REG_OPTICAL_TRACKING_READ(void)
{
	//app_regs.REG_REG_OPTICAL_TRACKING_READ[0] = 0;

}

bool app_write_REG_REG_OPTICAL_TRACKING_READ(void *a)
{
	int16_t *reg = ((int16_t*)a);

	app_regs.REG_REG_OPTICAL_TRACKING_READ[0] = reg[0];
	return true;
}