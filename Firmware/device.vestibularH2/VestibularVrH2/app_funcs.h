#ifndef _APP_FUNCTIONS_H_
#define _APP_FUNCTIONS_H_
#include <avr/io.h>


/************************************************************************/
/* Define if not defined                                                */
/************************************************************************/
#ifndef bool
	#define bool uint8_t
#endif
#ifndef true
	#define true 1
#endif
#ifndef false
	#define false 0
#endif


/************************************************************************/
/* Prototypes                                                           */
/************************************************************************/
void app_read_ANALOG_VREF(void);
void app_read_HALL_EFFECT_SENSOR(void);
void app_read_CLOCK_INPUT(void);
void app_read_EMERGENCY_INPUT(void);
void app_read_ENCODER_A_PHASE(void);
void app_read_ENCODER_B_PHASE(void);
void app_read_REG_IN_STATE(void);
void app_read_REG_OUT_SET(void);
void app_read_REG_OUT_CLEAR(void);
void app_read_REG_OUT_TOGGLE(void);
void app_read_REG_OUT_WRITE(void);


bool app_write_ANALOG_VREF(void *a);
bool app_write_HALL_EFFECT_SENSOR(void *a);
bool app_write_CLOCK_INPUT(void *a);
bool app_write_EMERGENCY_INPUT(void *a);
bool app_write_ENCODER_A_PHASE(void *a);
bool app_write_ENCODER_B_PHASE(void *a);
bool app_write_REG_IN_STATE(void *a);
bool app_write_REG_OUT_SET(void *a);
bool app_write_REG_OUT_CLEAR(void *a);
bool app_write_REG_OUT_TOGGLE(void *a);
bool app_write_REG_OUT_WRITE(void *a);
bool app_write_REG_REG_OPTICAL_TRACKING_READ(void *a);


#endif /* _APP_FUNCTIONS_H_ */