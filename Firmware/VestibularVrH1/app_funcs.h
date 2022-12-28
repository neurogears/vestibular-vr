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
void app_read_REG_CAM0_EVENT(void);
void app_read_REG_CAM1_EVENT(void);
void app_read_REG_CAM0_TRIGGER_FREQUENCY(void);
void app_read_REG_CAM0_TRIGGER_DURATION_US(void);
void app_read_REG_CAM1_TRIGGER_FREQUENCY(void);
void app_read_REG_CAM1_TRIGGER_DURATION_US(void);
void app_read_REG_START_AND_STOP(void);
void app_read_REG_IN_STATE(void);
void app_read_REG_VALVE0_PULSE(void);
void app_read_REG_VALVE1_PULSE(void);
void app_read_REG_OUT_SET(void);
void app_read_REG_OUT_CLEAR(void);
void app_read_REG_OUT_TOGGLE(void);
void app_read_REG_OUT_WRITE(void);
void app_read_REG_REG_OPTICAL_TRACKING_READ(void);

bool app_write_REG_CAM0_EVENT(void *a);
bool app_write_REG_CAM1_EVENT(void *a);
bool app_write_REG_CAM0_TRIGGER_FREQUENCY(void *a);
bool app_write_REG_CAM0_TRIGGER_DURATION_US(void *a);
bool app_write_REG_CAM1_TRIGGER_FREQUENCY(void *a);
bool app_write_REG_CAM1_TRIGGER_DURATION_US(void *a);
bool app_write_REG_START_AND_STOP(void *a);
bool app_write_REG_IN_STATE(void *a);
bool app_write_REG_VALVE0_PULSE(void *a);
bool app_write_REG_VALVE1_PULSE(void *a);
bool app_write_REG_OUT_SET(void *a);
bool app_write_REG_OUT_CLEAR(void *a);
bool app_write_REG_OUT_TOGGLE(void *a);
bool app_write_REG_OUT_WRITE(void *a);
bool app_write_REG_REG_OPTICAL_TRACKING_READ(void *a);


#endif /* _APP_FUNCTIONS_H_ */