#include <Arduino.h>
#include "battery.h"
#include "pinout.h"

float battery_voltage = 0.0;

void battery_setup(void){
}

void battery_measure(void){

    uint64_t val = 0;

    for(uint8_t i = 0; i < BATTERY_MEASURE_NUM; i++){
        val += analogRead(PIN_BATTERY);
    }

    battery_voltage = (val / BATTERY_MEASURE_NUM) * BATTERY_VOLTAGE_FACTOR;

}
