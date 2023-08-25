#include <string.h>


#include "hwbp_core.h"
#include "hwbp_core_regs.h"
#include "hwbp_core_types.h"

#include "app.h"
#include "app_funcs.h"
#include "app_ios_and_regs.h"

//#include "spi.h"



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
static const uint8_t default_device_name[] = "VestibularVrH1";

void hwbp_app_initialize(void)
{
    /* Define versions */
    uint8_t hwH = 1;
    uint8_t hwL = 0;
    uint8_t fwH = 1;
    uint8_t fwL = 0;
    uint8_t ass = 0;
    
   	/* Start core */
    core_func_start_core(
        1224,
        hwH, hwL,
        fwH, fwL,
        ass,
        (uint8_t*)(&app_regs),
        APP_NBYTES_OF_REG_BANK,
        APP_REGS_ADD_MAX - APP_REGS_ADD_MIN + 1,
        default_device_name,
        true,	// The device is able to repeat the harp timestamp clock
        false,	// The device is not able to generate the harp timestamp clock
        0		// Default timestamp offset
    );
}

/************************************************************************/
/* Handle if a catastrophic error occur                                 */
/************************************************************************/
void core_callback_catastrophic_error_detected(void)
{
	
}

/************************************************************************/
/* User functions                                                       */
/************************************************************************/
/* Add your functions here or load external functions if needed */

/************************************************************************/
/* Initialization Callbacks                                             */
/************************************************************************/
void core_callback_define_clock_default(void)
{
	/* By default, the device will be used as a clock repeater */
	core_device_to_clock_repeater();
}

void core_callback_initialize_hardware(void)
{
	/* Initialize IOs */
	/* Don't delete this function!!! */
	init_ios();
}

void core_callback_reset_registers(void)
{
	/* Initialize registers */
	//app_regs.REG_CAM0_TRIGGER_FREQUENCY = 120;		// 120 Hz
	//app_regs.REG_CAM0_TRIGGER_DURATION_US = 1000;	// 1 mS

	
	app_regs.REG_OUT_SET = 0;
	app_regs.REG_OUT_CLEAR = 0;
	app_regs.REG_OUT_TOGGLE = 0;
	app_regs.REG_OUT_WRITE = 0;
}

void core_callback_registers_were_reinitialized(void)
{
	/* Update registers if needed */
	app_read_REG_IN_STATE();
	
	//david app_write_REG_CAM0_TRIGGER_FREQUENCY(&app_regs.REG_CAM0_TRIGGER_FREQUENCY);
	//david app_write_REG_CAM0_TRIGGER_DURATION_US(&app_regs.REG_CAM0_TRIGGER_DURATION_US);

	
}

/************************************************************************/
/* Callbacks: Visualization                                             */
/************************************************************************/
void core_callback_visualen_to_on(void)
{
	/* Update visual indicators */
	
}

void core_callback_visualen_to_off(void)
{
	/* Clear all the enabled indicators */
	
}

/************************************************************************/
/* Callbacks: Change on the operation mode                              */
/************************************************************************/
void core_callback_device_to_standby(void) {}
void core_callback_device_to_active(void) {}
void core_callback_device_to_enchanced_active(void) {}
void core_callback_device_to_speed(void) {}

/************************************************************************/
/* Callbacks: 1 ms timer                                                */
/************************************************************************/

uint16_t wait_to_start = 3000;
uint16_t n_pulses;

uint16_t pulse_completed=0;
uint16_t waiting_next_cycle=0;

void core_callback_t_before_exec(void) {}
void core_callback_t_after_exec(void) {}
void core_callback_t_new_second(void) {}
	
void core_callback_t_500us(void)
{
}

void core_callback_t_1ms(void)
{
	//waiting to startup...
	if(wait_to_start){
		wait_to_start--;
		n_pulses=5000;
		return;
	}

	drive_motor();
	
	//tgl_STEP_MOTOR_PULSE;
		
}




void drive_motor(void)
{

	if(!waiting_next_cycle){
		if(n_pulses){
			n_pulses--;
			tgl_STEP_MOTOR_PULSE;
		}
		else{
			//n_pulses=800*2;
			n_pulses=30;
			waiting_next_cycle=2000;
		}
	}
	else{
		waiting_next_cycle--;
	}
}




/************************************************************************/
/* Callbacks: clock control                                             */
/************************************************************************/
void core_callback_clock_to_repeater(void) {}
void core_callback_clock_to_generator(void) {}
void core_callback_clock_to_unlock(void) {}
void core_callback_clock_to_lock(void) {}

/************************************************************************/
/* Callbacks: uart control                                              */
/************************************************************************/
//void core_callback_uart_rx_before_exec(void) {}
//void core_callback_uart_rx_after_exec(void) {}
//void core_callback_uart_tx_before_exec(void) {}
//void core_callback_uart_tx_after_exec(void) {}
//void core_callback_uart_cts_before_exec(void) {}
//void core_callback_uart_cts_after_exec(void) {}

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