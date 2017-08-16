#include <Arduino.h>
#include "main.h"
#include "uplink.h"
#include "usonic.h"

extern "C" {
    #include "motor.h"
    #include "pinout.h"
    #include "odometry.h"
}

//////////////////////
/// Scheduler vars ///
//////////////////////
uint16_t scheduler_send_status        = 0;
uint16_t scheduler_send_sensor        = 0;
uint16_t scheduler_measure_ultrasonic = 0;

//////////////////////
/// Setup function ///
//////////////////////
void setup() {
  motor_setup();
  odometry_setup();
  uplink_setup();
  ultrasonic_setup();
}

////////////////////
/// Endless loop ///
////////////////////
void loop() {

   if (scheduler_send_status > SCHEDULER_SEND_STATUS_DELAY){
        //uplink_sendStatus();
        scheduler_send_status = 0;
   }

   if (scheduler_send_sensor > SCHEDULER_SEND_SENSOR_DELAY){
        uplink_sendSensor();
        scheduler_send_sensor = 0;
   }

   if (scheduler_measure_ultrasonic > SCHEDULER_MEASURE_ULTRASONIC_DELAY){
        ultrasonic_measure();
        scheduler_measure_ultrasonic = 0;
   }

   scheduler_send_status++;
   scheduler_send_sensor++;
   scheduler_measure_ultrasonic++;
}
