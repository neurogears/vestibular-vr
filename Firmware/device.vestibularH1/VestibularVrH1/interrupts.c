#include "cpu.h"
#include "hwbp_core_types.h"
#include "app_ios_and_regs.h"
#include "app_funcs.h"
#include "hwbp_core.h"

/************************************************************************/
/* Declare application registers                                        */
/************************************************************************/
extern AppRegs app_regs;

/************************************************************************/
/* Interrupts from Timers                                               */
/************************************************************************/
// ISR(TCC0_OVF_vect, ISR_NAKED)
// ISR(TCD0_OVF_vect, ISR_NAKED)
// ISR(TCE0_OVF_vect, ISR_NAKED)
// ISR(TCF0_OVF_vect, ISR_NAKED)
// 
// ISR(TCC0_CCA_vect, ISR_NAKED)
// ISR(TCD0_CCA_vect, ISR_NAKED)
// ISR(TCE0_CCA_vect, ISR_NAKED)
// ISR(TCF0_CCA_vect, ISR_NAKED)
// 
// ISR(TCD1_OVF_vect, ISR_NAKED)
// 
// ISR(TCD1_CCA_vect, ISR_NAKED)

/************************************************************************/ 
/* LICK0                                                                */
/************************************************************************/
bool previous_lick0_state = true;	// Licks are inverted;

ISR(PORTA_INT0_vect, ISR_NAKED)
{
	if (read_LICK0)
	{
		if (previous_lick0_state == false)
		{			
			previous_lick0_state = true;
			
			app_regs.REG_IN_STATE = B_LICK0_CHANGED | (app_regs.REG_IN_STATE & B_LICK1) | B_LICK0;			
			core_func_send_event(ADD_REG_IN_STATE, true);
		}
	}
	else
	{
		if (previous_lick0_state == true)
		{
			previous_lick0_state = false;
			
			app_regs.REG_IN_STATE = B_LICK0_CHANGED | (app_regs.REG_IN_STATE & B_LICK1);
			core_func_send_event(ADD_REG_IN_STATE, true);
		}
	}
	
	reti();
}

/************************************************************************/ 
/* LICK1                                                                */
/************************************************************************/
bool previous_lick1_state = true;	// Licks are inverted

ISR(PORTA_INT1_vect, ISR_NAKED)
{
	if (read_LICK1)
	{
		if (previous_lick1_state == false)
		{
			previous_lick1_state = true;
			
			app_regs.REG_IN_STATE = B_LICK1_CHANGED | (app_regs.REG_IN_STATE & B_LICK0) | B_LICK1;			
			core_func_send_event(ADD_REG_IN_STATE, true);
		}
	}
	else
	{
		if (previous_lick1_state == true)
		{
			previous_lick1_state = false;
			
			app_regs.REG_IN_STATE = B_LICK1_CHANGED | (app_regs.REG_IN_STATE & B_LICK0);
			core_func_send_event(ADD_REG_IN_STATE, true);
		}
	}
	
	reti();
}

/************************************************************************/
/* CAMERA 0                                                             */
/************************************************************************/
extern bool cam0_acquiring;
extern bool stop_cam0_when_possible;

uint32_t cam0_int_s;
uint16_t cam0_int_us;

ISR(TCC0_OVF_vect, ISR_NAKED)
{		
	core_func_mark_user_timestamp();
	core_func_read_user_timestamp(&cam0_int_s, &cam0_int_us);
	
	reti();
}

ISR(TCC0_CCA_vect, ISR_NAKED)
{
	if (stop_cam0_when_possible)
	{
		stop_cam0_when_possible = false;
		cam0_acquiring = false;
		
		timer_type0_stop(&TCC0);
	}
	
	app_regs.REG_CAM0_EVENT = B_TRIGGER;
	core_func_update_user_timestamp(cam0_int_s, cam0_int_us);
	core_func_send_event(ADD_REG_CAM0_EVENT, false);
	
	reti();
}

/************************************************************************/
/* CAMERA 1                                                             */
/************************************************************************/
extern bool cam1_acquiring;
extern bool stop_cam1_when_possible;

uint32_t cam1_int_s;
uint16_t cam1_int_us;

ISR(TCD0_OVF_vect, ISR_NAKED)
{
	core_func_mark_user_timestamp();
	core_func_read_user_timestamp(&cam1_int_s, &cam1_int_us);
	
	reti();
}

ISR(TCD0_CCA_vect, ISR_NAKED)
{
	if (stop_cam1_when_possible)
	{
		stop_cam1_when_possible = false;
		cam1_acquiring = false;
		
		timer_type0_stop(&TCD0);
	}
	
	app_regs.REG_CAM1_EVENT = B_TRIGGER;
	core_func_update_user_timestamp(cam1_int_s, cam1_int_us);
	core_func_send_event(ADD_REG_CAM1_EVENT, false);
	
	reti();
}