#ifndef MAIN_H
#define MAIN_H

extern "C" {
    #include "pb.h"
    #include "config.pb.h"
    #include "motor.pb.h"
    #include "sensor.pb.h"
    #include "status.pb.h"
}

extern antikeimena_Config config;
extern antikeimena_Motor  motor;
extern antikeimena_Sensor sensor;
extern antikeimena_Status status;

#endif
