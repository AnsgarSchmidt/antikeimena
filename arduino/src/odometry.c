#include <Arduino.h>
#include "odometry.h"
#include "pinout.h"

void setup_odometry(void){

    odometry_left_counter  = 0;
    odometry_right_counter = 0;

    attachInterrupt(digitalPinToInterrupt(ODOMETRY_LEFT),  handle_odometry_left,  RISING);
    attachInterrupt(digitalPinToInterrupt(ODOMETRY_RIGHT), handle_odometry_right, RISING);

}

void handle_odometry_left(void){
    odometry_left_counter++;
}

void handle_odometry_right(void){
    odometry_right_counter++;
}

uint16_t get_odometry_left_counter(void){
    return 0;
}

uint16_t get_odometry_right_counter(void){
    return 0;
}
