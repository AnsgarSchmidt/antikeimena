#ifndef MAIN_H
#define MAIN_H

extern "C" {
    #include "pb.h"
    #include "config.pb.h"
    #include "motor.pb.h"
    #include "sensor.pb.h"
    #include "status.pb.h"
}

// Global vars
extern antikeimena_Config config_pb;
extern antikeimena_Motor  motor_pb;
extern antikeimena_Sensor sensor_pb;
extern antikeimena_Status status_pb;

#endif
