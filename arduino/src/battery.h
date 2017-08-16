#ifndef BATTERY_H
#define BATTERY_H

#define BATTERY_MEASURE_NUM    100
#define BATTERY_VOLTAGE_FACTOR 1.32

extern float battery_voltage;

extern void  battery_setup(void);
extern void  battery_measure(void);

#endif
