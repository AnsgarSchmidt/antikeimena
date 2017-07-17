#include "pinout.h"
#include "status.pb.h"
#include <Servo.h>

Servo leftMotor;
Servo rightMotor;

void setup_pin(){

  pinMode(MOTOR_BREAK,      OUTPUT);
  digitalWrite(MOTOR_BREAK, LOW);

  leftMotor.attach(MOTOR_PWM_LEFT);
  leftMotor.write(90);

  rightMotor.attach(MOTOR_PWM_RIGHT);
  rightMotor.write(90);
}

void setup() {
  setup_pin();
  Serial3.begin(9600);
  Serial3.println("Begin");
}

void loop() {
  digitalWrite(MOTOR_BREAK, HIGH);
  delay(100);
  Serial3.println("Hallo");

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
