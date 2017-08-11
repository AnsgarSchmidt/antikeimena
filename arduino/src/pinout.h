#ifndef PINOUT_H
#define PINOUT_H

//      Serial RX         0
//      Serial TX         1
#define PIN_MOTOR_PWM_RIGHT  13 // PWM
#define PIN_MOTOR_PWM_LEFT   12 // PWM
#define PIN_MOTOR_BREAK      11

#define PIN_BATTERY          A0

#define PIN_ODOMETRY_LEFT     2 // Interrupt enabled
#define PIN_ODOMETRY_RIGHT    3 // Interrupt enabled

#endif
