#ifndef _APP_IOS_AND_REGS_H_
#define _APP_IOS_AND_REGS_H_
#include "cpu.h"

void init_ios(void);
/************************************************************************/
/* Definition of input pins                                             */
/************************************************************************/
// LICK0                  Description: Input for the Lick 0
// LICK1                  Description: Input for the Lick 1

#define read_LICK0 read_io(PORTA, 0)            // LICK0
#define read_LICK1 read_io(PORTA, 1)            // LICK1

/************************************************************************/
/* Definition of output pins                                            */
/************************************************************************/
// LED_STATE              Description: Power's LED
// CAM0_TRIGGER           Description: Trigger for cammera 0 (T0)
// CAM1_TRIGGER           Description: Trigger for cammera 1 (T1)
// VALVE0                 Description: Controls the transitor of Valve 0
// VALVE1                 Description: Controls the transitor of Valve 1
// FLOW0_CS               Description: Flow meter SPI line CS
// FLOW0_MOSI             Description: Flow meter SPI line MOSI
// FLOW0_SCK              Description: Flow meter SPI line SCK
// FLOW1_CS               Description: Flow meter SPI line CS
// FLOW1_MOSI             Description: Flow meter SPI line MOSI
// FLOW1_SCK              Description: Flow meter SPI line SCK

/* LED_STATE */
#define set_LED_STATE set_io(PORTR, 0)
#define clr_LED_STATE clear_io(PORTR, 0)
#define tgl_LED_STATE toggle_io(PORTR, 0)
#define read_LED_STATE read_io(PORTR, 0)

/* CAM0_TRIGGER */
#define set_CAM0_TRIGGER set_io(PORTC, 0)
#define clr_CAM0_TRIGGER clear_io(PORTC, 0)
#define tgl_CAM0_TRIGGER toggle_io(PORTC, 0)
#define read_CAM0_TRIGGER read_io(PORTC, 0)

/* CAM1_TRIGGER */
#define set_CAM1_TRIGGER set_io(PORTD, 0)
#define clr_CAM1_TRIGGER clear_io(PORTD, 0)
#define tgl_CAM1_TRIGGER toggle_io(PORTD, 0)
#define read_CAM1_TRIGGER read_io(PORTD, 0)

/* VALVE0 */
#define set_VALVE0 set_io(PORTA, 6)
#define clr_VALVE0 clear_io(PORTA, 6)
#define tgl_VALVE0 toggle_io(PORTA, 6)
#define read_VALVE0 read_io(PORTA, 6)

/* VALVE1 */
#define set_VALVE1 set_io(PORTA, 7)
#define clr_VALVE1 clear_io(PORTA, 7)
#define tgl_VALVE1 toggle_io(PORTA, 7)
#define read_VALVE1 read_io(PORTA, 7)

/* FLOW0_CS */
#define set_FLOW0_CS set_io(PORTC, 4)
#define clr_FLOW0_CS clear_io(PORTC, 4)
#define tgl_FLOW0_CS toggle_io(PORTC, 4)
#define read_FLOW0_CS read_io(PORTC, 4)

/* FLOW0_MOSI */
#define set_FLOW0_MOSI set_io(PORTC, 5)
#define clr_FLOW0_MOSI clear_io(PORTC, 5)
#define tgl_FLOW0_MOSI toggle_io(PORTC, 5)
#define read_FLOW0_MOSI read_io(PORTC, 5)

/* FLOW0_SCK */
#define set_FLOW0_SCK set_io(PORTC, 7)
#define clr_FLOW0_SCK clear_io(PORTC, 7)
#define tgl_FLOW0_SCK toggle_io(PORTC, 7)
#define read_FLOW0_SCK read_io(PORTC, 7)

/* FLOW1_CS */
#define set_FLOW1_CS set_io(PORTD, 4)
#define clr_FLOW1_CS clear_io(PORTD, 4)
#define tgl_FLOW1_CS toggle_io(PORTD, 4)
#define read_FLOW1_CS read_io(PORTD, 4)

/* FLOW1_MOSI */
#define set_FLOW1_MOSI set_io(PORTD, 5)
#define clr_FLOW1_MOSI clear_io(PORTD, 5)
#define tgl_FLOW1_MOSI toggle_io(PORTD, 5)
#define read_FLOW1_MOSI read_io(PORTD, 5)

/* FLOW1_SCK */
#define set_FLOW1_SCK set_io(PORTD, 7)
#define clr_FLOW1_SCK clear_io(PORTD, 7)
#define tgl_FLOW1_SCK toggle_io(PORTD, 7)
#define read_FLOW1_SCK read_io(PORTD, 7)


/************************************************************************/
/* Registers' structure                                                 */
/************************************************************************/
typedef struct
{
	uint8_t REG_CAM0_EVENT;
	uint8_t REG_CAM1_EVENT;
	uint16_t REG_CAM0_TRIGGER_FREQUENCY;
	uint16_t REG_CAM0_TRIGGER_DURATION_US;
	uint16_t REG_CAM1_TRIGGER_FREQUENCY;
	uint16_t REG_CAM1_TRIGGER_DURATION_US;
	uint8_t REG_START_AND_STOP;
	uint8_t REG_IN_STATE;
	uint8_t REG_VALVE0_PULSE;
	uint8_t REG_VALVE1_PULSE;
	uint8_t REG_OUT_SET;
	uint8_t REG_OUT_CLEAR;
	uint8_t REG_OUT_TOGGLE;
	uint8_t REG_OUT_WRITE;
	int16_t REG_REG_OPTICAL_TRACKING_READ[6];
} AppRegs;

/************************************************************************/
/* Registers' address                                                   */
/************************************************************************/
/* Registers */
#define ADD_REG_CAM0_EVENT                  32 // U8     
#define ADD_REG_CAM1_EVENT                  33 // U8     
#define ADD_REG_CAM0_TRIGGER_FREQUENCY      34 // U16    Sets the trigger frequency for camera 0 between 1 and 1000
#define ADD_REG_CAM0_TRIGGER_DURATION_US    35 // U16    Sets the duration of the trigger pulse (minimum is 100) for camera 0
#define ADD_REG_CAM1_TRIGGER_FREQUENCY      36 // U16    Sets the trigger frequency for camera 1 between 1 and 1000
#define ADD_REG_CAM1_TRIGGER_DURATION_US    37 // U16    Sets the duration of the trigger pulse (minimum is 100) for camera 1
#define ADD_REG_START_AND_STOP              38 // U8     Starts or stops the cameras immediately
#define ADD_REG_IN_STATE                    39 // U8     Contains the state of the lick ports
#define ADD_REG_VALVE0_PULSE                40 // U8     Configures the valve 0 open time in milliseconds
#define ADD_REG_VALVE1_PULSE                41 // U8     Configures the valve 1 open time in milliseconds
#define ADD_REG_OUT_SET                     42 // U8     Bitmask to set the available outputs
#define ADD_REG_OUT_CLEAR                   43 // U8     Bitmask to clear the digital ouputs
#define ADD_REG_OUT_TOGGLE                  44 // U8     Bitmask to toggle the digital ouputs
#define ADD_REG_OUT_WRITE                   45 // U8     Bitmask to write the digital ouputs
#define ADD_REG_REG_OPTICAL_TRACKING_READ   46 // I16    

/************************************************************************/
/* PWM Generator registers' memory limits                               */
/*                                                                      */
/* DON'T change the APP_REGS_ADD_MIN value !!!                          */
/* DON'T change these names !!!                                         */
/************************************************************************/
/* Memory limits */
#define APP_REGS_ADD_MIN                    0x20
#define APP_REGS_ADD_MAX                    0x2E
#define APP_NBYTES_OF_REG_BANK              30

/************************************************************************/
/* Registers' bits                                                      */
/************************************************************************/
#define B_TRIGGER                          (1<<0)       // A trigger was sent to camera
#define MSK_STROBE_DIRECT                  0            // Selects the direct line
#define MSK_STROBE_PULL_UP                 1            // Selects the pull-up line
#define B_START_CAM0                       (1<<0)       // 
#define B_START_CAM1                       (1<<1)       // 
#define B_STOP_CAM0                        (1<<2)       // 
#define B_STOP_CAM1                        (1<<3)       // 
#define B_LICK0                            (1<<0)       // 
#define B_LICK1                            (1<<1)       // 
#define B_LICK0_CHANGED                    (1<<4)       // 
#define B_LICK1_CHANGED                    (1<<5)       // 
#define B_TRIGGER_CAM0                     (1<<0)       // 
#define B_TRIGGER_CAM1                     (1<<1)       // 
#define B_VALVE0                           (1<<2)       // 
#define B_VALVE1                           (1<<3)       // 
#define B_PULSE_VALVE0                     (1<<4)       // 
#define B_PULSE_VALVE1                     (1<<5)       // 

#endif /* _APP_REGS_H_ */