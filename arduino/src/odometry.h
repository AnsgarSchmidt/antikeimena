#ifndef ODOMETRY_H
#define ODOMERTY_H

#include <Arduino.h>

volatile uint16_t odometry_left_counter;
volatile uint16_t odometry_right_counter;

extern void odometry_setup(void);
extern void odometry_handle_left(void);
extern void odometry_handle_right(void);

extern uint16_t odometry_get_left_counter(void);
extern uint16_t odometry_get_right_counter(void);

#endif
