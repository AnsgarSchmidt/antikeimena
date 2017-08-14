#ifndef MAIN_H
#define MAIN_H

extern "C" {
    #include "pb.h"
    #include "config.pb.h"
    #include "motor.pb.h"
    #include "sensor.pb.h"
    #include "status.pb.h"
}

#define SCHEDULER_SEND_STATUS_DELAY 10000
#define SCHEDULER_SEND_SENSOR_DELAY  1000

#endif
