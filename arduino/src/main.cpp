#include <Arduino.h>
#include "main.h"
#include "uplink.h"

extern "C" {
    #include "motor.h"
    #include "pinout.h"
    #include "odometry.h"
}

////////////////////
/// Protobuffers ///
////////////////////
antikeimena_Config config_pb;
antikeimena_Motor  motor_pb;
antikeimena_Sensor sensor_pb;
antikeimena_Status status_pb;

//////////////////////
/// Scheduler vars ///
//////////////////////
uint32_t scheduler_send_status;
uint32_t scheduler_send_sensor;

//////////////////////
/// Setup function ///
//////////////////////
void setup() {
  motor_setup();
  odometry_setup();
  uplink_setup();

  scheduler_send_status = millis();
  scheduler_send_sensor = millis();
}

////////////////////
/// Endless loop ///
////////////////////
void loop() {

   if ( (scheduler_send_status + SCHEDULER_SEND_STATUS_DELAY) < millis()){
        uplink_sendStatus();
        scheduler_send_status = millis();
   }

   if ( (scheduler_send_sensor + SCHEDULER_SEND_SENSOR_DELAY) < millis()){
        uplink_sendSensor();
        scheduler_send_sensor = millis();
   }

}
