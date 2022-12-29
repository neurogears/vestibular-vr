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
void app_read_REG_CAM0_EVENT(void) {}
bool app_write_REG_CAM0_EVENT(void *a)
{
	return false;
}


/************************************************************************/
/* REG_CAM1_EVENT                                                       */
/************************************************************************/
void app_read_REG_CAM1_EVENT(void) {}
bool app_write_REG_CAM1_EVENT(void *a)
{
	return false;
}


/************************************************************************/
/* REG_CAM0_TRIGGER_FREQUENCY                                           */
/************************************************************************/
bool cam0_start_request = false;
bool cam1_start_request = false;
bool cam0_stop_request = false;
bool cam1_stop_request = false;

bool cam0_acquiring = false;
bool cam1_acquiring = false;

uint8_t cam0_freq_prescaler;
uint8_t cam1_freq_prescaler;
uint16_t cam0_freq_target_count;
uint16_t cam1_freq_target_count;
uint16_t cam0_freq_dutycyle;
uint16_t cam1_freq_dutycyle;

void update_cam0_timer_pre_values(void)
{
	calculate_timer_16bits(32000000, app_regs.REG_CAM0_TRIGGER_FREQUENCY, &cam0_freq_prescaler, &cam0_freq_target_count);
	
	switch (cam0_freq_prescaler)
	{
		case TIMER_PRESCALER_DIV1:    cam0_freq_dutycyle = (app_regs.REG_CAM0_TRIGGER_DURATION_US *32.0) / 1.0;    return;
		case TIMER_PRESCALER_DIV2:    cam0_freq_dutycyle = (app_regs.REG_CAM0_TRIGGER_DURATION_US *32.0) / 2.0;    return;
		case TIMER_PRESCALER_DIV4:    cam0_freq_dutycyle = (app_regs.REG_CAM0_TRIGGER_DURATION_US *32.0) / 4.0;    return;
		case TIMER_PRESCALER_DIV8:    cam0_freq_dutycyle = (app_regs.REG_CAM0_TRIGGER_DURATION_US *32.0) / 8.0;    return;
		case TIMER_PRESCALER_DIV64:   cam0_freq_dutycyle = (app_regs.REG_CAM0_TRIGGER_DURATION_US *32.0) / 64.0;   return;
		case TIMER_PRESCALER_DIV256:  cam0_freq_dutycyle = (app_regs.REG_CAM0_TRIGGER_DURATION_US *32.0) / 256.0;  return;
		case TIMER_PRESCALER_DIV1024: cam0_freq_dutycyle = (app_regs.REG_CAM0_TRIGGER_DURATION_US *32.0) / 1024.0; return;
	}
}

void update_cam1_timer_pre_values(void)
{
	calculate_timer_16bits(32000000, app_regs.REG_CAM1_TRIGGER_FREQUENCY, &cam1_freq_prescaler, &cam1_freq_target_count);
	
	switch (cam1_freq_prescaler)
	{
		case TIMER_PRESCALER_DIV1:    cam1_freq_dutycyle = (app_regs.REG_CAM1_TRIGGER_DURATION_US *32.0) / 1.0;    return;
		case TIMER_PRESCALER_DIV2:    cam1_freq_dutycyle = (app_regs.REG_CAM1_TRIGGER_DURATION_US *32.0) / 2.0;    return;
		case TIMER_PRESCALER_DIV4:    cam1_freq_dutycyle = (app_regs.REG_CAM1_TRIGGER_DURATION_US *32.0) / 4.0;    return;
		case TIMER_PRESCALER_DIV8:    cam1_freq_dutycyle = (app_regs.REG_CAM1_TRIGGER_DURATION_US *32.0) / 8.0;    return;
		case TIMER_PRESCALER_DIV64:   cam1_freq_dutycyle = (app_regs.REG_CAM1_TRIGGER_DURATION_US *32.0) / 64.0;   return;
		case TIMER_PRESCALER_DIV256:  cam1_freq_dutycyle = (app_regs.REG_CAM1_TRIGGER_DURATION_US *32.0) / 256.0;  return;
		case TIMER_PRESCALER_DIV1024: cam1_freq_dutycyle = (app_regs.REG_CAM1_TRIGGER_DURATION_US *32.0) / 1024.0; return;
	}
}

void app_read_REG_CAM0_TRIGGER_FREQUENCY(void) {}
bool app_write_REG_CAM0_TRIGGER_FREQUENCY(void *a)
{
	uint16_t reg = *((uint16_t*)a);
	
	if (reg < 1 || reg > 1000)
		return false;
	
	if (cam0_acquiring)
		return false;

	app_regs.REG_CAM0_TRIGGER_FREQUENCY = reg;
	update_cam0_timer_pre_values();
	
	return true;
}


/************************************************************************/
/* REG_CAM0_TRIGGER_DURATION_US                                         */
/************************************************************************/
void app_read_REG_CAM0_TRIGGER_DURATION_US(void) {}
bool app_write_REG_CAM0_TRIGGER_DURATION_US(void *a)
{
	uint16_t reg = *((uint16_t*)a);
	
	if (reg < 100 || reg > 5000)
		return false;
	
	if (cam0_acquiring)
		return false;
	
	app_regs.REG_CAM0_TRIGGER_DURATION_US = reg;
	update_cam0_timer_pre_values();
	
	return true;
}


/************************************************************************/
/* REG_CAM1_TRIGGER_FREQUENCY                                           */
/************************************************************************/
void app_read_REG_CAM1_TRIGGER_FREQUENCY(void) {}
bool app_write_REG_CAM1_TRIGGER_FREQUENCY(void *a)
{
	uint16_t reg = *((uint16_t*)a);
	
	if (reg < 1 || reg > 1000)
		return false;
	
	if (cam1_acquiring)
		return false;

	app_regs.REG_CAM1_TRIGGER_FREQUENCY = reg;
	update_cam1_timer_pre_values();
	
	return true;
}


/************************************************************************/
/* REG_CAM1_TRIGGER_DURATION_US                                         */
/************************************************************************/
void app_read_REG_CAM1_TRIGGER_DURATION_US(void) {}
bool app_write_REG_CAM1_TRIGGER_DURATION_US(void *a)
{
	uint16_t reg = *((uint16_t*)a);
	
	if (reg < 100 || reg > 5000)
		return false;
	
	if (cam1_acquiring)
		return false;
	
	app_regs.REG_CAM1_TRIGGER_DURATION_US = reg;
	update_cam1_timer_pre_values();
	
	return true;
}


/************************************************************************/
/* REG_START_AND_STOP                                                   */
/************************************************************************/
void app_read_REG_START_AND_STOP(void)
{
	app_regs.REG_START_AND_STOP  = (cam0_acquiring) ? B_START_CAM0 : B_STOP_CAM0;
	app_regs.REG_START_AND_STOP |= (cam1_acquiring) ? B_START_CAM1 : B_STOP_CAM1;
}

bool app_write_REG_START_AND_STOP(void *a)
{
	uint8_t reg = *((uint8_t*)a);
	
	if (reg & B_START_CAM0)
	{
		if (cam0_acquiring == false)
		{				
			cam0_start_request = true;
		}
	}
	
	if (reg & B_START_CAM1)
	{
		if (cam1_acquiring == false)
		{			
			cam1_start_request = true;
		}
	}
				
	if (reg & B_STOP_CAM0)		
	{
		cam0_start_request = false;
			
		if (cam0_acquiring)
		{
			cam0_stop_request = true;
		}
	}
				
	if (reg & B_STOP_CAM1)
	{
		cam1_start_request = false;
			
		if (cam1_acquiring)
		{
			cam1_stop_request = true;
		}
	}
	
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
void app_read_REG_REG_OPTICAL_TRACKING_READ(void) {}
bool app_write_REG_REG_OPTICAL_TRACKING_READ(void *a)
{
	return false;
}