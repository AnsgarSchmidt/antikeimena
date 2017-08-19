#include <Arduino.h>
#include "motor.h"
#include "pinout.h"
#include "Servo.h"
#include "pinout.h"

Servo motor_left;
Servo motor_right;

void motor_setup(void){

  pinMode(PIN_MOTOR_BREAK,      OUTPUT);
  digitalWrite(PIN_MOTOR_BREAK, LOW);   // Motors are blocked at startup

  motor_left.attach(PIN_MOTOR_PWM_LEFT);
  motor_left.write(90); // neutral

  motor_right.attach(PIN_MOTOR_PWM_RIGHT);
  motor_right.write(90); // neutral
}

void motor_move(uint8_t speed_left, uint8_t speed_right){

    if(speed_left == 90 && speed_right == 90){
        digitalWrite(PIN_MOTOR_BREAK, LOW);
    }else{
        digitalWrite(PIN_MOTOR_BREAK, HIGH);
    }

    motor_left.write(speed_left);
    motor_right.write(speed_right);

}
