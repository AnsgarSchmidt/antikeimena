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

#define UPLINK_SPEED 115200

#define NOTSET_MESSAGE 0
#define CONFIG_MESSAGE 1
#define MOTOR_MESSAGE  2
#define SENSOR_MESSAGE 3
#define STATUS_MESSAGE 4

extern void uplink_setup(void);
extern void uplink_sendStatus(void);
extern void uplink_sendSensor(void);
extern void uplink_checkReceive(void);

#endif
