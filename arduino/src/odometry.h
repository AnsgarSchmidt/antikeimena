#ifndef ODOMETRY_H
#define ODOMERTY_H

#include <Arduino.h>

volatile uint16_t odometry_left_counter;
volatile uint16_t odometry_right_counter;

extern void setup_odometry(void);
extern void handle_odometry_left(void);
extern void handle_odometry_right(void);

extern uint16_t get_odometry_left_counter(void);
extern uint16_t get_odometry_right_counter(void);

#endif
