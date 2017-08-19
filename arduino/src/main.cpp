#include <Arduino.h>
#include "main.h"
#include "uplink.h"
#include "usonic.h"
#include "motor.h"
#include "pinout.h"

extern "C" {
    #include "battery.h"
    #include "odometry.h"
}

//////////////////////
/// Scheduler vars ///
//////////////////////
uint16_t scheduler_send_status        = UINT16_MAX;
uint16_t scheduler_send_sensor        = UINT16_MAX;
uint16_t scheduler_measure_ultrasonic = UINT16_MAX;
uint16_t scheduler_measure_battery    = UINT16_MAX;

//////////////////////
/// Setup function ///
//////////////////////
void setup() {
  battery_setup();
  motor_setup();
  odometry_setup();
  uplink_setup();
  ultrasonic_setup();
}

////////////////////
/// Endless loop ///
////////////////////
void loop() {

   if (scheduler_measure_battery > SCHEDULER_MEASURE_BATTERY_DELAY){
        battery_measure();
        scheduler_measure_battery = 0;
   }

   if (scheduler_measure_ultrasonic > SCHEDULER_MEASURE_ULTRASONIC_DELAY){
        ultrasonic_measure();
        scheduler_measure_ultrasonic = 0;
   }

   if (scheduler_send_status > SCHEDULER_SEND_STATUS_DELAY){
        uplink_sendStatus();
        scheduler_send_status = 0;
   }

   if (scheduler_send_sensor > SCHEDULER_SEND_SENSOR_DELAY){
        uplink_sendSensor();
        scheduler_send_sensor = 0;
   }

   uplink_checkReceive();

   scheduler_send_status++;
   //scheduler_send_sensor++;
   scheduler_measure_ultrasonic++;
   scheduler_measure_battery++;
}
