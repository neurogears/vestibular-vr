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
bool previous_lick0_state = false;

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
bool previous_lick1_state = false;

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

