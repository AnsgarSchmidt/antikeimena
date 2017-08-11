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
/// Setup function ///
//////////////////////
void setup() {

  motor_setup();
  odometry_setup();
  uplink_setup();

  status_pb.version       = 12;
  status_pb.uptime        = 13;
  status_pb.sensorInError = 14;
}

////////////////////
/// Endless loop ///
////////////////////
void loop() {
   delay(1000);
   uplink_sendStatus();
}
