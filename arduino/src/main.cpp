#include <Arduino.h>
#include "uplink.h"
#include "main.h"

extern "C" {
    #include "motor.h"
    #include "pinout.h"
    #include "odometry.h"
}

////////////////////
/// Protobuffers ///
////////////////////
antikeimena_Config config;
antikeimena_Motor  motor;
antikeimena_Sensor sensor;
antikeimena_Status status;

//////////////////////
/// Setup function ///
//////////////////////
void setup() {

  setup_motor();
  setup_odometry();
  setup_uplink();

  status.version       = 12;
  status.uptime        = 13;
  status.sensorInError = 14;
}

////////////////////
/// Endless loop ///
////////////////////
void loop() {
   delay(1000);
   sendPB();
}
