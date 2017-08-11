#ifndef UPLINK_H
#define UPLINK_H

#include <Arduino.h>

#include "config.pb.h"
#include "motor.pb.h"
#include "sensor.pb.h"
#include "status.pb.h"

#define MAX(a,b) ((a) > (b) ? a : b)
#define MIN(a,b) ((a) < (b) ? a : b)

#define BUFFERSIZE MAX(antikeimena_Config_size, MAX(antikeimena_Motor_size, MAX(antikeimena_Sensor_size, antikeimena_Status_size)))

extern void uplink_setup(void);
extern void uplink_sendStatus(void);
extern void uplink_sendSensor(void);

#endif
