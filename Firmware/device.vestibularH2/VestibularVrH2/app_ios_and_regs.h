#ifndef _APP_IOS_AND_REGS_H_
#define _APP_IOS_AND_REGS_H_
#include "cpu.h"

void init_ios(void);
/************************************************************************/
/* Definition of input pins                                             */
/************************************************************************/
// LICK0                  Description: Input for the Lick 0
// LICK1                  Description: Input for the Lick 1
//#define read_LICK0 read_io(PORTA, 0)            // LICK0
//#define read_LICK1 read_io(PORTA, 1)            // LICK1






// EMERGENCY_INPUT			Description: Emergency-button state; NO; closed=GND when pressed
// CLOCK_INPUT				Description: External Clock signal
// ENCODER_A_PHASE			Description: Rotary A-Phase input
// ENCODER_B_PHASE			Description: Rotary B-Phase input

#define read_EMERGENCY_INPUT read_io(PORTB, 0)		// EMERGENCY_INPUT
#define read_CLOCK_INPUT read_io(PORTC, 2)			// CLOCK_INPUT
#define read_ENCODER_A_PHASE read_io(PORTC, 4)		// ENCODER_A_PHASE
#define read_ENCODER_B_PHASE read_io(PORTC, 5)		// ENCODER_B_PHASE



/************************************************************************/
/* Definition of output pins                                            */
/************************************************************************/
// LED_STATE              Description: Power's LED

// STEP_MOTOR_ENABLE			Description: Enables Step Motor 
// STEP_MOTOR_PULSE				Description: Defines Step Motor speed
// STEP_MOTOR_DIRECTION			Description: Defines Step Motor spinning direction


/* LED_STATE */
#define set_LED_STATE set_io(PORTR, 0)
#define clr_LED_STATE clear_io(PORTR, 0)
#define tgl_LED_STATE toggle_io(PORTR, 0)
#define read_LED_STATE read_io(PORTR, 0)

/* STEP_MOTOR_ENABLE */
#define set_STEP_MOTOR_ENABLE set_io(PORTC, 0)
#define clr_STEP_MOTOR_ENABLE clear_io(PORTC, 0)
#define tgl_STEP_MOTOR_ENABLE toggle_io(PORTC, 0)
#define read_STEP_MOTOR_ENABLE read_io(PORTC, 0)

/* STEP_MOTOR_PULSE */
#define set_STEP_MOTOR_PULSE set_io(PORTC, 3)
#define clr_STEP_MOTOR_PULSE clear_io(PORTC, 3)
#define tgl_STEP_MOTOR_PULSE toggle_io(PORTC, 3)
#define read_STEP_MOTOR_PULSE read_io(PORTC, 3)

/* STEP_MOTOR_DIRECTION */
#define set_STEP_MOTOR_DIRECTION set_io(PORTC, 6)
#define clr_STEP_MOTOR_DIRECTION clear_io(PORTC, 6)
#define tgl_STEP_MOTOR_DIRECTION toggle_io(PORTC, 6)
#define read_STEP_MOTOR_DIRECTION read_io(PORTC, 6)



/************************************************************************/
/* Registers' structure                                                 */
/************************************************************************/
typedef struct
{
	//uint8_t REG_CAM0_EVENT;
	//uint8_t REG_CAM1_EVENT;
	//uint16_t REG_CAM0_TRIGGER_FREQUENCY;
	//uint16_t REG_CAM0_TRIGGER_DURATION_US;
	//uint16_t REG_CAM1_TRIGGER_FREQUENCY;
	//uint16_t REG_CAM1_TRIGGER_DURATION_US;
	//uint8_t REG_START_AND_STOP;
	uint8_t REG_IN_STATE;
	//uint8_t REG_VALVE0_PULSE;
	//uint8_t REG_VALVE1_PULSE;
	uint8_t REG_OUT_SET;
	uint8_t REG_OUT_CLEAR;
	uint8_t REG_OUT_TOGGLE;
	uint8_t REG_OUT_WRITE;
	//int16_t REG_REG_OPTICAL_TRACKING_READ[6];
} AppRegs;

/************************************************************************/
/* Registers' address                                                   */
/************************************************************************/
/* Registers */
//#define ADD_REG_CAM0_EVENT                  32 // U8     
//#define ADD_REG_CAM1_EVENT                  33 // U8     
//#define ADD_REG_CAM0_TRIGGER_FREQUENCY      34 // U16    Sets the trigger frequency for camera 0 between 1 and 1000
//#define ADD_REG_CAM0_TRIGGER_DURATION_US    35 // U16    Sets the duration of the trigger pulse (minimum is 100) for camera 0
//#define ADD_REG_CAM1_TRIGGER_FREQUENCY      36 // U16    Sets the trigger frequency for camera 1 between 1 and 1000
//#define ADD_REG_CAM1_TRIGGER_DURATION_US    37 // U16    Sets the duration of the trigger pulse (minimum is 100) for camera 1
//#define ADD_REG_START_AND_STOP              38 // U8     Starts or stops the cameras immediately
#define ADD_REG_IN_STATE                    39 // U8     Contains the state of the lick ports
//#define ADD_REG_VALVE0_PULSE                40 // U8     Configures the valve 0 open time in milliseconds
//#define ADD_REG_VALVE1_PULSE                41 // U8     Configures the valve 1 open time in milliseconds
#define ADD_REG_OUT_SET                     42 // U8     Bitmask to set the available outputs
#define ADD_REG_OUT_CLEAR                   43 // U8     Bitmask to clear the digital ouputs
#define ADD_REG_OUT_TOGGLE                  44 // U8     Bitmask to toggle the digital ouputs
#define ADD_REG_OUT_WRITE                   45 // U8     Bitmask to write the digital ouputs
//#define ADD_REG_REG_OPTICAL_TRACKING_READ   46 // I16    

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
//#define MSK_STROBE_DIRECT                  0            // Selects the direct line
#define MSK_STROBE_PULL_UP                 1            // Selects the pull-up line
//#define B_START_CAM0                       (1<<0)       // 
//#define B_START_CAM1                       (1<<1)       // 
//#define B_STOP_CAM0                        (1<<2)       // 
#define B_ENCODER_B_PHASE                        (1<<3)       // 
#define B_EMERGENCY_INPUT                            (1<<0)       // 
#define B_ENCODER_A_PHASE                            (1<<1)       // 
#define B_EMERGENCY_INPUT_CHANGED                    (1<<4)       // 
#define B_ENCODER_A_PHASE_CHANGED                    (1<<5)       // 
#define B_STEP_MOTOR_ENABLE                     (1<<0)       // 
#define B_STEP_MOTOR_PULSE                     (1<<1)       // 
#define B_STEP_MOTOR_DIRECTION                           (1<<2)       // 
//#define B_VALVE1                           (1<<3)       // 
//#define B_PULSE_VALVE0                     (1<<4)       // 
//#define B_PULSE_VALVE1                     (1<<5)       // 

#endif /* _APP_REGS_H_ */