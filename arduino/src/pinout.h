#ifndef PINOUT_H
#define PINOUT_H

//      Serial RX         0
//      Serial TX         1
#define MOTOR_PWM_RIGHT  13 // PWM
#define MOTOR_PWM_LEFT   12 // PWM
#define MOTOR_BREAK      11

#define BATTERY          A0

#define ODOMETRY_LEFT     2 // Interrupt enabled
#define ODOMETRY_RIGHT    3 // Interrupt enabled

extern void setup_pin(void);

#endif
