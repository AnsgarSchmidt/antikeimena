#include <Arduino.h>
#include "uplink.h"
#include "main.h"

extern "C" {
    #include "pinout.h"
    #include "odometry.h"
}

antikeimena_Status status;
antikeimena_Config config;

void setup() {
  setup_pin();
  Serial.begin(9600);

  status.version       = 12;
  status.uptime        = 13;
  status.sensorInError = 14;
}

void loop() {

   delay(1000);
   sendPB();

  //digitalWrite(MOTOR_BREAK, HIGH);
  //delay(100);
  //Serial3.println("Hallo");

/*

  int pos = 0;    // variable to store the servo position
  
  for (pos = 90; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    leftMotor.write(pos);              // tell servo to go to position in variable 'pos'
    rightMotor.write(pos);              // tell servo to go to position in variable 'pos'
    delay(50);                       // waits 15ms for the servo to reach the position
  }
  
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    leftMotor.write(pos);              // tell servo to go to position in variable 'pos'
    rightMotor.write(pos);              // tell servo to go to position in variable 'pos'
    delay(50);                       // waits 15ms for the servo to reach the position
  }


  for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    leftMotor.write(pos);              // tell servo to go to position in variable 'pos'
    rightMotor.write(pos);              // tell servo to go to position in variable 'pos'
    delay(50);                       // waits 15ms for the servo to reach the position
  }
*/
}
