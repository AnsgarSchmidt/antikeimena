#include "pinout.h"

void setup_pin(){
  pinMode(MOTOR_PWM_RIGHT, OUTPUT);
  pinMode(MOTOR_PWM_LEFT,  OUTPUT);
  pinMode(MOTOR_BREAK,     OUTPUT);

  digitalWrite(MOTOR_BREAK, LOW);
}



void setup() {
  Serial.begin(9600);
  setup_pin();
}

void loop() {
  digitalWrite(MOTOR_BREAK, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(MOTOR_BREAK, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
