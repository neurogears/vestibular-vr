#include <avr/io.h>
#include "hwbp_core_types.h"
#include "app_ios_and_regs.h"

/************************************************************************/
/* Configure and initialize IOs                                         */
/************************************************************************/
void init_ios(void)
{	/* Configure input pins */
	io_pin2in(&PORTA, 0, PULL_IO_TRISTATE, SENSE_IO_EDGES_BOTH);         // LICK0
	io_pin2in(&PORTA, 1, PULL_IO_TRISTATE, SENSE_IO_EDGES_BOTH);         // LICK1

	/* Configure input interrupts */
	io_set_int(&PORTA, INT_LEVEL_LOW, 0, (1<<0), false);                 // LICK0
	io_set_int(&PORTA, INT_LEVEL_LOW, 1, (1<<1), false);                 // LICK1

	/* Configure output pins */
	io_pin2out(&PORTR, 0, OUT_IO_DIGITAL, IN_EN_IO_EN);                  // LED_STATE
	io_pin2out(&PORTC, 0, OUT_IO_DIGITAL, IN_EN_IO_EN);                  // CAM0_TRIGGER
	io_pin2out(&PORTD, 0, OUT_IO_DIGITAL, IN_EN_IO_EN);                  // CAM1_TRIGGER
	io_pin2out(&PORTA, 6, OUT_IO_DIGITAL, IN_EN_IO_EN);                  // VALVE0
	io_pin2out(&PORTA, 7, OUT_IO_DIGITAL, IN_EN_IO_EN);                  // VALVE1
	io_pin2out(&PORTC, 4, OUT_IO_DIGITAL, IN_EN_IO_EN);                  // FLOW0_CS
	io_pin2out(&PORTC, 5, OUT_IO_DIGITAL, IN_EN_IO_EN);                  // FLOW0_MOSI
	io_pin2out(&PORTC, 7, OUT_IO_DIGITAL, IN_EN_IO_EN);                  // FLOW0_SCK
	io_pin2out(&PORTD, 4, OUT_IO_DIGITAL, IN_EN_IO_EN);                  // FLOW1_CS
	io_pin2out(&PORTD, 5, OUT_IO_DIGITAL, IN_EN_IO_EN);                  // FLOW1_MOSI
	io_pin2out(&PORTD, 7, OUT_IO_DIGITAL, IN_EN_IO_EN);                  // FLOW1_SCK

	/* Initialize output pins */
	clr_LED_STATE;
	clr_CAM0_TRIGGER;
	clr_CAM1_TRIGGER;
	clr_VALVE0;
	clr_VALVE1;
	clr_FLOW0_CS;
	clr_FLOW0_MOSI;
	clr_FLOW0_SCK;
	clr_FLOW1_CS;
	clr_FLOW1_MOSI;
	clr_FLOW1_SCK;
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
	(uint8_t*)(&app_regs.REG_CAM0_EVENT),
	(uint8_t*)(&app_regs.REG_CAM1_EVENT),
	(uint8_t*)(&app_regs.REG_CAM0_TRIGGER_FREQUENCY),
	(uint8_t*)(&app_regs.REG_CAM0_TRIGGER_DURATION_US),
	(uint8_t*)(&app_regs.REG_CAM1_TRIGGER_FREQUENCY),
	(uint8_t*)(&app_regs.REG_CAM1_TRIGGER_DURATION_US),
	(uint8_t*)(&app_regs.REG_START_AND_STOP),
	(uint8_t*)(&app_regs.REG_IN_STATE),
	(uint8_t*)(&app_regs.REG_VALVE0_PULSE),
	(uint8_t*)(&app_regs.REG_VALVE1_PULSE),
	(uint8_t*)(&app_regs.REG_OUT_SET),
	(uint8_t*)(&app_regs.REG_OUT_CLEAR),
	(uint8_t*)(&app_regs.REG_OUT_TOGGLE),
	(uint8_t*)(&app_regs.REG_OUT_WRITE),
	(uint8_t*)(app_regs.REG_REG_OPTICAL_TRACKING_READ)
};