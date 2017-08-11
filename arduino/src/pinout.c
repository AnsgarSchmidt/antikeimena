#include <Arduino.h>
#include "pinout.h"

void setup_pin(void){

  pinMode(MOTOR_BREAK,      OUTPUT);
  digitalWrite(MOTOR_BREAK, LOW);   // Motors are blocked at startup

  //leftMotor.attach(MOTOR_PWM_LEFT);
  //leftMotor.write(90);

  //rightMotor.attach(MOTOR_PWM_RIGHT);
  //rightMotor.write(90);

  pinMode(ODOMETRY_LEFT,  INPUT_PULLUP);
  pinMode(ODOMETRY_RIGHT, INPUT_PULLUP);

}

